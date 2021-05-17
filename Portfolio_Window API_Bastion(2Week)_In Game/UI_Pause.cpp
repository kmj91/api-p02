#include "stdafx.h"
#include "UI_Pause.h"


HRESULT UI_Pause::init()
{
	m_objectType = OBJECT_TYPE::OBJECT_UI;
	m_layerType = LAYER_UI;
	m_uiType = UI_TYPE::UI_PAUSE;

	m_isActive = true;
	m_isOpen = false;

	m_pauseBackground = { WINSIZEX / 2, WINSIZEY / 2 };
	m_pauseBackground.imageWidth = IMAGEMANAGER->findImage("Pause_Background")->getWidth();
	m_pauseBackground.imageHeight = IMAGEMANAGER->findImage("Pause_Background")->getHeight();
	m_pauseBackground.imageRect = RectMakeCenter(m_pauseBackground.position.x, m_pauseBackground.position.y, m_pauseBackground.imageWidth, m_pauseBackground.imageHeight);
	m_pauseBackground.alpha = 0;

	m_pauseList.position = { WINSIZEX / 2, WINSIZEY / 2 };
	m_pauseList.imageWidth = IMAGEMANAGER->findImage("Pause_List")->getWidth();
	m_pauseList.imageHeight = IMAGEMANAGER->findImage("Pause_List")->getHeight();
	m_pauseList.imageRect = RectMakeCenter(m_pauseList.position.x, m_pauseList.position.y, m_pauseList.imageWidth, m_pauseList.imageHeight);
	m_pauseList.alpha = 0;

	for (int i = 0; i < BUTTON_MAX; ++i)
	{
		switch (i)
		{
		case BUTTON_RESUME_GAME:
			m_button[i].position = PointFloatMake(WINSIZEX / 2, 350 + 80 * i);
			m_button[i].imageWidth = IMAGEMANAGER->findImage("Pause_Button_ResumeGame")->getWidth();
			m_button[i].imageHeight = IMAGEMANAGER->findImage("Pause_Button_ResumeGame")->getHeight();
			m_button[i].imageRect = RectMakeCenter(m_button[i].position.x, m_button[i].position.y, m_button[i].imageWidth, m_button[i].imageHeight);
			m_button[i].colliderWidth = 300;
			m_button[i].colliderHeight = 50;
			m_button[i].colliderRect = RectMakeCenter(m_button[i].position.x, m_button[i].position.y, m_button[i].colliderWidth, m_button[i].colliderHeight);
			m_button[i].alpha = 0;
			break;
		case BUTTON_EXIT_MENU:
			m_button[i].position = PointFloatMake(WINSIZEX / 2, 350 + 80 * i);
			m_button[i].imageWidth = IMAGEMANAGER->findImage("Pause_Button_ExitMenu")->getWidth();
			m_button[i].imageHeight = IMAGEMANAGER->findImage("Pause_Button_ExitMenu")->getHeight();
			m_button[i].imageRect = RectMakeCenter(m_button[i].position.x, m_button[i].position.y, m_button[i].imageWidth, m_button[i].imageHeight);
			m_button[i].colliderWidth = 300;
			m_button[i].colliderHeight = 50;
			m_button[i].colliderRect = RectMakeCenter(m_button[i].position.x, m_button[i].position.y, m_button[i].colliderWidth, m_button[i].colliderHeight);
			m_button[i].alpha = 0;
			break;
		}
	}

	m_buttonBackground.position = { 0, 0 };
	m_buttonBackground.imageWidth = IMAGEMANAGER->findImage("Pause_Button_Background")->getWidth();
	m_buttonBackground.imageHeight = IMAGEMANAGER->findImage("Pause_Button_Background")->getHeight();
	m_buttonBackground.imageRect = RectMakeCenter(m_buttonBackground.position.x, m_buttonBackground.position.y, m_buttonBackground.imageWidth, m_buttonBackground.imageHeight);
	m_buttonBackground.alpha = 150;

	return S_OK;
}

void UI_Pause::release()
{

}

