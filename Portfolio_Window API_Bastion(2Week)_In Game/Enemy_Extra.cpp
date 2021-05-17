#include "stdafx.h"
#include "Enemy_Extra.h"
#include "Character_PC.h"

HRESULT Enemy_Extra::init()
{
	m_objectType = OBJECT_TYPE::OBJECT_ENEMY;
	m_layerType = LAYER_TYPE::LAYER_ACTOR;

	switch (m_enemyType)
	{
	case ENEMY_URA_SWORD:
		m_maxAttackCount = 2;
		m_attack = 1.f;
		m_speed = 30.0f;
		m_maxHP = 100;
		m_approchRange = 400.0f;
		m_attackRange = 100.0f;
		m_moveTime = 3.0f;
		m_attackTime = 3.0f;
		m_colliderWidth = m_colliderHeight = 75;
		break;
	case ENEMY_URA_HALBERD:
		m_maxAttackCount = 1;
		m_attack = 1.f;
		m_speed = 30.0f;
		m_maxHP = 100;
		m_approchRange = 400.0f;
		m_attackRange = 100.0f;
		m_moveTime = 3.0f;
		m_attackTime = 3.0f;
		m_colliderWidth = m_colliderHeight = 75;
		break;
	case ENEMY_URA_CROSSBOW:
		m_maxAttackCount = 1;
		m_attack = 1.0f;
		m_speed = 30.0f;
		m_maxHP = 100;
		m_approchRange = 600.0f;
		m_attackRange = 500.0f;
		m_moveTime = 3.0f;
		m_attackTime = 3.0f;
		m_colliderWidth = m_colliderHeight = 75;
		break;
	case ENEMY_URA_RIFLE:
		m_maxAttackCount = 5;
		m_attack = 1.0f;
		m_speed = 30.0f;
		m_maxHP = 100;
		m_approchRange = 600.0f;
		m_attackRange = 500.0f;
		m_moveTime = 3.0f;
		m_attackTime = 3.0f;
		m_colliderWidth = m_colliderHeight = 75;
		break;
	case ENEMY_URA_BOSS:
		m_maxAttackCount = 2;
		m_attack = 5.0f;
		m_speed = 30.0f;
		m_maxHP = 500;
		m_approchRange = 400.0f;
		m_attackRange = 100.0f;
		m_moveTime = 2.0f;
		m_attackTime = 2.0f;
		m_colliderWidth = m_colliderHeight = 100;
		break;
	case ENEMY_PECKER:
		m_maxAttackCount = 1;
		m_attack = 1.f;
		m_speed = 5.0f;
		m_maxHP = 100;
		m_approchRange = 400.0f;
		m_attackRange = 100.0f;
		m_moveTime = 0.f;
		m_attackTime = 1.0f;
		m_colliderWidth = m_colliderHeight = 75;
		break;
	case ENEMY_RATTLE_TAIL:
		m_maxAttackCount = 1;
		m_attack = 1.f;
		m_speed = 3.0f;
		m_maxHP = 100;
		m_approchRange = 400.0f;
		m_attackRange = 100.0f;
		m_moveTime = 0.f;
		m_attackTime = 1.0f;
		m_colliderWidth = m_colliderHeight = 75;
		break;
	case ENEMY_TURRET:
		m_maxAttackCount = 1;
		m_attack = 1.f;
		m_speed = 0.f;
		m_maxHP = 100;
		m_approchRange = 0.f;
		m_attackRange = 500.0f;
		m_moveTime = 0.f;
		m_attackTime = 1.0f;
		m_colliderWidth = m_colliderHeight = 75;
		break;
	case ENEMY_MECHANICAL_PYTH:
		m_maxAttackCount = 5;
		m_attack = 1.f;
		m_speed = 3.0f;
		m_maxHP = 100;
		m_approchRange = 400.0f;
		m_attackRange = 100.0f;
		m_moveTime = 0.f;
		m_attackTime = 1.0f;
		m_colliderWidth = m_colliderHeight = 100;
		break;
	}

	m_animationState = ANIMATION_STATE::IDLE;
	m_directionState = DIRECTION_STATE::DOWN;

	m_colliderRect = RectMakeCenter(m_position.x, m_position.y, m_colliderWidth, m_colliderHeight);

	m_obtainEXP = 10;
	
	m_isActive = true;
	m_isAniFinish = true;

	m_curAttackCount = 0;
	m_isSetAttackCount = true;

	m_elapsedMoveTime = GetTickCount();
	m_elapsedAttackTime = GetTickCount();

	m_curHP = m_maxHP;
	m_angle = 12 * PI_8;

	STATUSBARMANAGER->CreateStateBar(STATUSBAR_TYPE::STATUSBAR_ENEMY, this);

	return S_OK;
}

