// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>


#include<iostream>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include<commdlg.h> // 오픈파일네임용(OpenFileName)

//STL
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <list>



//====================================
//	## 내가 만든 헤더파일 이곳에 추가 ## 
//====================================
#include"commonMacroFunction.h"
#include"keyManager.h"
#include"imageManager.h"
#include"timeManager.h"
#include"sceneManager.h"
#include"soundManager.h"
#include"animationManager.h"
#include"randomFunction.h"
#include"utils.h"
#include"txtData.h"
#include"iniData.h"

#include "CameraManager.h"
#include "StageManager.h"
#include "TileManager.h"
#include "ObstacleManager.h"
#include "TriggerManager.h"
#include "CharacterManager.h"
#include "EnemyManager.h"
#include "ProjectileManager.h"
#include "EffectManager.h"
#include "ParticleManager.h"
#include "SkillManager.h"
#include "UIManager.h"
#include "StatusBarManager.h"

using namespace UTIL;
using namespace std;
//====================================
//	## 싱글톤 추가 ## 
//====================================

#define RND						randomFunction::getSingleton()
#define KEYMANAGER				keyManager::getSingleton()
#define IMAGEMANAGER			imageManager::getSingleton()
#define TIMEMANAGER             timeManager::getSingleton()
#define SCENEMANAGER			sceneManager::getSingleton()
#define SOUNDMANAGER			soundManager::getSingleton()
#define ANIMATIONMANAGER		animationManager::getSingleton()
#define TXTDATA					txtData::getSingleton()
#define INIDATA					iniData::getSingleton()

#define CAMERAMANAGER			CameraManager::getSingleton()
#define STAGEMANAGER			StageManager::getSingleton()
#define TILEMANAGER				TileManager::getSingleton()
#define OBSTACLEMANAGER			ObstacleManager::getSingleton()
#define TRIGGERMANAGER			TriggerManager::getSingleton()
#define CHARACTERMANAGER		CharacterManager::getSingleton()
#define ENEMYMANAGER			EnemyManager::getSingleton()
#define PROJECTILEMANAGER		ProjectileManager::getSingleton()
#define EFFECTMANAGER			EffectManager::getSingleton()
#define PARTICLEMANAGER			ParticleManager::getSingleton()

#define SKILLMANAGER			SkillManager::getSingleton()
#define UIMANAGER				UIManager::getSingleton()
#define STATUSBARMANAGER		StatusBarManager::getSingleton()

//====================================
//	## 디파인문 ## (윈도우 초기화 셋팅) 
//====================================

#define WINNAME (LPTSTR)(TEXT("Bastion"))
#define WINSTARTX 450
#define WINSTARTY 100
#define WINSIZEX 1024
#define WINSIZEY 768
#define WINSTYLE WS_CAPTION | WS_SYSMENU

//==================================================
//	## 매크로 함수 ## (메인게임의 릴리즈 부분에서 사용) 
//==================================================

#define SAFE_DELETE(p)	{if(p) {delete(p); (p) = nullptr;}}
#define SAFE_RELEASE(p)	{if(p) {(p)->release(); (p) = nullptr;}}

//==================================================
//	## 전역변수 ## (인스턴스, 윈도우 핸들, 마우스좌표) 
//==================================================
extern HINSTANCE m_hInstance;
extern HWND m_hWnd;
extern POINT m_ptMouse;

enum DIRECTION_STATE
{
	DIRECTION_NONE = 0,
	DOWN = 0, 
	UP,
	LEFT_UP, 
	RIGHT_UP, 
	LEFT, 
	RIGHT, 
	LEFT_DOWN,
	RIGHT_DOWN 
};

enum ANIMATION_STATE
{
	ANIMATION_NONE, 
	IDLE,
	MOVE, 
	TUMBLING,
	ATTACK,
	SMASH, 
	SHOOT, 
	COUNTER,
	UPPER, 
	FINISH, 
	DRINK,
	FALL, 
	HIT, 
	DIE,
	WAKE_UP, 
	STAND_UP 
};

enum MOUSE_STATE
{ 
	MOUSE_NONE, 
	MOUSE_NORMAL, 
	MOUSE_MOVE,
	MOUSE_ATTACK 
};

