#pragma once
#include "ObjectMenuElement.h"

class ObjectMenuStageElement : public ObjectMenuElement
{
public:
	ObjectMenuStageElement(int iSpriteIndex, int iPosX, int iPosY, int * iScrollTopPtr, int * iScrollBottomPtr);
	virtual ~ObjectMenuStageElement();

	virtual bool Action();
	virtual void Draw();
	virtual bool Click();

	virtual void Move(int iMoveValueX, int iMoveValueY);

	virtual void SetPosition(int iPosX, int iPosY);

public:
	int m_iPropertiesCenterPointX;						// 加己 吝痢 谅钎 X
	int m_iPropertiesCenterPointY;						// 加己 吝痢 谅钎 Y
	int m_iPropertiesSizeX;								// 加己 农扁 X
	int m_iPropertiesSizeY;								// 加己 农扁 Y

	int * m_iScrollTopPtr;								// 胶农费 困
	int * m_iScrollBottomPtr;							// 胶农费 酒贰
};

