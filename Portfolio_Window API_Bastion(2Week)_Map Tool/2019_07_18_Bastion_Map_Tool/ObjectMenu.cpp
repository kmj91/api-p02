// �����
// UI �޴� ���̾�α�
// �׸�� ����Ʈ�� ����

#include "stdafx.h"
#include "ObjectMenu.h"
#include "ObjectMenuTitleBar.h"
#include "ObjectMenuTile.h"
#include "ObjectMenuStage.h"
#include "ObjectMenuPlayer.h"
#include "ObjectMenuObject.h"
#include "ObjectMenuBroken.h"
#include "ObjectMenuEnemy.h"
#include "ObjectMenuElementList.h"


ObjectMenu::ObjectMenu(int iPosX, int iPosY)
{
	ObjectUI * newObject;
	// Ÿ��
	m_iType = df_TYPE_UI;
	// ��ġ
	m_dX = iPosX;
	m_dY = iPosY;
	// ���� ���� ����
	m_iWidth = 350;
	m_iHeight = 300;
	// ������Ʈ ����
	m_dLeft = m_dX;
	m_dTop = m_dY;
	m_dRight = m_dLeft + m_iWidth;
	m_dBottom = m_dTop + m_iHeight;
	// �׸��� �켱����
	m_iRenderPriority = df_RENDER_PRIORITY_LAST;
	// �޴� ������Ʈ ����Ʈ
	m_MenuObjectList = new CList<ObjectUI *>;

	//-------------------------------------
	// Ÿ��Ʋ ��
	//-------------------------------------
	newObject = new ObjectMenuTitleBar(0xff69c3e2, m_dX, m_dY, m_iWidth, 40, 0.8);
	m_MenuObjectList->push_back(newObject);

	//-------------------------------------
	// �޴�
	// ����Ʈ ����
	//-------------------------------------
	m_FocusMenu = FOCUS_MENU_TILE;
	m_ChangeMenu = FOCUS_MENU_EMPT;

	// Ÿ�� �޴�
	newObject = new ObjectMenuTile(m_dX + 5, m_dY + 45, this);
	m_MenuObjectList->push_back(newObject);
	// �������� �޴�
	newObject = new ObjectMenuStage(m_dX + 60, m_dY + 45, this);
	m_MenuObjectList->push_back(newObject);
	// �÷��̾� �޴�
	newObject = new ObjectMenuPlayer(m_dX + 115, m_dY + 45, this);
	m_MenuObjectList->push_back(newObject);
	// ��ü �޴�
	newObject = new ObjectMenuObject(m_dX + 170, m_dY + 45, this);
	m_MenuObjectList->push_back(newObject);
	// �μ����� ��ü �޴�
	newObject = new ObjectMenuBroken(m_dX + 225, m_dY + 45, this);
	m_MenuObjectList->push_back(newObject);
	// �� �޴�
	newObject = new ObjectMenuEnemy(m_dX + 280, m_dY + 45, this);
	m_MenuObjectList->push_back(newObject);

	//-------------------------------------
	// �޴� ��� ���
	//-------------------------------------
	m_MenuElementList = new ObjectMenuElementList(m_dX, m_dY + 80, m_iWidth, m_iHeight - 80);
	m_MenuObjectList->push_back(m_MenuElementList);
	g_TestObject = m_MenuElementList;

	// ����Ʈ ��� ����
	m_MenuElementList->ChangeElementList(m_FocusMenu);
}


ObjectMenu::~ObjectMenu()
{
	CList<ObjectUI*>::iterator iter;
	CList<ObjectUI*>::iterator iter_end;
	ObjectUI * ObjectTemp;

	//--------------------------------------
	// �޸� ����
	//--------------------------------------
	iter = m_MenuObjectList->begin();
	iter_end = m_MenuObjectList->end();
	while (iter != iter_end) {
		ObjectTemp = *iter;
		iter = m_MenuObjectList->erase(iter);
		delete ObjectTemp;
	}

	delete m_MenuObjectList;
}