void Enemy_Extra::release()
{

}

void Enemy_Extra::update()
{
	StateProcess();
	ActionProcess();
}

void Enemy_Extra::render()
{	
	ImageInit();
	ImageFrameUpdate();

	// 이미지 사각형 갱신
	m_imageWidth = m_image->getFrameWidth();
	m_imageHeight = m_image->getFrameHeight();
	m_imageRect = RectMakeCenter(m_position.x, m_position.y, m_imageWidth, m_imageHeight);

	RENDER_INFO renderInfo;

	// 적 랜더정보 전달
	renderInfo = { (int)m_position.y, m_position, m_imageRect, m_imageWidth, m_imageHeight, m_image, m_frameX, m_frameY };
	CAMERAMANAGER->AddRenderInfo(m_layerType, renderInfo);

	// 그림자 랜더정보 전달
	POINTFLOAT shadowPosition = { m_position.x,  m_colliderRect.bottom };
	image* shadowImage = IMAGEMANAGER->findImage("Shadow");
	int shadowWidth = shadowImage->getWidth();
	int shadowHeight = shadowImage->getHeight();
	RECT shadowImageRect = RectMakeCenter(shadowPosition.x, shadowPosition.y, shadowWidth, shadowHeight);

	renderInfo = { (int)shadowPosition.y, shadowPosition, shadowImageRect, shadowWidth, shadowHeight, shadowImage, 0, 0, 150 };
	CAMERAMANAGER->AddRenderInfo(LAYER_TYPE::LAYER_BACK_EFFECT, renderInfo);
}


