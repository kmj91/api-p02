#include "stdafx.h"
#include "Scene_MainMenu.h"


HRESULT Scene_MainMenu::init()
{
	m_sceneType = SCENE_TYPE::SCENE_MAINMENU;
	UIMANAGER->init(m_sceneType);
	CAMERAMANAGER->init();

	if (!SOUNDMANAGER->isPlaySound("BGM_Bastion"))
	{
		SOUNDMANAGER->play("BGM_Bastion");
	}
	return S_OK;
}

void Scene_MainMenu::release()
{

}

void Scene_MainMenu::update()
{
	UIMANAGER->update();
}

void Scene_MainMenu::render()
{
	UIMANAGER->render();
	CAMERAMANAGER->render();
}

Scene_MainMenu::Scene_MainMenu()
{
}


Scene_MainMenu::~Scene_MainMenu()
{
}
