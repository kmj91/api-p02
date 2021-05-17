#pragma once
#include "UI.h"

class UI_StatusBar :
	public UI
{
private:
	STATUSBAR_TYPE m_statusBarType;			// �������ͽ��� Ÿ��
private:
	UI_BASE m_statusBarHP;					// �������ͽ��� HP
	UI_BASE m_statusBarEXP;					// �������ͽ��� EXP
private:
	Object* m_targetObject;					// �������ͽ��ٰ� ��Ÿ�� ��ü
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

