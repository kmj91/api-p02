#include "stdafx.h"
#include "Skill_Tumbling.h"
#include "Character_PC.h"
#include "Obstacle.h"
#include "Enemy.h"

HRESULT Skill_Tumbling::init()
{
	m_isAvailable = true;
	m_attackRate = 0.5f;
	m_skillRange = 50.0f;

	return S_OK;
}

void Skill_Tumbling::ActivateSkill(Object * _userObject)
{

	switch (_userObject->getObjectType())
	{
	case OBJECT_PC:
	{
		// 스킬을 사용하는 객체
		Character_PC* pc = (Character_PC*)_userObject;

		// 스킬을 적용받는 객체
		vector<Enemy*> enemyList = ENEMYMANAGER->getEnemyList();
		for (int i = 0; i < enemyList.size(); ++i)
		{
			if (!enemyList[i]->getIsActive()) continue;

			POINTFLOAT pcPosition = pc->getPosition();
			POINTFLOAT enemyPosition = enemyList[i]->getPosition();

			float distance = getDistance(pcPosition.x, pcPosition.y, enemyPosition.x, enemyPosition.y);

			if (distance < m_skillRange)
			{
				enemyList[i]->setCurHP(enemyList[i]->getCurHP() - pc->getAttack() * m_attackRate);
			}
		}//end of for
		
		
		vector<Obstacle*> obstacleList = OBSTACLEMANAGER->getObstacleList();
		for (int i = 0; i < obstacleList.size(); ++i)
		{
			if (!obstacleList[i]->getIsActive()) continue;

			POINTFLOAT pcPosition = pc->getPosition();
			POINTFLOAT obstaclePosition = obstacleList[i]->getPosition();

			float distance = getDistance(pcPosition.x, pcPosition.y, obstaclePosition.x, obstaclePosition.y);

			if (distance < m_skillRange)
			{
				obstacleList[i]->setCurHP(obstacleList[i]->getCurHP() - pc->getAttack() * m_attackRate);
			}
		}
		break;
	}
	case OBJECT_ENEMY:
	{
		// 스킬을 사용하는 객체
		Enemy* enemy = (Enemy*)_userObject;

		// 스킬을 적용받는 객체
		Character_PC* pc = (Character_PC*)CHARACTERMANAGER->FindCharacter(CHARACTER_TYPE::CHARACTER_KID);

		if (!pc->getIsActive()) return;

		POINTFLOAT enemyPosition = enemy->getPosition();
		POINTFLOAT pcPosition = pc->getPosition();

		float distance = getDistance(enemyPosition.x, enemyPosition.y, pcPosition.x, pcPosition.y);

		if (distance < m_skillRange)
		{
			pc->setCurHP(pc->getCurHP() - enemy->getAttack() * m_attackRate);
		}

		break;
	}
	}//end of switch

}

Skill_Tumbling::Skill_Tumbling()
{
}


Skill_Tumbling::~Skill_Tumbling()
{
}
