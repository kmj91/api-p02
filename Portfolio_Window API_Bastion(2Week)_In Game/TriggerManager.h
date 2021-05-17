#pragma once
#include "singletonBase.h"

class Trigger;
class TriggerManager :
	public singletonBase<TriggerManager>
{
private:
	typedef vector<Trigger*> TRIGGER_LIST;
	TRIGGER_LIST m_triggerList;
public:
	HRESULT init();
	void release();
	void update();
	void render();
public:
	void AddTrigger(Trigger* _trigger) { m_triggerList.push_back(_trigger); }
public:
	TriggerManager();
	virtual ~TriggerManager();
};

