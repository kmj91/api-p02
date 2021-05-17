#pragma once
#include "Projectile.h"
class Projectile_Straight :
	public Projectile
{
public:
	virtual HRESULT init();
	virtual HRESULT init(PROJECTILE_TYPE _projectileType);
	virtual void release();
	virtual void update();
	virtual void render();
public:
	virtual void StateProcess();
	virtual void ActionProcess();
public:
	Projectile_Straight();
	virtual ~Projectile_Straight();
};

