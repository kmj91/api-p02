#include "stdafx.h"
#include "ObstacleManager.h"
#include "Obstacle.h"
#include "Character_PC.h"


HRESULT ObstacleManager::init()
{

	return S_OK;
}

void ObstacleManager::release()
{

}

void ObstacleManager::update()
{
	for (int i = 0; i < m_obstacleList.size(); ++i)
	{
		if (!m_obstacleList[i]->getIsActive()) continue;
		m_obstacleList[i]->update();
	}
}

void ObstacleManager::render()
{
	for (int i = 0; i < m_obstacleList.size(); ++i)
	{
		if (!m_obstacleList[i]->getIsActive()) continue;
		m_obstacleList[i]->render();
	}
}


ObstacleManager::ObstacleManager()
{
}


ObstacleManager::~ObstacleManager()
{
}
