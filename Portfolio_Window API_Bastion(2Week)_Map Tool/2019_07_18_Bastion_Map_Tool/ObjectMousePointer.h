// �����
// ���콺 ������ Ŭ����
// �޴����� ������ ������Ʈ�� ���� �����ϱ��� �����ִ� ������ ��

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
	int m_iSpriteWidth;		// ȭ�鿡 ����� ��������Ʈ ���� ����
	int m_iSpriteHeight;	// ȭ�鿡 ����� ��������Ʈ ���� ����

	bool m_bRedOption;		// ������ �׸��� �ɼ� : true ������, false �ʷϻ�
};

