#pragma once
#include "Scene.h"
class Scene_MainMenu :
	public Scene
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Scene_MainMenu();
	virtual ~Scene_MainMenu();
};

