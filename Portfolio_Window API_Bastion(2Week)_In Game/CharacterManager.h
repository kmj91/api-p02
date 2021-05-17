#pragma once
#include "singletonBase.h"

enum CHARACTER_TYPE;
class Character;
class CharacterManager :
	public singletonBase<CharacterManager>
{
private:
	typedef vector<Character*> CHARACTER_LIST;
	CHARACTER_LIST m_characterList;
public:
	HRESULT init();
	void release();
	void update();
	void render();
public:
	void AddCharacter(Character* _character) { m_characterList.push_back(_character); }
	Character* FindCharacter(CHARACTER_TYPE _characterType);
public:
	CharacterManager();
	virtual ~CharacterManager();
};

