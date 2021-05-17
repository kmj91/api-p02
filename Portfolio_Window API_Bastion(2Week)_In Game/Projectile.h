#pragma once
#include "Actor.h"

class Projectile :
	public Actor
{
protected:
	PROJECTILE_TYPE m_projectileType;	// 투사체 타입
protected:
	OBJECT_TYPE m_userObjectType;		// 사용자 타입
protected:
	float m_attack;						// 공격력
protected:
	float m_actionRange;				// 활동범위(날아갈 수 있는 범위)
public:
	virtual HRESULT init() = 0;
	virtual HRESULT init(PROJECTILE_TYPE _projectileType) = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
public:
	virtual void StateProcess() = 0;
	virtual void ActionProcess() = 0;
	virtual void ImageInit();
public:
	PROJECTILE_TYPE getProjectileType() { return m_projectileType; }

	OBJECT_TYPE getUserObjectType() { return m_userObjectType; }
	void setUserObjectType(OBJECT_TYPE _targetObjectType) { m_userObjectType = _targetObjectType; }

	float getAttack() { return m_attack; }
	void setAttack(float _attack) { m_attack = _attack; }

	float getActionRange() { return m_actionRange; }
	void setActionRange(float _actionRange) { m_actionRange = _actionRange; }
public:
	Projectile();
	virtual ~Projectile();
};

