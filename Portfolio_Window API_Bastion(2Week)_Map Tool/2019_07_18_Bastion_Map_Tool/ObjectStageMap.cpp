// 기명준
// 스테이지 맵
// 맵툴로 생성한 스테이지의 크기 및 속성 관리
// Click 함수에서 현재 상태에 따라 전역 변수로 선언된 게임 오브젝트 리스트를 관리

#include "stdafx.h"
#include "ObjectStageMap.h"
#include "ObjectUnit.h"


ObjectStageMap::ObjectStageMap(int iMapWidth, int iMapHeight)
{
	// 타입
	m_iType = df_TYPE_STAGE_MAP;
	// 위치
	m_dX = 0;
	m_dY = 0;
	// 스프라이트 번호
	m_iSpriteIndex = df_SPRITE_BACKGROUND_2;
	// 오브젝트 범위
	m_dLeft = 0;
	m_dTop = 0;
	m_dRight = m_dLeft + g_iDestWidth;
	m_dBottom = m_dTop + g_iDestHeight;
	// 그리기 우선순위
	m_iRenderPriority = 0;

	CreateMap(iMapWidth, iMapHeight);
}


ObjectStageMap::~ObjectStageMap()
{
	ReleaseMap();
}

bool ObjectStageMap::Action()
{
	return false;
}

void ObjectStageMap::Draw()
{
	g_cSprite->DrawSprite(m_iSpriteIndex, m_dX, m_dY, g_bypDest, g_iDestWidth, g_iDestHeight, g_iDestPitch, false);
}

