// 기명준
// 유닛
// 지형 위에 생성된 오브젝트들

#pragma once
#include "Object.h"

class ObjectUnit : public Object
{
public:
	ObjectUnit(int iType, int iSpriteIndex, int iPosX, int iPosY);
	virtual ~ObjectUnit();

	virtual bool Action();
	virtual void Draw();
	virtual bool Click();

	bool Erase(int iEraseX, int iEraseY);

private:

	bool m_bEraseFlag;		// 삭제 플래그
};

