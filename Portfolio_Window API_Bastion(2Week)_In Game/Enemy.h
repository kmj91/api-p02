#pragma once
#include "Actor.h"

class Enemy :
	public Actor
{
protected:
	ENEMY_TYPE m_enemyType;		// 적 타입
protected:
	POINTFLOAT m_targetPosition;			// 타겟 좌표
	POINTFLOAT m_destinationPosition;		// 목적지 좌표
protected:
	list<POINTFLOAT> m_moveList;
protected:
	int m_obtainEXP;				// 처치시 획득경험치
	int m_maxAttackCount;			// 최대공격횟수
	int m_curAttackCount;			// 현재공격횟수
protected:
	bool m_isSetAttackCount;		// 공격횟수세팅하였는가
protected:
	float m_attack;					// 공격력
	float m_approchRange;			// 접근범위
	float m_attackRange;			// 공격범위
public:
	virtual HRESULT init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
public:
	virtual void StateProcess() = 0;		// 애니메이션 및 방향 상태 처리
	virtual void ActionProcess() = 0;		// 애니메이션 및 방향 상태에 따라 동작 처리
	virtual void ImageInit();
public:
	ENEMY_TYPE getEnemyType() { return m_enemyType; }
	void setEnemyType(ENEMY_TYPE _enemyType) { m_enemyType = _enemyType; }

	POINTFLOAT getDestinationPosition() { return m_destinationPosition; }

	int getObtainEXP() { return m_obtainEXP; }
	void setObtainEXP(int _obtainEXP) { m_obtainEXP = _obtainEXP; }

	bool getIsAniFinish() { return m_isAniFinish; }
	void setIsAniFinish(bool _isAniFinish) { m_isAniFinish = _isAniFinish; }

	float getAttack() { return m_attack; }
	void setAttack(float _attack) { m_attack = _attack; }
public:
	Enemy();
	virtual ~Enemy();
};

