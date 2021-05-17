#pragma once
#include "Object.h"

typedef struct UI_Base
{
	POINTFLOAT position;	// UI ��ǥ
	image* image;			// UI �̹���
	RECT imageRect;			// UI ������ �簢��(�׷����� �̹����� �»�� ��ǥ�� �˱����� �뵵)
	RECT colliderRect;		// UI �浹�� �簢��
	int imageWidth;			// �̹��� ����ũ��
	int imageHeight;		// �̹��� ����ũ��
	int colliderWidth;		// �浹ü ����ũ��
	int colliderHeight;		// �浹ü ����ũ��
	bool isClick = false;	// ��ư Ŭ������
	float alpha = 0;			// ���İ�
}UI_BASE;

class UI : 
	public Object
{
protected:
	UI_TYPE m_uiType;			// UI Ÿ��
protected:
	bool m_isOpen;				// UI�� ���ȴ°�
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

