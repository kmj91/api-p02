#pragma once
#include "Object.h"
class Stage :
	public Object
{
private:
	STAGE_TYPE m_stageType;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	STAGE_TYPE getStageType() { return m_stageType; }
	void setStageType(STAGE_TYPE _stageType) { m_stageType = _stageType; }
public:
	Stage();
	virtual ~Stage();
};

