#pragma once
#include "Actor.h"

class Enemy :
	public Actor
{
protected:
	ENEMY_TYPE m_enemyType;		// �� Ÿ��
protected:
	POINTFLOAT m_targetPosition;			// Ÿ�� ��ǥ
	POINTFLOAT m_destinationPosition;		// ������ ��ǥ
protected:
	list<POINTFLOAT> m_moveList;
protected:
	int m_obtainEXP;				// óġ�� ȹ�����ġ
	int m_maxAttackCount;			// �ִ����Ƚ��
	int m_curAttackCount;			// �������Ƚ��
protected:
	bool m_isSetAttackCount;		// ����Ƚ�������Ͽ��°�
protected:
	float m_attack;					// ���ݷ�
	float m_approchRange;			// ���ٹ���
	float m_attackRange;			// ���ݹ���
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

