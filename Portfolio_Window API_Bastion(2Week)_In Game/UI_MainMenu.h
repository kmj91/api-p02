#pragma once
#include "UI.h"

class UI_MainMenu :
	public UI
{
private:
	RECT m_selectTile[4];
	RECT m_kidRect;
	POINTFLOAT m_kidPosition;
private:
	float m_kidSpeed;
	float m_moveTime;
	float m_moveSpeed;
private:
	bool m_isMove;
	bool m_isSelectTile1;
	bool m_isSelectTile2;
	bool m_isSelectTile3;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	UI_MainMenu();
	virtual ~UI_MainMenu();
};

