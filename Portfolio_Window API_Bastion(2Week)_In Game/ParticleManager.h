#pragma once
#include "singletonBase.h"

enum PARTICLE_TYPE;
class Particle;
class ParticleManager :
	public singletonBase<ParticleManager>
{
private:
	typedef vector<Particle*> PARTICLE_LIST;
	PARTICLE_LIST m_particleList;
public:
	HRESULT init();
	void release();
	void update();
	void render();
public:
	void AddParticle(Particle* _particle) { m_particleList.push_back(_particle); }
public:
	ParticleManager();
	virtual ~ParticleManager();
};

