#pragma once
#include "Obstacle.h"
class Obstacle_Unbroken :
	public Obstacle
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Obstacle_Unbroken();
	virtual ~Obstacle_Unbroken();
};

