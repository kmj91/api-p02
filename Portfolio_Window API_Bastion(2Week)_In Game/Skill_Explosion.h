#pragma once
#include "Skill.h"
class Skill_Explosion :
	public Skill
{
public:
	virtual HRESULT init();
public:
	virtual void ActivateSkill(Object* _userObject);
public:
	Skill_Explosion();
	virtual ~Skill_Explosion();
};

