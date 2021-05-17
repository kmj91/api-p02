#pragma once
#include "Object.h"

typedef struct UI_Base
{
	POINTFLOAT position;	// UI 좌표
	image* image;			// UI 이미지
	RECT imageRect;			// UI 렌더용 사각형(그려야할 이미지의 좌상단 좌표를 알기위한 용도)
	RECT colliderRect;		// UI 충돌용 사각형
	int imageWidth;			// 이미지 가로크기
	int imageHeight;		// 이미지 세로크기
	int colliderWidth;		// 충돌체 가로크기
	int colliderHeight;		// 충돌체 세로크기
	bool isClick = false;	// 버튼 클릭여부
	float alpha = 0;			// 알파값
}UI_BASE;

class UI : 
	public Object
{
protected:
	UI_TYPE m_uiType;			// UI 타입
protected:
	bool m_isOpen;				// UI가 열렸는가
public:
	virtual HRESULT init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
public:
	UI_TYPE getUIType() { return m_uiType; }
	void setUIType(UI_TYPE _uiType) { m_uiType = _uiType; }

	bool getIsOpen() { return m_isOpen; }
	void setIsOpen(bool _isOpen) { m_isOpen = _isOpen; }
public:
	UI();
	virtual ~UI();
};

