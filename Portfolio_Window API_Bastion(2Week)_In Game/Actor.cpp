#include "stdafx.h"
#include "Actor.h"

void Actor::ImageInit()
{
}

void Actor::ImageFrameUpdate()
{
	// ���⿡ ���� �̹��� ������ Y��ǥ ����
	m_frameY = m_directionState;

	// �̹��� ������ ��������� �����ð��� ���� X��ǥ ����
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