bool ObjectMenu::Action()
{
	// ��ü�� �׸��� ������
	if (m_ChangeMenu != FOCUS_MENU_EMPT) {
		// ��ü
		m_FocusMenu = m_ChangeMenu;
		// ����Ʈ ��� ����
		m_MenuElementList->ChangeElementList(m_FocusMenu);
		m_ChangeMenu = FOCUS_MENU_EMPT;
	}

	return false;
}

// �޴� �ȿ� ���Ե� ��� UI ������Ʈ Draw ó��
void ObjectMenu::Draw()
{
	CList<ObjectUI*>::iterator iter;
	CList<ObjectUI*>::iterator iter_end;
	ObjectUI * ObjectTemp;

	// �޴� ����
	g_cSprite->DrawBackground(0xffffff, m_dX, m_dY, m_iWidth, m_iHeight, g_bypDest, g_iDestWidth, g_iDestHeight, g_iDestPitch, 0.5, false, true);
	
	// �޴� ���� ������Ʈ ó��
	iter = m_MenuObjectList->begin();
	iter_end = m_MenuObjectList->end();
	while (iter != iter_end) {
		ObjectTemp = *iter;
		if (ObjectTemp->Action()) {
			delete ObjectTemp;
		}
		ObjectTemp->Draw();
		++iter;
	}
}

// �޴� �ȿ� ���Ե� UI ������Ʈ�� Click ó��
// ��ȯ �� : UI ���� ���̶�� true �ٱ��̶�� false
bool ObjectMenu::Click()
{
	CList<ObjectUI*>::iterator iter;
	CList<ObjectUI*>::iterator iter_end;
	ObjectUI * ObjectTemp;
	int iMouseX;
	int iMouseY;

	//--------------------------------------
	// ȭ�� �������� �����̴� UI
	// ī�޶� ��ǥ�� ���ش�
	//--------------------------------------
	iMouseX = g_iMouseX - g_CameraRect.left;
	iMouseY = g_iMouseY - g_CameraRect.top;

	// �޴��� �簢�� ���� ���̶�� UI ������Ʈ ����Ʈ�� ���鼭 Click ó��
	if (m_dLeft < iMouseX && iMouseX < m_dRight &&
		m_dTop < iMouseY && iMouseY < m_dBottom) {

		iter = m_MenuObjectList->rbegin();
		iter_end = m_MenuObjectList->head();
		while (iter != iter_end) {
			ObjectTemp = *iter;
			if (ObjectTemp->Click()) {
				return true;
			}
			--iter;
		}
		return true;
	}

	return false;
}

// UI �޴� �̵� ó��
// �޴��� ���Ե� ��� UI ������Ʈ�鵵 ���� �̵� ó��
void ObjectMenu::Move(int iMoveValueX, int iMoveValueY)
{
	CList<ObjectUI*>::iterator iter;
	CList<ObjectUI*>::iterator iter_end;
	ObjectUI * ObjectTemp;

	// �޴� �̵�
	m_dX = m_dX - iMoveValueX;
	m_dY = m_dY - iMoveValueY;
	m_dLeft = m_dLeft - iMoveValueX;
	m_dTop = m_dTop - iMoveValueY;
	m_dRight = m_dRight - iMoveValueX;
	m_dBottom = m_dBottom - iMoveValueY;

	// �޴� �ȿ� ���Ե� UI ������Ʈ�鵵 �̵�
	iter = m_MenuObjectList->begin();
	iter_end = m_MenuObjectList->end();
	while (iter != iter_end) {
		ObjectTemp = *iter;
		ObjectTemp->Move(iMoveValueX, iMoveValueY);
		++iter;
	}
}

// ���콺 �����Ͱ� UI �޴� ���� �ȿ� �ִ��� �˻�
// ��ȯ �� : UI ���� ���̶�� true �ٱ��̶�� false
bool ObjectMenu::CheckOnMouse()
{
	int iMouseX;
	int iMouseY;

	//--------------------------------------
	// ȭ�� �������� �����̴� UI
	// ī�޶� ��ǥ�� ���ش�
	//--------------------------------------
	iMouseX = g_iMouseX - g_CameraRect.left;
	iMouseY = g_iMouseY - g_CameraRect.top;

	if (m_dLeft < iMouseX && iMouseX < m_dRight &&
		m_dTop < iMouseY && iMouseY < m_dBottom) {

		return true;
	}

	return false;
}