// 스테이지가 클릭 됬을 경우
// 전역 변수 g_MouseState의 상태에 따라 분기 처리
bool ObjectStageMap::Click()
{
	CList<Object*>::iterator iter;
	CList<Object*>::iterator iter_end;
	Object *newObject;
	Object *ObjectTemp;
	int iMouseX;
	int iMouseY;
	int iTilePosX;
	int iTilePosY;
	int iPropertiesX;
	int iPropertiesY;

	//--------------------------------------
	// 화면 기준으로 움직이는 UI
	// 카메라 좌표를 빼준다
	//--------------------------------------
	iMouseX = g_iMouseX - g_CameraRect.left;
	iMouseY = g_iMouseY - g_CameraRect.top;

	if (m_dLeft < iMouseX && iMouseX < m_dRight &&
		m_dTop < iMouseY && iMouseY < m_dBottom) {

		switch (g_MouseState)
		{
			// 아무것도 선택되지 않은 상태
		case MOUSE_STATE_EMPT:
			break;
			// 4칸 짜리 타일
		case MOUSE_STATE_TILE_MAKE_4:
			iPropertiesX = g_MousePointer->m_dX / df_TILE_PROPERTIES_SIZE;
			iPropertiesY = g_MousePointer->m_dY / df_TILE_PROPERTIES_SIZE;

			SetProperties(iPropertiesX, iPropertiesY);

			newObject = new ObjectUnit(df_TYPE_TILE, g_iMakeTileIndex, g_MousePointer->m_dX, g_MousePointer->m_dY);
			g_ObjectList->push_back(newObject);

			break;
			// 1칸 짜리 타일
		case MOUSE_STATE_TILE_MAKE_1:
			iPropertiesX = g_MousePointer->m_dX / df_TILE_PROPERTIES_SIZE;
			iPropertiesY = g_MousePointer->m_dY / df_TILE_PROPERTIES_SIZE;

			SetProperties(iPropertiesX, iPropertiesY);

			newObject = new ObjectUnit(df_TYPE_TILE, g_iMakeTileIndex, g_MousePointer->m_dX, g_MousePointer->m_dY);
			g_ObjectList->push_back(newObject);

			break;
			// 일반 오브젝트
		case MOUSE_STATE_OBJECT_MAKE:
			// 스프라이트 중점좌표가 기준임 x, y
			iPropertiesX = g_iMouseX / df_TILE_PROPERTIES_SIZE;
			iPropertiesY = g_iMouseY / df_TILE_PROPERTIES_SIZE;

			if (CheckProperties(iPropertiesX, iPropertiesY)) {
				iTilePosX = iPropertiesX * df_TILE_PROPERTIES_SIZE;
				iTilePosY = iPropertiesY * df_TILE_PROPERTIES_SIZE;

				SetProperties(iPropertiesX, iPropertiesY);

				newObject = new ObjectUnit(df_TYPE_OBJECT, g_iMakeTileIndex, iTilePosX, iTilePosY);
				g_ObjectList->push_back(newObject);
			}

			break;
			// 거대 지형
		case MOUSE_STATE_STAGE_MAKE:
			// 스프라이트 중점좌표가 기준임 x, y
			iPropertiesX = g_iMouseX / df_TILE_PROPERTIES_SIZE;
			iPropertiesY = g_iMouseY / df_TILE_PROPERTIES_SIZE;

			if (CheckProperties(iPropertiesX, iPropertiesY)) {
				iTilePosX = iPropertiesX * df_TILE_PROPERTIES_SIZE;
				iTilePosY = iPropertiesY * df_TILE_PROPERTIES_SIZE;

				SetProperties(iPropertiesX, iPropertiesY);

				newObject = new ObjectUnit(df_TYPE_STAGE, g_iMakeTileIndex, iTilePosX, iTilePosY);
				g_ObjectList->push_back(newObject);
			}

			break;
			// 파괴되는 오브젝트
		case MOUSE_STATE_BROKEN_MAKE:
			// 스프라이트 중점좌표가 기준임 x, y
			iPropertiesX = g_iMouseX / df_TILE_PROPERTIES_SIZE;
			iPropertiesY = g_iMouseY / df_TILE_PROPERTIES_SIZE;

			if (CheckProperties(iPropertiesX, iPropertiesY)) {
				iTilePosX = iPropertiesX * df_TILE_PROPERTIES_SIZE;
				iTilePosY = iPropertiesY * df_TILE_PROPERTIES_SIZE;

				SetProperties(iPropertiesX, iPropertiesY);

				newObject = new ObjectUnit(df_TYPE_BROKEN, g_iMakeTileIndex, iTilePosX, iTilePosY);
				g_ObjectList->push_back(newObject);
			}

			break;
			// 
		case MOUSE_STATE_ENEMY_MAKE:
			// 스프라이트 중점좌표가 기준임 x, y
			iPropertiesX = g_iMouseX / df_TILE_PROPERTIES_SIZE;
			iPropertiesY = g_iMouseY / df_TILE_PROPERTIES_SIZE;

			if (CheckProperties(iPropertiesX, iPropertiesY)) {
				iTilePosX = iPropertiesX * df_TILE_PROPERTIES_SIZE;
				iTilePosY = iPropertiesY * df_TILE_PROPERTIES_SIZE;

				SetProperties(iPropertiesX, iPropertiesY);

				newObject = new ObjectUnit(df_TYPE_ENEMY, g_iMakeTileIndex, iTilePosX, iTilePosY);
				g_ObjectList->push_back(newObject);
			}

			break;
		case MOUSE_STATE_PLAYER_MAKE:
			// 스프라이트 중점좌표가 기준임 x, y
			iPropertiesX = g_iMouseX / df_TILE_PROPERTIES_SIZE;
			iPropertiesY = g_iMouseY / df_TILE_PROPERTIES_SIZE;

			if (CheckProperties(iPropertiesX, iPropertiesY)) {
				iTilePosX = iPropertiesX * df_TILE_PROPERTIES_SIZE;
				iTilePosY = iPropertiesY * df_TILE_PROPERTIES_SIZE;

				SetProperties(iPropertiesX, iPropertiesY);

				if (g_Player != NULL) {
					g_ObjectList->delete_Node(g_Player);
				}

				g_Player = new ObjectUnit(df_TYPE_PLAYER , g_iMakeTileIndex, iTilePosX, iTilePosY);
				g_ObjectList->push_back(g_Player);
			}
			
			break;
		case MOUSE_STATE_ERASE:
			// 지울 영역 탐색
			iter = g_ObjectList->rbegin();
			iter_end = g_ObjectList->head();
			while (iter != iter_end) {
				ObjectTemp = *iter;
				
				switch (ObjectTemp->m_iType) {
				case df_TYPE_STAGE:
				case df_TYPE_TILE:
				case df_TYPE_PLAYER:
				case df_TYPE_OBJECT:
				case df_TYPE_BROKEN:
				case df_TYPE_ENEMY:
					if (((ObjectUnit *)ObjectTemp)->Erase(g_iMouseX, g_iMouseY)) {
						// 속성도 지우기
						//--------------------------------------
						// 솔직히 오브젝트가 자신의 속성좌표 지우는거
						// 애바참치임
						// 그냥 다시 모든 오브젝트 돌면서
						// 속성 업데이트하는게 나음
						//--------------------------------------
						g_bUpdateProperties = true;
					}
					break;
				}

				--iter;
			}


			break;
		default:
			break;
		}
		return true;
	}

	return false;
}

