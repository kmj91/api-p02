#include "stdafx.h"
#include "Obstacle_Unbroken.h"

HRESULT Obstacle_Unbroken::init()
{
	m_objectType = OBJECT_TYPE::OBJECT_OBSTACLE;
	m_layerType = LAYER_TYPE::LAYER_ACTOR;

	m_isActive = true;
	m_isDestroyed = false;
	m_image = IMAGEMANAGER->findImage_Obstacle(static_cast<int>(m_obstacleType));


	return S_OK;
}

void Obstacle_Unbroken::release()
{
}

void Obstacle_Unbroken::update()
{
}

void Obstacle_Unbroken::render()
{
	m_imageWidth = m_image->getWidth();
	m_imageHeight = m_image->getHeight();
	m_imageRect = RectMakeCenter(m_position.x, m_position.y, m_imageWidth, m_imageHeight);

	RENDER_INFO renderInfo;
	renderInfo = { (int)m_position.y, m_position, m_imageRect, m_imageWidth, m_imageHeight, m_image };
	CAMERAMANAGER->AddRenderInfo(m_layerType,  renderInfo);
}

Obstacle_Unbroken::Obstacle_Unbroken()
{
}


Obstacle_Unbroken::~Obstacle_Unbroken()
{
}
