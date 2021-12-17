// 기명준
// UI 메뉴 항목
// 메뉴의 하위 리스트에 들어가는 개별 요소를 대표하는 품목

#pragma once
#include "ObjectUI.h"

class ObjectMenu;

class ObjectMenuItem : public ObjectUI
{
public:
	ObjectMenuItem(int iPosX, int iPosY, int iSpriteIndex, FocusMenu eItemType, ObjectMenu * MenuPtr);
	virtual ~ObjectMenuItem();

	virtual bool Action();
	virtual void Draw();
	virtual bool Click();

	virtual void Move(int iMoveValueX, int iMoveValueY);

private:
	ObjectMenu * m_MenuPtr;			// 메뉴 포인터
	FocusMenu m_eItemType;			// 항목 식별 타입
};

