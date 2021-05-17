#include "stdafx.h"
#include "ObjectUnit.h"


ObjectUnit::ObjectUnit(int iType, int iSpriteIndex, int iPosX, int iPosY)
{
	// Ÿ��
	m_iType = iType;
	// ��ġ
	m_dX = iPosX;
	m_dY = iPosY;
	// ��������Ʈ ��ȣ
	m_iSpriteIndex = iSpriteIndex;
	// ������Ʈ ����
	m_dLeft = m_dX - g_cSprite->m_stpSprite[m_iSpriteIndex].iCenterPointX;
	m_dTop = m_dY - g_cSprite->m_stpSprite[m_iSpriteIndex].iCenterPointY;
	m_dRight = m_dLeft + g_cSprite->m_stpSprite[m_iSpriteIndex].iWidth;
	m_dBottom = m_dTop + g_cSprite->m_stpSprite[m_iSpriteIndex].iHeight;
	// �׸��� �켱����
	m_iRenderPriority = iPosY;
	// ����� �÷���
	m_bEraseFlag = false;
}


ObjectUnit::~ObjectUnit()
{
}

bool ObjectUnit::Action()
{
	// ����� �ɼ�
	if (m_bEraseFlag) {
		return true;
	}

	return false;
}

void ObjectUnit::Draw()
{
	g_cSprite->DrawSprite(m_iSpriteIndex, m_dX, m_dY, g_bypDest, g_iDestWidth, g_iDestHeight, g_iDestPitch);
}

bool ObjectUnit::Click()
{
	return false;
}

bool ObjectUnit::Erase(int iEraseX, int iEraseY)
{
	if (m_dLeft < iEraseX && iEraseX < m_dRight &&
		m_dTop < iEraseY && iEraseY < m_dBottom) {

		m_bEraseFlag = true;

		return true;
	}

	return false;
}
