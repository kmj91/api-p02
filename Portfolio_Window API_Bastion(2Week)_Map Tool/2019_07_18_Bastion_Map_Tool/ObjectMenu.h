// �����
// UI �޴� ���̾�α�
// �׸�� ����Ʈ�� ����

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

	virtual void Move(int iMoveValueX, int iMoveValueY);// �޴��� ������Ʈ ��� ���� �̵�

	bool CheckOnMouse();		// ���콺�� �ö���ֳ�?

private:
	CList<ObjectUI *> *m_MenuObjectList;		// �޴� ������Ʈ ����Ʈ, �޴� �ȿ� ���� ��� UI ������Ʈ���� CList�� ����
	FocusMenu m_FocusMenu;						// ���õ� �޴�
	ObjectMenuElementList * m_MenuElementList;	// �޴� ��� ����Ʈ, �ٷ� ������ �� �ְ� ��� ������ ����

public:
	int m_iWidth;								// �޴� �ʺ�
	int m_iHeight;								// �޴� ����

	FocusMenu m_ChangeMenu;						// ��ü �޴�
};

