#include "stdafx.h"
#include "ObjectMenuElementList.h"
#include "ObjectMenuElementListScrollBar.h"
#include "ObjectMenuTileElement.h"
#include "ObjectMenuStageElement.h"
#include "ObjectMenuPlayerElement.h"
#include "ObjectMenuObjectElement.h"
#include "ObjectMenuBrokenElement.h"
#include "ObjectMenuEnemyElement.h"


ObjectMenuElementList::ObjectMenuElementList(int iPosX, int iPosY, int iWidth, int iHeight)
{
	Object * newObject;

	// ��ġ
	m_dX = iPosX;
	m_dY = iPosY;
	//-------------------------------------
	// �޴� ��� ��� ���� ���� ����
	// ��ũ�ѹ� ���� ���̸� ��
	//-------------------------------------
	m_iElementListWidth = iWidth - df_MENU_SCROLL_BAR_WIDTH;
	m_iElementListHeight = iHeight;
	// ������Ʈ ����
	m_dLeft = m_dX;
	m_dTop = m_dY;
	m_dRight = m_dLeft + iWidth;
	m_dBottom = m_dTop + iHeight;
	// �׸��� �켱����
	m_iRenderPriority = 0;


	// �޴� ��� ������Ʈ ����Ʈ (���� ����� ������Ʈ)
	m_MenuElementObjectList = new CList<ObjectUI *>;

	//-------------------------------------
	// �޴� Ÿ�� ������ ������Ʈ
	// ���Ϳ� ���� ��ȣ ������ ����
	//-------------------------------------
	m_ObjectMenuTileElementArr = new vector<Object *>;
	//-------------------------------------
	// ���찳
	newObject = new ObjectMenuTileElement(df_SPRITE_ERASE, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	//-------------------------------------

	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_0, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_1, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_2, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_3, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_4, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_5, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_6, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_7, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_8, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_9, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_10, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_11, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_12, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_13, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_14, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_15, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_16, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_17, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_18, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_19, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_20, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_21, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_22, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_23, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_24, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_25, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_26, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_27, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_28, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_29, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_30, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_31, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_32, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_33, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_34, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_35, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_36, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_37, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_38, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_39, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_40, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_41, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_42, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_43, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_44, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_45, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_46, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_47, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_48, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_55, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_56, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_57, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_58, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_59, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr->push_back(newObject);


	//-------------------------------------
	// �޴� �������� ������ ������Ʈ
	// ���Ϳ� ���� ��ȣ ������ ����
	//-------------------------------------
	m_ObjectMenuStageElementArr = new vector<Object *>;
	newObject = new ObjectMenuStageElement(df_SPRITE_MENU_STAGE_1, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuStageElementArr->push_back(newObject);
	newObject = new ObjectMenuStageElement(df_SPRITE_MENU_STAGE_2, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuStageElementArr->push_back(newObject);
	newObject = new ObjectMenuStageElement(df_SPRITE_MENU_STAGE_3, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuStageElementArr->push_back(newObject);
	newObject = new ObjectMenuStageElement(df_SPRITE_MENU_STAGE_4, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuStageElementArr->push_back(newObject);
	newObject = new ObjectMenuStageElement(df_SPRITE_MENU_STAGE_5, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuStageElementArr->push_back(newObject);
	newObject = new ObjectMenuStageElement(df_SPRITE_MENU_STAGE_6, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuStageElementArr->push_back(newObject);


	//-------------------------------------
	// �޴� �÷��̾� ������ ������Ʈ
	// ���Ϳ� ���� ��ȣ ������ ����
	//-------------------------------------
	m_ObjectMenuPlayerElementArr = new vector<Object *>;
	newObject = new ObjectMenuPlayerElement(df_SPRITE_MENU_KID_WAKE_UP, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuPlayerElementArr->push_back(newObject);


	//-------------------------------------
	// �޴� ��ü ������ ������Ʈ
	// ���Ϳ� ���� ��ȣ ������ ����
	//-------------------------------------
	m_ObjectMenuObjectElementArr = new vector<Object *>;
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_0, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_1, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_2, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_3, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_4, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_5, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_6, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_7, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_8, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_9, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_10, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_11, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_12, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_13, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_14, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_15, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_16, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_17, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_18, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_19, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_20, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_21, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_22, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_23, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_24, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_25, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_26, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_27, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_28, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr->push_back(newObject);


	//-------------------------------------
	// �޴� �μ����� ��ü ������ ������Ʈ
	// ���Ϳ� ���� ��ȣ ������ ����
	//-------------------------------------
	m_ObjectMenuBrokenElementArr = new vector<Object *>;
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_27, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr->push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_28, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr->push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_29, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr->push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_30, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr->push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_31, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr->push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_32, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr->push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_33, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr->push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_34, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr->push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_35, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr->push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_36, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr->push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_37, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr->push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_38, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr->push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_39, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr->push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_40, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr->push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_41, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr->push_back(newObject);


	//-------------------------------------
	// �޴� �� ������ ������Ʈ
	// ���Ϳ� ���� ��ȣ ������ ����
	//-------------------------------------
	m_ObjectMenuEnemyElementArr = new vector<Object *>;
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_0, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr->push_back(newObject);
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_1, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr->push_back(newObject);
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_2, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr->push_back(newObject);
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_3, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr->push_back(newObject);
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_4, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr->push_back(newObject);
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_5, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr->push_back(newObject);
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_6, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr->push_back(newObject);
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_7, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr->push_back(newObject);
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_8, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr->push_back(newObject);


	//-------------------------------------
	// �޴� ����Ʈ ��ũ�� ��
	//-------------------------------------
	m_TileScrollBar = new ObjectMenuElementListScrollBar(m_dRight - df_MENU_SCROLL_BAR_WIDTH, m_dTop, df_MENU_SCROLL_BAR_WIDTH, m_iElementListHeight, this);
	m_StageScrollBar = new ObjectMenuElementListScrollBar(m_dRight - df_MENU_SCROLL_BAR_WIDTH, m_dTop, df_MENU_SCROLL_BAR_WIDTH, m_iElementListHeight, this);
	m_PlayerScrollBar = new ObjectMenuElementListScrollBar(m_dRight - df_MENU_SCROLL_BAR_WIDTH, m_dTop, df_MENU_SCROLL_BAR_WIDTH, m_iElementListHeight, this);
	m_ObjectScrollBar = new ObjectMenuElementListScrollBar(m_dRight - df_MENU_SCROLL_BAR_WIDTH, m_dTop, df_MENU_SCROLL_BAR_WIDTH, m_iElementListHeight, this);
	m_BrokenScrollBar = new ObjectMenuElementListScrollBar(m_dRight - df_MENU_SCROLL_BAR_WIDTH, m_dTop, df_MENU_SCROLL_BAR_WIDTH, m_iElementListHeight, this);
	m_EnemyScrollBar = new ObjectMenuElementListScrollBar(m_dRight - df_MENU_SCROLL_BAR_WIDTH, m_dTop, df_MENU_SCROLL_BAR_WIDTH, m_iElementListHeight, this);
	// �⺻ ��ũ�� Ÿ�ϸ޴�
	m_FocusScrollBar = m_TileScrollBar;
	// �޴� ��ũ�� �� ���� ������
	g_MenuElementListScrollBar = m_FocusScrollBar;

	// ��ũ�� ����
	m_iScrollTop = m_dTop;
	m_iScrollBottom = m_dBottom;
}


ObjectMenuElementList::~ObjectMenuElementList()
{
	int iCnt;
	int iSize;
	Object * ObjectTemp;

	//--------------------------------------
	// �޸� ����
	//--------------------------------------
	m_MenuElementObjectList->clear();
	delete m_MenuElementObjectList;

	// Ÿ�� �޸� ����
	iSize = m_ObjectMenuTileElementArr->size();
	iCnt = 0;
	while (iCnt < iSize) {
		delete (*m_ObjectMenuTileElementArr)[iCnt];
		++iCnt;
	}
	m_ObjectMenuTileElementArr->clear();
	delete m_ObjectMenuTileElementArr;


	// �������� �޸� ����
	iSize = m_ObjectMenuStageElementArr->size();
	iCnt = 0;
	while (iCnt < iSize) {
		delete (*m_ObjectMenuStageElementArr)[iCnt];
		++iCnt;
	}
	m_ObjectMenuStageElementArr->clear();
	delete m_ObjectMenuStageElementArr;


	// �÷��̾� �޸� ����
	iSize = m_ObjectMenuPlayerElementArr->size();
	iCnt = 0;
	while (iCnt < iSize) {
		delete (*m_ObjectMenuPlayerElementArr)[iCnt];
		++iCnt;
	}
	m_ObjectMenuPlayerElementArr->clear();
	delete m_ObjectMenuPlayerElementArr;


	// ��ü �޸� ����
	iSize = m_ObjectMenuObjectElementArr->size();
	iCnt = 0;
	while (iCnt < iSize) {
		delete (*m_ObjectMenuObjectElementArr)[iCnt];
		++iCnt;
	}
	m_ObjectMenuObjectElementArr->clear();
	delete m_ObjectMenuObjectElementArr;


	// �μ����� ��ü �޸� ����
	iSize = m_ObjectMenuBrokenElementArr->size();
	iCnt = 0;
	while (iCnt < iSize) {
		delete (*m_ObjectMenuBrokenElementArr)[iCnt];
		++iCnt;
	}
	m_ObjectMenuBrokenElementArr->clear();
	delete m_ObjectMenuBrokenElementArr;


	// �� �޸� ����
	iSize = m_ObjectMenuEnemyElementArr->size();
	iCnt = 0;
	while (iCnt < iSize) {
		delete (*m_ObjectMenuEnemyElementArr)[iCnt];
		++iCnt;
	}
	m_ObjectMenuEnemyElementArr->clear();
	delete m_ObjectMenuEnemyElementArr;


	delete m_TileScrollBar;
	delete m_StageScrollBar;
	delete m_PlayerScrollBar;
	delete m_ObjectScrollBar;
	delete m_BrokenScrollBar;
	delete m_EnemyScrollBar;
}

bool ObjectMenuElementList::Action()
{
	return false;
}

void ObjectMenuElementList::Draw()
{
	CList<ObjectUI*>::iterator iter;
	CList<ObjectUI*>::iterator iter_end;
	ObjectUI * ObjectTemp;

	
	// ��ũ�� ��
	m_FocusScrollBar->Action();
	m_FocusScrollBar->Draw();


	// �޴� ���� ������Ʈ ó��
	iter = m_MenuElementObjectList->begin();
	iter_end = m_MenuElementObjectList->end();
	while (iter != iter_end) {
		ObjectTemp = *iter;

		// �޴� ����Ʈ ��ũ�� ����� ��� ����
		if (ObjectTemp->m_dBottom < m_iScrollTop) {
			++iter;
			continue;
		}
		else if (ObjectTemp->m_dTop > m_iScrollBottom) {
			++iter;
			continue;
		}

		if (ObjectTemp->Action()) {
			delete ObjectTemp;
		}
		ObjectTemp->Draw();
		++iter;
	}
}

bool ObjectMenuElementList::Click()
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

	if (m_dLeft < iMouseX && iMouseX < m_dRight &&
		m_dTop < iMouseY && iMouseY < m_dBottom) {

		m_FocusScrollBar->Click();

		iter = m_MenuElementObjectList->rbegin();
		iter_end = m_MenuElementObjectList->head();
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

void ObjectMenuElementList::Move(int iMoveValueX, int iMoveValueY)
{
	CList<ObjectUI*>::iterator iter;
	CList<ObjectUI*>::iterator iter_end;
	ObjectUI * ObjectTemp;

	m_dX = m_dX - iMoveValueX;
	m_dY = m_dY - iMoveValueY;
	m_dLeft = m_dLeft - iMoveValueX;
	m_dTop = m_dTop - iMoveValueY;
	m_dRight = m_dRight - iMoveValueX;
	m_dBottom = m_dBottom - iMoveValueY;

	// ��ũ�� ����
	m_iScrollTop = m_dTop;
	m_iScrollBottom = m_dBottom;

	// ��ũ�� ��
	//m_FocusScrollBar->Move(iMoveValueX, iMoveValueY);
	m_TileScrollBar->Move(iMoveValueX, iMoveValueY);
	m_StageScrollBar->Move(iMoveValueX, iMoveValueY);
	m_PlayerScrollBar->Move(iMoveValueX, iMoveValueY);
	m_ObjectScrollBar->Move(iMoveValueX, iMoveValueY);
	m_BrokenScrollBar->Move(iMoveValueX, iMoveValueY);
	m_EnemyScrollBar->Move(iMoveValueX, iMoveValueY);

	iter = m_MenuElementObjectList->begin();
	iter_end = m_MenuElementObjectList->end();
	while (iter != iter_end) {
		ObjectTemp = *iter;
		ObjectTemp->Move(iMoveValueX, iMoveValueY);
		++iter;
	}
}


void ObjectMenuElementList::ScrollMove(int iMoveValueY)
{
	CList<ObjectUI*>::iterator iter;
	CList<ObjectUI*>::iterator iter_end;
	ObjectUI * ObjectTemp;
	int iMoveValue;

	iMoveValue = -(iMoveValueY * m_dScrollMoveValue);

	iter = m_MenuElementObjectList->begin();
	iter_end = m_MenuElementObjectList->end();
	while (iter != iter_end) {
		ObjectTemp = *iter;
		ObjectTemp->Move(0, iMoveValue);
		++iter;
	}
}

void ObjectMenuElementList::ChangeElementList(FocusMenu enFocusMenu)
{
	int iSize;				// ��� �� ����
	ObjectMenuElement ** ObjectElementArray;

	// ����Ʈ ����
	m_MenuElementObjectList->clear();

	//--------------------------------------
	// �޴� ��� ���
	// �Ű������� ��û���� Ÿ������
	// ����Ʈ �ٽ� ä��
	//--------------------------------------
	switch (enFocusMenu)
	{
	case FOCUS_MENU_TILE:
		// ��ũ�� �� ��ü
		m_FocusScrollBar = m_TileScrollBar;
		// �޴� ��ũ�� �� ���� ������
		g_MenuElementListScrollBar = m_FocusScrollBar;
		// Ÿ�� ������ ������Ʈ �迭
		ObjectElementArray = (ObjectMenuElement**)m_ObjectMenuTileElementArr->data();
		// ũ��
		iSize = m_ObjectMenuTileElementArr->size();
		// ��Ұ� �ϳ��� ����
		if (iSize == 0) {
			m_FocusScrollBar->ChangeScrollBarSize(0, false);
			break;
		}

		SetElementList(ObjectElementArray, iSize, m_FocusScrollBar);

		// ��ũ�� ��ġ�� ��� ��� �� ��ġ
		ScrollMove(m_iScrollTop - m_FocusScrollBar->m_dScrollBarTop);

		break;
	case FOCUS_MENU_STAGE:
		// ��ũ�� �� ��ü
		m_FocusScrollBar = m_StageScrollBar;
		// �޴� ��ũ�� �� ���� ������
		g_MenuElementListScrollBar = m_FocusScrollBar;
		// Ÿ�� ������ ������Ʈ �迭
		ObjectElementArray = (ObjectMenuElement**)m_ObjectMenuStageElementArr->data();
		// ũ��
		iSize = m_ObjectMenuStageElementArr->size();
		// ��Ұ� �ϳ��� ����
		if (iSize == 0) {
			m_FocusScrollBar->ChangeScrollBarSize(0, false);
			break;
		}

		SetElementList(ObjectElementArray, iSize, m_FocusScrollBar);

		// ��ũ�� ��ġ�� ��� ��� �� ��ġ
		ScrollMove(m_iScrollTop - m_FocusScrollBar->m_dScrollBarTop);

		break;
	case FOCUS_MENU_PLAYER:
		// ��ũ�� �� ��ü
		m_FocusScrollBar = m_PlayerScrollBar;
		// �޴� ��ũ�� �� ���� ������
		g_MenuElementListScrollBar = m_FocusScrollBar;
		// �÷��̾� ������ ������Ʈ �迭
		ObjectElementArray = (ObjectMenuElement**)m_ObjectMenuPlayerElementArr->data();
		// ũ��
		iSize = m_ObjectMenuPlayerElementArr->size();
		// ��Ұ� �ϳ��� ����
		if (iSize == 0) {
			m_FocusScrollBar->ChangeScrollBarSize(0, false);
			break;
		}

		SetElementList(ObjectElementArray, iSize, m_FocusScrollBar);

		// ��ũ�� ��ġ�� ��� ��� �� ��ġ
		ScrollMove(m_iScrollTop - m_FocusScrollBar->m_dScrollBarTop);

		break;
	case FOCUS_MENU_OBJECT:
		// ��ũ�� �� ��ü
		m_FocusScrollBar = m_ObjectScrollBar;
		// �޴� ��ũ�� �� ���� ������
		g_MenuElementListScrollBar = m_FocusScrollBar;
		// ��ü ������ ������Ʈ �迭
		ObjectElementArray = (ObjectMenuElement**)m_ObjectMenuObjectElementArr->data();
		// ũ��
		iSize = m_ObjectMenuObjectElementArr->size();
		// ��Ұ� �ϳ��� ����
		if (iSize == 0) {
			m_FocusScrollBar->ChangeScrollBarSize(0, false);
			break;
		}

		SetElementList(ObjectElementArray, iSize, m_FocusScrollBar);

		// ��ũ�� ��ġ�� ��� ��� �� ��ġ
		ScrollMove(m_iScrollTop - m_FocusScrollBar->m_dScrollBarTop);

		break;
	case FOCUS_MENU_BROKEN:
		// ��ũ�� �� ��ü
		m_FocusScrollBar = m_BrokenScrollBar;
		// �޴� ��ũ�� �� ���� ������
		g_MenuElementListScrollBar = m_FocusScrollBar;
		// �μ����� ��ü ������ ������Ʈ �迭
		ObjectElementArray = (ObjectMenuElement**)m_ObjectMenuBrokenElementArr->data();
		// ũ��
		iSize = m_ObjectMenuBrokenElementArr->size();
		// ��Ұ� �ϳ��� ����
		if (iSize == 0) {
			m_FocusScrollBar->ChangeScrollBarSize(0, false);
			break;
		}

		SetElementList(ObjectElementArray, iSize, m_FocusScrollBar);

		// ��ũ�� ��ġ�� ��� ��� �� ��ġ
		ScrollMove(m_iScrollTop - m_FocusScrollBar->m_dScrollBarTop);

		break;
	case FOCUS_MENU_ENEMY:
		// ��ũ�� �� ��ü
		m_FocusScrollBar = m_EnemyScrollBar;
		// �޴� ��ũ�� �� ���� ������
		g_MenuElementListScrollBar = m_FocusScrollBar;
		// �÷��̾� ������ ������Ʈ �迭
		ObjectElementArray = (ObjectMenuElement**)m_ObjectMenuEnemyElementArr->data();
		// ũ��
		iSize = m_ObjectMenuEnemyElementArr->size();
		// ��Ұ� �ϳ��� ����
		if (iSize == 0) {
			m_FocusScrollBar->ChangeScrollBarSize(0, false);
			break;
		}

		SetElementList(ObjectElementArray, iSize, m_FocusScrollBar);

		// ��ũ�� ��ġ�� ��� ��� �� ��ġ
		ScrollMove(m_iScrollTop - m_FocusScrollBar->m_dScrollBarTop);

		break;
	case FOCUS_MENU_EMPT:
		break;
	default:
		break;
	}
}

void ObjectMenuElementList::SetElementList(ObjectMenuElement** ObjectElementArray, int iSize,
	ObjectMenuElementListScrollBar * SetScrollBar)
{
	int iCnt;
	int iLineFeedCnt;		// �޴� ��� �ٹٲ�
	int iScrollBarSize;		// �޴� ��� ������ ����� ����� ��ũ�� ũ��
	int iScrollMoveValue;	// ��ũ�� �̵� ��
	int iPosX;				// ������ ��ġ X
	int iPosY;				// ������ ��ġ Y
	int iWidth;				// ���� ����
	int iHeight;			// ���� ����
	int iCntWidth;			// ��� ���� ����
	int iCntHeight;			// ��� ���� ����
	double dTemp;

	// ó�� ������ ��ġ
	iPosX = 5;
	iPosY = 5;

	iWidth = 5 + ObjectElementArray[0]->m_iSpriteWidth;
	iHeight = 5 + ObjectElementArray[0]->m_iSpriteHeight;

	iCntWidth = m_iElementListWidth / iWidth;
	iCntHeight = m_iElementListHeight / iHeight;

	iCnt = 0;
	iLineFeedCnt = 1;
	while (iCnt < iSize) {
		if (iPosX + iWidth >= m_iElementListWidth) {
			iPosX = 5;
			iPosY = iPosY + iHeight;
			++iLineFeedCnt;
		}

		ObjectElementArray[iCnt]->SetPosition(m_dX + iPosX, m_dY + iPosY);
		iPosX = iPosX + iWidth;

		m_MenuElementObjectList->push_back(ObjectElementArray[iCnt]);

		++iCnt;
	}

	// ��ũ�� �� ũ��
	if (iLineFeedCnt <= iCntHeight) {
		iScrollBarSize = m_iElementListHeight;
	}
	else {
		dTemp = (double)iLineFeedCnt / (double)iCntHeight;
		if (dTemp < 2){
			iScrollBarSize = m_iElementListHeight / 2;
		}
		else {
			iScrollBarSize = m_iElementListHeight / dTemp;
		}
		
	}

	// ��ũ�� �̵� ��
	m_dScrollMoveValue = (double)iLineFeedCnt / (double)iCntHeight;

	if (iScrollBarSize != m_iElementListHeight) {
		m_FocusScrollBar->ChangeScrollBarSize(iScrollBarSize, true);
	}
	else {
		m_FocusScrollBar->ChangeScrollBarSize(iScrollBarSize, false);
	}
}
