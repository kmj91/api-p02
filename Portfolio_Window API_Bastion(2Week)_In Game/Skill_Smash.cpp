#include "stdafx.h"
#include "Skill_Smash.h"
#include "Character_PC.h"
#include "Enemy.h"
#include "Obstacle.h"

HRESULT Skill_Smash::init()
{
	m_isAvailable = true;
	m_attackRate = 1.0f;
	m_skillRange = 150.0f;

	return S_OK;
}

void Skill_Smash::ActivateSkill(Object * _userObject)
{
	switch (_userObject->getObjectType())
	{
	case OBJECT_PC:
	{
		// 스킬을 사용하는 객체
		Character_PC* pc = (Character_PC*)_userObject;

		//스킬을 적용받는 객체
		vector<Enemy*> enemyList = ENEMYMANAGER->getEnemyList();
		for (int i = 0; i < enemyList.size(); ++i)
		{
			if (!enemyList[i]->getIsActive()) continue;
			POINTFLOAT pcPosition = pc->getPosition();
			POINTFLOAT enemyPosition = enemyList[i]->getPosition();

			float distance = getDistance(pcPosition.x, pcPosition.y, enemyPosition.x, enemyPosition.y);
			float angle = getAngle(pcPosition.x, pcPosition.y, enemyPosition.x, enemyPosition.y);
			float playerAngle = pc->getAngle();

			// 스킬을 사용하는 객체가 바라보는 각도가 1사분면이고 스킬을 사용하는 객체와 스킬을 적용할 객체가 이루는 각도가 4사분면일 경우
			if ((0 <= playerAngle && playerAngle < PI_2) && (PI + PI_2 < angle && angle <= PI2)) playerAngle += PI2;
			// 스킬을 적용하는 객체가 바라보는 각도가 4사분면이고 스킬을 사용하는 객체와 스킬을 적용할 객체가 이루는 각도가 1사분면일 경우
			else if ((0 <= angle && angle < PI_2) && (PI + PI_2 < playerAngle && playerAngle <= PI2)) angle += PI2;

			// 스킬을 사용하는 객체와 스킬을 적용할 객체와의 거리가 스킬 범위 내에 있다면 충돌(부채꼴 범위 판정)
			if (distance < m_skillRange && (playerAngle - 1 * PI_4 <= angle && angle <= playerAngle + 1 * PI_4))
			{
				enemyList[i]->setCurHP(enemyList[i]->getCurHP() - pc->getAttack() * m_attackRate);
				EFFECTMANAGER->ActivateEffect(EFFECT_TYPE::EFFECT_SMOKE, enemyPosition, DIRECTION_STATE::DIRECTION_NONE);
			}
		}

		vector<Obstacle*> obstacleList = OBSTACLEMANAGER->getObstacleList();
		for (int i = 0; i < obstacleList.size(); ++i)
		{
			if (!obstacleList[i]->getIsActive()) continue;
			POINTFLOAT pcPosition = pc->getPosition();
			POINTFLOAT obstaclePosition = obstacleList[i]->getPosition();

			float distance = getDistance(pcPosition.x, pcPosition.y, obstaclePosition.x, obstaclePosition.y);
			float angle = getAngle(pcPosition.x, pcPosition.y, obstaclePosition.x, obstaclePosition.y);
			float playerAngle = pc->getAngle();

			// 스킬을 사용하는 객체가 바라보는 각도가 1사분면이고 스킬을 사용하는 객체와 스킬을 적용할 객체가 이루는 각도가 4사분면일 경우
			if ((0 <= playerAngle && playerAngle < PI_2) && (PI + PI_2 < angle && angle <= PI2)) playerAngle += PI2;
			// 스킬을 적용하는 객체가 바라보는 각도가 4사분면이고 스킬을 사용하는 객체와 스킬을 적용할 객체가 이루는 각도가 1사분면일 경우
			else if ((0 <= angle && angle < PI_2) && (PI + PI_2 < playerAngle && playerAngle <= PI2)) angle += PI2;

			// 스킬을 사용하는 객체와 스킬을 적용할 객체와의 거리가 스킬 범위 내에 있다면 충돌(부채꼴 범위 판정)
			if (distance < m_skillRange && (playerAngle - 1 * PI_4 <= angle && angle <= playerAngle + 1 * PI_4))
			{
				obstacleList[i]->setCurHP(obstacleList[i]->getCurHP() - pc->getAttack() * m_attackRate);
				EFFECTMANAGER->ActivateEffect(EFFECT_TYPE::EFFECT_SMOKE, obstaclePosition, DIRECTION_STATE::DIRECTION_NONE);
			}
		}
		break;
	}
	case OBJECT_ENEMY:
	{
		//스킬을 사용하는 객체
		Enemy* enemy = (Enemy*)_userObject;

		//스킬을 적용받는 객체
		Character_PC* pc = (Character_PC*)CHARACTERMANAGER->FindCharacter(CHARACTER_TYPE::CHARACTER_KID);
		
		if (!pc->getIsActive()) return;

		POINTFLOAT pcPosition = pc->getPosition();
		POINTFLOAT enemyPosition = enemy->getPosition();

		float distance = getDistance(enemyPosition.x, enemyPosition.y, pcPosition.x, pcPosition.y);
		float angle = getAngle(enemyPosition.x, enemyPosition.y, pcPosition.x, pcPosition.y);
		float enemyAngle = enemy->getAngle();

		// 스킬을 사용하는 객체가 바라보는 각도가 1사분면이고 스킬을 사용하는 객체와 스킬을 적용할 객체가 이루는 각도가 4사분면일 경우
		if ((0 <= enemyAngle && enemyAngle < PI_2) && (PI + PI_2 < angle && angle <= PI2)) enemyAngle += PI2;
		// 스킬을 적용하는 객체가 바라보는 각도가 4사분면이고 스킬을 사용하는 객체와 스킬을 적용할 객체가 이루는 각도가 1사분면일 경우
		else if ((0 <= angle && angle < PI_2) && (PI + PI_2 < enemyAngle && enemyAngle <= PI2)) angle += PI2;

		// 스킬을 사용하는 객체와 스킬을 적용할 객체와의 거리가 스킬 범위 내에 있다면 충돌(부채꼴 범위 판정)
		if (distance < m_skillRange && (enemyAngle - 1 * PI_4 <= angle && angle <= enemyAngle + 1 * PI_4))
		{
			pc->setCurHP(pc->getCurHP() - enemy->getAttack() * m_attackRate);

			switch (enemy->getEnemyType())
			{
			case ENEMY_TYPE::ENEMY_MECHANICAL_PYTH:
				EFFECTMANAGER->ActivateEffect(EFFECT_TYPE::EFFECT_FIRE, pcPosition, DIRECTION_STATE::DIRECTION_NONE);
				break;
			}
		}
		break;
	}
	}//end of switch

}

Skill_Smash::Skill_Smash()
{
}


Skill_Smash::~Skill_Smash()
{
}
