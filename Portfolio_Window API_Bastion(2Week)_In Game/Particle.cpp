#include "stdafx.h"
#include "Particle.h"


HRESULT Particle::init()
{
	return S_OK;
}

HRESULT Particle::init(PARTICLE_TYPE _particleType)
{
	m_objectType = OBJECT_TYPE::OBJECT_PARTICLE;
	m_layerType = LAYER_TYPE::LAYER_PARTICLE;
	m_particleType = _particleType;
	m_isActive = true;

	switch (m_particleType)
	{
	case PARTICLE_TYPE::PARTICLE_LEAF1:
	case PARTICLE_TYPE::PARTICLE_LEAF2:
		m_position = { RND->getFromFloatTo(0,WINSIZEX), RND->getFromFloatTo(-1000,0) };
		m_image = IMAGEMANAGER->findImage_Particle(static_cast<int>(m_particleType));
		m_imageWidth = m_image->getFrameWidth();
		m_imageHeight = m_image->getFrameHeight();
		break;
	}// end of switch

	m_speed = 2.0f;
	m_angleSpeed = 0.f;

	m_alpha = 255;
	m_imageRect = RectMakeCenter(m_position.x, m_position.y, m_imageWidth, m_imageHeight);

	return S_OK;
}

void Particle::release()
{
}

void Particle::update()
{
	switch (m_particleType)
	{
	case PARTICLE_TYPE::PARTICLE_LEAF1:
	case PARTICLE_TYPE::PARTICLE_LEAF2:
	{
		m_angle += m_angleSpeed;
		m_angleSpeed = RND->getFromFloatTo(0.01f, 0.1f);

		m_position.x += cosf(m_angle) * m_speed;
		m_position.y += m_speed;

		if (m_position.y > WINSIZEY)
		{
			m_position.y = RND->getFromFloatTo(-1000.0f, 0.f);
			m_alpha = 255;
		}

		float height;
		if (m_position.y <= 0) height = 0;
		else height = m_position.y;

		m_alpha = 255 * (1 - (height / WINSIZEY));

		break;
	}
	}// end of switch

}

void Particle::render()
{
	ImageFrameUpdate();
	switch (m_particleType)
	{
	case PARTICLE_TYPE::PARTICLE_LEAF1:
	case PARTICLE_TYPE::PARTICLE_LEAF2:
	{
		// �̹��� �簢�� ����
		m_imageWidth = m_image->getFrameWidth();
		m_imageHeight = m_image->getFrameHeight();
		m_imageRect = RectMakeCenter(m_position.x, m_position.y, m_imageWidth, m_imageHeight);

		RENDER_INFO renderInfo;
		renderInfo = { (int)m_position.y, m_position, m_imageRect, m_imageWidth, m_imageHeight, m_image, m_frameX, m_frameY, m_alpha };
		CAMERAMANAGER->AddRenderInfo(m_layerType, renderInfo);
		break;
	}
	}// end of switch
}

void Particle::ImageInit()
{
	// ���� �ִϸ��̼� ���¶� ���� �ִϸ��̼� ���°� ������ �ִϸ��̼� ������ �̷������ �ʾ����Ƿ� ����
	if (m_prevAnimationState == m_animationState) return;

	// ������ �̷�����ٸ� ���� �ִϸ��̼� ���¸� ���� �ִϸ��̼� ���·� ����
	m_prevAnimationState = m_animationState;

	// �̹��� �ʱ�ȭ
	m_image = IMAGEMANAGER->findImage_Particle(static_cast<int>(m_particleType));

	// �̹��� ������ �ε����� �̹��� ������ �����ð� �ʱ�ȭ
	m_frameIndex = 0;
	m_frameX = m_frameIndex;
	m_frameDelay = 0;
}

Particle::Particle()
{
}


Particle::~Particle()
{
}
