#pragma once
#include "singletonBase.h"

enum EFFECT_TYPE;
enum DIRECTION_STATE;
class Effect;
class EffectManager : public singletonBase<EffectManager>
{
private:
	typedef vector<Effect*> EFFECT_VECTOR;

	EFFECT_VECTOR m_effectVector;
private:
	int m_startTime;	// 함수의 실행주기를 조절하기 위한 변수
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	void AddEffect(Effect* _effect) { m_effectVector.push_back(_effect); }
	void ActivateEffect(EFFECT_TYPE _effectType, POINTFLOAT _position, DIRECTION_STATE _directionState, float _loopTime = 0);
public:
	EffectManager();
	~EffectManager();
};

