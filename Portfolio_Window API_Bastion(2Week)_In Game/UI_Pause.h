#pragma once
#include "UI.h"
class UI_Pause :
	public UI
{
private:
	UI_BASE m_pauseBackground;
	UI_BASE m_pauseList;

	enum BUTTON_TYPE 
	{ 
		BUTTON_RESUME_GAME,
		BUTTON_EXIT_MENU, 
		BUTTON_MAX
	};
	UI_BASE m_button[BUTTON_MAX];
	UI_BASE m_buttonBackground;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	UI_Pause();
	virtual ~UI_Pause();
};
