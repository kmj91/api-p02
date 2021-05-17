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
	//��ų�� ����ϴ� ��ü ����
	switch (_userObject->getObjectType())
	{
	case OBJECT_PC:
		Character_PC* pc = (Character_PC*)_userObject;

		//��ų�� ����޴� ��ü ����
		vector<Projectile*> projectileList = PROJECTILEMANAGER->getProejectileList();

		//��ų ������ ���� �浹üũ
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
