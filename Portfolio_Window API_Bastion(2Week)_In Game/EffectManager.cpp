#include "stdafx.h"
#include "EffectManager.h"
#include "Effect.h"

HRESULT EffectManager::init()
{
	m_effectVector.clear();
	for (int i = 0; i < 2; ++i)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_BREATH);
		AddEffect(effect);
	}
	for (int i = 0; i < 1; ++i)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_COUNTER);
		AddEffect(effect);
	}
	for (int i = 0; i < 2; ++i)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_CRACK);
		AddEffect(effect);
	}
	for (int i = 0; i < 2; ++i)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_EXPLOSION);
		AddEffect(effect);
	}
	for (int i = 0; i < 5; ++i)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_FIRE);
		AddEffect(effect);
	}
	for (int i = 0; i < 15; ++i)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_METEOR);
		AddEffect(effect);
	}
	for (int i = 0; i < 15; ++i)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_SMOKE);
		AddEffect(effect);
	}
	for (int i = 0; i < 10; ++i)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_BULLET_FIRE_RED);
		AddEffect(effect);
	}
	for (int i = 0; i < 10; ++i)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_BULLET_FIRE_GREEN);
		AddEffect(effect);
	}
	for (int i = 0; i < 10; ++i)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_BULLET_FIRE_BLUE);
		AddEffect(effect);
	}
	for (int i = 0; i < 20; ++i)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_BULLET_HIT_RED);
		AddEffect(effect);
	}
	for (int i = 0; i < 20; ++i)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_BULLET_HIT_GREEN);
		AddEffect(effect);
	}
	for (int i = 0; i < 20; ++i)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_BULLET_HIT_BLUE);
		AddEffect(effect);
	}
	for (int i = 0; i < 2; ++i)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_RESTORE);
		AddEffect(effect);
	}
	for (int i = 0; i < 10; i++)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_SPECTRUM_URA_BOSS);
		AddEffect(effect);
	}
	for (int i = 0; i < 10; i++)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_SPECTRUM_URA_CROSSBOW);
		AddEffect(effect);
	}
	for (int i = 0; i < 10; i++)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_SPECTRUM_URA_RIFLE);
		AddEffect(effect);
	}
	for (int i = 0; i < 10; i++)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_SPECTRUM_URA_SWORD);
		AddEffect(effect);
	}
	for (int i = 0; i < 10; i++)
	{
		Effect* effect = new Effect;
		effect->init(EFFECT_TYPE::EFFECT_SPECTRUM_URA_HALBERD);
		AddEffect(effect);
	}

	m_startTime = GetTickCount();
	return S_OK;
}

void EffectManager::release()
{
	vector<Effect*>::iterator iter = m_effectVector.begin();
	for (iter; iter != m_effectVector.end();)
	{
		(*iter)->release();
		SAFE_RELEASE((*iter));
		iter = m_effectVector.erase(iter);
	}
}

void EffectManager::update()
{
	for (int i = 0; i < m_effectVector.size(); i++)
	{
		if (!m_effectVector[i]->getIsActive()) continue;
		m_effectVector[i]->update();
	}
}

void EffectManager::render()
{
	for (int i = 0; i < m_effectVector.size(); i++)
	{
		if (!m_effectVector[i]->getIsActive()) continue;
		m_effectVector[i]->render();
	}
}


void EffectManager::ActivateEffect(EFFECT_TYPE _effectType, POINTFLOAT _position, DIRECTION_STATE _directionState, float _loopTime)
{
	if (GetTickCount() - m_startTime < _loopTime * 1000.0f) return;
	m_startTime = GetTickCount();

	for (int i = 0; i < m_effectVector.size(); i++)
	{
		if (m_effectVector[i]->getEffectType() != _effectType) continue;
		if (m_effectVector[i]->getIsActive()) continue;
		m_effectVector[i]->setIsActive(true);
		m_effectVector[i]->setIsAniFinish(false);
		m_effectVector[i]->setPosition(_position);
		m_effectVector[i]->setDirectionState(_directionState);
		break;
	}
}

EffectManager::EffectManager()
{
}


EffectManager::~EffectManager()
{
}

