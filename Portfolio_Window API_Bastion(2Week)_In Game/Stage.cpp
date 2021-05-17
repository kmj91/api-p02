#include "stdafx.h"
#include "Stage.h"


HRESULT Stage::init()
{
	m_objectType = OBJECT_TYPE::OBJECT_STAGE;
	m_layerType = LAYER_TYPE::LAYER_BACKGROUND;

	m_isActive = true;

	m_colliderWidth = IMAGEMANAGER->findImage_Stage(static_cast<int>(m_stageType))->getWidth();
	m_colliderHeight = IMAGEMANAGER->findImage_Stage(static_cast<int>(m_stageType))->getHeight();
	m_colliderRect = RectMakeCenter(m_position.x, m_position.y, m_colliderWidth, m_colliderHeight);

	return S_OK;
}

void Stage::release()
{
}

void Stage::update()
{
	m_colliderRect = RectMakeCenter(m_position.x, m_position.y, m_colliderWidth, m_colliderHeight);
}

void Stage::render()
{
	m_imageWidth = IMAGEMANAGER->findImage_Stage(static_cast<int>(m_stageType))->getWidth();
	m_imageHeight = IMAGEMANAGER->findImage_Stage(static_cast<int>(m_stageType))->getHeight();
	m_imageRect = RectMakeCenter(m_position.x, m_position.y, m_imageWidth, m_imageHeight);

	RENDER_INFO renderInfo;
	renderInfo = { (int)m_position.y, m_position, m_imageRect, m_imageWidth, m_imageHeight, IMAGEMANAGER->findImage_Stage(static_cast<int>(m_stageType)) };
	CAMERAMANAGER->AddRenderInfo(m_layerType,  renderInfo);
}

Stage::Stage()
{
}


Stage::~Stage()
{
}
