#pragma once
#include "Actor.h"

class Effect :
	public Actor
{
private:
	EFFECT_TYPE m_effectType;
private:
	BYTE m_alpha;
public:
	virtual HRESULT init();
	virtual HRESULT init(EFFECT_TYPE _effectType);
	virtual void release();
	virtual void update();
	virtual void render();
public:
	EFFECT_TYPE getEffectType() { return m_effectType; }
public:
	Effect();
	virtual ~Effect();
};

