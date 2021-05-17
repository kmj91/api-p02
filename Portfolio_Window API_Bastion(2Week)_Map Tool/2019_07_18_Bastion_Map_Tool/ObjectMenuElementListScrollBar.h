#pragma once
#include "ObjectUI.h"

class ObjectMenuElementList;

class ObjectMenuElementListScrollBar : public ObjectUI
{
public:
	ObjectMenuElementListScrollBar(int iPosX, int iPosY, int iWidth, int iHeight, ObjectMenuElementList * MenuListPtr);
	virtual ~ObjectMenuElementListScrollBar();

	virtual bool Action();
	virtual void Draw();
	virtual bool Click();

	virtual void Move(int iMoveValueX, int iMoveValueY);

	void ScrollMove(int iMoveValueY);
	void ChangeScrollBarSize(int iScrollBarSize, bool bEmployScrollBar);

public:
	// ��ũ�� �� ����
	double m_dScrollBarLeft;
	double m_dScrollBarRight;
	double m_dScrollBarTop;
	double m_dScrollBarBottom;

private:
	int m_iWidth;								// ��ũ�� �� ���� �ʺ�
	int m_iHeight;								// ��ũ�� �� ���� ����
	int m_iScrollBarSize;						// ��ũ�� �� ũ��

	ObjectMenuElementList * m_MenuListPtr;		// �޴� ��� ������

	bool m_bEmployScrollBar;					// ��ũ�� �� ��� ����
};