// 맵 크기 변경
// iMapWidth : 변경할 가로 길이
// iMapHeight : 변경할 세로 길이
void ObjectStageMap::ResizeMap(int iMapWidth, int iMapHeight)
{
	ReleaseMap();
	CreateMap(iMapWidth, iMapHeight);
}

// 맵 속성 생성
// iMapWidth : 맵 속성 가로 길이
// iMapHeight : 맵 속성 세로 길이
void ObjectStageMap::CreateMap(int iMapWidth, int iMapHeight)
{
	// 가로
	m_iPropertiesWidth = iMapWidth / df_TILE_PROPERTIES_SIZE;
	if (iMapWidth % df_TILE_PROPERTIES_SIZE) {
		++m_iPropertiesWidth;
	}
	// 세로
	m_iPropertiesHeight = iMapHeight / df_TILE_PROPERTIES_SIZE;
	if (iMapHeight % df_TILE_PROPERTIES_SIZE) {
		++m_iPropertiesHeight;
	}
	// 크기
	m_iPropertiesSize = m_iPropertiesWidth * m_iPropertiesHeight;

	// 동적 생성
	m_bypMapProperties = (BYTE*)malloc(m_iPropertiesSize);

	// 1번으로 멤셋 1번은 빈 공간임
	memset(m_bypMapProperties, 1, m_iPropertiesSize);
}

void ObjectStageMap::ReleaseMap()
{
	free(m_bypMapProperties);
}

// 속성 값 셋
// iPropertiesX : 변경할 속성 시작 좌표 X
// iPropertiesY : 변경할 속성 시작 좌표 Y
void ObjectStageMap::SetProperties(int iPropertiesX, int iPropertiesY)
{
	int iCntX;						// 카운트 X
	int iCntY;						// 카운트 Y
	int iArrayCntX;					// 맵 속성 배열의 범위를 벗어날 경우 보정할 좌표 X
	int iArrayCntY;					// 맵 속성 배열의 범위를 벗어날 경우 보정할 좌표 Y
	int iPropertiesSizeX;			// 변경할 속성 가로 길이
	int iPropertiesSizeY;			// 변경할 속성 세로 길이
	int iArrayPropertiesIndex;		// 변경할 속성 배열 인덱스
	int iMapPropertiesIndex;		// 변경할 맵 속성 배열 인덱스

	//--------------------------------------
	// 타일 범위
	// 중점 좌표를 뺀 값이 시작 위치 좌표
	//--------------------------------------
	iPropertiesX = iPropertiesX - g_iPropertiesCenterPointX;
	iPropertiesY = iPropertiesY - g_iPropertiesCenterPointY;


	iPropertiesSizeX = g_iMakePropertiesSizeX;	// 변경할 속성 가로 길이
	iPropertiesSizeY = g_iMakePropertiesSizeY;	// 변경할 속성 세로 길이

	// 맵 속성 배열의 범위를 벗어날 경우 보정활 좌표
	iArrayCntX = 0;
	iArrayCntY = 0;

	// 화면밖으로 빠져나가는지?
	// 빠져나가면 좌표와 길이들 보정
	if (iPropertiesX < 0) {
		iArrayCntX = -iPropertiesX;
		iPropertiesSizeX = iPropertiesSizeX + iPropertiesX;
		iPropertiesX = 0;
	}
	if (iPropertiesX + iPropertiesSizeX > m_iPropertiesWidth) {
		iPropertiesSizeX = iPropertiesSizeX - ((iPropertiesX + iPropertiesSizeX) - m_iPropertiesWidth);
	}
	if (iPropertiesY < 0) {
		iArrayCntY = -iPropertiesY;
		iPropertiesSizeY = iPropertiesSizeY + iPropertiesY;
		iPropertiesY = 0;
	}
	if (iPropertiesY + iPropertiesSizeY > m_iPropertiesHeight) {
		iPropertiesSizeY = iPropertiesSizeY - ((iPropertiesY + iPropertiesSizeY) - m_iPropertiesHeight);
	}


	// 속성 변경
	iCntY = 0;
	while (iCntY < iPropertiesSizeY) {

		iCntX = 0;
		while (iCntX < iPropertiesSizeX) {
			// 변경할 속성 1차원 인덱스 값
			iArrayPropertiesIndex = (iArrayCntX + iCntX) + ((iArrayCntY + iCntY) * g_iMakePropertiesSizeX);

			// 공백 무시 1번은 빈 공간 속성임
			if (g_bypArrayMAkeTileProperties[iArrayPropertiesIndex] == 1) {
				++iCntX;
				continue;
			}

			// 변경할 맵 속성 1차원 인덱스 값
			iMapPropertiesIndex = (iPropertiesX + iCntX) + ((iPropertiesY + iCntY) * m_iPropertiesWidth);

			// 속성 변경
			m_bypMapProperties[iMapPropertiesIndex] = g_bypArrayMAkeTileProperties[iArrayPropertiesIndex];
			++iCntX;
		}
		++iCntY;
	}
}

