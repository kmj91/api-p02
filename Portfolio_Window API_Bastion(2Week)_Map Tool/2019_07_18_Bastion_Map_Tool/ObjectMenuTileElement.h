#pragma once
#include "ObjectMenuElement.h"

class ObjectMenuTileElement : public ObjectMenuElement
{
public:
	ObjectMenuTileElement(int iSpriteIndex, int iPosX, int iPosY, int * iScrollTopPtr, int * iScrollBottomPtr);
	virtual ~ObjectMenuTileElement();

	virtual bool Action();
	virtual void Draw();
	virtual bool Click();

	virtual void Move(int iMoveValueX, int iMoveValueY);

	virtual void SetPosition(int iPosX, int iPosY);

public:
	int m_iPropertiesCenterPointX;						// �Ӽ� ���� ��ǥ X
	int m_iPropertiesCenterPointY;						// �Ӽ� ���� ��ǥ Y

	int * m_iScrollTopPtr;								// ��ũ�� ��
	int * m_iScrollBottomPtr;							// ��ũ�� �Ʒ�
};

