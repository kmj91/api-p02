#pragma once
#include "Scene.h"
class Scene_MainGame :
	public Scene
{
private:
	BACKGROUND m_background[BACKGROUND_MAX];
	BACKGROUND_TYPE m_prevBackgroundType;
	BACKGROUND_TYPE m_curBackgroundType;
	int m_elapsedChangeTime;
	int m_changeTime;
	bool m_isChage;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	virtual void LoadProcess();
public:
	Scene_MainGame();
	virtual ~Scene_MainGame();
};

