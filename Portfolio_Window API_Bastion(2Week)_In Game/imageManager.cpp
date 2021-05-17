#include "stdafx.h"
#include "imageManager.h"


imageManager::imageManager()
{
}


imageManager::~imageManager()
{
}

HRESULT imageManager::init()
{
	// 애니메이션 상태에 대한 키 값 세팅
	mapAnimationStateKey.insert(make_pair(ANIMATION_STATE::IDLE, "Idle"));
	mapAnimationStateKey.insert(make_pair(ANIMATION_STATE::MOVE, "Move"));
	mapAnimationStateKey.insert(make_pair(ANIMATION_STATE::DRINK, "Drink"));
	mapAnimationStateKey.insert(make_pair(ANIMATION_STATE::FALL, "Fall"));
	mapAnimationStateKey.insert(make_pair(ANIMATION_STATE::WAKE_UP, "Wake_Up"));
	mapAnimationStateKey.insert(make_pair(ANIMATION_STATE::STAND_UP, "Stand_Up"));
	mapAnimationStateKey.insert(make_pair(ANIMATION_STATE::TUMBLING, "Tumbling"));
	mapAnimationStateKey.insert(make_pair(ANIMATION_STATE::HIT, "Hit"));
	mapAnimationStateKey.insert(make_pair(ANIMATION_STATE::DIE, "Die"));
	mapAnimationStateKey.insert(make_pair(ANIMATION_STATE::ATTACK, "Attack"));
	mapAnimationStateKey.insert(make_pair(ANIMATION_STATE::SMASH, "Smash"));
	mapAnimationStateKey.insert(make_pair(ANIMATION_STATE::SHOOT, "Shoot"));
	mapAnimationStateKey.insert(make_pair(ANIMATION_STATE::UPPER, "Upper"));
	mapAnimationStateKey.insert(make_pair(ANIMATION_STATE::FINISH, "Finish"));
	

	// 캐릭터 타입에 대한 키 값 세팅
	mapCharacterTypeKey.insert(make_pair(CHARACTER_TYPE::CHARACTER_KID, "Kid"));


	// 적 타입에 대한 키 값 세팅
	mapEnemyTypeKey.insert(make_pair(ENEMY_TYPE::ENEMY_URA_SWORD, "Ura_Sword"));
	mapEnemyTypeKey.insert(make_pair(ENEMY_TYPE::ENEMY_URA_HALBERD, "Ura_Halberd"));
	mapEnemyTypeKey.insert(make_pair(ENEMY_TYPE::ENEMY_URA_CROSSBOW, "Ura_Crossbow"));
	mapEnemyTypeKey.insert(make_pair(ENEMY_TYPE::ENEMY_URA_RIFLE, "Ura_Rifle"));
	mapEnemyTypeKey.insert(make_pair(ENEMY_TYPE::ENEMY_URA_BOSS, "Ura_Boss"));
	mapEnemyTypeKey.insert(make_pair(ENEMY_TYPE::ENEMY_PECKER, "Pecker"));
	mapEnemyTypeKey.insert(make_pair(ENEMY_TYPE::ENEMY_RATTLE_TAIL, "RattleTail"));
	mapEnemyTypeKey.insert(make_pair(ENEMY_TYPE::ENEMY_MECHANICAL_PYTH, "Mechanical_Pyth"));
	mapEnemyTypeKey.insert(make_pair(ENEMY_TYPE::ENEMY_TURRET, "Turret"));


	// 투사체 타입에 대한 키 값 세팅
	mapProjectileTypeKey.insert(make_pair(PROJECTILE_TYPE::PROJECTILE_ARROW, "Projectile_Arrow"));
	mapProjectileTypeKey.insert(make_pair(PROJECTILE_TYPE::PROJECTILE_BULLET_RED, "Projectile_Bullet_Red"));
	mapProjectileTypeKey.insert(make_pair(PROJECTILE_TYPE::PROJECTILE_BULLET_GREEN, "Projectile_Bullet_Green"));
	mapProjectileTypeKey.insert(make_pair(PROJECTILE_TYPE::PROJECTILE_BULLET_BLUE, "Projectile_Bullet_Blue"));
	mapProjectileTypeKey.insert(make_pair(PROJECTILE_TYPE::PROJECTILE_AURA, "Projectile_Aura"));

	// 이펙트 타입에 대한 키 값 세팅
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_BREATH, "Effect_Breath"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_COUNTER, "Effect_Counter"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_CRACK, "Effect_Crack"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_EXPLOSION, "Effect_Explosion"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_FIRE, "Effect_Fire"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_METEOR, "Effect_Meteor"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_SMOKE, "Effect_Smoke"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_BULLET_FIRE_RED, "Effect_Bullet_Fire_Red"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_BULLET_FIRE_GREEN, "Effect_Bullet_Fire_Green"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_BULLET_FIRE_BLUE, "Effect_Bullet_Fire_Blue"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_BULLET_HIT_RED, "Effect_Bullet_Hit_Red"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_BULLET_HIT_GREEN, "Effect_Bullet_Hit_Green"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_BULLET_HIT_BLUE, "Effect_Bullet_Hit_Blue"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_UPPER, "Effect_Upper"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_RESTORE, "Effect_Restore"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_SPECTRUM_URA_BOSS, "Effect_Spectrum_Ura_Boss"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_SPECTRUM_URA_CROSSBOW, "Effect_Spectrum_Ura_Crossbow"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_SPECTRUM_URA_SWORD, "Effect_Spectrum_Ura_Sword"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_SPECTRUM_URA_RIFLE, "Effect_Spectrum_Ura_Rifle"));
	mapEffectTypeKey.insert(make_pair(EFFECT_TYPE::EFFECT_SPECTRUM_URA_HALBERD, "Effect_Spectrum_Ura_Halberd"));

	// 파티클 타입에 대한 키 값 세팅
	mapParticleTypeKey.insert(make_pair(PARTICLE_TYPE::PARTICLE_LEAF1, "Particle_Leaf1"));
	mapParticleTypeKey.insert(make_pair(PARTICLE_TYPE::PARTICLE_LEAF2, "Particle_Leaf2"));
	mapParticleTypeKey.insert(make_pair(PARTICLE_TYPE::PARTICLE_FIREFLY, "Particle_Firefly"));

	// 백그라운드 배경 타입에 대한 키 값 세팅
	mapBackgroundTypeKey.insert(make_pair(BACKGROUND_TYPE::BACKGROUND0, "Background0"));
	mapBackgroundTypeKey.insert(make_pair(BACKGROUND_TYPE::BACKGROUND1, "Background1"));
	mapBackgroundTypeKey.insert(make_pair(BACKGROUND_TYPE::BACKGROUND2, "Background2"));
	mapBackgroundTypeKey.insert(make_pair(BACKGROUND_TYPE::BACKGROUND3, "Background3"));

	// 스테이지 타입에 대한 키 값 세팅
	mapStageTypeKey.insert(make_pair(STAGE_TYPE::STAGE1, "Stage1"));
	mapStageTypeKey.insert(make_pair(STAGE_TYPE::STAGE2, "Stage2"));
	mapStageTypeKey.insert(make_pair(STAGE_TYPE::STAGE3, "Stage3"));
	mapStageTypeKey.insert(make_pair(STAGE_TYPE::STAGE4, "Stage4"));
	mapStageTypeKey.insert(make_pair(STAGE_TYPE::STAGE5, "Stage5"));
	mapStageTypeKey.insert(make_pair(STAGE_TYPE::STAGE6, "Stage6"));

	// 타일 타입에 대한 키 값 세팅
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE0, "Tile0"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE1, "Tile1"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE2, "Tile2"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE3, "Tile3"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE4, "Tile4"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE5, "Tile5"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE6, "Tile6"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE7, "Tile7"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE8, "Tile8"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE9, "Tile9"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE10, "Tile10"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE11, "Tile11"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE12, "Tile12"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE13, "Tile13"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE14, "Tile14"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE15, "Tile15"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE16, "Tile16"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE17, "Tile17"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE18, "Tile18"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE19, "Tile19"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE20, "Tile20"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE21, "Tile21"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE22, "Tile22"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE23, "Tile23"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE24, "Tile24"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE25, "Tile25"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE26, "Tile26"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE27, "Tile27"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE28, "Tile28"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE29, "Tile29"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE30, "Tile30"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE31, "Tile31"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE32, "Tile32"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE33, "Tile33"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE34, "Tile34"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE35, "Tile35"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE36, "Tile36"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE37, "Tile37"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE38, "Tile38"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE39, "Tile39"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE40, "Tile40"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE41, "Tile41"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE42, "Tile42"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE43, "Tile43"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE44, "Tile44"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE45, "Tile45"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE46, "Tile46"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE47, "Tile47"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE48, "Tile48"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE49, "Tile49"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE50, "Tile50"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE51, "Tile51"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE52, "Tile52"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE53, "Tile53"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE54, "Tile54"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE55, "Tile55"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE56, "Tile56"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE57, "Tile57"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE58, "Tile58"));
	mapTileTypeKey.insert(make_pair(TILE_TYPE::TILE59, "Tile59"));

	// 물체 타입에 대한 키 값 셋팅
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_0, "Obstacle_Non_Broken_0"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_1, "Obstacle_Non_Broken_1"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_2, "Obstacle_Non_Broken_2"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_3, "Obstacle_Non_Broken_3"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_4, "Obstacle_Non_Broken_4"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_5, "Obstacle_Non_Broken_5"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_6, "Obstacle_Non_Broken_6"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_7, "Obstacle_Non_Broken_7"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_8, "Obstacle_Non_Broken_8"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_9, "Obstacle_Non_Broken_9"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_10, "Obstacle_Non_Broken_10"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_11, "Obstacle_Non_Broken_11"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_12, "Obstacle_Non_Broken_12"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_13, "Obstacle_Non_Broken_13"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_14, "Obstacle_Non_Broken_14"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_15, "Obstacle_Non_Broken_15"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_16, "Obstacle_Non_Broken_16"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_17, "Obstacle_Non_Broken_17"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_18, "Obstacle_Non_Broken_18"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_19, "Obstacle_Non_Broken_19"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_20, "Obstacle_Non_Broken_20"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_21, "Obstacle_Non_Broken_21"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_22, "Obstacle_Non_Broken_22"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_23, "Obstacle_Non_Broken_23"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_24, "Obstacle_Non_Broken_24"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_25, "Obstacle_Non_Broken_25"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_26, "Obstacle_Non_Broken_26"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_27, "Obstacle_Non_Broken_27"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_NON_BROKEN_28, "Obstacle_Non_Broken_28"));

	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_BROKEN_27, "Obstacle_Broken_27"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_BROKEN_28, "Obstacle_Broken_28"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_BROKEN_29, "Obstacle_Broken_29"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_BROKEN_30, "Obstacle_Broken_30"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_BROKEN_31, "Obstacle_Broken_31"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_BROKEN_32, "Obstacle_Broken_32"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_BROKEN_33, "Obstacle_Broken_33"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_BROKEN_34, "Obstacle_Broken_34"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_BROKEN_35, "Obstacle_Broken_35"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_BROKEN_36, "Obstacle_Broken_36"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_BROKEN_37, "Obstacle_Broken_37"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_BROKEN_38, "Obstacle_Broken_38"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_BROKEN_39, "Obstacle_Broken_39"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_BROKEN_40, "Obstacle_Broken_40"));
	mapObstacleTypeKey.insert(make_pair(OBSTACLE_TYPE::OBSTACLE_BROKEN_41, "Obstacle_Broken_41"));

	// UI관련 키 값 세팅
	mapMouseStateKey.insert(make_pair(MOUSE_STATE::MOUSE_NORMAL, "Mouse_Normal"));
	mapMouseStateKey.insert(make_pair(MOUSE_STATE::MOUSE_MOVE, "Mouse_Move"));
	mapMouseStateKey.insert(make_pair(MOUSE_STATE::MOUSE_ATTACK, "Mouse_Attack"));
	
	addImage("Mouse_Normal", "images/UI/Mouse/Mouse_Normal.bmp", 64, 64, true, RGB(255, 255, 255));
	addImage("Mouse_Move", "images/UI/Mouse/Mouse_Move.bmp", 43, 44, true, RGB(255, 255, 255));
	addImage("Mouse_Attack", "images/UI/Mouse/Mouse_Attack.bmp", 43, 44, true, RGB(255, 255, 255));

	addImage("MainMenu_List", "images/UI/MainMenu/MainMenu_List.bmp", 600, 720, true, RGB(255, 255, 255));
	addImage("MainMenu_Background", "images/UI/MainMenu/MainMenu_Background.bmp", WINSIZEX, WINSIZEY);
	addImage("MainMenu_Character", "images/UI/MainMenu/MainMenu_Character.bmp", 200, 340, true, RGB(255, 255, 255));
	addImage("MainMenu_Button_Background", "images/UI/MainMenu/MainMenu_Button_Background.bmp", 515, 60);
	addImage("MainMenu_Button_Story", "images/UI/MainMenu/MainMenu_Button_Story.bmp", 300, 50, true, RGB(255, 255, 255));
	addImage("MainMenu_Button_Story_Bold", "images/UI/MainMenu/MainMenu_Button_Story_Bold.bmp", 300, 50, true, RGB(255, 255, 255));
	addImage("MainMenu_Button_MapTool", "images/UI/MainMenu/MainMenu_Button_MapTool.bmp", 300, 50, true, RGB(255, 255, 255));
	addImage("MainMenu_Button_MapTool_Bold", "images/UI/MainMenu/MainMenu_Button_MapTool_Bold.bmp", 300, 50, true, RGB(255, 255, 255));
	addImage("MainMenu_Button_ExitGame", "images/UI/MainMenu/MainMenu_Button_ExitGame.bmp", 300, 50, true, RGB(255, 255, 255));
	addImage("MainMenu_Button_ExitGame_Bold", "images/UI/MainMenu/MainMenu_Button_ExitGame_Bold.bmp", 300, 50, true, RGB(255, 255, 255));

	addImage("Title_Logo1", "images/UI/Title/Title_Logo1.bmp", WINSIZEX, WINSIZEY);
	addImage("Title_Logo2", "images/UI/Title/Title_Logo2.bmp", WINSIZEX, WINSIZEY);
	addImage("Title_LogoBackground", "images/UI/Title/Title_LogoBackground.bmp", WINSIZEX, WINSIZEY);
	addImage("Title_Background", "images/UI/TItle/Title_Background.bmp", WINSIZEX, WINSIZEY);
	addImage("Title_Bastion", "images/UI/Title/Title_Bastion.bmp", 500, 250, true, RGB(255, 255, 255));
	addImage("Title_Button_Start", "images/UI/Title/Title_Button_Start.bmp", 300, 50, true, RGB(255, 255, 255));
	addImage("Title_Button_Background", "images/UI/Title/Title_Button_Background.bmp", 400, 75);

	return S_OK;
}

