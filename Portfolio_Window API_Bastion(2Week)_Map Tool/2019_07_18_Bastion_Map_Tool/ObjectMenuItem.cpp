// �����
// UI �޴� �׸�
// �޴��� ���� ����Ʈ�� ���� ���� ��Ҹ� ��ǥ�ϴ� ǰ��

#include "stdafx.h"
#include "ObjectMenuItem.h"
#include "ObjectMenu.h"

ObjectMenuItem::ObjectMenuItem(int iPosX, int iPosY, int iSpriteIndex, FocusMenu eItemType, ObjectMenu * MenuPtr)
{
	// ��ġ
	m_dX = iPosX;
	m_dY = iPosY;
	// ��������Ʈ ��ȣ
	m_iSpriteIndex = iSpriteIndex;
	// ������Ʈ ����
	m_dLeft = m_dX - g_cSprite->m_stpSprite[m_iSpriteIndex].iCenterPointX;
	m_dTop = m_dY - g_cSprite->m_stpSprite[m_iSpriteIndex].iCenterPointY;
	m_dRight = m_dLeft + g_cSprite->m_stpSprite[m_iSpriteIndex].iWidth;
	m_dBottom = m_dTop + g_cSprite->m_stpSprite[m_iSpriteIndex].iHeight;
	// �׸��� �켱����
	m_iRenderPriority = 0;
	// �׸� Ÿ��
	m_eItemType = eItemType;
	// �޴� ������
	m_MenuPtr = MenuPtr;
}


ObjectMenuItem::~ObjectMenuItem()
{
}

bool ObjectMenuItem::Action()
{
	return false;
}

void ObjectMenuItem::Draw()
{
	g_cSprite->DrawImage(m_iSpriteIndex, m_dX, m_dY, g_bypDest, g_iDestWidth, g_iDestHeight, g_iDestPitch, false);
}

bool ObjectMenuItem::Click()
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
		
		// �޴��� ������ �ĺ� Ÿ��
		m_MenuPtr->m_ChangeMenu = m_eItemType;

		return true;
	}

	return false;
}

void ObjectMenuItem::Move(int iMoveValueX, int iMoveValueY)
{
	m_dX = m_dX - iMoveValueX;
	m_dY = m_dY - iMoveValueY;
	m_dLeft = m_dLeft - iMoveValueX;
	m_dTop = m_dTop - iMoveValueY;
	m_dRight = m_dRight - iMoveValueX;
	m_dBottom = m_dBottom - iMoveValueY;
}