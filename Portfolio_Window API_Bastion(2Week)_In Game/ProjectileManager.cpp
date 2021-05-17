#include "stdafx.h"
#include "ProjectileManager.h"
#include "Projectile.h"
#include "Projectile_Straight.h"

HRESULT ProjectileManager::init()
{
	m_projectileList.clear();

	Projectile* projectile;

	for (int i = 0; i < 20; ++i)
	{
		projectile = new Projectile_Straight;
		projectile->init(PROJECTILE_TYPE::PROJECTILE_ARROW);
		AddProjectile(projectile);
	}
	for (int i = 0; i < 20; ++i)
	{
		projectile = new Projectile_Straight;
		projectile->init(PROJECTILE_TYPE::PROJECTILE_BULLET_RED);
		AddProjectile(projectile);
	}
	for (int i = 0; i < 20; ++i)
	{
		projectile = new Projectile_Straight;
		projectile->init(PROJECTILE_TYPE::PROJECTILE_BULLET_GREEN);
		AddProjectile(projectile);
	}
	for (int i = 0; i < 20; ++i)
	{
		projectile = new Projectile_Straight;
		projectile->init(PROJECTILE_TYPE::PROJECTILE_BULLET_BLUE);
		AddProjectile(projectile);
	}
	for (int i = 0; i < 10; ++i)
	{
		projectile = new Projectile_Straight;
		projectile->init(PROJECTILE_TYPE::PROJECTILE_AURA);
		AddProjectile(projectile);
	}

	m_startTime = GetTickCount();
	return S_OK;
}

void ProjectileManager::release()
{
	vector<Projectile*>::iterator iter = m_projectileList.begin();
	for (iter; iter != m_projectileList.end();)
	{
		(*iter)->release();
		SAFE_DELETE((*iter));
		iter = m_projectileList.erase(iter);
	}
}

void ProjectileManager::update()
{
	for (int i = 0; i < m_projectileList.size(); i++)
	{
		if (!m_projectileList[i]->getIsActive()) continue;
		m_projectileList[i]->update();
	}
}

void ProjectileManager::render()
{
	for (int i = 0; i < m_projectileList.size(); i++)
	{
		if (!m_projectileList[i]->getIsActive()) continue;
		m_projectileList[i]->render();
	}
}

void ProjectileManager::ActivateProjectile(PROJECTILE_TYPE _projectileType, OBJECT_TYPE _userObjectType, POINTFLOAT _position, float _angle, float _attack, float _loopTime)
{
	if (GetTickCount() - m_startTime < _loopTime * 1000) return;
	m_startTime = GetTickCount();

	for (int i = 0; i < m_projectileList.size(); ++i)
	{
		// 사용하려는 투사체 타입과 일치하는 타입의 투사체인가? 틀리면 continue
		if (m_projectileList[i]->getProjectileType() != _projectileType) continue;
		// 투사체가 활성화되어 있는가? 활성화되있으면 continue
		if (m_projectileList[i]->getIsActive()) continue;

		m_projectileList[i]->setIsActive(true);
		m_projectileList[i]->setUserObjectType(_userObjectType);

		m_projectileList[i]->setPosition(_position);
		m_projectileList[i]->setActivePosition(_position);
		m_projectileList[i]->setAngle(_angle);
		m_projectileList[i]->setAttack(_attack);
		break;
	}
}

ProjectileManager::ProjectileManager()
{
}


ProjectileManager::~ProjectileManager()
{
}
