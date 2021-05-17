#include "stdafx.h"
#include "Skill_Explosion.h"
#include "Character_PC.h"
#include "Enemy.h"

HRESULT Skill_Explosion::init()
{
	m_isAvailable = true;
	m_attackRate = 5.0f;
	m_skillRange = 800.0f;
	return S_OK;
}

void Skill_Explosion::ActivateSkill(Object* _userObject)
{

	switch (_userObject->getObjectType())
	{
	case OBJECT_PC:
		Character_PC* pc = (Character_PC*)_userObject;
		// 스킬을 적용받는 객체 셋팅

		vector<Enemy*> enemyList = ENEMYMANAGER->getEnemyList();

		// 스킬 적용을 위한 충돌체크
		for (int i = 0; i < enemyList.size(); ++i)
		{
			if (!enemyList[i]->getIsActive()) continue;

			POINTFLOAT pcPosition = pc->getPosition();
			POINTFLOAT enemyPosition = enemyList[i]->getPosition();

			float distance = getDistance(pcPosition.x, pcPosition.y, enemyPosition.x, enemyPosition.y);
			float angle = getAngle(pcPosition.x, pcPosition.y, enemyPosition.x, enemyPosition.y);

			// 투사체 객체와 스킬을 적용할 객체와의 거리가 스킬 범위 내에 있다면 충돌(원형 범위 판정)
			if (distance < m_skillRange)
			{
				enemyList[i]->setCurHP(enemyList[i]->getCurHP() - pc->getAttack() * m_attackRate);

				EFFECTMANAGER->ActivateEffect(EFFECT_TYPE::EFFECT_METEOR, PointFloatMake(enemyPosition.x + 70, enemyPosition.y - 135), DIRECTION_STATE::DIRECTION_NONE);
				if(!SOUNDMANAGER->isPlaySound("Effect_Player_Meteor")) SOUNDMANAGER->play("Effect_Player_Meteor");
			}
		}
		break;
	}
}

Skill_Explosion::Skill_Explosion()
{
}


Skill_Explosion::~Skill_Explosion()
{
}
