// 기명준
// 마우스 포인터 클래스
// 메뉴에서 선택한 오브젝트를 실제 생성하기전 보여주는 역할을 함

#pragma once
#include "Object.h"
class ObjectMousePointer : public Object
{
public:
	ObjectMousePointer(int iPosX, int iPosY);
	virtual ~ObjectMousePointer();

	virtual bool Action();
	virtual void Draw();
	virtual bool Click();

public:
	int m_iSpriteWidth;		// 화면에 출력할 스프라이트 가로 길이
	int m_iSpriteHeight;	// 화면에 출력할 스프라이트 세로 길이

	bool m_bRedOption;		// 빨간색 그리기 옵션 : true 빨간색, false 초록색
};

