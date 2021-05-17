#pragma once
#include "singletonBase.h"

enum SCENE_TYPE;
enum UI_TYPE;
class UI;
class UIManager :
	public singletonBase<UIManager>
{
private:
	typedef vector<UI*> UI_LIST;
	UI_LIST m_UIList;
public:
	HRESULT init(SCENE_TYPE _sceneType);
	void release();
	void update();
	void render();
public:
	void AddUI(UI* _ui) { m_UIList.push_back(_ui); }
	UI* FindUI(UI_TYPE _uiType);
	bool CheckOpenUI();
public:
	UI_LIST getUIList() { return m_UIList; }
public:
	UIManager();
	virtual ~UIManager();
};

