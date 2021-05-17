#pragma once
#include "Actor.h"

class Particle :
	public Actor
{
private:
	PARTICLE_TYPE m_particleType;
private:
	float m_angleSpeed;
public:
	virtual HRESULT init();
	virtual HRESULT init(PARTICLE_TYPE _particleType);
	virtual void release();
	virtual void update();
	virtual void render();
public:
	virtual void ImageInit();
public:
	Particle();
	virtual ~Particle();
};

