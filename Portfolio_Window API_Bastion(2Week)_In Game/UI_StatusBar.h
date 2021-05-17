#pragma once
#include "UI.h"

class UI_StatusBar :
	public UI
{
private:
	STATUSBAR_TYPE m_statusBarType;			// 스테이터스바 타입
private:
	UI_BASE m_statusBarHP;					// 스테이터스바 HP
	UI_BASE m_statusBarEXP;					// 스테이터스바 EXP
private:
	Object* m_targetObject;					// 스테이터스바가 나타낼 객체
public:
	virtual HRESULT init();
	virtual HRESULT init(STATUSBAR_TYPE _statusBarType, Object* _object);
	virtual void release();
	virtual void update();
	virtual void render();
public:
	UI_StatusBar();
	virtual ~UI_StatusBar();
};