void Enemy_Extra::StateProcess()
{
	Character* pc = CHARACTERMANAGER->FindCharacter(CHARACTER_TYPE::CHARACTER_KID);
	ANIMATION_STATE pcAnimationState = pc->getAnimationState();
	m_targetPosition = pc->getPosition();
	float distance = getDistance(m_position.x, m_position.y, m_targetPosition.x, m_targetPosition.y);


	// 자신과 타겟 사이의 거리에 따라 애니메이션 상태 갱신
	if (distance <= m_attackRange && m_isAniFinish && m_curAttackCount < m_maxAttackCount) // 자신과 타겟 사이의 거리가 공격범위보다 작으면 공격
	{
		if (!pc->getIsActive() || pcAnimationState == FALL || pcAnimationState == STAND_UP) return;
		m_isAniFinish = false;
		m_animationState = ATTACK;
		++m_curAttackCount;
		if (m_curAttackCount >= m_maxAttackCount) m_isSetAttackCount = false;

		// 적 타입에 따라 각각 다른 공격스킬을 사용
		switch (m_enemyType)
		{
		case ENEMY_URA_SWORD: 
			SKILLMANAGER->ActivateSkill("Skill_Smash", this);
			SOUNDMANAGER->play("Effect_Ura_Sword_Attack");
			break;
		case ENEMY_URA_HALBERD:  
			SKILLMANAGER->ActivateSkill("Skill_Smash", this);
			SOUNDMANAGER->play("Effect_Ura_Halberd_Attack");
			break;
		case ENEMY_URA_CROSSBOW:
			PROJECTILEMANAGER->ActivateProjectile(PROJECTILE_TYPE::PROJECTILE_ARROW, OBJECT_TYPE::OBJECT_ENEMY, m_position, m_angle, m_attack);
			SOUNDMANAGER->play("Effect_Ura_Crossbow_Attack");
			break;
		case ENEMY_URA_RIFLE:
			PROJECTILEMANAGER->ActivateProjectile(PROJECTILE_TYPE::PROJECTILE_BULLET_GREEN, OBJECT_TYPE::OBJECT_ENEMY, m_position, m_angle, m_attack);
			EFFECTMANAGER->ActivateEffect(EFFECT_TYPE::EFFECT_BULLET_FIRE_GREEN, PointFloatMake(m_position.x + cosf(m_angle) * 100, m_position.y + (-sinf(m_angle) * 100)), DIRECTION_STATE::DIRECTION_NONE);
			SOUNDMANAGER->play("Effect_Ura_Rifle_Attack");
			break;
		case ENEMY_URA_BOSS:
			SKILLMANAGER->ActivateSkill("Skill_Smash", this);
			SOUNDMANAGER->play("Effect_Ura_Boss_Attack");
			break;
		case ENEMY_PECKER:
			SKILLMANAGER->ActivateSkill("Skill_Smash", this);
			SOUNDMANAGER->play("Effect_Pecker_Attack");
			break;
		case ENEMY_RATTLE_TAIL:
			SKILLMANAGER->ActivateSkill("Skill_Tumbling", this);
			SOUNDMANAGER->play("Effect_RattleTail_Attack");
			break;
		case ENEMY_MECHANICAL_PYTH:
			SKILLMANAGER->ActivateSkill("Skill_Smash", this);
			EFFECTMANAGER->ActivateEffect(EFFECT_TYPE::EFFECT_BREATH, PointFloatMake(m_position.x + cosf(m_angle) * 200, m_position.y + (-sinf(m_angle) * 200)), m_directionState);
			SOUNDMANAGER->play("Effect_Mechanical_Pyth_Attack");
			break;
		case ENEMY_TURRET:
			PROJECTILEMANAGER->ActivateProjectile(PROJECTILE_TYPE::PROJECTILE_BULLET_BLUE, OBJECT_TYPE::OBJECT_ENEMY, m_position, m_angle, m_attack);
			EFFECTMANAGER->ActivateEffect(EFFECT_TYPE::EFFECT_BULLET_FIRE_BLUE, PointFloatMake(m_position.x + cosf(m_angle) * 100, m_position.y + (-sinf(m_angle) * 100)), DIRECTION_STATE::DIRECTION_NONE);
			SOUNDMANAGER->play("Effect_Turret_Attack");
			break;
		}
	}
	else if (m_attackRange < distance && distance <= m_approchRange && m_isAniFinish && m_moveList.empty()) // 자신과 타겟 사이의 거리가 접근범위보다 작으면 이동
	{
		if (!pc->getIsActive() || pcAnimationState == FALL || pcAnimationState == STAND_UP) return;
		if (m_animationState == ATTACK) m_animationState = IDLE;
		if (GetTickCount() - m_elapsedMoveTime >= 1000.0f * m_moveTime)
		{
			m_elapsedMoveTime = GetTickCount();
			m_animationState = MOVE;
			m_angle = UTIL::getAngle(m_position.x, m_position.y, m_targetPosition.x, m_targetPosition.y);
		}
	}
	else
	{
		if (m_isAniFinish)
		{
			m_animationState = IDLE;
		}
		if (!m_isSetAttackCount)
		{
			m_isSetAttackCount = true;
			m_elapsedAttackTime = GetTickCount();
		}
	}

	if (m_curHP <= 0)
	{
		m_curHP = 0;
		m_isActive = false;
		pc->setCurEXP(pc->getCurEXP() + m_obtainEXP);
	}


	if (m_angle >= PI2) m_angle -= PI2; // 각도가 360이상일 경우에 대한 예외처리
	// 각도에 따른 방향 상태 갱신 
	if (15.5 * PI_8 <= m_angle && m_angle < PI2 || 0 <= m_angle && m_angle < 0.5 * PI_8) m_directionState = RIGHT;
	else if (0.5 * PI_8 <= m_angle && m_angle < 3.5 * PI_8) m_directionState = RIGHT_UP;
	else if (3.5 * PI_8 <= m_angle && m_angle < 4.5 * PI_8) m_directionState = UP;
	else if (4.5 * PI_8 <= m_angle && m_angle < 7.5 * PI_8) m_directionState = LEFT_UP;
	else if (7.5 * PI_8 <= m_angle && m_angle < 8.5 * PI_8) m_directionState = LEFT;
	else if (8.5 * PI_8 <= m_angle && m_angle < 11.5 * PI_8) m_directionState = LEFT_DOWN;
	else if (11.5 * PI_8 <= m_angle && m_angle < 12.5 * PI_8) m_directionState = DOWN;
	else if (12.5 * PI_8 <= m_angle && m_angle < 15.5 * PI_8) m_directionState = RIGHT_DOWN;
}

