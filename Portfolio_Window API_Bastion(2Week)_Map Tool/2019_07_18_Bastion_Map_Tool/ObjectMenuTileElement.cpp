#include "stdafx.h"
#include "ObjectMenuTileElement.h"


// �ε��� ��ȣ, ��ġ ��ǥ X, Y, ��ũ�� ���� TOP, BOTTOM
ObjectMenuTileElement::ObjectMenuTileElement(int iSpriteIndex, int iPosX, int iPosY, int * iScrollTopPtr, int * iScrollBottomPtr)
{
	// ��ġ
	m_dX = iPosX;
	m_dY = iPosY;
	// ��������Ʈ ��ȣ
	m_iSpriteIndex = iSpriteIndex;
	// ��������Ʈ ����
	m_iSpriteWidth = g_cSprite->m_stpSprite[m_iSpriteIndex].iWidth;
	m_iSpriteHeight = g_cSprite->m_stpSprite[m_iSpriteIndex].iHeight;
	// ���� ������
	// �ش� ��� ��������Ʈ �ε����� -100�� �� ���� ���� ����� Ÿ�� ��������Ʈ ��ȣ ��
	m_iPropertiesCenterPointX = g_cSprite->m_stpSprite[m_iSpriteIndex - 100].iCenterPointX / df_TILE_PROPERTIES_SIZE;
	m_iPropertiesCenterPointY = g_cSprite->m_stpSprite[m_iSpriteIndex - 100].iCenterPointY / df_TILE_PROPERTIES_SIZE;

	// ������Ʈ ����
	m_dLeft = m_dX - g_cSprite->m_stpSprite[m_iSpriteIndex].iCenterPointX;
	m_dTop = m_dY - g_cSprite->m_stpSprite[m_iSpriteIndex].iCenterPointY;
	m_dRight = m_dLeft + m_iSpriteWidth;
	m_dBottom = m_dTop + m_iSpriteHeight;
	// �׸��� �켱����
	m_iRenderPriority = 0;
	// ����Ʈ ��ũ�� ����
	m_iScrollTopPtr = iScrollTopPtr;
	m_iScrollBottomPtr = iScrollBottomPtr;
}


ObjectMenuTileElement::~ObjectMenuTileElement()
{
}

bool ObjectMenuTileElement::Action()
{
	return false;
}

void ObjectMenuTileElement::Draw()
{
	int iPosY;
	RECT SpriteCutOutRect;
	SpriteCutOutRect.left = 0;
	SpriteCutOutRect.top = 0;
	SpriteCutOutRect.right = 0;
	SpriteCutOutRect.bottom = 0;
	iPosY = m_dY;

	//--------------------------------------
	// ��� ��Ҵ� �޴� ����� ��������
	// ��ũ���� ���̸� ������
	//--------------------------------------

	// �޴��� ����� ����� ��ŭ ��������Ʈ�� �߶󳽴�
	// ��
	if (m_dTop < *m_iScrollTopPtr) {
		SpriteCutOutRect.top = *m_iScrollTopPtr - m_dTop;
		//--------------------------------------
		// ���� ��������Ʈ�� �߶� ���
		// ��������Ʈ ��� ��ġ�� �߶� ��ǥ���� �ؾߵǱ� ������ 
		// TOP���� ���� ��ġ�� �������ش� (m_iScrollTopPtr)
		//--------------------------------------
		iPosY = *m_iScrollTopPtr;
	}

	// �Ʒ�
	if (m_dBottom > *m_iScrollBottomPtr) {
		SpriteCutOutRect.bottom = m_dBottom - *m_iScrollBottomPtr;
	}

	g_cSprite->DrawCutOutImage(m_iSpriteIndex, m_dX, iPosY, g_bypDest, g_iDestWidth, g_iDestHeight, g_iDestPitch, SpriteCutOutRect, false);
}

bool ObjectMenuTileElement::Click()
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

		if (140 <= m_iSpriteIndex && m_iSpriteIndex <= 149) {
			g_MouseState = MOUSE_STATE_TILE_MAKE_4;
			g_MousePointer->m_iSpriteIndex = df_SPRITE_MAKE_TILE_SIZE_4;
			g_iPropertiesCenterPointX = m_iPropertiesCenterPointX;
			g_iPropertiesCenterPointY = m_iPropertiesCenterPointY;
			g_bypArrayMAkeTileProperties = g_byArrayMAkeTileProperties_4;
			g_iMakePropertiesSizeX = df_TILE_PROPERTIES_X;
			g_iMakePropertiesSizeY = df_TILE_PROPERTIES_Y;
		}
		// ���찳
		else if (m_iSpriteIndex == df_SPRITE_ERASE) {
			g_MouseState = MOUSE_STATE_ERASE;
			g_MousePointer->m_iSpriteIndex = df_SPRITE_MAKE_TILE_SIZE_4;
		}
		else {
			g_MouseState = MOUSE_STATE_TILE_MAKE_1;
			g_MousePointer->m_iSpriteIndex = df_SPRITE_MAKE_TILE_SIZE_1;
			g_iPropertiesCenterPointX = m_iPropertiesCenterPointX;
			g_iPropertiesCenterPointY = m_iPropertiesCenterPointY;
			g_bypArrayMAkeTileProperties = g_byArrayMAkeTileProperties_1;
			g_iMakePropertiesSizeX = df_TILE_PROPERTIES_X;
			g_iMakePropertiesSizeY = df_TILE_PROPERTIES_Y;
		}

		g_byCheckMakeProperties = 0;
		g_byCheckMapProperties = 1;

		g_iMakeTileIndex = m_iSpriteIndex - 100;
		return true;
	}

	return false;
}

void ObjectMenuTileElement::Move(int iMoveValueX, int iMoveValueY)
{
	m_dX = m_dX - iMoveValueX;
	m_dY = m_dY - iMoveValueY;
	m_dLeft = m_dLeft - iMoveValueX;
	m_dTop = m_dTop - iMoveValueY;
	m_dRight = m_dRight - iMoveValueX;
	m_dBottom = m_dBottom - iMoveValueY;
}

void ObjectMenuTileElement::SetPosition(int iPosX, int iPosY)
{
	// ��ġ
	m_dX = iPosX;
	m_dY = iPosY;
	// ������Ʈ ����
	m_dLeft = m_dX - g_cSprite->m_stpSprite[m_iSpriteIndex].iCenterPointX;
	m_dTop = m_dY - g_cSprite->m_stpSprite[m_iSpriteIndex].iCenterPointY;
	m_dRight = m_dLeft + m_iSpriteWidth;
	m_dBottom = m_dTop + m_iSpriteHeight;
}
