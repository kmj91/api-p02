#include "stdafx.h"
#include "UI_Title.h"


HRESULT UI_Title::init()
{
	m_objectType = OBJECT_TYPE::OBJECT_UI;
	m_layerType = LAYER_UI;
	m_uiType = UI_TYPE::UI_TITLE;

	m_isActive = true;
	m_isOpen = true;

	m_titleLogoBackground.position = { WINSIZEX / 2, WINSIZEY / 2 };
	m_titleLogoBackground.imageWidth = IMAGEMANAGER->findImage("Title_LogoBackground")->getWidth();
	m_titleLogoBackground.imageHeight = IMAGEMANAGER->findImage("Title_LogoBackground")->getHeight();
	m_titleLogoBackground.imageRect = RectMakeCenter(m_titleLogoBackground.position.x, m_titleLogoBackground.position.y, m_titleLogoBackground.imageWidth, m_titleLogoBackground.imageHeight);

	for (int i = 0; i < LOGO_MAX; ++i)
	{
		m_titleLogo[i].position = { WINSIZEX / 2, WINSIZEY / 2 };
		m_titleLogo[i].imageWidth = WINSIZEX;
		m_titleLogo[i].imageHeight = WINSIZEY;
		m_titleLogo[i].imageRect = RectMakeCenter(m_titleLogo[i].position.x, m_titleLogo[i].position.y, m_titleLogo[i].imageWidth, m_titleLogo[i].imageHeight);
		m_titleLogo[i].alpha = 0;
	}

	m_titleBackground.position = { WINSIZEX / 2, WINSIZEY / 2 };
	m_titleBackground.imageWidth = IMAGEMANAGER->findImage("Title_Background")->getWidth();
	m_titleBackground.imageHeight = IMAGEMANAGER->findImage("Title_Background")->getHeight();
	m_titleBackground.imageRect = RectMakeCenter(m_titleBackground.position.x, m_titleBackground.position.y, m_titleBackground.imageWidth, m_titleBackground.imageHeight);
	m_titleBackground.alpha = 0;

	m_title.position = { WINSIZEX / 2, 1000 };
	m_title.imageWidth = IMAGEMANAGER->findImage("Title_Bastion")->getWidth();
	m_title.imageHeight = IMAGEMANAGER->findImage("Title_Bastion")->getHeight();
	m_title.imageRect = RectMakeCenter(m_title.position.x, m_title.position.y, m_title.imageWidth, m_title.imageHeight);

	m_button.position = { WINSIZEX / 2, 500 };
	m_button.imageWidth = IMAGEMANAGER->findImage("Title_Button_Start")->getWidth();
	m_button.imageHeight = IMAGEMANAGER->findImage("Title_Button_Start")->getHeight();
	m_button.imageRect = RectMakeCenter(m_button.position.x, m_button.position.y, m_button.imageWidth, m_button.imageHeight);
	m_button.alpha = 0;

	m_buttonBackground.position = { WINSIZEX / 2, 500 };
	m_buttonBackground.imageWidth = IMAGEMANAGER->findImage("Title_Button_Background")->getWidth();
	m_buttonBackground.imageHeight = IMAGEMANAGER->findImage("Title_Button_Background")->getHeight();
	m_buttonBackground.imageRect = RectMakeCenter(m_buttonBackground.position.x, m_buttonBackground.position.y, m_buttonBackground.imageWidth, m_buttonBackground.imageHeight);
	m_buttonBackground.alpha = 0;

	m_titleSpeed = 0.2f;
	m_moveTime = 1.f;
	m_elapsedMoveTime = GetTickCount();

	m_directionState = CENTER;
	return S_OK;
}

void UI_Title::release()
{
}

