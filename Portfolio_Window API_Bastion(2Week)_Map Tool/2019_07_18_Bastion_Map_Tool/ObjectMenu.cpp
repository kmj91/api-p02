// 기명준
// UI 메뉴 다이얼로그
// 항목과 리스트로 구성

#include "stdafx.h"
#include "ObjectMenu.h"
#include "ObjectMenuTitleBar.h"
#include "ObjectMenuItem.h"
#include "ObjectMenuElementList.h"


ObjectMenu::ObjectMenu(int iPosX, int iPosY)
{
	ObjectUI * newObject;
	// 타입
	m_iType = df_TYPE_UI;
	// 위치
	m_dX = iPosX;
	m_dY = iPosY;
	// 가로 세로 길이
	m_iWidth = 350;
	m_iHeight = 300;
	// 오브젝트 범위
	m_dLeft = m_dX;
	m_dTop = m_dY;
	m_dRight = m_dLeft + m_iWidth;
	m_dBottom = m_dTop + m_iHeight;
	// 그리기 우선순위
	m_iRenderPriority = df_RENDER_PRIORITY_LAST;

	//-------------------------------------
	// 타이틀 바
	//-------------------------------------
	newObject = new ObjectMenuTitleBar(0xff69c3e2, m_dX, m_dY, m_iWidth, 40, 0.8);
	m_MenuObjectList.push_back(newObject);

	//-------------------------------------
	// 메뉴
	// 디폴트 선택
	//-------------------------------------
	m_FocusMenu = FOCUS_MENU_TILE;
	m_ChangeMenu = FOCUS_MENU_EMPT;

	// 타일 메뉴
	newObject = new ObjectMenuItem(m_dX + 5, m_dY + 45, df_SPRITE_MENU_TILE, FOCUS_MENU_TILE, this);
	m_MenuObjectList.push_back(newObject);
	// 스테이지 메뉴
	newObject = new ObjectMenuItem(m_dX + 60, m_dY + 45, df_SPRITE_MENU_STAGE, FOCUS_MENU_STAGE, this);
	m_MenuObjectList.push_back(newObject);
	// 플레이어 메뉴
	newObject = new ObjectMenuItem(m_dX + 115, m_dY + 45, df_SPRITE_MENU_PLAYER, FOCUS_MENU_PLAYER, this);
	m_MenuObjectList.push_back(newObject);
	// 물체 메뉴
	newObject = new ObjectMenuItem(m_dX + 170, m_dY + 45, df_SPRITE_MENU_OBJECT, FOCUS_MENU_OBJECT, this);
	m_MenuObjectList.push_back(newObject);
	// 부셔지는 물체 메뉴
	newObject = new ObjectMenuItem(m_dX + 225, m_dY + 45, df_SPRITE_MENU_BROKEN, FOCUS_MENU_BROKEN, this);
	m_MenuObjectList.push_back(newObject);
	// 적 메뉴
	newObject = new ObjectMenuItem(m_dX + 280, m_dY + 45, df_SPRITE_MENU_ENEMY, FOCUS_MENU_ENEMY, this);
	m_MenuObjectList.push_back(newObject);

	//-------------------------------------
	// 메뉴 요소 목록
	//-------------------------------------
	m_MenuElementList = new ObjectMenuElementList(m_dX, m_dY + 80, m_iWidth, m_iHeight - 80);
	m_MenuObjectList.push_back(m_MenuElementList);
	g_TestObject = m_MenuElementList;

	// 리스트 요소 갱신
	m_MenuElementList->ChangeElementList(m_FocusMenu);
}


ObjectMenu::~ObjectMenu()
{
	CList<ObjectUI*>::iterator iter;
	CList<ObjectUI*>::iterator iter_end;

	//--------------------------------------
	// 메모리 정리
	//--------------------------------------
	iter = m_MenuObjectList.begin();
	iter_end = m_MenuObjectList.end();
	while (iter != iter_end) {
		delete *iter;
		iter = m_MenuObjectList.erase(iter);
	}
}

