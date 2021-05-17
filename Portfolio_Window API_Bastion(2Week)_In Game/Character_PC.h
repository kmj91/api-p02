#pragma once
#include "Character.h"

class Character_PC :
	public Character
{
private:
	POINTFLOAT m_prevPosition;	// 낙하하기 전 좌표
private:
	float m_dropSpeed;		// 낙하속도
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	virtual void StateProcess();		// 애니메이션 및 방향 상태 처리
	virtual void ActionProcess();		// 애니메이션 및 방향 상태에 따라 동작 처리
public:
	Character_PC();
	virtual ~Character_PC();
};

