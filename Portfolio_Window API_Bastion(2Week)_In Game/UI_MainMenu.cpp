#include "stdafx.h"
#include "UI_MainMenu.h"


HRESULT UI_MainMenu::init()
{
	m_objectType = OBJECT_TYPE::OBJECT_UI;
	m_layerType = LAYER_UI;
	m_uiType = UI_TYPE::UI_MAINMENU;

	m_isActive = true;
	m_isOpen = true;
	m_position = { WINSIZEX / 2 , WINSIZEY / 2 };
	m_imageRect = RectMakeCenter(m_position.x, m_position.y, IMAGEMANAGER->findImage("MainMenu_Background")->getWidth(), IMAGEMANAGER->findImage("MainMenu_Background")->getHeight());
	m_kidPosition = { 220, 375 };
	m_kidRect = RectMakeCenter(m_kidPosition.x, m_kidPosition.y, IMAGEMANAGER->findImage("MainMenu_Character")->getWidth(), IMAGEMANAGER->findImage("MainMenu_Character")->getHeight());

	for (int i = 0; i < 3; ++i)
	{
		m_selectTile[i] = RectMakeCenter(550, 325 + 60 * i, 300, 50);
	}

	m_kidSpeed = 0.3f;
	m_moveTime = 1.f;
	m_moveSpeed = 0.03f;
	m_isMove = false;
	m_isSelectTile1 = true;
	m_isSelectTile2 = false;
	m_isSelectTile3 = false;


	return S_OK;
}

void UI_MainMenu::release()
{
}

void UI_MainMenu::update()
{
	if (PtInRect(&m_selectTile[0], m_ptMouse))
	{
		m_isSelectTile1 = true;
		m_isSelectTile2 = false;
		m_isSelectTile3 = false;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			m_isOpen = false;
			SCENEMANAGER->changeScene("Scene_Loading");
		}
	}
	if (PtInRect(&m_selectTile[1], m_ptMouse))
	{
		m_isSelectTile1 = false;
		m_isSelectTile2 = true;
		m_isSelectTile3 = false;
	}
	if (PtInRect(&m_selectTile[2], m_ptMouse))
	{
		m_isSelectTile1 = false;
		m_isSelectTile2 = false;
		m_isSelectTile3 = true;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			m_isOpen = false;
			exit(0);
		}
	}

	if (m_isMove == false)
	{
		m_kidPosition.y -= m_kidSpeed;
		m_moveTime += m_moveSpeed;
		if (m_moveTime >= 2)
		{
			m_isMove = true;
			m_moveTime = 1;
		}
	}
	else if (m_isMove == true)
	{
		m_kidPosition.y += m_kidSpeed;
		m_moveTime -= m_moveSpeed;
		if (m_moveTime <= 0)
		{
			m_moveTime = 1;
			m_isMove = false;
		}
	}

	m_kidRect = RectMakeCenter(m_kidPosition.x, m_kidPosition.y, IMAGEMANAGER->findImage("MainMenu_Character")->getWidth(), IMAGEMANAGER->findImage("MainMenu_Character")->getHeight());
}

void UI_MainMenu::render()
{
	IMAGEMANAGER->findImage("MainMenu_Background")->render(getMemDC(), m_imageRect.left, m_imageRect.top);
	IMAGEMANAGER->findImage("MainMenu_List")->render(getMemDC(), m_imageRect.left + 250, m_imageRect.top);

	for (int i = 0; i < 3; i++)
	{
		if (PtInRect(&m_selectTile[i], m_ptMouse))
		{
			IMAGEMANAGER->findImage("MainMenu_Button_Background")->alphaRender(getMemDC(), m_selectTile[i].left - 110, m_selectTile[i].top, 120);
		}
	}
	if (m_isSelectTile1)
	{
		IMAGEMANAGER->findImage("MainMenu_Button_Story_Bold")->render(getMemDC(), m_selectTile[0].left, m_selectTile[0].top);
		IMAGEMANAGER->findImage("MainMenu_Character")->render(getMemDC(), m_kidRect.left, m_kidRect.top);
	}
	else
	{
		IMAGEMANAGER->findImage("MainMenu_Button_Story")->render(getMemDC(), m_selectTile[0].left, m_selectTile[0].top);
	}
	if (m_isSelectTile2)
	{
		IMAGEMANAGER->findImage("MainMenu_Button_MapTool_Bold")->render(getMemDC(), m_selectTile[1].left, m_selectTile[1].top);
		IMAGEMANAGER->findImage("MainMenu_Character")->render(getMemDC(), m_kidRect.left, m_kidRect.top + 60);

	}
	else
	{
		IMAGEMANAGER->findImage("MainMenu_Button_MapTool")->render(getMemDC(), m_selectTile[1].left, m_selectTile[1].top);
	}
	if (m_isSelectTile3)
	{
		IMAGEMANAGER->findImage("MainMenu_Button_ExitGame_Bold")->render(getMemDC(), m_selectTile[2].left, m_selectTile[2].top);
		IMAGEMANAGER->findImage("MainMenu_Character")->render(getMemDC(), m_kidRect.left, m_kidRect.top + 120);
	}
	else
	{
		IMAGEMANAGER->findImage("MainMenu_Button_ExitGame")->render(getMemDC(), m_selectTile[2].left, m_selectTile[2].top);
	}
}

UI_MainMenu::UI_MainMenu()
{
}


UI_MainMenu::~UI_MainMenu()
{
}