void imageManager::release()
{
	deleteAll();
}

image * imageManager::addImage(string strKey, int width, int height)
{

	//추가하려는 키값으로 이미지가 존재하는지 확인
	image* img = findImage(strKey);

	//추가하려는 이미지가 이미 있으면  리턴
	if (img) return img;

	img = new image;
	//이미지가 초기화 되지 않으면 
	if (FAILED(img->init(width, height)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image * imageManager::addImage(string strKey, const char * fileName, int width, int height, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	if (img) return img;

	img = new image;

	if (FAILED(img->init(fileName, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image * imageManager::addImage(string strKey, const char * fileName, float x, float y, int width, int height, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	if (img) return img;

	img = new image;

	if (FAILED(img->init(fileName, x, y, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}


	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image * imageManager::addFrameImage(string strKey, const char * fileName, float x, float y, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	if (img) return img;

	img = new image;

	if (FAILED(img->init(fileName, x, y, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}
	//생성된 이미지를 맵으로 만든 이미지 목록에 추가한다.
	_mImageList.insert(make_pair(strKey, img));

	return img;

}

image * imageManager::addFrameImage(string strKey, const char * fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor)
{
	//추가 하려는 키값으로 이미지가 존재하는지 확인
	image* img = findImage(strKey);

	//추가하려는 이미지가 이미 있으면 리턴
	if (img) return img;

	img = new image;
	//이미지가 제대로 초기화 되지 않으면
	if (FAILED(img->init(fileName, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image * imageManager::findImage(string strKey)
{
	mapImageListIter key = _mImageList.find(strKey);

	if (key != _mImageList.end())
	{
		return key->second;
	}

	return NULL;
}

image * imageManager::findImage_Background(int _backgroundType)
{
	auto mapBackgroundTypeKeyIter = mapBackgroundTypeKey.find(_backgroundType);
	if (mapBackgroundTypeKeyIter != mapBackgroundTypeKey.end())
	{
		string key = mapBackgroundTypeKeyIter->second;
		return findImage(key);
	}
	return nullptr;
}

image * imageManager::findImage_Stage(int _stageType)
{
	auto mapStageTypekeyIter = mapStageTypeKey.find(_stageType);
	
	if (mapStageTypekeyIter != mapStageTypeKey.end())
	{
		string key = mapStageTypekeyIter->second;
		return findImage(key);
	}
	return nullptr;
}

image * imageManager::findImage_Character(int _characterType, int _animationState)
{
	auto mapCharacterTypeKeyIter = mapCharacterTypeKey.find(_characterType);
	auto mapAnimationStateKeyIter = mapAnimationStateKey.find(_animationState);

	if (mapCharacterTypeKeyIter != mapCharacterTypeKey.end() && mapAnimationStateKeyIter != mapAnimationStateKey.end())
	{
		string key = mapCharacterTypeKeyIter->second + "_" + mapAnimationStateKeyIter->second;
		return findImage(key);
	}
	return nullptr;
}

image * imageManager::findImage_Enemy(int _enemyType, int _animationState)
{
	auto mapEnemyTypeKeyIter = mapEnemyTypeKey.find(_enemyType);
	auto mapAnimationStateKeyIter = mapAnimationStateKey.find(_animationState);

	if (mapEnemyTypeKeyIter != mapEnemyTypeKey.end() && mapAnimationStateKeyIter != mapAnimationStateKey.end())
	{
		string key = mapEnemyTypeKeyIter->second + "_" + mapAnimationStateKeyIter->second;
		return findImage(key);
	}
	return nullptr;
}


image * imageManager::findImage_Projectile(int _projectileType)
{
	auto mapProjectileTypeKeyIter = mapProjectileTypeKey.find(_projectileType);
	
	if (mapProjectileTypeKeyIter != mapProjectileTypeKey.end())
	{
		string key = mapProjectileTypeKeyIter->second;
		return findImage(key);
	}
	return nullptr;
}

image * imageManager::findImage_Effect(int _effectType)
{
	auto mapEffectTypeKeyIter = mapEffectTypeKey.find(_effectType);
	
	if (mapEffectTypeKeyIter != mapEffectTypeKey.end())
	{
		string key = mapEffectTypeKeyIter->second;
		return findImage(key);
	}
	return nullptr;
}

image * imageManager::findImage_Particle(int _particleType)
{
	auto mapParticleTypeKeyIter = mapParticleTypeKey.find(_particleType);

	if (mapParticleTypeKeyIter != mapParticleTypeKey.end())
	{
		string key = mapParticleTypeKeyIter->second;
		return findImage(key);
	}

	return nullptr;
}

image * imageManager::findImage_Tile(int _tileType)
{
	auto mapTileTypeKeyIter = mapTileTypeKey.find(_tileType);
	
	if (mapTileTypeKeyIter != mapTileTypeKey.end())
	{
		string key = mapTileTypeKeyIter->second;
		return findImage(key);
	}
	return nullptr;
}

image * imageManager::findImage_Obstacle(int _obstacleType)
{
	auto mapObstacleTypeKeyIter = mapObstacleTypeKey.find(_obstacleType);

	if (mapObstacleTypeKeyIter != mapObstacleTypeKey.end())
	{
		string key = mapObstacleTypeKeyIter->second;
		return findImage(key);
	}
	return nullptr;
}

image * imageManager::findImage_Mouse(int _mouseState)
{
	auto mapMouseStateKeyIter = mapMouseStateKey.find(_mouseState);

	if (mapMouseStateKeyIter != mapMouseStateKey.end())
	{
		string key = mapMouseStateKeyIter->second;
		return findImage(key);
	}

	return nullptr;
}

bool imageManager::deleteImage(string strKey)
{
	//해당 키 검색
	mapImageListIter key = _mImageList.find(strKey);

	//키를 찾으면
	if (key != _mImageList.end())
	{
		key->second->release();
		SAFE_DELETE(key->second);
		_mImageList.erase(key);

		return true;
	}

	return false;
}

bool imageManager::deleteAll()
{

	//맵전체를 돌면서 삭제
	mapImageListIter iter = _mImageList.begin();

	for (iter; iter != _mImageList.end();)
	{
		if (iter->second != NULL)
		{
			SAFE_DELETE(iter->second);
			iter = _mImageList.erase(iter);
		}
		else ++iter;
	}

	_mImageList.clear();

	return true;
}

void imageManager::render(string strKey, HDC hdc)
{
	//이미지를 찾은 후 렌더
	image* img = findImage(strKey);
	if (img) img->render(hdc);
}

void imageManager::render(string strKey, HDC hdc, int destX, int destY)
{
	//이미지를 찾은 후 렌더
	image* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY);
}

void imageManager::render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	//이미지를 찾은 후 렌더
	image* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight);
}

void imageManager::frameRender(string strKey,HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	//이미지를 찾은 후 렌더
	image* img = findImage(strKey);

	if (img)img->frameRender(hdc, destX, destY, currentFrameX, currentFrameY);
}
