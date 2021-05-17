#pragma once
#include "Enemy.h"

class Enemy_Extra :
	public Enemy
{
private:
	float m_elapsedMoveTime;		// �̵����·� ��ȯ�Ǳ���� ����� �ð�
	float m_moveTime;				// �̵����·� ��ȯ�Ǵ� �ð��ֱ�
	float m_elapsedAttackTime;		// ���ݻ��·� ��ȯ�Ǳ���� ����� �ð�
	float m_attackTime;				// ���ݻ��·� ��ȯ�Ǵ� �ð��ֱ�
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	virtual void StateProcess();		// �ִϸ��̼� �� ���� ���� ó��
	virtual void ActionProcess();		// �ִϸ��̼� �� ���� ���¿� ���� ���� ó��
public:
	Enemy_Extra();
	virtual ~Enemy_Extra();
};

