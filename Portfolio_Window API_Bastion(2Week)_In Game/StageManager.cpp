#include "stdafx.h"
#include "StageManager.h"
#include "Stage.h"

HRESULT StageManager::init()
{
	return S_OK;
}

void StageManager::release()
{
}

void StageManager::update()
{
	for (int i = 0; i < m_stageList.size(); ++i)
	{
		if (!m_stageList[i]->getIsActive()) continue;
		m_stageList[i]->update();
	}
}

void StageManager::render()
{
	for (int i = 0; i < m_stageList.size(); ++i)
	{
		if (!m_stageList[i]->getIsActive()) continue;
		m_stageList[i]->render();
	}
}

StageManager::StageManager()
{
}


StageManager::~StageManager()
{
}
