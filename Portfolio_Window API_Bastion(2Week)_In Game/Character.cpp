#include "stdafx.h"
#include "Character.h"


Character::Character()
{
}


Character::~Character()
{
}

void Character::ImageInit()
{
	// ���� �ִϸ��̼� ���¶� ���� �ִϸ��̼� ���°� ������ �ִϸ��̼� ������ �̷������ �ʾ����Ƿ� ����
	if (m_prevAnimationState == m_animationState) return;

	// ������ �̷�����ٸ� ���� �ִϸ��̼� ���¸� ���� �ִϸ��̼� ���·� ����
	m_prevAnimationState = m_animationState;

	// �̹��� �ʱ�ȭ
	m_image = IMAGEMANAGER->findImage_Character(static_cast<int>(m_characterType), static_cast<int>(m_animationState));

	// �̹��� ������ �ε����� �̹��� ������ �����ð� �ʱ�ȭ
	m_frameIndex = 0;
	m_frameX = m_frameIndex;
	m_frameDelay = 0;
}