// 생성할 수 있는 속성인지 검사
// iPropertiesX : 검사할 속성 시작 좌표 X
// iPropertiesY : 검사할 속성 시작 좌표 Y
// 반환 값 : 생성 가능 true, 불가 false
bool ObjectStageMap::CheckProperties(int iPropertiesX, int iPropertiesY)
{
	int iCntX;					// 카운트 X
	int iCntY;					// 카운트 Y
	int iPropertiesSizeX;		// 속성 가로 길이
	int iPropertiesSizeY;		// 속성 세로 길이
	int iArrayPropertiesIndex;	// 생성 속성 배열 인덱스
	int iMapPropertiesIndex;	// 맵 속성 배열 인덱스
	BYTE byCheckMakeProperties;	// 검사할 생성 속성 값
	BYTE byCheckMapProperties;	// 검사할 맵 속성 값

	//--------------------------------------
	// 타일 범위
	// 중점 좌표를 뺀 값이 시작 위치 좌표
	//--------------------------------------
	iPropertiesX = iPropertiesX - g_iPropertiesCenterPointX;
	iPropertiesY = iPropertiesY - g_iPropertiesCenterPointY;
	

	iPropertiesSizeX = g_iMakePropertiesSizeX;			// 속성 가로 길이
	iPropertiesSizeY = g_iMakePropertiesSizeY;			// 속성 세로 길이
	byCheckMakeProperties = g_byCheckMakeProperties;	// 검사할 생성 속성 값
	byCheckMapProperties = g_byCheckMapProperties;		// 검사할 맵 속성 값

	// 검사
	iCntY = 0;
	while (iCntY < iPropertiesSizeY) {
		// 맵을 벗어남
		if (iPropertiesY + iCntY < 0) {
			++iCntY;
			continue;
		}
		// 맵을 벗어남
		if (iPropertiesY + iCntY >= m_iPropertiesHeight) {
			break;
		}

		iCntX = 0;
		while (iCntX < iPropertiesSizeX) {
			// 생성할 속성 1차원 배열 인덱스 값
			iArrayPropertiesIndex = iCntX + (iCntY * iPropertiesSizeX);

			// 무시
			if (g_bypArrayMAkeTileProperties[iArrayPropertiesIndex] != byCheckMakeProperties) {
				++iCntX;
				continue;
			}
			// 맵을 벗어남
			if (iPropertiesX + iCntX < 0) {
				++iCntX;
				continue;
			}
			// 맵을 벗어남
			if (iPropertiesX + iCntX >= m_iPropertiesWidth) {
				break;
			}

			// 검사할 맵 속성 1차원 배열 인덱스 값
			iMapPropertiesIndex = (iPropertiesX + iCntX) + ((iPropertiesY + iCntY) * m_iPropertiesWidth);

			// 맵 속성 값과 같지 않으면 생성할 수 없음
			if (m_bypMapProperties[iMapPropertiesIndex] != byCheckMapProperties) {
				return false;
			}

			++iCntX;
		}
		++iCntY;
	}

	return true;
}
