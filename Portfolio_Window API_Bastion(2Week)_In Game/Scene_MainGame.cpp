#include "stdafx.h"
#include "Scene_MainGame.h"
#include "UI.h"

#include "Stage.h"
#include "Tile.h"
#include "Obstacle_Broken.h"
#include "Obstacle_Unbroken.h"
#include "Character_PC.h"
#include "Enemy_Extra.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
using namespace rapidjson;

HRESULT Scene_MainGame::init()
{
	m_sceneType = SCENE_TYPE::SCENE_MAINGAME;

	LoadProcess();

	CAMERAMANAGER->init();
	PROJECTILEMANAGER->init();
	EFFECTMANAGER->init();
	PARTICLEMANAGER->init();
	UIMANAGER->init(m_sceneType);

	SKILLMANAGER->init();

	SOUNDMANAGER->stop("BGM_Bastion");
	SOUNDMANAGER->play("BGM_Stage1");

	m_curBackgroundType = BACKGROUND0;
	m_elapsedChangeTime = GetTickCount();
	m_changeTime = 30;

	for (int i = 0; i < BACKGROUND_MAX; ++i)
	{
		m_background[i].backgroundType = static_cast<BACKGROUND_TYPE>(i);
		m_background[i].image = IMAGEMANAGER->findImage_Background(m_background[i].backgroundType);
		m_background[i].alpha = 0;
	}
	
	m_background[m_curBackgroundType].alpha = 255;

	m_isChage = false;
	return S_OK;
}

void Scene_MainGame::release()
{

}

void Scene_MainGame::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE) )
	{
		UIMANAGER->FindUI(UI_PAUSE)->setIsOpen(!UIMANAGER->FindUI(UI_PAUSE)->getIsOpen());
	}

	if (!UIMANAGER->CheckOpenUI())
	{
		STAGEMANAGER->update();
		TILEMANAGER->update();
		OBSTACLEMANAGER->update();
		CHARACTERMANAGER->update();
		ENEMYMANAGER->update();
		PROJECTILEMANAGER->update();
		EFFECTMANAGER->update();
		PARTICLEMANAGER->update();
		STATUSBARMANAGER->update();
		CAMERAMANAGER->update();
	}

	UIMANAGER->update();
}

void Scene_MainGame::render()
{
	if (GetTickCount() - m_elapsedChangeTime >= 1000.0f * m_changeTime)
	{
		m_elapsedChangeTime = GetTickCount();

		m_isChage = true;

		m_prevBackgroundType = m_curBackgroundType;
		switch (m_curBackgroundType)
		{
		case BACKGROUND0:
			m_curBackgroundType = BACKGROUND1;
			break;
		case BACKGROUND1:
			m_curBackgroundType = BACKGROUND2;
			break;
		case BACKGROUND2:
			m_curBackgroundType = BACKGROUND3;
			break;
		case BACKGROUND3:
			m_curBackgroundType = BACKGROUND0;
			break;
		}

		m_background[m_curBackgroundType].alpha = 255;
	}
	if (m_isChage)
	{
		m_background[m_prevBackgroundType].alpha -= 3.0f;
		if (m_background[m_curBackgroundType].alpha < 0)
			m_background[m_curBackgroundType].alpha = 0;
	}

	m_background[m_curBackgroundType].image->render(getMemDC());

	if (m_background[m_prevBackgroundType].alpha > 0)
	{
		m_background[m_prevBackgroundType].image->alphaRender(getMemDC(), m_background[m_prevBackgroundType].alpha);
	}

	

	STAGEMANAGER->render();
	TILEMANAGER->render();
	OBSTACLEMANAGER->render();
	CHARACTERMANAGER->render();
	ENEMYMANAGER->render();
	PROJECTILEMANAGER->render();
	EFFECTMANAGER->render();
	PARTICLEMANAGER->render();
	STATUSBARMANAGER->render();
	UIMANAGER->render();
	CAMERAMANAGER->render();
}

