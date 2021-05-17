#include "stdafx.h"
#include "Character_PC.h"
#include "Camera_FollowCam.h"
#include "Tile.h"
#include "Stage.h"

HRESULT Character_PC::init()
{
	m_objectType = OBJECT_TYPE::OBJECT_PC;
	m_layerType = LAYER_TYPE::LAYER_ACTOR;

	m_characterType = CHARACTER_TYPE::CHARACTER_KID;

	m_colliderWidth = m_colliderHeight = 100;
	m_colliderRect = RectMakeCenter(m_position.x, m_position.y, m_colliderWidth, m_colliderHeight);
	
	m_isActive = true;
	m_isAniFinish = false;


	m_maxHP = 100;
	m_curHP = m_maxHP;

	m_speed = 5.0f;
	m_angle = 12 * PI_8;
	m_attack = 10.0f;

	m_level = 1;
	m_maxEXP = 100;
	m_curEXP = 0;

	m_dropSpeed = 20.0f;

	STATUSBARMANAGER->CreateStateBar(STATUSBAR_TYPE::STATUSBAR_CHARACTER_PC, this);

	return S_OK;
}

void Character_PC::release()
{

}

void Character_PC::update()
{
	if (m_animationState == DIE) return;

	StateProcess();
	ActionProcess();
}

void Character_PC::render()
{
	ImageInit();
	if (m_animationState == DIE && m_isAniFinish)
	{

	}
	else
	{
		ImageFrameUpdate();
	}

	// 이미지 사각형 갱신
	m_imageWidth = m_image->getFrameWidth();
	m_imageHeight = m_image->getFrameHeight();
	m_imageRect = RectMakeCenter(m_position.x, m_position.y, m_imageWidth, m_imageHeight);

	RENDER_INFO renderInfo;
	
	// 캐릭터 렌더정보 전달
	renderInfo = { (int)m_position.y, m_position, m_imageRect, m_imageWidth, m_imageHeight, m_image, m_frameX, m_frameY };
	CAMERAMANAGER->AddRenderInfo(m_layerType,  renderInfo);

	// 그림자 렌더정보 전달
	if (m_animationState == FALL) return;
	POINTFLOAT shadowPosition = { m_position.x,  m_colliderRect.bottom };
	image* shadowImage = IMAGEMANAGER->findImage("Shadow");
	int shadowWidth = shadowImage->getWidth();
	int shadowHeight = shadowImage->getHeight();
	RECT shadowImageRect = RectMakeCenter(shadowPosition.x, shadowPosition.y, shadowWidth, shadowHeight);

	renderInfo = { (int)shadowPosition.y, shadowPosition, shadowImageRect, shadowWidth, shadowHeight, shadowImage, 0, 0, 150};
	CAMERAMANAGER->AddRenderInfo(LAYER_TYPE::LAYER_BACK_EFFECT,  renderInfo);
}


