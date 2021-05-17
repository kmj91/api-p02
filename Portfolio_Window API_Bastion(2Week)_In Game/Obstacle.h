#pragma once
#include "Actor.h"

class Obstacle :
	public Actor
{
protected:
	OBSTACLE_TYPE m_obstacleType;
protected:
	bool m_isDestroyed;			// 파괴되었는가
protected:
	float m_activeRange;		// 활성화범위
public:
	virtual HRESULT init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
public:
	virtual void ImageInit();
public:
	OBSTACLE_TYPE getObstacleType() { return m_obstacleType; }
	void setObstacleType(OBSTACLE_TYPE _obstacleType) { m_obstacleType = _obstacleType; }

	bool getIsDestroyed() { return m_isDestroyed; }
	void setIsDestroyed(bool _isDestroyed) { m_isDestroyed = _isDestroyed; }
public:
	Obstacle();
	virtual ~Obstacle();
};

