#pragma once
#include "ObjectUI.h"

class ObjectMenuElement : public ObjectUI
{
public:
	ObjectMenuElement();
	virtual ~ObjectMenuElement();

	virtual bool Action();
	virtual void Draw();
	virtual bool Click();

	virtual void Move(int iMoveValueX, int iMoveValueY);

	virtual void SetPosition(int iPosX, int iPosY) = 0;

public:
	int m_iSpriteWidth;									// ��������Ʈ ���� ����
	int m_iSpriteHeight;								// ��������Ʈ ���� ����
};

