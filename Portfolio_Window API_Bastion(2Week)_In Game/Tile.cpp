#include "stdafx.h"
#include "Tile.h"
#include "Character_PC.h"

HRESULT Tile::init()
{
	m_objectType = OBJECT_TYPE::OBJECT_TILE;
	m_layerType = LAYER_TYPE::LAYER_BACKGROUND;

	m_isActive = true;
	m_isAniFinish = false;

	m_image = IMAGEMANAGER->findImage_Tile(static_cast<int>(m_tileType));

	m_position = { m_activePosition.x, m_activePosition.y + 1000};

	m_speed = 40.0f;
	m_activeRange = 550;

	m_startAni = false;

	m_frameDelayTime = 5;
	return S_OK;
}

void Tile::release()
{
	
}

void Tile::update()
{
	Character_PC* pc = (Character_PC*)CHARACTERMANAGER->FindCharacter(CHARACTER_TYPE::CHARACTER_KID);
	ANIMATION_STATE pcAnimationState = pc->getAnimationState();
	POINTFLOAT pcPosition = pc->getPosition();

	if (pcAnimationState == FALL || pcAnimationState == STAND_UP) return;
	if (getDistance(pcPosition.x, pcPosition.y, m_activePosition.x, m_activePosition.y) < m_activeRange)
	{
		m_startAni = true;
		m_position.y -= m_speed;
		if (m_position.y < m_activePosition.y)
		{
			m_position.y = m_activePosition.y;
		}
	}
	

	// 충돌체 사각형 갱신
	m_colliderRect = RectMakeCenter(m_position.x, m_position.y, m_colliderWidth, m_colliderHeight);
}

void Tile::render()
{
	if(m_startAni && !m_isAniFinish) ImageFrameUpdate();

	//// 이미지 사각형 갱신
	m_imageWidth = m_image->getFrameWidth();
	m_imageHeight = m_image->getFrameHeight();
	m_imageRect = RectMakeCenter(m_position.x, m_position.y, m_imageWidth, m_imageHeight);

	RENDER_INFO renderInfo;
	renderInfo = { (int)m_activePosition.y, m_position, m_imageRect, m_imageWidth, m_imageHeight, m_image, m_frameX, m_frameY };
	CAMERAMANAGER->AddRenderInfo(m_layerType, renderInfo);
}

Tile::Tile()
{
}


Tile::~Tile()
{
}
