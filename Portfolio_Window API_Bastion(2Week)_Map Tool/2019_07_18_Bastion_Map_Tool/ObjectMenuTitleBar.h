// 기명준
// 메뉴 타이틀 바
// 클릭시 상태 전달

#pragma once
#include "ObjectUI.h"

class ObjectMenu;

class ObjectMenuTitleBar : public ObjectUI
{
public:
	ObjectMenuTitleBar(DWORD dwRGBColor, int iPosX, int iPosY, int iWidth, int iHeight, double dCompose);
	virtual ~ObjectMenuTitleBar();

	virtual bool Action();
	virtual void Draw();
	virtual bool Click();

	virtual void Move(int iMoveValueX, int iMoveValueY);

private:
	DWORD m_dwRGBColor;

	int m_iWidth;
	int m_iHeight;
	
	double m_dCompose;
};

