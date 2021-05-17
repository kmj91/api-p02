#pragma once
#include "Object.h"
class Actor :
	public Object
{
protected:
	ANIMATION_STATE m_animationState;		// 애니메이션 상태
	ANIMATION_STATE m_prevAnimationState;	// 이전 애니메이션 상태
	DIRECTION_STATE m_directionState;		// 방향 상태
protected:
	POINTFLOAT m_activePosition;			// 활성화된 좌표
protected:
	int m_frameIndex = 0;			// 이미지 프레임 인덱스
	int m_frameX = 0;				// 이미지 프레임 X
	int m_frameY = 0;				// 이미지 프레임 Y
	int m_frameDelay = 0;			// 이미지 프레임 지연률 if(m_frameDelay % m_frameDelayTime == 0) 이미지 프레임 인덱스 변경
	int m_frameDelayTime = 2;		// 다음 이미지 프레임 변경까지의 지연시간(=재생속도)
protected:
	int m_maxHP;			// 최대체력
	int m_curHP;			// 현재체력
protected:
	bool m_isAniFinish;		// 애니메이션이 끝났는가
protected:
	float m_speed;			// 이동속도
	float m_angle;			// 회전각도
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