void UI_Pause::update()
{
	if (m_isOpen) // 열렸으면 페이드 인
	{
		m_pauseBackground.alpha += 5.0f;
		if (m_pauseBackground.alpha >= 120) m_pauseBackground.alpha = 120;

		m_pauseList.alpha += 5.0f;
		if (m_pauseList.alpha >= 255) m_pauseList.alpha = 255;

		for (int i = 0; i < BUTTON_MAX; ++i)
		{
			m_button[i].alpha += 5.0f;
			if (m_button[i].alpha >= 255) m_button[i].alpha = 255;
		}
	}
	else // 닫혔으면 페이드 아웃
	{
		m_pauseBackground.alpha -= 5.0f;
		if (m_pauseBackground.alpha <= 0) m_pauseBackground.alpha = 0;

		m_pauseList.alpha -= 5.0f;
		if (m_pauseList.alpha <= 0) m_pauseList.alpha = 0;

		for (int i = 0; i < BUTTON_MAX; ++i)
		{
			m_button[i].alpha -= 5.0f;
			if (m_button[i].alpha <= 0) m_button[i].alpha = 0;
		}
	}

	if (m_isOpen)
	{
		// 버튼 동작
		for (int i = 0; i < BUTTON_MAX; ++i)
		{
			if (PtInRect(&m_button[i].colliderRect, m_ptMouse))
			{
				m_buttonBackground.position = m_button[i].position;
				m_buttonBackground.imageRect = RectMakeCenter(m_buttonBackground.position.x, m_buttonBackground.position.y, m_buttonBackground.imageWidth, m_buttonBackground.imageHeight);

				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					switch (i)
					{
					case BUTTON_RESUME_GAME:
						break;
					case BUTTON_EXIT_MENU:
						SOUNDMANAGER->allStop();
						SCENEMANAGER->changeScene("Scene_MainMenu");
						break;
					}
					m_isOpen = false;
				}
				else
				{
					m_button[i].isClick = false;
				}
			}
		}
	}
}

void UI_Pause::render()
{
	if (!m_isOpen) return;

	RENDER_INFO renderInfo;

	// Pause_Background 렌더정보 전달
	renderInfo = { (int)m_uiType, m_pauseBackground.position, m_pauseBackground.imageRect, m_pauseBackground.imageWidth, m_pauseBackground.imageHeight,
	IMAGEMANAGER->findImage("Pause_Background"), 0, 0, m_pauseBackground.alpha };
	CAMERAMANAGER->AddRenderInfo(m_layerType,  renderInfo);

	// Pause_List 렌더정보 전달
	renderInfo = { (int)m_uiType, m_pauseList.position, m_pauseList.imageRect, m_pauseList.imageWidth, m_pauseList.imageHeight,
	IMAGEMANAGER->findImage("Pause_List"), 0, 0, m_pauseList.alpha };
	CAMERAMANAGER->AddRenderInfo(m_layerType,  renderInfo);

	// Pause_Button 렌더정보 전달
	for (int i = 0; i < BUTTON_MAX; i++)
	{
		switch (i)
		{
		case BUTTON_RESUME_GAME:
			if (PtInRect(&m_button[i].colliderRect, m_ptMouse))
			{
				renderInfo = { (int)m_uiType, m_buttonBackground.position, m_buttonBackground.imageRect, m_buttonBackground.imageWidth, m_buttonBackground.imageHeight,
				IMAGEMANAGER->findImage("Pause_Button_Background"), 0, 0, m_buttonBackground.alpha };
				CAMERAMANAGER->AddRenderInfo(m_layerType, renderInfo);

				renderInfo = { (int)m_uiType, m_button[i].position, m_button[i].imageRect, m_button[i].imageWidth, m_button[i].imageHeight,
				IMAGEMANAGER->findImage("Pause_Button_ResumeGame_Bold"), 0, 0, m_button[i].alpha };
				CAMERAMANAGER->AddRenderInfo(m_layerType, renderInfo);
			}
			else
			{
				renderInfo = { (int)m_uiType, m_button[i].position, m_button[i].imageRect, m_button[i].imageWidth, m_button[i].imageHeight,
				IMAGEMANAGER->findImage("Pause_Button_ResumeGame"), 0, 0, m_button[i].alpha };
				CAMERAMANAGER->AddRenderInfo(m_layerType,  renderInfo);
			}
			break;
		case BUTTON_EXIT_MENU:
			if (PtInRect(&m_button[i].colliderRect, m_ptMouse))
			{
				renderInfo = { (int)m_uiType, m_buttonBackground.position, m_buttonBackground.imageRect, m_buttonBackground.imageWidth, m_buttonBackground.imageHeight,
				IMAGEMANAGER->findImage("Pause_Button_Background"), 0, 0, m_buttonBackground.alpha };
				CAMERAMANAGER->AddRenderInfo(m_layerType, renderInfo);

				renderInfo = { (int)m_uiType, m_button[i].position, m_button[i].imageRect, m_button[i].imageWidth, m_button[i].imageHeight,
				IMAGEMANAGER->findImage("Pause_Button_ExitMenu_Bold"), 0, 0, m_button[i].alpha };
				CAMERAMANAGER->AddRenderInfo(m_layerType,  renderInfo);
			}
			else
			{
				renderInfo = { (int)m_uiType, m_button[i].position, m_button[i].imageRect, m_button[i].imageWidth, m_button[i].imageHeight,
				IMAGEMANAGER->findImage("Pause_Button_ExitMenu"), 0, 0, m_button[i].alpha };
				CAMERAMANAGER->AddRenderInfo(m_layerType,  renderInfo);
			}
		}
	}
}

UI_Pause::UI_Pause()
{
}


UI_Pause::~UI_Pause()
{
}
