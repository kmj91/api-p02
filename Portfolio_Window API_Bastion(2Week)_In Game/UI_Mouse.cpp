#include "stdafx.h"
#include "UI_Mouse.h"
#include "Enemy.h"
#include "Obstacle_Broken.h"
#include "Camera.h"

HRESULT UI_Mouse::init()
{
	ShowCursor(false);

	m_objectType = OBJECT_TYPE::OBJECT_UI;
	m_layerType = LAYER_UI;
	m_uiType = UI_MOUSE;
	m_isActive = true;

	m_mouseState = MOUSE_STATE::MOUSE_MOVE;
	m_position = PointFloatMake(m_ptMouse.x, m_ptMouse.y);
	m_imageWidth = IMAGEMANAGER->findImage_Mouse(static_cast<int>(m_mouseState))->getWidth();
	m_imageHeight = IMAGEMANAGER->findImage_Mouse(static_cast<int>(m_mouseState))->getHeight();
	m_imageRect = RectMakeCenter(m_position.x, m_position.y, m_imageWidth, m_imageHeight);

	return S_OK;
}

void UI_Mouse::release()
{

}

void UI_Mouse::update()
{
	m_position = PointFloatMake(m_ptMouse.x, m_ptMouse.y);

	if (UIMANAGER->CheckOpenUI())
	{
		m_mouseState = MOUSE_STATE::MOUSE_NORMAL;
	}
	else
	{
		m_mouseState = MOUSE_STATE::MOUSE_MOVE;

		vector<Enemy*> enemyList = ENEMYMANAGER->getEnemyList();
		for (int i = 0; i < enemyList.size(); i++)
		{
			if (!enemyList[i]->getIsActive()) continue;
			POINTFLOAT cameraPosition = CAMERAMANAGER->getMainCamera()->getPosition();
			int cameraWidth = CAMERAMANAGER->getMainCamera()->getColliderWidth();
			int cameraHeight = CAMERAMANAGER->getMainCamera()->getColliderHeight();
			RECT colliderRect = RectMakeCenter(enemyList[i]->getPosition().x - cameraPosition.x + cameraWidth / 2, enemyList[i]->getPosition().y - cameraPosition.y + cameraHeight / 2, enemyList[i]->getColliderWidth(), enemyList[i]->getColliderHeight());
			if (PtInRect(&colliderRect, m_ptMouse))
			{
				m_mouseState = MOUSE_STATE::MOUSE_ATTACK;
				break;
			}
		}
	}

	m_imageWidth = IMAGEMANAGER->findImage_Mouse(static_cast<int>(m_mouseState))->getWidth();
	m_imageHeight = IMAGEMANAGER->findImage_Mouse(static_cast<int>(m_mouseState))->getHeight();
	m_imageRect = RectMakeCenter(m_position.x, m_position.y, m_imageWidth, m_imageHeight);
}

void UI_Mouse::render()
{
	RENDER_INFO renderInfo;
	renderInfo = { (int)m_uiType, m_position, m_imageRect, m_imageWidth, m_imageHeight, IMAGEMANAGER->findImage_Mouse(static_cast<int>(m_mouseState)) };
	CAMERAMANAGER->AddRenderInfo(m_layerType,  renderInfo);
}


UI_Mouse::UI_Mouse()
{
}


UI_Mouse::~UI_Mouse()
{
}
