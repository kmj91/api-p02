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
	// 이전 애니메이션 상태랑 현재 애니메이션 상태가 같으면 애니메이션 변경이 이루어지지 않았으므로 리턴
	if (m_prevAnimationState == m_animationState) return;

	// 변경이 이루어졌다면 이전 애니메이션 상태를 현재 애니메이션 상태로 갱신
	m_prevAnimationState = m_animationState;

	// 이미지 초기화
	m_image = IMAGEMANAGER->findImage_Character(static_cast<int>(m_characterType), static_cast<int>(m_animationState));

	// 이미지 프레임 인덱스와 이미지 프레임 지연시간 초기화
	m_frameIndex = 0;
	m_frameX = m_frameIndex;
	m_frameDelay = 0;
}
