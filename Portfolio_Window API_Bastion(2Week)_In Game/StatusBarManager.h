#pragma once
#include "singletonBase.h"

enum STATUSBAR_TYPE;
class UI_StatusBar;
class StatusBarManager : public singletonBase<StatusBarManager>
{
private:
	typedef vector<UI_StatusBar*> STATEBAR_VECTOR;
	STATEBAR_VECTOR m_statusBarVector;
public:
	HRESULT init();
	void release();
	void update();
	void render();
public:
	void AddStatusBar(UI_StatusBar* _stateBar) { m_statusBarVector.push_back(_stateBar); }
	void CreateStateBar(STATUSBAR_TYPE _stateBarType, Object* _object);
public:
	StatusBarManager();
	virtual ~StatusBarManager();
};

