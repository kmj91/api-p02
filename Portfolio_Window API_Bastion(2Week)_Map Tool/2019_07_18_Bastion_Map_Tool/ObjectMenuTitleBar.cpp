// �����
// �޴� Ÿ��Ʋ ��
// Ŭ���� ���� ����

#include "stdafx.h"
#include "ObjectMenuTitleBar.h"
#include "ObjectMenu.h"

ObjectMenuTitleBar::ObjectMenuTitleBar(DWORD dwRGBColor, int iPosX, int iPosY, int iWidth, int iHeight, double dCompose)
{
	// ����
	m_dwRGBColor = dwRGBColor;
	// ��ġ
	m_dX = iPosX;
	m_dY = iPosY;
	// ���� ���� ����
	m_iWidth = iWidth;
	m_iHeight = iHeight;
	// �ռ� ��
	m_dCompose = dCompose;
	// ������Ʈ ����
	m_dLeft = m_dX;
	m_dTop = m_dY;
	m_dRight = m_dLeft + m_iWidth;
	m_dBottom = m_dTop + m_iHeight;
	// �׸��� �켱����
	m_iRenderPriority = 0;
}


ObjectMenuTitleBar::~ObjectMenuTitleBar()
{
}

bool ObjectMenuTitleBar::Action()
{

	return false;
}

void ObjectMenuTitleBar::Draw()
{
	g_cSprite->DrawBackground(m_dwRGBColor, m_dX, m_dY, m_iWidth, m_iHeight, g_bypDest, g_iDestWidth, g_iDestHeight, g_iDestPitch, m_dCompose, false, true);
}

bool ObjectMenuTitleBar::Click()
{
	int iMouseX;
	int iMouseY;

	//--------------------------------------
	// ȭ�� �������� �����̴� UI
	// ī�޶� ��ǥ�� ���ش�
	//--------------------------------------
	iMouseX = g_iMouseX - g_CameraRect.left;
	iMouseY = g_iMouseY - g_CameraRect.top;

	if (m_dLeft < iMouseX && iMouseX < m_dRight &&
		m_dTop < iMouseY && iMouseY < m_dBottom) {

		g_MouseClickObject = MOUSE_CLICK_MENU_TITLE_BAR;
		return true;
	}

	return false;
}

void ObjectMenuTitleBar::Move(int iMoveValueX, int iMoveValueY)
{
	m_dX = m_dX - iMoveValueX;
	m_dY = m_dY - iMoveValueY;
	m_dLeft = m_dLeft - iMoveValueX;
	m_dTop = m_dTop - iMoveValueY;
	m_dRight = m_dRight - iMoveValueX;
	m_dBottom = m_dBottom - iMoveValueY;
}
