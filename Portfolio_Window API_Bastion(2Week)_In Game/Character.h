#pragma once
#include "Actor.h"
class Character :
	public Actor
{
protected:
	CHARACTER_TYPE m_characterType;
protected:
	int m_level;			// ����
	int m_maxEXP;			// �ִ����ġ
	int m_curEXP;			// �������ġ
protected:
	float m_attack;			// ���ݷ�
public:
	virtual HRESULT init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
public:
	virtual void StateProcess() = 0;		// �ִϸ��̼� �� ���� ���� ó��
	virtual void ActionProcess() = 0;		// �ִϸ��̼� �� ���� ���¿� ���� ���� ó��
	virtual void ImageInit();
public:
	CHARACTER_TYPE getCharacterType() { return m_characterType; }
	void setCharacterType(CHARACTER_TYPE _characterType) { m_characterType = _characterType; }

	int getLevel() { return m_level; }
	void setLevel(int _level) { m_level = _level; }

	int getMaxEXP() { return m_maxEXP; }
	void setMaxEXP(int _maxEXP) { m_maxEXP = _maxEXP; }

	int getCurEXP() { return m_curEXP; }
	void setCurEXP(int _curEXP) { m_curEXP = _curEXP; }

	float getAttack() { return m_attack; }
	void setAttack(float _attack) { m_attack = _attack; }
public:
	Character();
	virtual ~Character();
};

