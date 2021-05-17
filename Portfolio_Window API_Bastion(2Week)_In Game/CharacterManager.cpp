#include "stdafx.h"
#include "CharacterManager.h"
#include "Character_PC.h"


HRESULT CharacterManager::init()
{
	m_characterList.clear();
	
	return S_OK;
}

void CharacterManager::release()
{
	for (auto iter = m_characterList.begin(); iter != m_characterList.end();)
	{
		(*iter)->release();
		SAFE_DELETE((*iter));
		iter = m_characterList.erase(iter);
	}
}

void CharacterManager::update()
{
	for (int i = 0; i < m_characterList.size(); ++i)
	{
		if (!m_characterList[i]->getIsActive()) continue;
			m_characterList[i]->update();
	}
}

void CharacterManager::render()
{
	for (int i = 0; i < m_characterList.size(); ++i)
	{
		if (!m_characterList[i]->getIsActive()) continue;
			m_characterList[i]->render();
	}
}



Character * CharacterManager::FindCharacter(CHARACTER_TYPE _characterType)
{
	for (int i = 0; i < m_characterList.size(); ++i)
	{
		if (m_characterList[i]->getCharacterType() == _characterType)
			return m_characterList[i];
	}
	return nullptr;
}

CharacterManager::CharacterManager()
{
}


CharacterManager::~CharacterManager()
{
}
