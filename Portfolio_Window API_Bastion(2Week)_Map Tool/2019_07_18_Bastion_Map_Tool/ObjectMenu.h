// 기명준
// UI 메뉴 다이얼로그
// 항목과 리스트로 구성

#pragma once
#include "ObjectUI.h"

class ObjectMenuElementList;

class ObjectMenu : public ObjectUI
{
public:
	ObjectMenu(int iPosX, int iPosY);
	virtual ~ObjectMenu();

	virtual bool Action();
	virtual void Draw();
	virtual bool Click();

	virtual void Move(int iMoveValueX, int iMoveValueY);// 메뉴와 오브젝트 요소 전부 이동

	bool CheckOnMouse();		// 마우스가 올라와있나?

private:
	CList<ObjectUI *> *m_MenuObjectList;		// 메뉴 오브젝트 리스트, 메뉴 안에 들어가는 모든 UI 오브젝트들은 CList로 관리
	FocusMenu m_FocusMenu;						// 선택된 메뉴
	ObjectMenuElementList * m_MenuElementList;	// 메뉴 요소 리스트, 바로 접근할 수 있게 멤버 변수로 관리

public:
	int m_iWidth;								// 메뉴 너비
	int m_iHeight;								// 메뉴 높이

	FocusMenu m_ChangeMenu;						// 교체 메뉴
};