void Enemy_Extra::ActionProcess()
{
	BYTE* tilePropertyInfo = TILEMANAGER->getTilePropertyInfo();
	int tilePropertyWidth = TILEMANAGER->getTilePropertyWidth();
	int x;
	int y;
	int index;

	// 애니메이션 상태에 따른 업데이트할 내용들 처리
	switch (m_animationState)
	{
	case IDLE:
		if (GetTickCount() - m_elapsedAttackTime >= 1000.0f * m_attackTime)
		{
			m_elapsedAttackTime = GetTickCount();
			m_curAttackCount = 0;
			m_angle = UTIL::getAngle(m_position.x, m_position.y, m_targetPosition.x, m_targetPosition.y); 	// 자신과 타겟 사이의 각도 셋팅
		}
		break;
	case MOVE:
	{
		m_position.x += cosf(m_angle) * m_speed;
		m_position.y += -sinf(m_angle) * m_speed;

		x = m_position.x / 25;
		y = (m_position.y + (m_colliderHeight / 2)) / 25;
		index = x + (y * tilePropertyWidth);

		switch (tilePropertyInfo[index])
		{
		case IMMOVABLE: case OBSTACLE:
			m_position.x -= cosf(m_angle) * m_speed;
			m_position.y -= -sinf(m_angle) * m_speed;
			break;
		}
		
		switch (m_enemyType)
		{
		case ENEMY_URA_CROSSBOW:
			EFFECTMANAGER->ActivateEffect(EFFECT_SPECTRUM_URA_CROSSBOW, m_position, m_directionState, 0.1f);
			if (!SOUNDMANAGER->isPlaySound("Effect_Ura_Move"))
			{
				SOUNDMANAGER->play("Effect_Ura_Move");
			}
			break;
		case ENEMY_URA_HALBERD:
			EFFECTMANAGER->ActivateEffect(EFFECT_SPECTRUM_URA_HALBERD, m_position, m_directionState, 0.1f);
			if (!SOUNDMANAGER->isPlaySound("Effect_Ura_Move"))
			{
				SOUNDMANAGER->play("Effect_Ura_Move");
			}
			break;
		case ENEMY_URA_SWORD:
			EFFECTMANAGER->ActivateEffect(EFFECT_SPECTRUM_URA_SWORD, m_position, m_directionState, 0.1f);
			if (!SOUNDMANAGER->isPlaySound("Effect_Ura_Move"))
			{
				SOUNDMANAGER->play("Effect_Ura_Move");
			}
			break;
		case ENEMY_URA_RIFLE:
			EFFECTMANAGER->ActivateEffect(EFFECT_SPECTRUM_URA_RIFLE, m_position, m_directionState, 0.1f);
			if (!SOUNDMANAGER->isPlaySound("Effect_Ura_Move"))
			{
				SOUNDMANAGER->play("Effect_Ura_Move");
			}
			break;
		case ENEMY_URA_BOSS:
			EFFECTMANAGER->ActivateEffect(EFFECT_SPECTRUM_URA_BOSS, m_position, m_directionState, 0.1f);
			if (!SOUNDMANAGER->isPlaySound("Effect_Ura_Move"))
			{
				SOUNDMANAGER->play("Effect_Ura_Move");
			}
			break;
		case ENEMY_PECKER:
			if (!SOUNDMANAGER->isPlaySound("Effect_Pecker_Move"))
			{
				SOUNDMANAGER->play("Effect_Pecker_Move");
			}
			break;
		case ENEMY_RATTLE_TAIL:
			if (!SOUNDMANAGER->isPlaySound("Effect_RattleTail_Move"))
			{
				SOUNDMANAGER->play("Effect_RattleTail_Move");
			}
			break;
		case ENEMY_MECHANICAL_PYTH:
			if (!SOUNDMANAGER->isPlaySound("Effect_Mechanical_Pyth_Move"))
			{
				SOUNDMANAGER->play("Effect_Mechanical_Pyth_Move");
			}
			break;
		}
		break;
	}	
	case ATTACK:
		break;
	case DIE:
		break;
	}

	// 충돌체 사각형 갱신
	m_colliderRect = RectMakeCenter(m_position.x, m_position.y, m_colliderWidth, m_colliderHeight);
}


Enemy_Extra::Enemy_Extra()
{
}


Enemy_Extra::~Enemy_Extra()
{
}
