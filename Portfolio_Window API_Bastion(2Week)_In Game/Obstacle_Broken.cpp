#include "stdafx.h"
#include "Obstacle_Broken.h"
#include "Character_PC.h"
//브로큰
BYTE g_byArrayMakePropertiesBroken_27[4 * 2] = 
{
	1,1,
	1,1,
	1,3,
	1,1
};

BYTE g_byArrayMakePropertiesBroken_28[7 * 5] =
{
	1,1,1,1,1,
	1,1,1,1,1,
	1,1,1,1,1,
	1,1,1,1,1,
	1,1,1,1,1,
	1,3,3,3,1,
	1,3,3,3,1
};

BYTE g_byArrayMakePropertiesBroken_29[6 * 7] = {
	1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,
	1,3,3,3,3,3,1,
	1,3,3,3,3,3,1,
	1,1,1,3,1,1,1
};

BYTE g_byArrayMakePropertiesBroken_30[6 * 8] = {
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,3,3,3,3,3,3,1,
	1,3,3,3,3,3,1,1,
	1,3,3,3,3,3,1,1,
	1,1,1,1,1,1,1,1
};

BYTE g_byArrayMakePropertiesBroken_31[6 * 7] = {
	1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,
	1,1,1,3,3,3,1,
	1,1,3,3,3,3,1,
	3,3,3,1,1,1,1,
	3,3,1,1,1,1,1
};

BYTE g_byArrayMakePropertiesBroken_32[6 * 7] = {
	1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,
	1,3,3,3,3,3,1,
	3,3,3,3,3,3,1,
	1,1,1,3,3,1,1
};

BYTE g_byArrayMakePropertiesBroken_33[5 * 6] = {
	1,1,1,1,1,1,
	1,1,1,1,1,1,
	1,1,1,1,1,1,
	3,3,3,3,3,3,
	1,3,3,3,1,1
};

BYTE g_byArrayMakePropertiesBroken_34[5 * 7] = {
	1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,
	1,3,3,3,3,3,1,
	3,3,3,3,3,3,1,
	1,1,1,1,1,1,1
};

BYTE g_byArrayMakePropertiesBroken_35[3 * 3] = {
	1,1,1,
	3,3,3,
	1,1,1,
};

BYTE g_byArrayMakePropertiesBroken_36[4 * 5] = {
	1,1,1,1,1,
	1,1,1,1,1,
	3,3,3,3,1,
	1,3,3,3,1
};

BYTE g_byArrayMakePropertiesBroken_37[4 * 5] = {
	1,1,1,1,1,
	1,1,1,1,1,
	3,3,3,3,1,
	1,3,3,3,1
};

BYTE g_byArrayMakePropertiesBroken_38[5 * 6] = {
	1,1,1,1,1,1,
	1,1,1,1,1,1,
	1,3,3,3,3,1,
	3,3,3,1,1,1
};

BYTE g_byArrayMakePropertiesBroken_39[4 * 3] = {
	1,1,1,
	1,1,1,
	1,3,1,
	1,1,1
};

BYTE g_byArrayMakePropertiesBroken_40[6 * 7] = {
	1,1,1,1,1,1,1,
	1,1,1,1,1,3,1,
	1,1,1,3,3,3,1,
	1,3,3,3,3,1,1,
	1,3,3,1,1,1,1,
	1,1,1,1,1,1,1
};

BYTE g_byArrayMakePropertiesBroken_41[2 * 3] = {
	1,1,1,
	3,3,3,
};


HRESULT Obstacle_Broken::init()
{
	m_objectType = OBJECT_TYPE::OBJECT_OBSTACLE;
	m_layerType = LAYER_TYPE::LAYER_ACTOR;

	m_isActive = true;
	m_isDestroyed = false;

	m_position = { m_activePosition.x, m_activePosition.y - 1000.0f };
	m_image = IMAGEMANAGER->findImage_Obstacle(static_cast<int>(m_obstacleType));

	m_alpha = 0;

	m_curHP = 50;
	m_speed = 40.0f;
	m_activeRange = 400;

	return S_OK;
}

