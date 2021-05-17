#pragma once

class Object;
class Skill
{
protected:
	bool m_isAvailable;		// ��ų ��밡�� ����
protected:
	float m_attackRate;		// ��ų ���ݰ��(�÷��̾� ���ݷ� * ��ų ���ݰ�� = ��ų ������)
	float m_skillRange;		// ��ų ���ݹ���
public:
	virtual HRESULT init() = 0;
public:
	// ��ų�� ����� ��ü�� �ް� �� ��ų�� ����/�ǰ� ������ ó���Ѵ�.
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

