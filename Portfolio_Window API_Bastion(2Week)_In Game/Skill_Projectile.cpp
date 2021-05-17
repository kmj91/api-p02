#include "stdafx.h"
#include "Skill_Projectile.h"
#include "Projectile.h"
#include "Character_PC.h"
#include "Enemy.h"
#include "Obstacle.h"


HRESULT Skill_Projectile::init()
{
	m_isAvailable = true;
	m_attackRate = 2.5f;
	m_skillRange = 150.f;
	return S_OK;
}

void Skill_Projectile::ActivateSkill(Object * _userObject)
{
	switch (_userObject->getObjectType())
	{
	case OBJECT_PROJECTILE:
	{
		//스킬을 사용하는 객체
		Projectile* projectile = (Projectile*)_userObject;

		//스킬을 적용받는 객체
		switch (projectile->getUserObjectType())
		{
		case OBJECT_ENEMY:
		{
			Character_PC* pc = (Character_PC*)CHARACTERMANAGER->FindCharacter(CHARACTER_TYPE::CHARACTER_KID);
			if (!pc->getIsActive()) return;

			POINTFLOAT projectilePosion = projectile->getPosition();
			POINTFLOAT pcPosition = pc->getPosition();

			float distance = getDistance(projectilePosion.x, projectilePosion.y, pcPosition.x, pcPosition.y);

			if (distance < m_skillRange)
			{
				pc->setCurHP(pc->getCurHP() - projectile->getAttack() * m_attackRate);

				switch (projectile->getProjectileType())
				{
				case PROJECTILE_TYPE::PROJECTILE_ARROW:
					
					break;
				case PROJECTILE_TYPE::PROJECTILE_BULLET_BLUE:
					EFFECTMANAGER->ActivateEffect(EFFECT_TYPE::EFFECT_BULLET_HIT_BLUE, pc->getPosition(), DIRECTION_STATE::DIRECTION_NONE);
					break;
				case PROJECTILE_TYPE::PROJECTILE_BULLET_GREEN:
					EFFECTMANAGER->ActivateEffect(EFFECT_TYPE::EFFECT_BULLET_HIT_GREEN, pc->getPosition(), DIRECTION_STATE::DIRECTION_NONE);
					break;
				}
			}
			break;
		}
		case OBJECT_PC:
		{
			vector<Enemy*> enemyList = ENEMYMANAGER->getEnemyList();
			for (int i = 0; i < enemyList.size(); ++i)
			{
				if (!enemyList[i]->getIsActive()) continue;

				POINTFLOAT projectilePosition = projectile->getPosition();
				POINTFLOAT enemyPosition = enemyList[i]->getPosition();

				float distance = getDistance(projectilePosition.x, projectilePosition.y, enemyPosition.x, enemyPosition.y);
				float angle = getAngle(projectilePosition.x, projectilePosition.y, enemyPosition.x, enemyPosition.y);

				//투사체 객체와 스킬을 적용할 객체와의 거리가 스킬 범위 내에 있다면 충돌
				if (distance < m_skillRange)
				{
					enemyList[i]->setCurHP(enemyList[i]->getCurHP() - projectile->getAttack() * m_attackRate);

					switch (projectile->getProjectileType())
					{
					case PROJECTILE_TYPE::PROJECTILE_BULLET_RED:
						EFFECTMANAGER->ActivateEffect(EFFECT_TYPE::EFFECT_BULLET_HIT_RED, enemyPosition, DIRECTION_STATE::DIRECTION_NONE);
						break;
					case PROJECTILE_TYPE::PROJECTILE_AURA:
						EFFECTMANAGER->ActivateEffect(EFFECT_TYPE::EFFECT_CRACK, enemyPosition, DIRECTION_STATE::DIRECTION_NONE);
					}
				}
			}

			vector<Obstacle*> obstacleList = OBSTACLEMANAGER->getObstacleList();
			for (int i = 0; i < obstacleList.size(); ++i)
			{
				if (!obstacleList[i]->getIsActive()) continue;

				POINTFLOAT projectilePosition = projectile->getPosition();
				POINTFLOAT obstaclePosition = obstacleList[i]->getPosition();

				float distance = getDistance(projectilePosition.x, projectilePosition.y, obstaclePosition.x, obstaclePosition.y);

				//투사체 객체와 스킬을 적용할 객체와의 거리가 스킬 범위 내에 있다면 충돌
				if (distance < m_skillRange)
				{
					obstacleList[i]->setCurHP(obstacleList[i]->getCurHP() - projectile->getAttack() * m_attackRate);

					switch (projectile->getProjectileType())
					{
					case PROJECTILE_TYPE::PROJECTILE_BULLET_RED:
						EFFECTMANAGER->ActivateEffect(EFFECT_TYPE::EFFECT_BULLET_HIT_RED, obstaclePosition, DIRECTION_STATE::DIRECTION_NONE);
						break;
					}
				}
			}
			break;
		}
		}//end of switch 
	break;
	}
	}// end of switch
}

Skill_Projectile::Skill_Projectile()
{
}


Skill_Projectile::~Skill_Projectile()
{
}