void Scene_MainGame::LoadProcess()
{
	FILE *fp = NULL;
	WCHAR FileName[32];
	UINT64 fileSize;					// 읽어들일 JSON 사이즈
	int headerSize = sizeof(UINT64);
	int err;

	wsprintfW(FileName, L"test.txt");

	//파일 읽기
	err = _wfopen_s(&fp, FileName, L"rt");
	if (err != 0) {
		return;
	}

	//헤더 읽기
	fread_s(&fileSize, headerSize, headerSize, 1, fp);

	char *pJson;

	pJson = new char[fileSize + 1];
	fread_s(pJson, fileSize, fileSize, 1, fp);
	pJson[fileSize] = '\0';

	fclose(fp);


	Document Doc;
	Doc.Parse(pJson);

	int iSpriteIndex;
	int iPosX;
	int iPosY;
	int iWidth;
	int iHeight;
	int iPropertiesWidth;
	int iPropertiesHeight;
	int iCnt;
	int iSize;
	char szObjectName[512];
	Object *newObject;
	Value::ConstMemberIterator itr;

	itr = Doc.FindMember("StageSize");
	if (itr != Doc.MemberEnd()) {
		Value &StageSizeArray = Doc["StageSize"];
		for (SizeType i = 0; i < StageSizeArray.Size(); i++) {
			Value &StageSizeObject = StageSizeArray[i];
			itr = StageSizeObject.FindMember("iWidth");
			if (itr == StageSizeObject.MemberEnd()) {
				break;
			}
			itr = StageSizeObject.FindMember("iHeight");
			if (itr == StageSizeObject.MemberEnd()) {
				break;
			}

			iWidth = StageSizeObject["iWidth"].GetUint();
			iHeight = StageSizeObject["iHeight"].GetUint();

			// 스테이지 크기
			CAMERAMANAGER->setStageWidth(iWidth);
			CAMERAMANAGER->setStageHeight(iHeight);
		}
	}


	// 맵 속성 정보
	itr = Doc.FindMember("Properties");
	if (itr != Doc.MemberEnd()) {
		Value &PropertiesArray = Doc["Properties"];
		for (SizeType i = 0; i < PropertiesArray.Size(); i++) {
			Value &PropertiesObject = PropertiesArray[i];
			itr = PropertiesObject.FindMember("iPropertiesWidth");
			if (itr == PropertiesObject.MemberEnd()) {
				break;
			}
			itr = PropertiesObject.FindMember("iPropertiesHeight");
			if (itr == PropertiesObject.MemberEnd()) {
				break;
			}
			itr = PropertiesObject.FindMember("iPropertiesSize");
			if (itr == PropertiesObject.MemberEnd()) {
				break;
			}

			iPropertiesWidth = PropertiesObject["iPropertiesWidth"].GetUint();
			iPropertiesHeight = PropertiesObject["iPropertiesHeight"].GetUint();
			iSize = PropertiesObject["iPropertiesSize"].GetUint();

			// 속성 배열 생성
			TILEMANAGER->setTilePropertyWidth(iPropertiesWidth);
			TILEMANAGER->setTilePropertyHeight(iPropertiesHeight);
			TILEMANAGER->setTilePropertySize(iSize);
			TILEMANAGER->ResizeTilePropertyInfo();

			// 타일 속성이 저장되어있는 파일 이름
			itr = PropertiesObject.FindMember("PropertiesFileName");
			if (itr == PropertiesObject.MemberEnd()) {
				break;
			}

			UTF8toUTF16(PropertiesObject["PropertiesFileName"].GetString(), FileName, 32);

			// 파일 읽기
			err = _wfopen_s(&fp, FileName, L"rt");
			if (err != 0) {
				return;
			}

			// 속성 읽기
			// ResizeMap 함수를 호출해서 버퍼를 동적할당 해놨음
			// 동적 할당한 곳에 파일 데이터 복사

			fread_s(TILEMANAGER->getTilePropertyInfo(), iSize, iSize, 1, fp);
			fclose(fp);

		}
	}


	// 스테이지 정보
	itr = Doc.FindMember("Stage");
	if (itr != Doc.MemberEnd()) {
		Value &ObjectTileArray = Doc["Stage"];
		for (SizeType i = 0; i < ObjectTileArray.Size(); i++) {
			Value &ObjectTileObject = ObjectTileArray[i];
			itr = ObjectTileObject.FindMember("iSpriteIndex");
			if (itr == ObjectTileObject.MemberEnd()) {
				break;
			}
			itr = ObjectTileObject.FindMember("iPosX");
			if (itr == ObjectTileObject.MemberEnd()) {
				break;
			}
			itr = ObjectTileObject.FindMember("iPosY");
			if (itr == ObjectTileObject.MemberEnd()) {
				break;
			}
			iSpriteIndex = ObjectTileObject["iSpriteIndex"].GetUint();
			iPosX = ObjectTileObject["iPosX"].GetUint();
			iPosY = ObjectTileObject["iPosY"].GetUint();

			// 스테이지 생성
			Stage* stage = new Stage;
			stage->setStageType(static_cast<STAGE_TYPE>(iSpriteIndex));
			stage->setPosition(PointFloatMake(iPosX, iPosY));
			stage->init();
			STAGEMANAGER->AddStage(stage);
		}
	}

	// 타일 정보
	itr = Doc.FindMember("Tile");
	if (itr != Doc.MemberEnd()) {
		Value &ObjectTileArray = Doc["Tile"];
		for (SizeType i = 0; i < ObjectTileArray.Size(); i++) {
			Value &ObjectTileObject = ObjectTileArray[i];
			itr = ObjectTileObject.FindMember("iSpriteIndex");
			if (itr == ObjectTileObject.MemberEnd()) {
				break;
			}
			itr = ObjectTileObject.FindMember("iPosX");
			if (itr == ObjectTileObject.MemberEnd()) {
				break;
			}
			itr = ObjectTileObject.FindMember("iPosY");
			if (itr == ObjectTileObject.MemberEnd()) {
				break;
			}
			iSpriteIndex = ObjectTileObject["iSpriteIndex"].GetUint();
			iPosX = ObjectTileObject["iPosX"].GetUint();
			iPosY = ObjectTileObject["iPosY"].GetUint();

			// 오브젝트 생성
			Tile* tile = new Tile;
			tile->setTileType(static_cast<TILE_TYPE>(iSpriteIndex));
			tile->setActivePosition(PointFloatMake(iPosX, iPosY));
			tile->init();
			TILEMANAGER->AddTile(tile);
		}
	}



	// 플레이어 정보
	itr = Doc.FindMember("Player");
	if (itr != Doc.MemberEnd()) {
		Value &PlayerArray = Doc["Player"];
		for (SizeType i = 0; i < PlayerArray.Size(); i++) {
			Value &PlayerObject = PlayerArray[i];
			itr = PlayerObject.FindMember("iType");
			if (itr == PlayerObject.MemberEnd()) {
				break;
			}
			itr = PlayerObject.FindMember("iPosX");
			if (itr == PlayerObject.MemberEnd()) {
				break;
			}
			itr = PlayerObject.FindMember("iPosY");
			if (itr == PlayerObject.MemberEnd()) {
				break;
			}
			iSpriteIndex = PlayerObject["iType"].GetUint();
			// 1이면 떨어지는거
			if (iSpriteIndex) {

			}
			// 0이면 일어나는거
			else {
				iSpriteIndex = ANIMATION_STATE::WAKE_UP;
			}
			iPosX = PlayerObject["iPosX"].GetUint();
			iPosY = PlayerObject["iPosY"].GetUint();

			// 오브젝트 생성
			Character* character = new Character_PC;
			character->setAnimationState(static_cast<ANIMATION_STATE>(iSpriteIndex));
			character->setDirectionState(DIRECTION_STATE::DIRECTION_NONE);
			character->setPosition(PointFloatMake(iPosX, iPosY));
			character->init();
			CHARACTERMANAGER->AddCharacter(character);
		}
	}

	// 부숴지지않는 물체 정보
	itr = Doc.FindMember("Object");
	if (itr != Doc.MemberEnd()) {
		Value &ObjectArray = Doc["Object"];
		for (SizeType i = 0; i < ObjectArray.Size(); i++) {
			Value &Object = ObjectArray[i];
			itr = Object.FindMember("iSpriteIndex");
			if (itr == Object.MemberEnd()) {
				break;
			}
			itr = Object.FindMember("iPosX");
			if (itr == Object.MemberEnd()) {
				break;
			}
			itr = Object.FindMember("iPosY");
			if (itr == Object.MemberEnd()) {
				break;
			}
			iSpriteIndex = Object["iSpriteIndex"].GetUint();
			iPosX = Object["iPosX"].GetUint();
			iPosY = Object["iPosY"].GetUint();

			// 오브젝트 생성
			Obstacle* obstacle = new Obstacle_Unbroken;
			obstacle->setObstacleType(static_cast<OBSTACLE_TYPE>(iSpriteIndex));
			obstacle->setPosition(PointFloatMake(iPosX, iPosY));
			obstacle->init();
			OBSTACLEMANAGER->AddObstacle(obstacle);
		}
	}

	// 부서지는 물체 정보
	itr = Doc.FindMember("Broken");
	if (itr != Doc.MemberEnd()) {
		Value &BrokenArray = Doc["Broken"];
		for (SizeType i = 0; i < BrokenArray.Size(); i++) {
			Value &BrokenObject = BrokenArray[i];
			itr = BrokenObject.FindMember("iSpriteIndex");
			if (itr == BrokenObject.MemberEnd()) {
				break;
			}
			itr = BrokenObject.FindMember("iPosX");
			if (itr == BrokenObject.MemberEnd()) {
				break;
			}
			itr = BrokenObject.FindMember("iPosY");
			if (itr == BrokenObject.MemberEnd()) {
				break;
			}
			iSpriteIndex = BrokenObject["iSpriteIndex"].GetUint();
			iPosX = BrokenObject["iPosX"].GetUint();
			iPosY = BrokenObject["iPosY"].GetUint();

			// 오브젝트 생성
			Obstacle* obstacle = new Obstacle_Broken;
			obstacle->setObstacleType(static_cast<OBSTACLE_TYPE>(iSpriteIndex));
			obstacle->setActivePosition(PointFloatMake(iPosX, iPosY));
			obstacle->init();
			OBSTACLEMANAGER->AddObstacle(obstacle);
		}
	}


	// 적 정보
	itr = Doc.FindMember("Enemy");
	if (itr != Doc.MemberEnd()) {
		Value &BrokenArray = Doc["Enemy"];
		for (SizeType i = 0; i < BrokenArray.Size(); i++) {
			Value &BrokenObject = BrokenArray[i];
			itr = BrokenObject.FindMember("iSpriteIndex");
			if (itr == BrokenObject.MemberEnd()) {
				break;
			}
			itr = BrokenObject.FindMember("iPosX");
			if (itr == BrokenObject.MemberEnd()) {
				break;
			}
			itr = BrokenObject.FindMember("iPosY");
			if (itr == BrokenObject.MemberEnd()) {
				break;
			}
			iSpriteIndex = BrokenObject["iSpriteIndex"].GetUint();
			iPosX = BrokenObject["iPosX"].GetUint();
			iPosY = BrokenObject["iPosY"].GetUint();

			// 적 생성
			Enemy* enemy = new Enemy_Extra;
			enemy->setEnemyType(static_cast<ENEMY_TYPE>(iSpriteIndex));
			enemy->setPosition(PointFloatMake(iPosX, iPosY));
			enemy->init();
			ENEMYMANAGER->AddEnemy(enemy);
		}
	}
}


Scene_MainGame::Scene_MainGame()
{
}


Scene_MainGame::~Scene_MainGame()
{
}
