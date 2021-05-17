#pragma once
#include "Skill.h"
class Skill_Tumbling :
	public Skill
{
public:
	virtual HRESULT init();
public:
	virtual void ActivateSkill(Object* _userObject);
public:
	Skill_Tumbling();
	virtual ~Skill_Tumbling();
};