enum SCENE_TYPE 
{ 
	SCENE_NONE, 
	SCENE_TITLE,
	SCENE_MAINMENU,
	SCENE_LOADING,
	SCENE_MAINGAME
};

enum LAYER_TYPE 
{ 
	LAYER_PLAYERFALL,
	LAYER_BACKGROUND,
	LAYER_TILE,
	LAYER_BACK_EFFECT,
	LAYER_ACTOR,
	LAYER_FRONT_EFFECT,
	LAYER_PARTICLE,
	LAYER_ENEMY_STATUSBAR,
	LAYER_UI,
	LAYER_MAX 
};


enum PROPERTY_TYPE
{
	MOVABLE, IMMOVABLE, EMPTY_PLACE, OBSTACLE
};

enum OBJECT_TYPE 
{ 
	OBJECT_NONE,
	OBJECT_CAMERA,
	OBJECT_STAGE,
	OBJECT_TILE,
	OBJECT_OBSTACLE,
	OBJECT_TRIGGER,
	OBJECT_PC,
	OBJECT_NPC,
	OBJECT_ENEMY,
	OBJECT_PROJECTILE,
	OBJECT_EFFECT,
	OBJECT_PARTICLE,
	OBJECT_SHADOW,
	OBJECT_ITEM, 
	OBJECT_UI 
};

enum CAMERA_TYPE 
{ 
	CAMERA_NONE, 
	CAMERA_FOLLOWCAM 
};

enum BACKGROUND_TYPE 
{
	BACKGROUND0, 
	BACKGROUND1,
	BACKGROUND2,
	BACKGROUND3,
	BACKGROUND_MAX
};

enum STAGE_TYPE
{
	STAGE1, STAGE2, STAGE3, STAGE4, STAGE5, STAGE6
};

enum TILE_TYPE
{
	TILE0, TILE1, TILE2, TILE3, TILE4, TILE5, TILE6, TILE7, TILE8, TILE9,
	TILE10, TILE11, TILE12, TILE13, TILE14, TILE15, TILE16, TILE17, TILE18, TILE19,
	TILE20, TILE21, TILE22, TILE23, TILE24, TILE25, TILE26, TILE27, TILE28, TILE29,
	TILE30, TILE31, TILE32, TILE33, TILE34, TILE35, TILE36, TILE37, TILE38, TILE39,
	TILE40, TILE41, TILE42, TILE43, TILE44, TILE45, TILE46, TILE47, TILE48, TILE49,
	TILE50, TILE51, TILE52, TILE53, TILE54, TILE55, TILE56, TILE57, TILE58, TILE59
};


enum OBSTACLE_TYPE
{
	OBSTACLE_NON_BROKEN_0,
	OBSTACLE_NON_BROKEN_1,
	OBSTACLE_NON_BROKEN_2,
	OBSTACLE_NON_BROKEN_3,
	OBSTACLE_NON_BROKEN_4,
	OBSTACLE_NON_BROKEN_5,
	OBSTACLE_NON_BROKEN_6,
	OBSTACLE_NON_BROKEN_7,
	OBSTACLE_NON_BROKEN_8,
	OBSTACLE_NON_BROKEN_9,
	OBSTACLE_NON_BROKEN_10,
	OBSTACLE_NON_BROKEN_11,
	OBSTACLE_NON_BROKEN_12,
	OBSTACLE_NON_BROKEN_13,
	OBSTACLE_NON_BROKEN_14,
	OBSTACLE_NON_BROKEN_15,
	OBSTACLE_NON_BROKEN_16,
	OBSTACLE_NON_BROKEN_17,
	OBSTACLE_NON_BROKEN_18,
	OBSTACLE_NON_BROKEN_19,
	OBSTACLE_NON_BROKEN_20,
	OBSTACLE_NON_BROKEN_21,
	OBSTACLE_NON_BROKEN_22,
	OBSTACLE_NON_BROKEN_23,
	OBSTACLE_NON_BROKEN_24,
	OBSTACLE_NON_BROKEN_25,
	OBSTACLE_NON_BROKEN_26,
	OBSTACLE_NON_BROKEN_27,
	OBSTACLE_NON_BROKEN_28,

