#include "stdafx.h"
#include "Camera_FollowCam.h"
#include "Character_PC.h"
#include "Enemy_Extra.h"

HRESULT Camera_FollowCam::init()
{
	m_objectType = OBJECT_TYPE::OBJECT_CAMERA;
	m_cameraType = CAMERA_TYPE::CAMERA_FOLLOWCAM;
	m_position = { WINSIZEX / 2,  WINSIZEY / 2 };
	m_colliderWidth = WINSIZEX;
	m_colliderHeight = WINSIZEY;
	m_colliderRect = RectMakeCenter(m_position.x, m_position.y, m_colliderWidth, m_colliderHeight);

	m_isActive = true;

	m_targetObject = CHARACTERMANAGER->FindCharacter(CHARACTER_TYPE::CHARACTER_KID);

	return S_OK;
}

void Camera_FollowCam::release()
{
}

void Camera_FollowCam::update()
{

	Character_PC* pc = (Character_PC*)m_targetObject;
	POINTFLOAT pcPosition = pc->getPosition();
	ANIMATION_STATE pcAnimationState = ((Character_PC*)m_targetObject)->getAnimationState();

	if (pcAnimationState == FALL || pcAnimationState == STAND_UP) return;

	m_position = pcPosition;

	m_colliderRect = RectMakeCenter(m_position.x, m_position.y, m_colliderWidth, m_colliderHeight);

	int stageWidth = CAMERAMANAGER->getStageWidth();
	int stageHeight = CAMERAMANAGER->getStageHeight();

	if (m_colliderRect.left < 0)
		m_position.x = m_colliderWidth / 2;
	if (stageWidth < m_colliderRect.right)
		m_position.x = stageWidth - m_colliderWidth / 2;
	if(m_colliderRect.top < 0)
		m_position.y = m_colliderHeight / 2;
	if (stageHeight < m_colliderRect.bottom)
		m_position.y = stageHeight - m_colliderHeight / 2;
		
	m_colliderRect = RectMakeCenter(m_position.x, m_position.y, m_colliderWidth, m_colliderHeight);
}

void Camera_FollowCam::render()
{
	SortRenderInfo();

	for (int i = 0; i < LAYER_MAX; ++i)
	{
		for (auto iter = m_renderList[i].begin(); iter != m_renderList[i].end(); ++iter)
		{
			switch (i)
			{
			case LAYER_PLAYERFALL:
				(*iter).m_image->frameRender(getMemDC(), (*iter).m_imageRect.left - m_position.x + m_colliderWidth / 2, (*iter).m_imageRect.top - m_position.y + m_colliderHeight / 2, (*iter).m_frameX, (*iter).m_frameY);
			case LAYER_BACKGROUND:
			{
				RECT temp;
				if (!IntersectRect(&temp, &m_colliderRect, &(*iter).m_imageRect)) continue;
				(*iter).m_image->frameRender(getMemDC(), (*iter).m_imageRect.left - m_position.x + m_colliderWidth / 2, (*iter).m_imageRect.top - m_position.y + m_colliderHeight / 2, (*iter).m_frameX, (*iter).m_frameY);
				break;
			}
			case LAYER_BACK_EFFECT: case LAYER_ACTOR: case LAYER_FRONT_EFFECT:
			{
				RECT temp;
				if (!IntersectRect(&temp, &m_colliderRect, &(*iter).m_imageRect)) continue;
				if ((*iter).m_alpha == 255)
				{
					(*iter).m_image->frameRender(getMemDC(), (*iter).m_imageRect.left - m_position.x + m_colliderWidth / 2, (*iter).m_imageRect.top - m_position.y + m_colliderHeight / 2, (*iter).m_frameX, (*iter).m_frameY);
				}
				else
				{
					(*iter).m_image->alphaRender(getMemDC(), (*iter).m_imageRect.left - m_position.x + m_colliderWidth / 2, (*iter).m_imageRect.top - m_position.y + m_colliderHeight / 2, (*iter).m_frameX * (*iter).m_imageWidth, (*iter).m_frameY * (*iter).m_imageHeight, (*iter).m_imageWidth, (*iter).m_imageHeight, (*iter).m_alpha);
				}
				break;
			}
			case LAYER_PARTICLE:
				if ((*iter).m_position.y < 0) continue;
				(*iter).m_image->alphaRender(getMemDC(), (*iter).m_imageRect.left, (*iter).m_imageRect.top, (*iter).m_frameX * (*iter).m_imageWidth, (*iter).m_frameY * (*iter).m_imageHeight, (*iter).m_imageWidth, (*iter).m_imageHeight, (*iter).m_alpha);
				break;
			case LAYER_ENEMY_STATUSBAR:
				RECT temp;
				if (!IntersectRect(&temp, &m_colliderRect, &(*iter).m_imageRect)) continue;
				(*iter).m_image->render(getMemDC(), (*iter).m_imageRect.left - m_position.x + m_colliderWidth / 2, (*iter).m_imageRect.top - m_position.y + m_colliderHeight / 2, 0, 0, (*iter).m_imageWidth, (*iter).m_imageHeight);
				break;
			case LAYER_UI:
				if ((*iter).m_alpha == 255)
				{
					(*iter).m_image->render(getMemDC(), (*iter).m_imageRect.left, (*iter).m_imageRect.top, 0, 0, (*iter).m_imageWidth, (*iter).m_imageHeight);
				}
				else
				{
					(*iter).m_image->alphaRender(getMemDC(), (*iter).m_imageRect.left, (*iter).m_imageRect.top, 0, 0, (*iter).m_imageWidth, (*iter).m_imageHeight, (*iter).m_alpha);
				}
				break;
			}
		}
		m_renderList[i].clear();
	}


	// 디버깅용 속성배열 출력
	BYTE* tilePropertyInfo = TILEMANAGER->getTilePropertyInfo();
	int tilePropertySize = TILEMANAGER->getTilePropertySize();
	int tilePropertyWidth = TILEMANAGER->getTilePropertyWidth();
	int tilePropertyHeight = TILEMANAGER->getTilePropertyHeight();

	vector<Enemy*> enemyList = ENEMYMANAGER->getEnemyList();

	if (KEYMANAGER->isStayKeyDown(VK_TAB))
	{
		for (int i = 0; i < tilePropertySize; ++i)
		{
			char str[128];
			sprintf(str, "%d", tilePropertyInfo[i]);
			TextOut(getMemDC(), (i % tilePropertyWidth) * 25 - m_position.x + m_colliderWidth / 2,  (i / tilePropertyWidth) * 25 - m_position.y + m_colliderHeight / 2, str, strlen(str));
		}
	}
}


Camera_FollowCam::Camera_FollowCam()
{
}


Camera_FollowCam::~Camera_FollowCam()
{
}
