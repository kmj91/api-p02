#include "stdafx.h"
#include "Scene_Title.h"


HRESULT Scene_Title::init()
{
	m_sceneType = SCENE_TYPE::SCENE_TITLE;
	UIMANAGER->init(m_sceneType);
	CAMERAMANAGER->init();
	return S_OK;
}

void Scene_Title::release()
{

}

void Scene_Title::update()
{
	UIMANAGER->update();
}

void Scene_Title::render()
{
	UIMANAGER->render();
	CAMERAMANAGER->render();
}

Scene_Title::Scene_Title()
{
}


Scene_Title::~Scene_Title()
{
}
