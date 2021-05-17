#pragma once
#include"UI.h"


class UI_Mouse : public UI
{
private:
	MOUSE_STATE m_mouseState;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	UI_Mouse();
	~UI_Mouse();
};

