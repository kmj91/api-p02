#include "stdafx.h"
#include "UIManager.h"
#include "UI.h"
#include "UI_Title.h"
#include "UI_MainMenu.h"
#include "UI_Background.h"
#include "UI_Pause.h"
#include "UI_Mouse.h"


HRESULT UIManager::init(SCENE_TYPE _sceneType)
{
	m_UIList.clear();

	UI* ui;
	switch (_sceneType)
	{
	case SCENE_TYPE::SCENE_TITLE:
		ui = new UI_Title;
		ui->init();
		AddUI(ui);
		break;
	case SCENE_TYPE::SCENE_MAINMENU:
		ui = new UI_MainMenu;
		ui->init();
		AddUI(ui);
		break;
	case SCENE_TYPE::SCENE_MAINGAME:
		ui = new UI_Background;
		ui->init();
		AddUI(ui);

		ui = new UI_Pause;
		ui->init();
		AddUI(ui);
		break;
	}

	ui = new UI_Mouse;
	ui->init();
	AddUI(ui);

	return S_OK;
}

void UIManager::release()
{
	vector<UI*>::iterator iter = m_UIList.begin();
	for (iter; iter != m_UIList.end(); )
	{
		(*iter)->release();
		SAFE_DELETE((*iter));
		iter = m_UIList.erase(iter);
	}
}

void UIManager::update()
{
	for (int i = 0; i < m_UIList.size(); ++i)
	{
		if (!m_UIList[i]->getIsActive()) continue;
		m_UIList[i]->update();
	}
}

void UIManager::render()
{
	for (int i = 0; i < m_UIList.size(); ++i)
	{
		if (!m_UIList[i]->getIsActive()) continue;
		m_UIList[i]->render();
	}
}


UI * UIManager::FindUI(UI_TYPE _uiType)
{
	for (int i = 0; i < m_UIList.size(); ++i)
	{
		if (m_UIList[i]->getUIType() == _uiType)
			return m_UIList[i];
	}
	return nullptr;
}

bool UIManager::CheckOpenUI()
{
	for (int i = 0; i < m_UIList.size(); ++i)
	{
		if (m_UIList[i]->getIsOpen())
			return true;
	}
	return false;
}

UIManager::UIManager()
{
}


UIManager::~UIManager()
{
}
