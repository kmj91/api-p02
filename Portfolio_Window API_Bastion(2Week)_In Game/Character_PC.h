#pragma once
#include "Character.h"

class Character_PC :
	public Character
{
private:
	POINTFLOAT m_prevPosition;	// �����ϱ� �� ��ǥ
private:
	float m_dropSpeed;		// ���ϼӵ�
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	virtual void StateProcess();		// �ִϸ��̼� �� ���� ���� ó��
	virtual void ActionProcess();		// �ִϸ��̼� �� ���� ���¿� ���� ���� ó��
public:
	Character_PC();
	virtual ~Character_PC();
};

