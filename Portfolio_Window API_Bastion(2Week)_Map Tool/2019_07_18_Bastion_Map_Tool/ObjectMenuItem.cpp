// 기명준
// UI 메뉴 항목
// 메뉴의 하위 리스트에 들어가는 개별 요소를 대표하는 품목

#include "stdafx.h"
#include "ObjectMenuItem.h"
#include "ObjectMenu.h"

ObjectMenuItem::ObjectMenuItem(int iPosX, int iPosY, int iSpriteIndex, FocusMenu eItemType, ObjectMenu * MenuPtr)
{
	// 위치
	m_dX = iPosX;
	m_dY = iPosY;
	// 스프라이트 번호
	m_iSpriteIndex = iSpriteIndex;
	// 오브젝트 범위
	m_dLeft = m_dX - g_cSprite->m_stpSprite[m_iSpriteIndex].iCenterPointX;
	m_dTop = m_dY - g_cSprite->m_stpSprite[m_iSpriteIndex].iCenterPointY;
	m_dRight = m_dLeft + g_cSprite->m_stpSprite[m_iSpriteIndex].iWidth;
	m_dBottom = m_dTop + g_cSprite->m_stpSprite[m_iSpriteIndex].iHeight;
	// 그리기 우선순위
	m_iRenderPriority = 0;
	// 항목 타입
	m_eItemType = eItemType;
	// 메뉴 포인터
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
	// 화면 기준으로 움직이는 UI
	// 카메라 좌표를 빼준다
	//--------------------------------------
	iMouseX = g_iMouseX - g_CameraRect.left;
	iMouseY = g_iMouseY - g_CameraRect.top;

	if (m_dLeft < iMouseX && iMouseX < m_dRight &&
		m_dTop < iMouseY && iMouseY < m_dBottom) {
		
		// 메뉴에 전달할 식별 타입
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
