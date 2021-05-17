#include "stdafx.h"
#include "Skill_Counter.h"
#include "Character_PC.h"
#include "Enemy.h"
#include "Projectile.h"

HRESULT Skill_Counter::init()
{
	m_isAvailable = true;
	m_attackRate = 1.0f;
	m_skillRange = 150.f;
	return S_OK;
}

void Skill_Counter::ActivateSkill(Object* _userObject)
{
	//스킬을 사용하는 객체 셋팅
	switch (_userObject->getObjectType())
	{
	case OBJECT_PC:
		Character_PC* pc = (Character_PC*)_userObject;

		//스킬을 적용받는 객체 셋팅
		vector<Projectile*> projectileList = PROJECTILEMANAGER->getProejectileList();

		//스킬 적용을 위한 충돌체크
		for (int i = 0; i < projectileList.size(); ++i)
		{
			if (!projectileList[i]->getIsActive()) continue;
			POINTFLOAT pcPosition = pc->getPosition();
			POINTFLOAT projectilePosition = projectileList[i]->getPosition();

			float distance = getDistance(pcPosition.x, pcPosition.y, projectilePosition.x, projectilePosition.y);

			if (distance < m_skillRange)
			{
				projectileList[i]->setAngle(projectileList[i]->getAngle() + PI);
				projectileList[i]->setUserObjectType(OBJECT_TYPE::OBJECT_PC);
			}
		}
		break;
	}//end of switch
}

Skill_Counter::Skill_Counter()
{
}


Skill_Counter::~Skill_Counter()
{
}
