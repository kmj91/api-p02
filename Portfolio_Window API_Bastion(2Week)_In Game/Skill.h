#pragma once

class Object;
class Skill
{
protected:
	bool m_isAvailable;		// 스킬 사용가능 여부
protected:
	float m_attackRate;		// 스킬 공격계수(플레이어 공격력 * 스킬 공격계수 = 스킬 데미지)
	float m_skillRange;		// 스킬 공격범위
public:
	virtual HRESULT init() = 0;
public:
	// 스킬을 사용할 객체를 받고 각 스킬별 공격/피격 로직을 처리한다.
	virtual void ActivateSkill(Object* _userObject) = 0;
public:
	bool getIsAvailable() { return m_isAvailable; }
	void setIsAvailable(bool _isAvailable) { m_isAvailable = _isAvailable; }

	float getAttackRate() { return m_attackRate; }
	void setAttackRate(float _attackRate) { m_attackRate = _attackRate; }

	float getAttackRange() { return m_skillRange; }
	void setAttackRange(float _attackRange) { m_skillRange = _attackRange; }
public:
	Skill();
	~Skill();
};

