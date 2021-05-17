#pragma once
#include "Object.h"

class ObjectUI : public Object
{
public:
	ObjectUI();
	virtual ~ObjectUI();

	virtual bool Action();
	virtual void Draw();
	virtual bool Click();

	virtual void Move(int iMoveValueX, int iMoveValueY) = 0;	// �޴��� ������Ʈ ��� ���� �̵�
};

