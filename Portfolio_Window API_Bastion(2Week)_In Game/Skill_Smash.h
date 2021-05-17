#pragma once
#include "Skill.h"
class Skill_Smash :
	public Skill
{
public:
	virtual HRESULT init();
public:
	virtual void ActivateSkill(Object* _userObject);
public:
	Skill_Smash();
	virtual ~Skill_Smash();
};

