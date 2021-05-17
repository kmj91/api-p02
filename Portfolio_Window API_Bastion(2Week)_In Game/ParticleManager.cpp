#include "stdafx.h"
#include "ParticleManager.h"
#include "Particle.h"

HRESULT ParticleManager::init()
{
	m_particleList.clear();

	Particle* particle;

	for (int i = 0; i < 10; ++i)
	{
		particle = new Particle;
		particle->init(PARTICLE_TYPE::PARTICLE_LEAF1);
		AddParticle(particle);
	}
	for (int i = 0; i < 10; ++i)
	{
		particle = new Particle;
		particle->init(PARTICLE_TYPE::PARTICLE_LEAF2);
		AddParticle(particle);
	}
	return S_OK;
}

void ParticleManager::release()
{
	for (auto iter = m_particleList.begin(); iter != m_particleList.end(); )
	{
		(*iter)->release();
		SAFE_DELETE((*iter));
		iter = m_particleList.erase(iter);
	}
}

void ParticleManager::update()
{
	for (int i = 0; i < m_particleList.size(); ++i)
	{
		if (!m_particleList[i]->getIsActive()) continue;
		m_particleList[i]->update();
	}
}

void ParticleManager::render()
{
	for (int i = 0; i < m_particleList.size(); ++i)
	{
		if (!m_particleList[i]->getIsActive()) continue;
		m_particleList[i]->render();
	}
}

ParticleManager::ParticleManager()
{
}


ParticleManager::~ParticleManager()
{
}