void Character_PC::StateProcess()
{
	POINTFLOAT cameraPosition = CAMERAMANAGER->getMainCamera()->getPosition();
	int cameraWidth = CAMERAMANAGER->getMainCamera()->getColliderWidth();
	int cameraHeight = CAMERAMANAGER->getMainCamera()->getColliderHeight();

	if (m_animationState == FALL && m_isAniFinish)
	{
		m_isAniFinish = false;
		m_animationState = STAND_UP;
		m_layerType = LAYER_TYPE::LAYER_ACTOR;

		m_position.x = m_prevPosition.x;
		m_position.y = m_prevPosition.y - WINSIZEY / 2;
	}

	// 플레이어 키 입력에 따른 상태 체크
	if(m_isAniFinish) m_animationState = IDLE;
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && m_isAniFinish)		// 근거리 공격
	{
		m_isAniFinish = false;
		m_animationState = SMASH;
		m_angle = UTIL::getAngle(m_position.x - cameraPosition.x + cameraWidth / 2, m_position.y - cameraPosition.y + cameraHeight / 2, m_ptMouse.x, m_ptMouse.y);

		SKILLMANAGER->ActivateSkill("Skill_Smash", this);
		SOUNDMANAGER->play("Effect_Player_Smash");
	}
	else if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON) && m_isAniFinish)	// 원거리 공격
	{
		m_isAniFinish = false;
		m_animationState = SHOOT;
		m_angle = UTIL::getAngle(m_position.x - cameraPosition.x + cameraWidth / 2, m_position.y - cameraPosition.y + cameraHeight / 2, m_ptMouse.x, m_ptMouse.y);

		PROJECTILEMANAGER->ActivateProjectile(PROJECTILE_TYPE::PROJECTILE_BULLET_RED, m_objectType, m_position, m_angle, m_attack);
		EFFECTMANAGER->ActivateEffect(EFFECT_TYPE::EFFECT_BULLET_FIRE_RED, PointFloatMake(m_position.x + cosf(m_angle) * 70, m_position.y + (-sinf(m_angle) * 70)), DIRECTION_STATE::DIRECTION_NONE);
		SOUNDMANAGER->play("Effect_Player_Shoot");
	}
	else if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && m_isAniFinish)		// 구르기 이동
	{
		m_isAniFinish = false;
		m_animationState = TUMBLING;

		SKILLMANAGER->ActivateSkill("Skill_Tumbling", this);
	}
	else if (KEYMANAGER->isStayKeyDown(VK_SHIFT) && m_isAniFinish)		// 카운터 공격
	{
		SKILLMANAGER->ActivateSkill("Skill_Counter", this);
		EFFECTMANAGER->ActivateEffect(EFFECT_TYPE::EFFECT_COUNTER, PointFloatMake(m_position.x, m_position.y), DIRECTION_STATE::DIRECTION_NONE);

		if (!SOUNDMANAGER->isPlaySound("Effect_Player_Counter"))
		{
			SOUNDMANAGER->play("Effect_Player_Counter");
		}
	}
	else if (KEYMANAGER->isOnceKeyDown('F') && m_isAniFinish)			// 포션 사용
	{
		m_isAniFinish = false;
		m_animationState = DRINK;

		m_curHP += m_maxHP * 0.2;
		if (m_curHP > m_maxHP) m_curHP = m_maxHP;

		EFFECTMANAGER->ActivateEffect(EFFECT_TYPE::EFFECT_RESTORE, m_position, DIRECTION_STATE::DIRECTION_NONE);
		SOUNDMANAGER->play("Effect_Player_Restore");
	}
	else if (KEYMANAGER->isOnceKeyDown('Q') && m_isAniFinish)			// 차징 스킬 공격
	{
		m_isAniFinish = false;
		m_animationState = UPPER;
		m_angle = UTIL::getAngle(m_position.x - cameraPosition.x + cameraWidth / 2, m_position.y - cameraPosition.y + cameraHeight / 2, m_ptMouse.x, m_ptMouse.y);

		PROJECTILEMANAGER->ActivateProjectile(PROJECTILE_TYPE::PROJECTILE_AURA, m_objectType, m_position, m_angle, m_attack);
		SOUNDMANAGER->play("Effect_Player_Upper");
	}
	else if (KEYMANAGER->isOnceKeyDown('E') && m_isAniFinish)			// 범위 스킬 공격
	{
		m_isAniFinish = false;
		m_animationState = FINISH;

		SKILLMANAGER->ActivateSkill("Skill_Explosion", this);
	}
	else if (KEYMANAGER->isStayKeyDown('A') && KEYMANAGER->isStayKeyDown('W') && m_isAniFinish)	// 왼쪽위 대각선 이동
	{
		m_animationState = MOVE;
		m_angle = 6 * PI_8;
	}
	else if (KEYMANAGER->isStayKeyDown('A') && KEYMANAGER->isStayKeyDown('S') && m_isAniFinish)	// 왼쪽아래 대각선 이동
	{
		m_animationState = MOVE;
		m_angle = 10 * PI_8;
	}
	else if (KEYMANAGER->isStayKeyDown('D') && KEYMANAGER->isStayKeyDown('W') && m_isAniFinish)	// 오른쪽위 대각선 이동
	{
		m_animationState = MOVE;
		m_angle = 2 * PI_8;
	}
	else if (KEYMANAGER->isStayKeyDown('D') && KEYMANAGER->isStayKeyDown('S') && m_isAniFinish)	// 오른쪽아래 대각선 이동
	{
		m_animationState = MOVE;
		m_angle = 14 * PI_8;
	}
	else if (KEYMANAGER->isStayKeyDown('A') && m_isAniFinish)	// 왼쪽 이동
	{
		m_animationState = MOVE;
		m_angle = 8 * PI_8;
	}
	else if (KEYMANAGER->isStayKeyDown('D') && m_isAniFinish)	// 오른쪽 이동
	{
		m_animationState = MOVE;
		m_angle = 0;
	}
	else if (KEYMANAGER->isStayKeyDown('W') && m_isAniFinish)	// 위쪽 이동
	{
		m_animationState = MOVE;
		m_angle = 4 * PI_8;
	}
	else if (KEYMANAGER->isStayKeyDown('S') && m_isAniFinish)	// 아래쪽 이동
	{
		m_animationState = MOVE;
		m_angle = 12 * PI_8;
	}


	// 플레이어 사망 체크
	if (m_curHP <= 0)
	{
		m_curHP = 0;
		m_isAniFinish = false;
		m_animationState = DIE;

		SOUNDMANAGER->play("Effect_Player_Die");
	}

	// 플레이어 레벨업 체크
	if (m_curEXP >= m_maxEXP)
	{
		m_curEXP -= m_maxEXP;
		++m_level;
		m_maxHP += 50 * m_level;
		m_curHP = m_maxHP;
		m_attack += 1 * m_level;

		SOUNDMANAGER->play("Effect_Player_LevelUp");
	}

	// 각도에 따른 방향 상태 갱신 
	if (m_angle >= PI2) m_angle -= PI2; // 각도가 360이상일 경우에 대한 예외처리

	if (15.5 * PI_8 <= m_angle && m_angle < PI2 || 0 <= m_angle && m_angle < 0.5 * PI_8) m_directionState = RIGHT;
	else if (0.5 * PI_8 <= m_angle && m_angle < 3.5 * PI_8) m_directionState = RIGHT_UP;
	else if (3.5 * PI_8 <= m_angle && m_angle < 4.5 * PI_8) m_directionState = UP;
	else if (4.5 * PI_8 <= m_angle && m_angle < 7.5 * PI_8) m_directionState = LEFT_UP;
	else if (7.5 * PI_8 <= m_angle && m_angle < 8.5 * PI_8) m_directionState = LEFT;
	else if (8.5 * PI_8 <= m_angle && m_angle < 11.5 * PI_8) m_directionState = LEFT_DOWN;
	else if (11.5 * PI_8 <= m_angle && m_angle < 12.5 * PI_8) m_directionState = DOWN;
	else if (12.5 * PI_8 <= m_angle && m_angle < 15.5 * PI_8) m_directionState = RIGHT_DOWN;

}
void Character_PC::ActionProcess()
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
		break;
	case MOVE:
		m_position.x += cosf(m_angle) * m_speed;
		m_position.y += -sinf(m_angle) * m_speed;

		x = m_position.x / 25;
		y = (m_position.y + (m_colliderHeight / 2)) / 25;
		index = x + (y * tilePropertyWidth);

		switch(tilePropertyInfo[index])
		{
		case IMMOVABLE:
			m_isAniFinish = false;
			m_animationState = FALL;
			m_layerType = LAYER_TYPE::LAYER_PLAYERFALL;

			m_position.x -= cosf(m_angle) * m_speed;
			m_position.y -= -sinf(m_angle) * m_speed;
			m_prevPosition = m_position;
			break;
		case OBSTACLE:
			m_position.x -= cosf(m_angle) * m_speed;
			m_position.y -= -sinf(m_angle) * m_speed;
			break;
		}

		if (!SOUNDMANAGER->isPlaySound("Effect_Player_Move"))
		{
			SOUNDMANAGER->play("Effect_Player_Move");
		}
		break;
	case SMASH:
		break;
	case SHOOT:
		break;
	case TUMBLING:
		m_position.x += cosf(m_angle) * (m_speed * 1.5f);
		m_position.y += -sinf(m_angle) * (m_speed * 1.5f);

		x = m_position.x / 25;
		y = (m_position.y + (m_colliderHeight / 2)) / 25;
		index = x + (y * tilePropertyWidth);

		switch(tilePropertyInfo[index])
		{
		case IMMOVABLE:
			m_isAniFinish = false;
			m_animationState = FALL;
			m_layerType = LAYER_TYPE::LAYER_PLAYERFALL;

			m_position.x -= cosf(m_angle) * (m_speed * 1.5f);
			m_position.y -= -sinf(m_angle) * (m_speed * 1.5f);
			m_prevPosition = m_position;
			break;
		case OBSTACLE:
			m_position.x -= cosf(m_angle) * (m_speed * 1.5f);
			m_position.y -= -sinf(m_angle) * (m_speed * 1.5f);
			break;
		}

		if (!SOUNDMANAGER->isPlaySound("Effect_Player_Tumbling"))
		{
			SOUNDMANAGER->play("Effect_Player_Tumbling");
		}
	case UPPER:
		break;
	case FINISH:
		m_directionState = DIRECTION_NONE;
		break;
	case COUNTER:
		break;
	case HIT:
		if (!SOUNDMANAGER->isPlaySound("Effect_Player_Hit"))
		{
			SOUNDMANAGER->play("Effect_Player_Hit");
		}
		break;
	case DIE:
		m_directionState = DIRECTION_NONE;
		break;
	case DRINK:
		m_directionState = DIRECTION_NONE;
		break;
	case WAKE_UP:
		m_directionState = DIRECTION_NONE;
		break;
	case STAND_UP:
		m_directionState = DIRECTION_NONE;
		m_position.y += m_dropSpeed;
		if (m_position.y > m_prevPosition.y) m_position.y = m_prevPosition.y;
		break;
	case FALL:
		m_directionState = DIRECTION_NONE;
		m_position.y += m_dropSpeed;

		if (!SOUNDMANAGER->isPlaySound("Effect_Player_Fall"))
		{
			SOUNDMANAGER->play("Effect_Player_Fall");
		}
		break;
	}

	// 충돌체 사각형 갱신
	m_colliderRect = RectMakeCenter(m_position.x, m_position.y, m_colliderWidth, m_colliderHeight);
}

Character_PC::Character_PC()
{
}


Character_PC::~Character_PC()
{
}
