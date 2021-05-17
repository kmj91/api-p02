#include "stdafx.h"
#include "EnemyManager.h"
#include "Enemy.h"
#include "Enemy_Extra.h"

HRESULT EnemyManager::init(int _stage)
{
	m_enemyList.clear();

	m_activeEnemyCount = 0;
	m_enemyIndex = 0;
	return S_OK;
}

void EnemyManager::release()
{
	vector<Enemy*>::iterator iter = m_enemyList.begin();
	for (iter; iter != m_enemyList.end();)
	{
		(*iter)->release();
		SAFE_DELETE((*iter));
		iter = m_enemyList.erase(iter);
	}
}

void EnemyManager::update()
{
	for (int i = 0; i < m_enemyList.size(); i++)
	{
		if (!m_enemyList[i]->getIsActive()) continue;
		m_enemyList[i]->update();
	}
}

void EnemyManager::render()
{
	for (int i = 0; i < m_enemyList.size(); i++)
	{
		if (!m_enemyList[i]->getIsActive()) continue;
		m_enemyList[i]->render();
	}
}


bool EnemyManager::CheckEnemyDie()
{
	int i;
	for (i = 0; i < m_enemyList.size(); ++i)
	{
		if (m_enemyList[i]->getIsActive()) break;
	}

	if (i == m_enemyList.size() && m_enemyIndex == m_enemyList.size()) return true;

	return false;
}

int EnemyManager::GetActiveEnemyCount()
{
	m_activeEnemyCount = 0;

	for (int i = 0; i < m_enemyList.size(); i++)
	{
		if (m_enemyList[i]->getIsActive()) m_activeEnemyCount++;
	}
	return m_activeEnemyCount;
}

EnemyManager::EnemyManager()
{
}


EnemyManager::~EnemyManager()
{
}
