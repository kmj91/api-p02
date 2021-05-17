#include "stdafx.h"
#include "UI_StatusBar.h"
#include "Character_PC.h"
#include "Enemy.h"



HRESULT UI_StatusBar::init()
{

	return S_OK;
}

HRESULT UI_StatusBar::init(STATUSBAR_TYPE _statusBarType, Object * _object)
{
	m_objectType = OBJECT_TYPE::OBJECT_UI;
	m_uiType = UI_TYPE::UI_STATUS_BAR;

	m_statusBarType = _statusBarType;
	m_targetObject = _object;

	switch (m_statusBarType)
	{
	case STATUSBAR_TYPE::STATUSBAR_CHARACTER_PC:
	{
		m_layerType = LAYER_UI;

		m_statusBarHP.position = { 81, 43 };
		m_statusBarHP.imageWidth = IMAGEMANAGER->findImage("StatusBar_PC_HP")->getWidth();
		m_statusBarHP.imageHeight = IMAGEMANAGER->findImage("StatusBar_PC_HP")->getHeight();
		m_statusBarHP.imageRect = RectMake(m_statusBarHP.position.x, m_statusBarHP.position.y, m_statusBarHP.imageWidth, m_statusBarHP.imageHeight);

		m_statusBarEXP.position = { 118, 75 };
		m_statusBarEXP.imageWidth = IMAGEMANAGER->findImage("StatusBar_PC_EXP")->getWidth();
		m_statusBarEXP.imageHeight = IMAGEMANAGER->findImage("StatusBar_PC_EXP")->getHeight();
		m_statusBarEXP.imageRect = RectMake(m_statusBarEXP.position.x, m_statusBarEXP.position.y, m_statusBarEXP.imageWidth, m_statusBarEXP.imageHeight);
		break;
	}
	case STATUSBAR_TYPE::STATUSBAR_ENEMY:
	{
		m_layerType = LAYER_ENEMY_STATUSBAR;

		m_statusBarHP.position = PointFloatMake( (((Enemy*)m_targetObject)->getPosition().x - IMAGEMANAGER->findImage("StatusBar_Enemy_HP")->getWidth() / 2), ((Enemy*)m_targetObject)->getColliderRect().bottom );
		m_statusBarHP.imageWidth = IMAGEMANAGER->findImage("StatusBar_Enemy_HP")->getWidth();
		m_statusBarHP.imageHeight = IMAGEMANAGER->findImage("StatusBar_Enemy_HP")->getHeight();
		m_statusBarHP.imageRect = RectMake(m_statusBarHP.position.x, m_statusBarHP.position.y, m_statusBarHP.imageWidth, m_statusBarHP.imageHeight);
		break;
	}
	}

	m_isActive = true;

	return S_OK;
}

void UI_StatusBar::release()
{
}

void UI_StatusBar::update()
{
	switch (m_statusBarType)
	{
	case STATUSBAR_TYPE::STATUSBAR_CHARACTER_PC:
	{
		float maxHP = ((Character_PC*)m_targetObject)->getMaxHP();
		float curHP = ((Character_PC*)m_targetObject)->getCurHP();
		float maxEXP = ((Character_PC*)m_targetObject)->getMaxEXP();
		float curEXP = ((Character_PC*)m_targetObject)->getCurEXP();

		m_statusBarHP.imageWidth = IMAGEMANAGER->findImage("StatusBar_PC_HP")->getWidth() * (curHP / maxHP);
		m_statusBarEXP.imageWidth = IMAGEMANAGER->findImage("StatusBar_PC_EXP")->getWidth() * (curEXP / maxEXP);
		break;
	}
	case STATUSBAR_TYPE::STATUSBAR_ENEMY:
	{
		m_isActive = ((Enemy*)m_targetObject)->getIsActive();

		m_statusBarHP.position = PointFloatMake( (((Enemy*)m_targetObject)->getPosition().x - IMAGEMANAGER->findImage("StatusBar_Enemy_HP")->getWidth() / 2), ((Enemy*)m_targetObject)->getColliderRect().bottom );

		float maxHP = ((Enemy*)m_targetObject)->getMaxHP();
		float curHP = ((Enemy*)m_targetObject)->getCurHP();

		// 체력바 가로 길이 갱신
		m_statusBarHP.imageWidth = IMAGEMANAGER->findImage("StatusBar_Enemy_HP")->getWidth() * (curHP / maxHP);

		// 이미지 사각형 갱신
		m_statusBarHP.imageRect = RectMake(m_statusBarHP.position.x, m_statusBarHP.position.y, IMAGEMANAGER->findImage("StatusBar_Enemy_HP")->getWidth(), IMAGEMANAGER->findImage("StatusBar_Enemy_HP")->getHeight());
		break;
	}
	}
}

void UI_StatusBar::render()
{
	RENDER_INFO renderInfo;

	switch (m_statusBarType)
	{
	case STATUSBAR_TYPE::STATUSBAR_CHARACTER_PC:
		renderInfo = { (int)m_uiType, m_statusBarHP.position, m_statusBarHP.imageRect, m_statusBarHP.imageWidth, m_statusBarHP.imageHeight, IMAGEMANAGER->findImage("StatusBar_PC_HP") };
		CAMERAMANAGER->AddRenderInfo(m_layerType, renderInfo);

		renderInfo = { (int)m_uiType, m_statusBarEXP.position, m_statusBarEXP.imageRect, m_statusBarEXP.imageWidth, m_statusBarEXP.imageHeight, IMAGEMANAGER->findImage("StatusBar_PC_EXP") };
		CAMERAMANAGER->AddRenderInfo(m_layerType, renderInfo);
		break;
	case STATUSBAR_TYPE::STATUSBAR_ENEMY:
		renderInfo = { (int)m_position.y, m_statusBarHP.position, m_statusBarHP.imageRect, m_statusBarHP.imageWidth, m_statusBarHP.imageHeight,IMAGEMANAGER->findImage("StatusBar_Enemy_HP") };
		CAMERAMANAGER->AddRenderInfo(m_layerType, renderInfo);
		break;
	}
}


UI_StatusBar::UI_StatusBar()
{
}


UI_StatusBar::~UI_StatusBar()
{
}
