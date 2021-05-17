#include "stdafx.h"
#include "ObjectSpriteCompose.h"


ObjectSpriteCompose::ObjectSpriteCompose(int iSpriteIndex, int iPosX, int iPosY, double dCompose)
{
	// ��ġ
	m_dX = iPosX;
	m_dY = iPosY;
	// ��������Ʈ ��ȣ
	m_iSpriteIndex = iSpriteIndex;
	// �ռ� ��
	m_dCompose = dCompose;
	// ������Ʈ ����
	m_dLeft = m_dX - g_cSprite->m_stpSprite[m_iSpriteIndex].iCenterPointX;
	m_dTop = m_dY - g_cSprite->m_stpSprite[m_iSpriteIndex].iCenterPointY;
	m_dRight = m_dLeft + g_cSprite->m_stpSprite[m_iSpriteIndex].iWidth;
	m_dBottom = m_dTop + g_cSprite->m_stpSprite[m_iSpriteIndex].iHeight;
	// �׸��� �켱����
	m_iRenderPriority = 0;
}


ObjectSpriteCompose::~ObjectSpriteCompose()
{
}

bool ObjectSpriteCompose::Action()
{
	return false;
}

void ObjectSpriteCompose::Draw()
{
	g_cSprite->DrawSpriteCompose(m_iSpriteIndex, m_dX, m_dY, g_bypDest, g_iDestWidth, g_iDestHeight, g_iDestPitch, m_dCompose);
}

bool ObjectSpriteCompose::Click()
{
	return false;
}
