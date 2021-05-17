#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::ImageInit()
{
	// ���� �ִϸ��̼� ���¶� ���� �ִϸ��̼� ���°� ������ �ִϸ��̼� ������ �̷������ �ʾ����Ƿ� ����
	if (m_prevAnimationState == m_animationState) return;

	// ������ �̷�����ٸ� ���� �ִϸ��̼� ���¸� ���� �ִϸ��̼� ���·� ����
	m_prevAnimationState = m_animationState;

	// �̹��� �ʱ�ȭ
	m_image = IMAGEMANAGER->findImage_Enemy(static_cast<int>(m_enemyType), static_cast<int>(m_animationState));

	// �̹��� ������ �ε����� �̹��� ������ �����ð� �ʱ�ȭ
	m_frameIndex = 0;
	m_frameX = m_frameIndex;
	m_frameDelay = 0;
}
