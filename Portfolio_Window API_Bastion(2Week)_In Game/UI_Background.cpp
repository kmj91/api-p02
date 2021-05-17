#include "stdafx.h"
#include "UI_Background.h"


HRESULT UI_Background::init()
{
	m_objectType = OBJECT_TYPE::OBJECT_UI;
	m_layerType = LAYER_UI;
	m_uiType = UI_TYPE::UI_BACKGROUND;

	m_position = { WINSIZEX / 2, WINSIZEY / 2 };
	m_imageWidth = IMAGEMANAGER->findImage("UI_Background")->getWidth();
	m_imageHeight = IMAGEMANAGER->findImage("UI_Background")->getHeight();
	m_imageRect = RectMakeCenter(m_position.x, m_position.y, m_imageWidth, m_imageHeight);

	m_isActive = true;
	m_isOpen = false;

	return S_OK;
}

void UI_Background::release()
{

}

void UI_Background::update()
{

}

void UI_Background::render()
{
	RENDER_INFO renderInfo;
	renderInfo = { (int)m_uiType, m_position, m_imageRect, m_imageWidth, m_imageHeight, IMAGEMANAGER->findImage("UI_Background") };
	CAMERAMANAGER->AddRenderInfo(m_layerType, renderInfo);
}


UI_Background::UI_Background()
{
}


UI_Background::~UI_Background()
{
}
