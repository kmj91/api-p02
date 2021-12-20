// 기명준
// 메뉴 하위 리스트
// 선택한 항목의 요소들을 보여줌

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

	// 위치
	m_dX = iPosX;
	m_dY = iPosY;
	//-------------------------------------
	// 메뉴 요소 목록 가로 세로 길이
	// 스크롤바 가로 길이를 뺌
	//-------------------------------------
	m_iElementListWidth = iWidth - df_MENU_SCROLL_BAR_WIDTH;
	m_iElementListHeight = iHeight;
	// 오브젝트 범위
	m_dLeft = m_dX;
	m_dTop = m_dY;
	m_dRight = m_dLeft + iWidth;
	m_dBottom = m_dTop + iHeight;
	// 그리기 우선순위
	m_iRenderPriority = 0;

	//-------------------------------------
	// 메뉴 타일 아이콘 오브젝트
	// 벡터에 전부 번호 순으로 보관
	//-------------------------------------
	//-------------------------------------
	// 지우개
	newObject = new ObjectMenuTileElement(df_SPRITE_ERASE, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	//-------------------------------------

	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_0, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_1, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_2, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_3, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_4, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_5, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_6, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_7, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_8, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_9, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_10, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_11, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_12, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_13, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_14, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_15, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_16, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_17, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_18, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_19, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_20, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_21, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_22, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_23, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_24, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_25, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_26, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_27, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_28, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_29, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_30, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_31, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_32, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_33, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_34, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_35, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_36, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_37, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_38, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_39, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_40, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_41, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_42, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_43, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_44, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_45, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_46, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_47, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_48, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_55, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_56, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_57, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_58, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);
	newObject = new ObjectMenuTileElement(df_SPRITE_MENU_TILE_59, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuTileElementArr.push_back(newObject);


	//-------------------------------------
	// 메뉴 스테이지 아이콘 오브젝트
	// 벡터에 전부 번호 순으로 보관
	//-------------------------------------
	newObject = new ObjectMenuStageElement(df_SPRITE_MENU_STAGE_1, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuStageElementArr.push_back(newObject);
	newObject = new ObjectMenuStageElement(df_SPRITE_MENU_STAGE_2, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuStageElementArr.push_back(newObject);
	newObject = new ObjectMenuStageElement(df_SPRITE_MENU_STAGE_3, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuStageElementArr.push_back(newObject);
	newObject = new ObjectMenuStageElement(df_SPRITE_MENU_STAGE_4, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuStageElementArr.push_back(newObject);
	newObject = new ObjectMenuStageElement(df_SPRITE_MENU_STAGE_5, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuStageElementArr.push_back(newObject);
	newObject = new ObjectMenuStageElement(df_SPRITE_MENU_STAGE_6, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuStageElementArr.push_back(newObject);


	//-------------------------------------
	// 메뉴 플레이어 아이콘 오브젝트
	// 벡터에 전부 번호 순으로 보관
	//-------------------------------------
	newObject = new ObjectMenuPlayerElement(df_SPRITE_MENU_KID_WAKE_UP, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuPlayerElementArr.push_back(newObject);


	//-------------------------------------
	// 메뉴 물체 아이콘 오브젝트
	// 벡터에 전부 번호 순으로 보관
	//-------------------------------------
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_0, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_1, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_2, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_3, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_4, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_5, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_6, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_7, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_8, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_9, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_10, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_11, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_12, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_13, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_14, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_15, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_16, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_17, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_18, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_19, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_20, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_21, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_22, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_23, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_24, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_25, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_26, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_27, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);
	newObject = new ObjectMenuObjectElement(df_SPRITE_MENU_OBJECT_28, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuObjectElementArr.push_back(newObject);


	//-------------------------------------
	// 메뉴 부서지는 물체 아이콘 오브젝트
	// 벡터에 전부 번호 순으로 보관
	//-------------------------------------
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_27, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr.push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_28, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr.push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_29, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr.push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_30, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr.push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_31, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr.push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_32, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr.push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_33, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr.push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_34, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr.push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_35, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr.push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_36, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr.push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_37, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr.push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_38, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr.push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_39, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr.push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_40, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr.push_back(newObject);
	newObject = new ObjectMenuBrokenElement(df_SPRITE_MENU_BROKEN_41, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuBrokenElementArr.push_back(newObject);


	//-------------------------------------
	// 메뉴 적 아이콘 오브젝트
	// 벡터에 전부 번호 순으로 보관
	//-------------------------------------
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_0, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr.push_back(newObject);
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_1, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr.push_back(newObject);
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_2, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr.push_back(newObject);
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_3, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr.push_back(newObject);
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_4, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr.push_back(newObject);
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_5, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr.push_back(newObject);
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_6, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr.push_back(newObject);
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_7, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr.push_back(newObject);
	newObject = new ObjectMenuEnemyElement(df_SPRITE_MENU_ENEMY_8, m_dX, m_dY, &m_iScrollTop, &m_iScrollBottom);
	m_ObjectMenuEnemyElementArr.push_back(newObject);


	//-------------------------------------
	// 메뉴 리스트 스크롤 바
	//-------------------------------------
	m_TileScrollBar = new ObjectMenuElementListScrollBar(m_dRight - df_MENU_SCROLL_BAR_WIDTH, m_dTop, df_MENU_SCROLL_BAR_WIDTH, m_iElementListHeight, this);
	m_StageScrollBar = new ObjectMenuElementListScrollBar(m_dRight - df_MENU_SCROLL_BAR_WIDTH, m_dTop, df_MENU_SCROLL_BAR_WIDTH, m_iElementListHeight, this);
	m_PlayerScrollBar = new ObjectMenuElementListScrollBar(m_dRight - df_MENU_SCROLL_BAR_WIDTH, m_dTop, df_MENU_SCROLL_BAR_WIDTH, m_iElementListHeight, this);
	m_ObjectScrollBar = new ObjectMenuElementListScrollBar(m_dRight - df_MENU_SCROLL_BAR_WIDTH, m_dTop, df_MENU_SCROLL_BAR_WIDTH, m_iElementListHeight, this);
	m_BrokenScrollBar = new ObjectMenuElementListScrollBar(m_dRight - df_MENU_SCROLL_BAR_WIDTH, m_dTop, df_MENU_SCROLL_BAR_WIDTH, m_iElementListHeight, this);
	m_EnemyScrollBar = new ObjectMenuElementListScrollBar(m_dRight - df_MENU_SCROLL_BAR_WIDTH, m_dTop, df_MENU_SCROLL_BAR_WIDTH, m_iElementListHeight, this);
	// 기본 스크롤 타일메뉴
	m_FocusScrollBar = m_TileScrollBar;
	// 메뉴 스크롤 바 전역 변수로
	g_MenuElementListScrollBar = m_FocusScrollBar;

	// 스크롤 범위
	m_iScrollTop = m_dTop;
	m_iScrollBottom = m_dBottom;
}


ObjectMenuElementList::~ObjectMenuElementList()
{
	int iCnt;
	int iSize;
	Object * ObjectTemp;

	//--------------------------------------
	// 메모리 정리
	//--------------------------------------
	m_MenuElementObjectList.clear();

	// 타일 메모리 정리
	iSize = m_ObjectMenuTileElementArr.size();
	iCnt = 0;
	while (iCnt < iSize) {
		delete m_ObjectMenuTileElementArr[iCnt];
		++iCnt;
	}
	m_ObjectMenuTileElementArr.clear();


	// 스테이지 메모리 정리
	iSize = m_ObjectMenuStageElementArr.size();
	iCnt = 0;
	while (iCnt < iSize) {
		delete m_ObjectMenuStageElementArr[iCnt];
		++iCnt;
	}
	m_ObjectMenuStageElementArr.clear();


	// 플레이어 메모리 정리
	iSize = m_ObjectMenuPlayerElementArr.size();
	iCnt = 0;
	while (iCnt < iSize) {
		delete m_ObjectMenuPlayerElementArr[iCnt];
		++iCnt;
	}
	m_ObjectMenuPlayerElementArr.clear();


	// 물체 메모리 정리
	iSize = m_ObjectMenuObjectElementArr.size();
	iCnt = 0;
	while (iCnt < iSize) {
		delete m_ObjectMenuObjectElementArr[iCnt];
		++iCnt;
	}
	m_ObjectMenuObjectElementArr.clear();


	// 부서지는 물체 메모리 정리
	iSize = m_ObjectMenuBrokenElementArr.size();
	iCnt = 0;
	while (iCnt < iSize) {
		delete m_ObjectMenuBrokenElementArr[iCnt];
		++iCnt;
	}
	m_ObjectMenuBrokenElementArr.clear();


	// 적 메모리 정리
	iSize = m_ObjectMenuEnemyElementArr.size();
	iCnt = 0;
	while (iCnt < iSize) {
		delete m_ObjectMenuEnemyElementArr[iCnt];
		++iCnt;
	}
	m_ObjectMenuEnemyElementArr.clear();


	delete m_TileScrollBar;
	delete m_StageScrollBar;
	delete m_PlayerScrollBar;
	delete m_ObjectScrollBar;
	delete m_BrokenScrollBar;
	delete m_EnemyScrollBar;
}

bool ObjectMenuElementList::Action()
{
	CList<ObjectUI*>::iterator iter;
	CList<ObjectUI*>::iterator iter_end;

	// 스크롤 바
	m_FocusScrollBar->Action();

	// 스크롤 뷰 내부 오브젝트 처리
	iter = m_MenuElementObjectList.begin();
	iter_end = m_MenuElementObjectList.end();
	while (iter != iter_end) {
		if ((*iter)->Action()) {
			delete *iter;
			iter = m_MenuElementObjectList.erase(iter);
			continue;
		}
		++iter;
	}

	return false;
}

void ObjectMenuElementList::Draw()
{
	CList<ObjectUI*>::iterator iter;
	CList<ObjectUI*>::iterator iter_end;
	ObjectUI * pObjectUI;
	
	// 스크롤 바
	m_FocusScrollBar->Draw();

	// 스크롤 뷰 내부 오브젝트 그리기
	iter = m_MenuElementObjectList.begin();
	iter_end = m_MenuElementObjectList.end();
	while (iter != iter_end) {
		pObjectUI = *iter;

		// 오브젝트의 Bottom이 스크롤 뷰의 Top 작다면 Draw() 호출 X
		if (pObjectUI->m_dBottom < m_iScrollTop) {
			++iter;
			continue;
		}
		// 오브젝트의 Top이 스크롤 뷰의 Bottom 크다면 Draw() 호출 X
		else if (pObjectUI->m_dTop > m_iScrollBottom) {
			++iter;
			continue;
		}
		// 그리기
		pObjectUI->Draw();
		++iter;
	}
}

bool ObjectMenuElementList::Click()
{
	CList<ObjectUI*>::iterator iter;
	CList<ObjectUI*>::iterator iter_end;
	ObjectUI * pObjectUI;
	int iMouseX;
	int iMouseY;

	//--------------------------------------
	// 화면 기준으로 움직이는 UI
	// 카메라 좌표를 빼준다
	//--------------------------------------
	iMouseX = g_iMouseX - g_CameraRect.left;
	iMouseY = g_iMouseY - g_CameraRect.top;

	if (m_dLeft < iMouseX && iMouseX < m_dRight &&
		m_dTop < iMouseY && iMouseY < m_dBottom) {

		m_FocusScrollBar->Click();

		iter = m_MenuElementObjectList.rbegin();
		iter_end = m_MenuElementObjectList.head();
		while (iter != iter_end) {
			pObjectUI = *iter;
			if (pObjectUI->Click()) {
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

	// 스크롤 범위
	m_iScrollTop = m_dTop;
	m_iScrollBottom = m_dBottom;

	// 스크롤 바
	m_TileScrollBar->Move(iMoveValueX, iMoveValueY);
	m_StageScrollBar->Move(iMoveValueX, iMoveValueY);
	m_PlayerScrollBar->Move(iMoveValueX, iMoveValueY);
	m_ObjectScrollBar->Move(iMoveValueX, iMoveValueY);
	m_BrokenScrollBar->Move(iMoveValueX, iMoveValueY);
	m_EnemyScrollBar->Move(iMoveValueX, iMoveValueY);

	iter = m_MenuElementObjectList.begin();
	iter_end = m_MenuElementObjectList.end();
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

	iter = m_MenuElementObjectList.begin();
	iter_end = m_MenuElementObjectList.end();
	while (iter != iter_end) {
		ObjectTemp = *iter;
		ObjectTemp->Move(0, iMoveValue);
		++iter;
	}
}

// 하위 리스트 요소 교체
// enFocusMenu : 교체할 항목
void ObjectMenuElementList::ChangeElementList(FocusMenu enFocusMenu)
{
	int iSize;				// 요소 총 개수
	ObjectMenuElement ** ObjectElementArray;

	// 리스트 비우기
	m_MenuElementObjectList.clear();

	//--------------------------------------
	// 메뉴 요소 목록
	// 매개변수로 요청받은 타입으로
	// 리스트 다시 채움
	//--------------------------------------
	switch (enFocusMenu)
	{
	case FOCUS_MENU_TILE:
		// 스크롤 바 교체
		m_FocusScrollBar = m_TileScrollBar;
		// 메뉴 스크롤 바 전역 변수로
		g_MenuElementListScrollBar = m_FocusScrollBar;
		// 타일 아이콘 오브젝트 배열
		ObjectElementArray = (ObjectMenuElement**)m_ObjectMenuTileElementArr.data();
		// 크기
		iSize = m_ObjectMenuTileElementArr.size();
		// 요소가 하나도 없음
		if (iSize == 0) {
			m_FocusScrollBar->ChangeScrollBarSize(0, false);
			break;
		}

		// 레이아웃 초기화
		InitLayout(ObjectElementArray, iSize, m_FocusScrollBar);

		// 스크롤 위치로 목록 요소 재 배치
		ScrollMove(m_iScrollTop - m_FocusScrollBar->m_dScrollBarTop);

		break;
	case FOCUS_MENU_STAGE:
		// 스크롤 바 교체
		m_FocusScrollBar = m_StageScrollBar;
		// 메뉴 스크롤 바 전역 변수로
		g_MenuElementListScrollBar = m_FocusScrollBar;
		// 타일 아이콘 오브젝트 배열
		ObjectElementArray = (ObjectMenuElement**)m_ObjectMenuStageElementArr.data();
		// 크기
		iSize = m_ObjectMenuStageElementArr.size();
		// 요소가 하나도 없음
		if (iSize == 0) {
			m_FocusScrollBar->ChangeScrollBarSize(0, false);
			break;
		}

		// 레이아웃 초기화
		InitLayout(ObjectElementArray, iSize, m_FocusScrollBar);

		// 스크롤 위치로 목록 요소 재 배치
		ScrollMove(m_iScrollTop - m_FocusScrollBar->m_dScrollBarTop);

		break;
	case FOCUS_MENU_PLAYER:
		// 스크롤 바 교체
		m_FocusScrollBar = m_PlayerScrollBar;
		// 메뉴 스크롤 바 전역 변수로
		g_MenuElementListScrollBar = m_FocusScrollBar;
		// 플레이어 아이콘 오브젝트 배열
		ObjectElementArray = (ObjectMenuElement**)m_ObjectMenuPlayerElementArr.data();
		// 크기
		iSize = m_ObjectMenuPlayerElementArr.size();
		// 요소가 하나도 없음
		if (iSize == 0) {
			m_FocusScrollBar->ChangeScrollBarSize(0, false);
			break;
		}

		// 레이아웃 초기화
		InitLayout(ObjectElementArray, iSize, m_FocusScrollBar);

		// 스크롤 위치로 목록 요소 재 배치
		ScrollMove(m_iScrollTop - m_FocusScrollBar->m_dScrollBarTop);

		break;
	case FOCUS_MENU_OBJECT:
		// 스크롤 바 교체
		m_FocusScrollBar = m_ObjectScrollBar;
		// 메뉴 스크롤 바 전역 변수로
		g_MenuElementListScrollBar = m_FocusScrollBar;
		// 물체 아이콘 오브젝트 배열
		ObjectElementArray = (ObjectMenuElement**)m_ObjectMenuObjectElementArr.data();
		// 크기
		iSize = m_ObjectMenuObjectElementArr.size();
		// 요소가 하나도 없음
		if (iSize == 0) {
			m_FocusScrollBar->ChangeScrollBarSize(0, false);
			break;
		}

		// 레이아웃 초기화
		InitLayout(ObjectElementArray, iSize, m_FocusScrollBar);

		// 스크롤 위치로 목록 요소 재 배치
		ScrollMove(m_iScrollTop - m_FocusScrollBar->m_dScrollBarTop);

		break;
	case FOCUS_MENU_BROKEN:
		// 스크롤 바 교체
		m_FocusScrollBar = m_BrokenScrollBar;
		// 메뉴 스크롤 바 전역 변수로
		g_MenuElementListScrollBar = m_FocusScrollBar;
		// 부서지는 물체 아이콘 오브젝트 배열
		ObjectElementArray = (ObjectMenuElement**)m_ObjectMenuBrokenElementArr.data();
		// 크기
		iSize = m_ObjectMenuBrokenElementArr.size();
		// 요소가 하나도 없음
		if (iSize == 0) {
			m_FocusScrollBar->ChangeScrollBarSize(0, false);
			break;
		}

		// 레이아웃 초기화
		InitLayout(ObjectElementArray, iSize, m_FocusScrollBar);

		// 스크롤 위치로 목록 요소 재 배치
		ScrollMove(m_iScrollTop - m_FocusScrollBar->m_dScrollBarTop);

		break;
	case FOCUS_MENU_ENEMY:
		// 스크롤 바 교체
		m_FocusScrollBar = m_EnemyScrollBar;
		// 메뉴 스크롤 바 전역 변수로
		g_MenuElementListScrollBar = m_FocusScrollBar;
		// 플레이어 아이콘 오브젝트 배열
		ObjectElementArray = (ObjectMenuElement**)m_ObjectMenuEnemyElementArr.data();
		// 크기
		iSize = m_ObjectMenuEnemyElementArr.size();
		// 요소가 하나도 없음
		if (iSize == 0) {
			m_FocusScrollBar->ChangeScrollBarSize(0, false);
			break;
		}

		// 레이아웃 초기화
		InitLayout(ObjectElementArray, iSize, m_FocusScrollBar);

		// 스크롤 위치로 목록 요소 재 배치
		ScrollMove(m_iScrollTop - m_FocusScrollBar->m_dScrollBarTop);

		break;
	case FOCUS_MENU_EMPT:
		break;
	default:
		break;
	}
}

// 레이아웃 초기화
// ObjectElementArray : 요소 배열
// iSize : 배열 크기
// SetScrollBar : 스크롤 바 포인터
void ObjectMenuElementList::InitLayout(ObjectMenuElement** ObjectElementArray, int iSize,
	ObjectMenuElementListScrollBar * SetScrollBar)
{
	int iCnt;				// 반복문 카운트
	int iLineFeedCnt;		// 메뉴 요소 줄바꿈 카운트
	int iScrollBarSize;		// 메뉴 요소 세로축 사이즈에 비례한 스크롤 크기
	int iScrollMoveValue;	// 스크롤 이동 값
	int iPosX;				// 아이콘 위치 X
	int iPosY;				// 아이콘 위치 Y
	int iWidth;				// 아이콘 가로 길이
	int iHeight;			// 아이콘 세로 길이
	int iCntWidth;			// 뷰포트에 보여질 수 있는 요소 가로 개수
	int iCntHeight;			// 뷰포트에 보여질 수 있는 요소 세로 개수

	// 처음 아이콘 위치
	iPosX = 5;
	iPosY = 5;

	// 아이콘 가로 세로 길이 5는 아이콘 사이의 간격
	iWidth = 5 + ObjectElementArray[0]->m_iSpriteWidth;
	iHeight = 5 + ObjectElementArray[0]->m_iSpriteHeight;

	// 위에서 구한 아이콘 길이를 리스트 길이와 나누어서 뷰포트에 보여질 수 있는 아이콘의 개수를 구함
	iCntWidth = m_iElementListWidth / iWidth;
	iCntHeight = m_iElementListHeight / iHeight;

	// 반복문을 돌면서 간격에 맞게 아이콘들의 위치 좌표 설정
	iCnt = 0;
	iLineFeedCnt = 1;
	while (iCnt < iSize) {
		// 뷰포트 가로 길이를 넘어가면 다음 줄로 좌표 이동
		if (iPosX + iWidth >= m_iElementListWidth) {
			iPosX = 5;
			iPosY = iPosY + iHeight;
			// 줄바꿈 카운트 증가
			++iLineFeedCnt;
		}

		// 아이콘 위치 좌표 설정
		ObjectElementArray[iCnt]->SetPosition(m_dX + iPosX, m_dY + iPosY);
		// 다음 아이콘 좌표로 이동
		iPosX = iPosX + iWidth;
		// 화면에 출력할 리스트에 저장
		m_MenuElementObjectList.push_back(ObjectElementArray[iCnt]);

		++iCnt;
	}

	// 스크롤 이동 값
	m_dScrollMoveValue = (double)iLineFeedCnt / (double)iCntHeight;

	// 스크롤 바 세로 길이 계산
	// 작거나 같으면 뷰포트 높이 그대로
	if (iLineFeedCnt <= iCntHeight) {
		iScrollBarSize = m_iElementListHeight;
	}
	// 크면 뷰포트 높이를 나눠서 스크롤 바 세로 길이를 일정 비율로 줄임
	else {
		if (m_dScrollMoveValue < 2){
			iScrollBarSize = m_iElementListHeight / 2;
		}
		else {
			iScrollBarSize = m_iElementListHeight / m_dScrollMoveValue;
		}
		
	}

	// 위에서 계산한 스크롤 바 세로 길이가 뷰포트 세로 길이와 다르면 표시
	if (iScrollBarSize != m_iElementListHeight) {
		// 활성화
		m_FocusScrollBar->ChangeScrollBarSize(iScrollBarSize, true);
	}
	// 같으면 표시하지 않음
	else {
		// 비활성화
		m_FocusScrollBar->ChangeScrollBarSize(iScrollBarSize, false);
	}
}
