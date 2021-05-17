#pragma once
#include "UI.h"
class UI_Title :
	public UI
{
private:
	enum PLAY_STATE { PLAY_LOGO1, PLAY_LOGO2, PLAY_TITLE, PLAY_MAX};
	enum FADE_STATE { FADE_IN, FADE_OUT };
	enum DIRECTION_STATE { CENTER, UP, DOWN };
	enum LOGO_TYPE { LOGO1, LOGO2, LOGO_MAX };
	UI_BASE m_titleLogo[LOGO_MAX];
	UI_BASE m_titleLogoBackground;
	UI_BASE m_title;
	UI_BASE m_titleBackground;
	UI_BASE m_button;
	UI_BASE m_buttonBackground;
private:
	float m_titleSpeed;
	float m_elapsedMoveTime;
	float m_moveTime;
private:
	PLAY_STATE m_curPlay;		// 현재 연출상태
	FADE_STATE m_fadeState[PLAY_MAX];
	DIRECTION_STATE m_directionState;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	UI_Title();
	virtual ~UI_Title();
};

