#pragma once
#include "Scene.h"
class Scene_Title :
	public Scene
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Scene_Title();
	virtual ~Scene_Title();
};

