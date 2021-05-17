#pragma once
#include "Object.h"
class Actor :
	public Object
{
protected:
	ANIMATION_STATE m_animationState;		// �ִϸ��̼� ����
	ANIMATION_STATE m_prevAnimationState;	// ���� �ִϸ��̼� ����
	DIRECTION_STATE m_directionState;		// ���� ����
protected:
	POINTFLOAT m_activePosition;			// Ȱ��ȭ�� ��ǥ
protected:
	int m_frameIndex = 0;			// �̹��� ������ �ε���
	int m_frameX = 0;				// �̹��� ������ X
	int m_frameY = 0;				// �̹��� ������ Y
	int m_frameDelay = 0;			// �̹��� ������ ������ if(m_frameDelay % m_frameDelayTime == 0) �̹��� ������ �ε��� ����
	int m_frameDelayTime = 2;		// ���� �̹��� ������ ��������� �����ð�(=����ӵ�)
protected:
	int m_maxHP;			// �ִ�ü��
	int m_curHP;			// ����ü��
protected:
	bool m_isAniFinish;		// �ִϸ��̼��� �����°�
protected:
	float m_speed;			// �̵��ӵ�
	float m_angle;			// ȸ������
public:
	virtual HRESULT init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
public:
	virtual void ImageInit();
	virtual void ImageFrameUpdate();
public:
	ANIMATION_STATE getAnimationState() { return m_animationState; }
	void setAnimationState(ANIMATION_STATE _animationState) { m_animationState = _animationState; }

	DIRECTION_STATE getDirectionState() { return m_directionState; }
	void setDirectionState(DIRECTION_STATE _directionState) { m_directionState = _directionState; }

	POINTFLOAT getActivePosition() { return m_activePosition; }
	void setActivePosition(POINTFLOAT _activePosition) { m_activePosition = _activePosition; }

	int getMaxHP() { return m_maxHP; }
	void setMaxHP(int _maxHP) { m_maxHP = _maxHP; }

	int getCurHP() { return m_curHP; }
	void setCurHP(int _curHP) { m_curHP = _curHP; }

	bool getIsAniFinish() { return m_isAniFinish; }
	void setIsAniFinish(bool _isAniFinish) { m_isAniFinish = _isAniFinish; }

	float getSpeed() { return m_speed; }
	void setSpeed(float _speed) { m_speed = _speed; }

	float getAngle() { return m_angle; }
	void setAngle(float _angle) { m_angle = _angle; }
public:
	Actor();
	virtual ~Actor();
};

