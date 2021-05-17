#pragma once
#include "singletonBase.h"

class Obstacle;
class ObstacleManager :
	public singletonBase<ObstacleManager>
{
private:
	typedef vector<Obstacle*> OBSTACLE_LIST;
	OBSTACLE_LIST m_obstacleList;
public:
	HRESULT init();
	void release();
	void update();
	void render();
public:
	void AddObstacle(Obstacle* _obstacle) { m_obstacleList.push_back(_obstacle); }
	void ActiavteObstacle();
public:
	OBSTACLE_LIST getObstacleList() { return m_obstacleList; }
public:
	ObstacleManager();
	virtual ~ObstacleManager();
};

