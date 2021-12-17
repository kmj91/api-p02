// �����
// UI �޴� �׸�
// �޴��� ���� ����Ʈ�� ���� ���� ��Ҹ� ��ǥ�ϴ� ǰ��

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
	ObjectMenu * m_MenuPtr;			// �޴� ������
	FocusMenu m_eItemType;			// �׸� �ĺ� Ÿ��
};

