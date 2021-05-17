#pragma once
#include "singletonBase.h"


class Object;
class Skill;
class SkillManager :
	public singletonBase<SkillManager>
{
private:
	typedef map<string, Skill*> SKILL_LIST;
	SKILL_LIST m_skillList;
public:
	HRESULT init();
	void release();
public:
	void AddSkill(string _skillName, Skill* _value) { m_skillList.insert(make_pair(_skillName, _value)); }
	Skill* FindSkill(string _skillName) { return m_skillList.find(_skillName)->second; }
	void ActivateSkill(string _skillName, Object* _userObject);
public:
	SKILL_LIST getSkillList() { return m_skillList; }
public:
	SkillManager();
	virtual ~SkillManager();
};

