#pragma once
#include "UI.h"
class UI_Background :
	public UI
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	UI_Background();
	virtual ~UI_Background();
};