	OBSTACLE_BROKEN_27,
	OBSTACLE_BROKEN_28,
	OBSTACLE_BROKEN_29,
	OBSTACLE_BROKEN_30,
	OBSTACLE_BROKEN_31,
	OBSTACLE_BROKEN_32,
	OBSTACLE_BROKEN_33,
	OBSTACLE_BROKEN_34,
	OBSTACLE_BROKEN_35,
	OBSTACLE_BROKEN_36,
	OBSTACLE_BROKEN_37,
	OBSTACLE_BROKEN_38,
	OBSTACLE_BROKEN_39,
	OBSTACLE_BROKEN_40,
	OBSTACLE_BROKEN_41
};


enum CHARACTER_TYPE
{
	CHARACTER_NONE, 
	CHARACTER_KID
};

enum ENEMY_TYPE
{ 
	ENEMY_MECHANICAL_PYTH,
	ENEMY_PECKER,
	ENEMY_RATTLE_TAIL,
	ENEMY_TURRET,
	ENEMY_URA_BOSS,
	ENEMY_URA_CROSSBOW,
	ENEMY_URA_HALBERD,
	ENEMY_URA_RIFLE,
	ENEMY_URA_SWORD,
	ENEMY_SCUMBAG,
};

enum PROJECTILE_TYPE
{
	PROJECTILE_NONE,
	PROJECTILE_ARROW,
	PROJECTILE_BULLET_RED,
	PROJECTILE_BULLET_GREEN,
	PROJECTILE_BULLET_BLUE,
	PROJECTILE_AURA
};

enum EFFECT_TYPE
{
	EFFECT_NONE,
	EFFECT_BREATH,
	EFFECT_COUNTER,
	EFFECT_CRACK,
	EFFECT_EXPLOSION,
	EFFECT_FIRE,
	EFFECT_METEOR,
	EFFECT_SMOKE,
	EFFECT_BULLET_FIRE_RED,
	EFFECT_BULLET_FIRE_GREEN,
	EFFECT_BULLET_FIRE_BLUE,
	EFFECT_BULLET_HIT_RED,
	EFFECT_BULLET_HIT_GREEN,
	EFFECT_BULLET_HIT_BLUE,
	EFFECT_UPPER,
	EFFECT_RESTORE,
	EFFECT_SPECTRUM_URA_BOSS,
	EFFECT_SPECTRUM_URA_CROSSBOW,
	EFFECT_SPECTRUM_URA_SWORD,
	EFFECT_SPECTRUM_URA_HALBERD,
	EFFECT_SPECTRUM_URA_RIFLE
};

enum PARTICLE_TYPE
{
	PARTICLE_NONE,
	PARTICLE_LEAF1,
	PARTICLE_LEAF2,
	PARTICLE_FIREFLY
};

enum TRIGGER_TYPE
{
	TRIGGER_NONE
};

enum ITEM_TYPE
{
	ITEM_NONE,
	ITEM_POTION_HP,
	ITEM_POTION_SKILL,
	ITEM_WEAPON_HAMMER,
	ITEM_WEAPON_RIFLE,
	ITEM_SPIRITS_SQUIRT_CIDER,
	ITEM_SPIRITS_BASTION_BOURBON,
	ITEM_SPIRITS_BLACK_RYE
};

enum UI_TYPE
{
	UI_NONE,
	UI_BACKGROUND,
	UI_TITLE,
	UI_MAINMENU,
	UI_STATUS_BAR,
	UI_PAUSE,
	UI_ARSNAL,
	UI_DISTILLERY,
	UI_PACK,
	UI_EQUIP,
	UI_DIALOGUE,
	UI_MOUSE
};

enum STATUSBAR_TYPE
{
	STATUSBAR_NONE,
	STATUSBAR_CHARACTER_PC,
	STATUSBAR_ENEMY
};

typedef struct renderInfo
{
	int m_sortValue;
	POINTFLOAT m_position;
	RECT m_imageRect;
	int m_imageWidth;
	int m_imageHeight;
	image* m_image;
	int m_frameX = 0;
	int m_frameY = 0;
	float m_alpha = 255;

	bool operator <(const renderInfo &a) const
	{
		return this->m_sortValue < a.m_sortValue;
	}
}RENDER_INFO;


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
