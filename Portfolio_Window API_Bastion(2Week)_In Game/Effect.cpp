#include "stdafx.h"
#include "Effect.h"

HRESULT Effect::init()
{
	return S_OK;
}

HRESULT Effect::init(EFFECT_TYPE _effectType)
{
	m_objectType = OBJECT_TYPE::OBJECT_EFFECT;

	m_effectType = _effectType;

	switch (m_effectType)
	{
	case EFFECT_BREATH:
		m_layerType = LAYER_TYPE::LAYER_BACK_EFFECT;
		m_alpha = 255;
		break;
	case EFFECT_COUNTER:
		m_layerType = LAYER_TYPE::LAYER_FRONT_EFFECT;
		m_alpha = 255;
		break;
	case EFFECT_CRACK:
		m_layerType = LAYER_TYPE::LAYER_BACK_EFFECT;
		m_alpha = 255;
		break;
	case EFFECT_EXPLOSION:
		m_layerType = LAYER_TYPE::LAYER_FRONT_EFFECT;
		m_alpha = 255;
		break;
	case EFFECT_FIRE:
		m_layerType = LAYER_TYPE::LAYER_FRONT_EFFECT;
		m_alpha = 255;
		break;
	case EFFECT_METEOR:
		m_layerType = LAYER_TYPE::LAYER_FRONT_EFFECT;
		m_alpha = 255;
		break;
	case EFFECT_SMOKE:
		m_layerType = LAYER_TYPE::LAYER_FRONT_EFFECT;
		m_alpha = 200;
	case EFFECT_BULLET_FIRE_RED:
		m_layerType = LAYER_TYPE::LAYER_FRONT_EFFECT;
		m_alpha = 255;
		break;
	case EFFECT_BULLET_FIRE_GREEN:
		m_layerType = LAYER_TYPE::LAYER_FRONT_EFFECT;
		m_alpha = 255;
		break;
	case EFFECT_BULLET_FIRE_BLUE:
		m_layerType = LAYER_TYPE::LAYER_FRONT_EFFECT;
		m_alpha = 255;
		break;
	case EFFECT_BULLET_HIT_RED:
		m_layerType = LAYER_TYPE::LAYER_FRONT_EFFECT;
		m_alpha = 255;
		break;
	case EFFECT_BULLET_HIT_GREEN:
		m_layerType = LAYER_TYPE::LAYER_FRONT_EFFECT;
		m_alpha = 255;
		break;
	case EFFECT_BULLET_HIT_BLUE:
		m_layerType = LAYER_TYPE::LAYER_FRONT_EFFECT;
		m_alpha = 255;
		break;
	case EFFECT_RESTORE:
		m_layerType = LAYER_TYPE::LAYER_FRONT_EFFECT;
		m_alpha = 100;
		break;
	case EFFECT_SPECTRUM_URA_BOSS:
		m_layerType = LAYER_TYPE::LAYER_BACK_EFFECT;
		m_alpha = 150;
		break;
	case EFFECT_SPECTRUM_URA_CROSSBOW:
		m_layerType = LAYER_TYPE::LAYER_BACK_EFFECT;
		m_alpha = 150;
		break;
	case EFFECT_SPECTRUM_URA_SWORD:
		m_layerType = LAYER_TYPE::LAYER_BACK_EFFECT;
		m_alpha = 150;
		break;
	case EFFECT_SPECTRUM_URA_HALBERD:
		m_layerType = LAYER_TYPE::LAYER_BACK_EFFECT;
		m_alpha = 150;
		break;
	case EFFECT_SPECTRUM_URA_RIFLE:
		m_layerType = LAYER_TYPE::LAYER_BACK_EFFECT;
		m_alpha = 150;
		break;
	}

	m_directionState = DIRECTION_STATE::DIRECTION_NONE;
	m_image = IMAGEMANAGER->findImage_Effect(static_cast<int>(m_effectType));

	m_isActive = false;
	m_isAniFinish = false;
	return S_OK;
}

void Effect::release()
{

}

void Effect::update()
{
	if (m_isAniFinish)
	{
		m_isActive = false;
	}
}

void Effect::render()
{
	ImageFrameUpdate();
	m_imageWidth = m_image->getFrameWidth();
	m_imageHeight = m_image->getFrameHeight();
	m_imageRect = RectMakeCenter(m_position.x, m_position.y, m_imageWidth, m_imageHeight);

	RENDER_INFO renderInfo = { (int)m_position.y, m_position, m_imageRect, m_imageWidth, m_imageHeight, m_image, m_frameX, m_frameY, m_alpha };
	CAMERAMANAGER->AddRenderInfo(m_layerType, renderInfo);
}

Effect::Effect()
{
}


Effect::~Effect()
{
}