void Obstacle_Broken::release()
{
}

void Obstacle_Broken::update()
{
	if (m_isDestroyed) return;

	POINTFLOAT pcPosition = CHARACTERMANAGER->FindCharacter(CHARACTER_TYPE::CHARACTER_KID)->getPosition();
	if (getDistance(pcPosition.x, pcPosition.y, m_activePosition.x, m_activePosition.y) < m_activeRange)
	{
		m_position.y += m_speed;
		m_alpha = 255;
		if (m_position.y > m_activePosition.y)
		{
			m_position.y = m_activePosition.y;
		}	
	}

	if (m_curHP <= 0)
	{
		m_curHP = 0;
		m_isDestroyed = true;
		m_isActive = false;

		// 여기에서 속성배열값 뺴는 로직이 들어가면 됨
		BYTE* tilePropertyInfo = TILEMANAGER->getTilePropertyInfo();		// 속성배열
		int tilePropertyWidth = TILEMANAGER->getTilePropertyWidth();
		int x = m_position.x / 25;
		int y = m_position.y / 25;

		int iCntX;
		int iCntY;
		int iArrayCntX;
		int iArrayCntY;
		int iPropertiesOriginX;
		int iPropertiesX;
		int iPropertiesY;
		int iPropertiesSizeX;			// 가로 길이
		int iPropertiesSizeY;			// 세로 길이
		int iArrayPropertiesIndex;
		int iMapPropertiesIndex;
		BYTE byCheckMakeProperties;
		BYTE *bypArrayMAkeTileProperties = nullptr;		// 해당 객체 타일 속성

		//--------------------------------------
		// 타일 범위
		// 중점 좌표를 뺀 값이 시작 위치 좌표
		//--------------------------------------
		iPropertiesOriginX = ((m_imageWidth / 2) * 25);
		iPropertiesX = x - iPropertiesOriginX;
		iPropertiesY = y - ((m_imageHeight / 2) * 25);


		iPropertiesSizeX = m_imageWidth / 25;
		// 소수점이 있다면 +1
		if (iPropertiesSizeX % 25) {
			++iPropertiesSizeX;
		}
		iPropertiesSizeY = m_imageHeight / 25;
		if (iPropertiesSizeY % 25) {
			++iPropertiesSizeY;
		}
		//--------------------------------------
		// 갈수 없는 타일은 3번임
		// 따라서 검사할 타일은 3번
		// 3번을 다시 0번
		// 갈수 있는 타일로 교체한다
		//--------------------------------------
		byCheckMakeProperties = 3;


		iArrayCntX = 0;
		iArrayCntY = 0;

		// 화면밖으로 빠져나가는지?
		if (iPropertiesX < 0) {
			iArrayCntX = -iPropertiesX;
			iPropertiesSizeX = iPropertiesSizeX + iPropertiesX;
			iPropertiesX = 0;
		}
		if (iPropertiesX + iPropertiesSizeX > tilePropertyWidth) {
			iPropertiesSizeX = iPropertiesSizeX - ((iPropertiesX + iPropertiesSizeX) - tilePropertyWidth);
		}
		if (iPropertiesY < 0) {
			iArrayCntY = -iPropertiesY;
			iPropertiesSizeY = iPropertiesSizeY + iPropertiesY;
			iPropertiesY = 0;
		}
		if (iPropertiesY + iPropertiesSizeY > tilePropertyWidth) {
			iPropertiesSizeY = iPropertiesSizeY - ((iPropertiesY + iPropertiesSizeY) - tilePropertyWidth);
		}


		// 무슨 객체인지?
		// 해당 객체 속성 배열을 가져온다
		switch (m_objectType) {
		case OBSTACLE_BROKEN_27:
			bypArrayMAkeTileProperties = g_byArrayMakePropertiesBroken_27;
			break;
		case OBSTACLE_BROKEN_28:
			bypArrayMAkeTileProperties = g_byArrayMakePropertiesBroken_28;
			break;
		case OBSTACLE_BROKEN_29:
			bypArrayMAkeTileProperties = g_byArrayMakePropertiesBroken_29;
			break;
		case OBSTACLE_BROKEN_30:
			bypArrayMAkeTileProperties = g_byArrayMakePropertiesBroken_30;
			break;
		case OBSTACLE_BROKEN_31:
			bypArrayMAkeTileProperties = g_byArrayMakePropertiesBroken_31;
			break;
		case OBSTACLE_BROKEN_32:
			bypArrayMAkeTileProperties = g_byArrayMakePropertiesBroken_32;
			break;
		case OBSTACLE_BROKEN_33:
			bypArrayMAkeTileProperties = g_byArrayMakePropertiesBroken_33;
			break;
		case OBSTACLE_BROKEN_34:
			bypArrayMAkeTileProperties = g_byArrayMakePropertiesBroken_34;
			break;
		case OBSTACLE_BROKEN_35:
			bypArrayMAkeTileProperties = g_byArrayMakePropertiesBroken_35;
			break;
		case OBSTACLE_BROKEN_36:
			bypArrayMAkeTileProperties = g_byArrayMakePropertiesBroken_36;
			break;
		case OBSTACLE_BROKEN_37:
			bypArrayMAkeTileProperties = g_byArrayMakePropertiesBroken_37;
			break;
		case OBSTACLE_BROKEN_38:
			bypArrayMAkeTileProperties = g_byArrayMakePropertiesBroken_38;
			break;
		case OBSTACLE_BROKEN_39:
			bypArrayMAkeTileProperties = g_byArrayMakePropertiesBroken_39;
			break;
		case OBSTACLE_BROKEN_40:
			bypArrayMAkeTileProperties = g_byArrayMakePropertiesBroken_40;
			break;
		case OBSTACLE_BROKEN_41:
			bypArrayMAkeTileProperties = g_byArrayMakePropertiesBroken_41;
			break;
		}


		iCntY = 0;
		while (iCntY < iPropertiesSizeY) {

			iCntX = 0;
			while (iCntX < iPropertiesSizeX) {

				// 객체의 속성 인덱스 번호
				iArrayPropertiesIndex = (iArrayCntX + iCntX) + ((iArrayCntY + iCntY) * iPropertiesOriginX);

				// 갈수없는 타일 3번 외에 속성은 검사할 필요가 없음
				if (bypArrayMAkeTileProperties[iArrayPropertiesIndex] != byCheckMakeProperties) {
					++iCntX;
					continue;
				}

				// 전체 스테이지의 속성 번호
				iMapPropertiesIndex = (iPropertiesX + iCntX) + ((iPropertiesY + iCntY) * tilePropertyWidth);

				// 갈수 없는 타일 3번을
				// 갈수 있는 타일인 0번으로 교체
				tilePropertyInfo[iMapPropertiesIndex] = 0;
				++iCntX;
			}
			++iCntY;
		}
	}
}

void Obstacle_Broken::render()
{
	m_imageWidth = m_image->getWidth();
	m_imageHeight = m_image->getHeight();
	m_imageRect = RectMakeCenter(m_position.x, m_position.y, m_imageWidth, m_imageHeight);

	RENDER_INFO renderInfo;
	renderInfo = { (int)m_position.y, m_position, m_imageRect, m_imageWidth, m_imageHeight, m_image, 0, 0, m_alpha };
	CAMERAMANAGER->AddRenderInfo(m_layerType,  renderInfo);
}

Obstacle_Broken::Obstacle_Broken()
{
}


Obstacle_Broken::~Obstacle_Broken()
{
}
