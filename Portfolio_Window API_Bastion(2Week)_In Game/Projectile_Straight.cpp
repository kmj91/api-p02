#include "stdafx.h"
#include "Projectile_Straight.h"
#include "Character_PC.h"
#include "Enemy.h"
#include "Obstacle.h"

HRESULT Projectile_Straight::init()
{

	return S_OK;
}

HRESULT Projectile_Straight::init(PROJECTILE_TYPE _projectileType)
{
	m_objectType = OBJECT_TYPE::OBJECT_PROJECTILE;
	m_layerType = LAYER_TYPE::LAYER_ACTOR;
	m_projectileType = _projectileType;

	switch (m_projectileType)
	{
	case PROJECTILE_ARROW:
		m_speed = 10.0f;
		m_actionRange = 1000.0f;
		break;
	case PROJECTILE_BULLET_RED:
	case PROJECTILE_BULLET_GREEN:
	case PROJECTILE_BULLET_BLUE:
		m_speed = 10.0f;
		m_actionRange = 1000.0f;
	case PROJECTILE_AURA:
		m_speed = 10.0f;
		m_actionRange = 1000.0f;
		m_alpha = 150;
		break;
	default:
		break;
	}

	m_colliderWidth = m_colliderHeight = 50;
	m_colliderRect = RectMakeCenter(m_position.x, m_position.y, m_colliderWidth, m_colliderHeight);
	
	m_isActive = false;
	m_isAniFinish = true;

	m_userObjectType = OBJECT_TYPE::OBJECT_NONE;

	m_animationState = ANIMATION_STATE::IDLE;
	m_directionState = DIRECTION_STATE::DOWN;

	m_activePosition = { 0.f,0.f };

	m_attack = 0.f;
	m_angle = 0.f;

	return S_OK;
}



void Projectile_Straight::release()
{
}

void Projectile_Straight::update()
{
	StateProcess();
	ActionProcess();
}

void Projectile_Straight::render()
{
	ImageInit();
	ImageFrameUpdate();

	// �̹��� �簢�� ����
	m_imageWidth = m_image->getFrameWidth();
	m_imageHeight = m_image->getFrameHeight();
	m_imageRect = RectMakeCenter(m_position.x, m_position.y, m_imageWidth, m_imageHeight);

	RENDER_INFO renderInfo;
	renderInfo = { (int)m_position.y, m_position, m_imageRect, m_imageWidth, m_imageHeight, m_image, m_frameX, m_frameY, m_alpha };
	CAMERAMANAGER->AddRenderInfo(m_layerType, renderInfo);
}


void Projectile_Straight::StateProcess()
{
	// ������ ���� ���� ���� ����
	if (m_angle >= PI2) m_angle -= PI2; // ������ 360�̻��� ��쿡 ���� ����ó��

	if (15.5 * PI_8 <= m_angle && m_angle < PI2 || 0 <= m_angle && m_angle < 0.5 * PI_8) m_directionState = RIGHT;
	else if (0.5 * PI_8 <= m_angle && m_angle < 3.5 * PI_8) m_directionState = RIGHT_UP;
	else if (3.5 * PI_8 <= m_angle && m_angle < 4.5 * PI_8) m_directionState = UP;
	else if (4.5 * PI_8 <= m_angle && m_angle < 7.5 * PI_8) m_directionState = LEFT_UP;
	else if (7.5 * PI_8 <= m_angle && m_angle < 8.5 * PI_8) m_directionState = LEFT;
	else if (8.5 * PI_8 <= m_angle && m_angle < 11.5 * PI_8) m_directionState = LEFT_DOWN;
	else if (11.5 * PI_8 <= m_angle && m_angle < 12.5 * PI_8) m_directionState = DOWN;
	else if (12.5 * PI_8 <= m_angle && m_angle < 15.5 * PI_8) m_directionState = RIGHT_DOWN;
}

void Projectile_Straight::ActionProcess()
{
	// ��ǥ ����
	m_position.x += cosf(m_angle) * m_speed;
	m_position.y += -sinf(m_angle) * m_speed;

	switch (m_projectileType)
	{
	case PROJECTILE_TYPE::PROJECTILE_BULLET_RED:
	case PROJECTILE_TYPE::PROJECTILE_BULLET_BLUE:
	case PROJECTILE_TYPE::PROJECTILE_BULLET_GREEN:
	case PROJECTILE_TYPE::PROJECTILE_AURA:
		m_directionState = DIRECTION_STATE::DIRECTION_NONE;
		break;
	}

	// Ȱ������ üũ
	if (getDistance(m_activePosition.x, m_activePosition.y, m_position.x, m_position.y) > m_actionRange) m_isActive = false;

	// �浹ü �簢�� ����
	m_colliderRect = RectMakeCenter(m_position.x, m_position.y, m_colliderWidth, m_colliderHeight);


	// �浹ó��
	switch (m_userObjectType)
	{
	case OBJECT_PC:	// ����ü ����ڰ� �÷��̾��� ���
	{
		// ���� �浹üũ
		vector<Enemy*> enemyList = ENEMYMANAGER->getEnemyList();
		for (int i = 0; i < enemyList.size(); ++i)
		{
			if (!enemyList[i]->getIsActive()) continue;

			RECT temp;
			if (IntersectRect(&temp, &m_colliderRect, &enemyList[i]->getColliderRect()))
			{
				m_isActive = false;
				SKILLMANAGER->ActivateSkill("Skill_Projectile", this);
			}
		}

		// ��ֹ��� �浹üũ
		vector<Obstacle*> obstacleList = OBSTACLEMANAGER->getObstacleList();
		for (int i = 0; i < obstacleList.size(); ++i)
		{
			if (!obstacleList[i]->getIsActive()) continue;

			RECT temp;
			if (IntersectRect(&temp, &m_colliderRect, &obstacleList[i]->getColliderRect()))
			{
				m_isActive = false;
				SKILLMANAGER->ActivateSkill("Skill_Projectile", this);
			}
		}
		break;
	}
	case OBJECT_ENEMY:	// ����ü ����ڰ� ���� ���
	{
		// �÷��̾�� �浹üũ
		Character_PC* pc = (Character_PC*)CHARACTERMANAGER->FindCharacter(CHARACTER_TYPE::CHARACTER_KID);
		if (!pc->getIsActive()) return;

		RECT temp;
		if (IntersectRect(&temp, &m_colliderRect, &pc->getColliderRect()))
		{
			// �÷��̾ ī���� ������ ��쿣 �Ѿ��� �Ҹ����� �ʴ´�.
			if (pc->getAnimationState() != ANIMATION_STATE::COUNTER)
			{
				m_isActive = false;
				SKILLMANAGER->ActivateSkill("Skill_Projectile", this);
			}
		}
		break;
	}
	}
}


Projectile_Straight::Projectile_Straight()
{
}


Projectile_Straight::~Projectile_Straight()
{
}
