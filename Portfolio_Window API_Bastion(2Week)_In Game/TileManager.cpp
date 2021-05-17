#include "stdafx.h"
#include "TileManager.h"
#include "Tile.h"

HRESULT TileManager::init()
{
	
	return S_OK;
}

void TileManager::release()
{
	for (auto iter = m_tileList.begin(); iter != m_tileList.end();)
	{
		(*iter)->release();
		SAFE_DELETE((*iter));
		m_tileList.erase(iter);
	}
}

void TileManager::update()
{
	for (int i = 0; i < m_tileList.size(); ++i)
	{
		if (!m_tileList[i]->getIsActive()) continue;
		m_tileList[i]->update();
	}
}

void TileManager::render()
{
	for (int i = 0; i < m_tileList.size(); ++i)
	{
		if (!m_tileList[i]->getIsActive()) continue;
		m_tileList[i]->render();
	}
}



TileManager::TileManager()
{
}


TileManager::~TileManager()
{
}
