#pragma once
#include "Skill.h"
class Skill_Projectile :
	public Skill
{
public:
	virtual HRESULT init();
public:
	virtual void ActivateSkill(Object* _userObject);
public:
	Skill_Projectile();
	virtual ~Skill_Projectile();
};

