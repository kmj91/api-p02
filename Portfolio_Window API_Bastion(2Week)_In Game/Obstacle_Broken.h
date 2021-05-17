#pragma once
#include "Obstacle.h"
class Obstacle_Broken :
	public Obstacle
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Obstacle_Broken();
	virtual ~Obstacle_Broken();
};

