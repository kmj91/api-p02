#include "stdafx.h"
#include "Actor.h"

void Actor::ImageInit()
{
}

void Actor::ImageFrameUpdate()
{
	// 방향에 따른 이미지 프레임 Y좌표 갱신
	m_frameY = m_directionState;

	// 이미지 프레임 변경까지의 지연시간에 따라 X좌표 갱신
	m_frameDelay++;
	if (m_frameDelay % m_frameDelayTime == 0)
	{
		m_frameDelay = 0;
		m_frameX = m_frameIndex++;
		if (m_frameIndex > m_image->getMaxFrameX())
		{
			m_frameIndex = 0;
			m_isAniFinish = true;
		}
	}
}

Actor::Actor()
{

}


Actor::~Actor()
{
}
