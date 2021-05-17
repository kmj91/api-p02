#pragma once
#include "Enemy.h"

class Enemy_Extra :
	public Enemy
{
private:
	float m_elapsedMoveTime;		// 이동상태로 전환되기까지 경과된 시간
	float m_moveTime;				// 이동상태로 전환되는 시간주기
	float m_elapsedAttackTime;		// 공격상태로 전환되기까지 경과된 시간
	float m_attackTime;				// 공격상태로 전환되는 시간주기
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	virtual void StateProcess();		// 애니메이션 및 방향 상태 처리
	virtual void ActionProcess();		// 애니메이션 및 방향 상태에 따라 동작 처리
public:
	Enemy_Extra();
	virtual ~Enemy_Extra();
};

