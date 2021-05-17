#include "stdafx.h"
#include "SkillManager.h"
#include "Skill_Smash.h"
#include "Skill_Projectile.h"
#include "Skill_Tumbling.h"
#include "Skill_Explosion.h"
#include "Skill_Counter.h"



HRESULT SkillManager::init()
{
	Skill* skill;

	skill = new Skill_Smash;
	skill->init();
	AddSkill("Skill_Smash", skill);

	skill = new Skill_Projectile;
	skill->init();
	AddSkill("Skill_Projectile", skill);

	skill = new Skill_Tumbling;
	skill->init();
	AddSkill("Skill_Tumbling", skill);

	skill = new Skill_Explosion;
	skill->init();
	AddSkill("Skill_Explosion", skill);

	skill = new Skill_Counter;
	skill->init();
	AddSkill("Skill_Counter", skill);

	return S_OK;
}

void SkillManager::release()
{
	map<string, Skill*>::iterator iter = m_skillList.begin();
	for (iter; iter != m_skillList.end();)
	{
		SAFE_DELETE(iter->second);
		iter = m_skillList.erase(iter);
	}
}

void SkillManager::ActivateSkill(string _skillName, Object* _userObject)
{
	FindSkill(_skillName)->ActivateSkill(_userObject);
}

SkillManager::SkillManager()
{
}


SkillManager::~SkillManager()
{
}
