#pragma once
#include "singletonBase.h"

class Stage;
class StageManager :
	public singletonBase<StageManager>
{
private:
	typedef vector<Stage*> STAGE_LIST;
	STAGE_LIST m_stageList;
public:
	HRESULT init();
	void release();
	void update();
	void render();
public:
	void AddStage(Stage* _stage) { m_stageList.push_back(_stage); }
public:
	STAGE_LIST getStageList() { return m_stageList; }
public:
	StageManager();
	virtual ~StageManager();
};