void UI_Title::update()
{
	// 로고1 -> 로고2 -> 타이틀 연출과정
	switch (m_curPlay)
	{
	case UI_Title::PLAY_LOGO1:
		if (m_fadeState[PLAY_LOGO1] == FADE_IN)
		{
			m_titleLogo[PLAY_LOGO1].alpha += 3.0f;
			if (m_titleLogo[PLAY_LOGO1].alpha >= 255)
			{
				m_fadeState[PLAY_LOGO1] = FADE_OUT;
				m_titleLogo[PLAY_LOGO1].alpha = 255;
			}
		}
		else
		{
			m_titleLogo[PLAY_LOGO1].alpha -= 3.0f;
			if (m_titleLogo[PLAY_LOGO1].alpha <= 0)
			{
				m_titleLogo[PLAY_LOGO1].alpha = 0;
				m_curPlay = PLAY_LOGO2;
			}
		}
		break;
	case UI_Title::PLAY_LOGO2:
		if (m_fadeState[PLAY_LOGO2] == FADE_IN)
		{
			m_titleLogo[PLAY_LOGO2].alpha += 3.0f;
			if (m_titleLogo[PLAY_LOGO2].alpha >= 255)
			{
				m_fadeState[PLAY_LOGO2] = FADE_OUT;
				m_titleLogo[PLAY_LOGO2].alpha = 255;
			}
		}
		else
		{
			m_titleLogo[PLAY_LOGO2].alpha -= 3.0f;
			if (m_titleLogo[PLAY_LOGO2].alpha <= 0)
			{
				m_titleLogo[PLAY_LOGO2].alpha = 0;
				m_curPlay = PLAY_TITLE;
				SOUNDMANAGER->play("BGM_Bastion");
			}
		}
		break;
	case UI_Title::PLAY_TITLE:
		if (m_fadeState[PLAY_TITLE] == FADE_IN)
		{
			m_button.alpha += 3.0f;
			if (m_button.alpha >= 150)
			{
				m_button.alpha = 150;
			}

			m_buttonBackground.alpha += 3.0f;
			if (m_buttonBackground.alpha >= 150)
			{
				m_buttonBackground.alpha = 150;
			}

			if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
			{
				SCENEMANAGER->changeScene("Scene_MainMenu");
			}

			// 타이틀 움직임
			if (m_directionState == CENTER)
			{
				m_title.position.y -= 10.0f;
				if (m_title.position.y <= 300.0f)
				{
					m_title.position.y = 300.0f;
					m_directionState = UP;
				}
			}
			else
			{
				if (GetTickCount() - m_elapsedMoveTime >= 1000.0f * m_moveTime)
				{
					m_elapsedMoveTime = GetTickCount();

					if (m_directionState == UP)
						m_directionState = DOWN;
					else
						m_directionState = UP;
				}
			}

			switch (m_directionState)
			{
			case UP:
				m_title.position.y -= m_titleSpeed;
				break;
			case DOWN:
				m_title.position.y += m_titleSpeed;
				break;
			}

			m_title.imageRect = RectMakeCenter(m_title.position.x, m_title.position.y, m_title.imageWidth, m_title.imageHeight);
		}
		break;
	}
}

void UI_Title::render()
{
	switch (m_curPlay)
	{
	case PLAY_LOGO1:
		IMAGEMANAGER->findImage("Title_LogoBackground")->render(getMemDC(), m_titleLogoBackground.imageRect.left, m_titleLogoBackground.imageRect.top);
		IMAGEMANAGER->findImage("Title_Logo1")->alphaRender(getMemDC(), m_titleLogo[LOGO1].imageRect.left, m_titleLogo[LOGO1].imageRect.top, m_titleLogo[LOGO1].alpha);
		break;
	case PLAY_LOGO2:
		IMAGEMANAGER->findImage("Title_LogoBackground")->render(getMemDC(), m_titleLogoBackground.imageRect.left, m_titleLogoBackground.imageRect.top);
		IMAGEMANAGER->findImage("Title_Logo2")->alphaRender(getMemDC(), m_titleLogo[LOGO2].imageRect.left, m_titleLogo[LOGO2].imageRect.top, m_titleLogo[LOGO2].alpha);
		break;
	case PLAY_TITLE:
		IMAGEMANAGER->findImage("Title_Background")->render(getMemDC(), m_titleBackground.imageRect.left, m_titleBackground.imageRect.top);
		IMAGEMANAGER->findImage("Title_Button_Background")->alphaRender(getMemDC(), m_buttonBackground.imageRect.left, m_buttonBackground.imageRect.top, m_buttonBackground.alpha);
		IMAGEMANAGER->findImage("Title_Button_Start")->alphaRender(getMemDC(), m_button.imageRect.left, m_button.imageRect.top, m_button.alpha);
		IMAGEMANAGER->findImage("Title_Bastion")->render(getMemDC(), m_title.imageRect.left, m_title.imageRect.top);
		break;
	}
}

UI_Title::UI_Title()
{
}


UI_Title::~UI_Title()
{
}
