// �����
// �޴� ���� ����Ʈ
// ������ �׸��� ��ҵ��� ������

#pragma once
#include "ObjectUI.h"

#include <vector>

using namespace std;

class ObjectMenuElement;
class ObjectMenuElementListScrollBar;
enum FocusMenu;

class ObjectMenuElementList : public ObjectUI
{
public:
	ObjectMenuElementList(int iPosX, int iPosY, int iWidth, int iHeight);
	virtual ~ObjectMenuElementList();

	virtual bool Action();
	virtual void Draw();
	virtual bool Click();

	virtual void Move(int iMoveValueX, int iMoveValueY);

	void ScrollMove(int iMoveValueY);
	void ChangeElementList(FocusMenu enFocusMenu);

private:
	void InitLayout(ObjectMenuElement** ObjectElementArray, int iSize,
		ObjectMenuElementListScrollBar * SetScrollBar);

private:
	CList<ObjectUI *> m_MenuElementObjectList;				// �޴� ��� ������Ʈ ����Ʈ (���� ����� ������Ʈ)
	vector<Object *> m_ObjectMenuTileElementArr;			// Ÿ�� ������ ������Ʈ ����
	vector<Object *> m_ObjectMenuStageElementArr;			// �������� ������ ������Ʈ ����
	vector<Object *> m_ObjectMenuPlayerElementArr;			// �÷��̾� ������ ������Ʈ ����
	vector<Object *> m_ObjectMenuObjectElementArr;			// ��ü ������ ������Ʈ ����
	vector<Object *> m_ObjectMenuBrokenElementArr;			// �μ����� ��ü ������ ������Ʈ ����
	vector<Object *> m_ObjectMenuEnemyElementArr;			// �� ������ ������Ʈ ����
	
	ObjectMenuElementListScrollBar * m_FocusScrollBar;		// ���� ��ũ�� ��
	ObjectMenuElementListScrollBar * m_TileScrollBar;		// Ÿ�� �޴� ��ũ�� ��
	ObjectMenuElementListScrollBar * m_StageScrollBar;		// �������� �޴� ��ũ�� ��
	ObjectMenuElementListScrollBar * m_PlayerScrollBar;		// �÷��̾� �޴� ��ũ�� ��
	ObjectMenuElementListScrollBar * m_ObjectScrollBar;		// ��ü �޴� ��ũ�� ��
	ObjectMenuElementListScrollBar * m_BrokenScrollBar;		// �μ����� ��ü �޴� ��ũ�� ��
	ObjectMenuElementListScrollBar * m_EnemyScrollBar;		// �� �޴� ��ũ�� ��

	int m_iScrollTop;										// ȭ����� ���� ��ũ�� ��
	int m_iScrollBottom;									// ȭ����� ���� ��ũ�� �Ʒ�
	int m_iElementListWidth;								// �޴� ��� ��� ���� ����
	int m_iElementListHeight;								// �޴� ��� ��� ���� ����
	double m_dScrollMoveValue;								// ��ũ�� �� �̵� ��
};