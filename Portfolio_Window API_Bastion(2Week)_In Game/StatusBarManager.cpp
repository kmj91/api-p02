#include "stdafx.h"
#include "StatusBarManager.h"
#include"UI_StatusBar.h"

HRESULT StatusBarManager::init()
{
	m_statusBarVector.clear();

	return S_OK;
}

void StatusBarManager::release()
{
	vector<UI_StatusBar*>::iterator iter = m_statusBarVector.begin();
	for (iter; iter != m_statusBarVector.end();)
	{
		if ((*iter) == nullptr) continue;
		(*iter)->release();
		SAFE_RELEASE((*iter));
		iter = m_statusBarVector.erase(iter);
	}
}

void StatusBarManager::update()
{
	for (int i = 0; i < m_statusBarVector.size(); ++i)
	{
		m_statusBarVector[i]->update();
	}
}

void StatusBarManager::render()
{
	for (int i = 0; i < m_statusBarVector.size(); ++i)
	{
		if (!m_statusBarVector[i]->getIsActive()) continue;
		m_statusBarVector[i]->render();
	}
}

void StatusBarManager::CreateStateBar(STATUSBAR_TYPE _stateBarType, Object * _object)
{
	UI_StatusBar* statusBar = new UI_StatusBar;
	statusBar->init(_stateBarType, _object);
	AddStatusBar(statusBar);
}

StatusBarManager::StatusBarManager()
{
}


StatusBarManager::~StatusBarManager()
{
}
