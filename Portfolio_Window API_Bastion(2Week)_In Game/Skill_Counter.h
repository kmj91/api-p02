#pragma once
#include "Skill.h"
class Skill_Counter :
	public Skill
{
public:
	virtual HRESULT init();
public:
	virtual void ActivateSkill(Object* _userObject);
public:
	Skill_Counter();
	virtual ~Skill_Counter();
};