bool ObjectMenu::Action()
{
	// 교체할 항목이 있으면
	if (m_ChangeMenu != FOCUS_MENU_EMPT) {
		// 교체할 항목이 현재 포커스된 항목과 같으면 무시
		if (m_FocusMenu == m_ChangeMenu)
		{
			m_ChangeMenu = FOCUS_MENU_EMPT;
			return false;
		}
		
		// 교체
		m_FocusMenu = m_ChangeMenu;
		// 리스트 요소 갱신
		m_MenuElementList->ChangeElementList(m_FocusMenu);
		m_ChangeMenu = FOCUS_MENU_EMPT;
	}

	CList<ObjectUI*>::iterator iter;
	CList<ObjectUI*>::iterator iter_end;

	// 메뉴 내부 오브젝트 처리
	iter = m_MenuObjectList.begin();
	iter_end = m_MenuObjectList.end();
	while (iter != iter_end) {
		if ((*iter)->Action()) {
			delete *iter;
			iter = m_MenuObjectList.erase(iter);
			continue;
		}
		++iter;
	}

	return false;
}

// 메뉴 안에 포함된 모든 UI 오브젝트 Draw 처리
void ObjectMenu::Draw()
{
	CList<ObjectUI*>::iterator iter;
	CList<ObjectUI*>::iterator iter_end;

	// 메뉴 영역
	g_cSprite->DrawBackground(0xffffff, m_dX, m_dY, m_iWidth, m_iHeight, g_bypDest, g_iDestWidth, g_iDestHeight, g_iDestPitch, 0.5, false, true);
	
	// 메뉴 내부 오브젝트 처리
	iter = m_MenuObjectList.begin();
	iter_end = m_MenuObjectList.end();
	while (iter != iter_end) {
		(*iter)->Draw();
		++iter;
	}
}

// 메뉴 안에 포함된 UI 오브젝트들 Click 처리
// 반환 값 : UI 영역 안이라면 true 바깥이라면 false
bool ObjectMenu::Click()
{
	CList<ObjectUI*>::iterator iter;
	CList<ObjectUI*>::iterator iter_end;
	int iMouseX;
	int iMouseY;

	//--------------------------------------
	// 화면 기준으로 움직이는 UI
	// 카메라 좌표를 빼준다
	//--------------------------------------
	iMouseX = g_iMouseX - g_CameraRect.left;
	iMouseY = g_iMouseY - g_CameraRect.top;

	// 메뉴의 사각형 범위 안이라면 UI 오브젝트 리스트를 돌면서 Click 처리
	if (m_dLeft < iMouseX && iMouseX < m_dRight &&
		m_dTop < iMouseY && iMouseY < m_dBottom) {

		iter = m_MenuObjectList.rbegin();
		iter_end = m_MenuObjectList.head();
		while (iter != iter_end) {
			if ((*iter)->Click()) {
				return true;
			}
			--iter;
		}
		return true;
	}

	return false;
}

// UI 메뉴 이동 처리
// 메뉴에 포함된 모든 UI 오브젝트들도 같이 이동 처리
void ObjectMenu::Move(int iMoveValueX, int iMoveValueY)
{
	CList<ObjectUI*>::iterator iter;
	CList<ObjectUI*>::iterator iter_end;

	// 메뉴 이동
	m_dX = m_dX - iMoveValueX;
	m_dY = m_dY - iMoveValueY;
	m_dLeft = m_dLeft - iMoveValueX;
	m_dTop = m_dTop - iMoveValueY;
	m_dRight = m_dRight - iMoveValueX;
	m_dBottom = m_dBottom - iMoveValueY;

	// 메뉴 안에 포함된 UI 오브젝트들도 이동
	iter = m_MenuObjectList.begin();
	iter_end = m_MenuObjectList.end();
	while (iter != iter_end) {
		(*iter)->Move(iMoveValueX, iMoveValueY);
		++iter;
	}
}

// 마우스 포인터가 UI 메뉴 영역 안에 있는지 검사
// 반환 값 : UI 영역 안이라면 true 바깥이라면 false
bool ObjectMenu::CheckOnMouse()
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

		return true;
	}

	return false;
}
