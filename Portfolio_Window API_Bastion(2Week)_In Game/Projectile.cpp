#include "stdafx.h"
#include "Projectile.h"

Projectile::Projectile()
{
}


Projectile::~Projectile()
{
}

void Projectile::ImageInit()
{
	// ���� �ִϸ��̼� ���¶� ���� �ִϸ��̼� ���°� ������ �ִϸ��̼� ������ �̷������ �ʾ����Ƿ� ����
	if (m_prevAnimationState == m_animationState) return;

	// ������ �̷�����ٸ� ���� �ִϸ��̼� ���¸� ���� �ִϸ��̼� ���·� ����
	m_prevAnimationState = m_animationState;

	// �̹��� �ʱ�ȭ
	m_image = IMAGEMANAGER->findImage_Projectile(static_cast<int>(m_projectileType));

	// �̹��� ������ �ε����� �̹��� ������ �����ð� �ʱ�ȭ
	m_frameIndex = 0;
	m_frameX = m_frameIndex;
	m_frameDelay = 0;
}
