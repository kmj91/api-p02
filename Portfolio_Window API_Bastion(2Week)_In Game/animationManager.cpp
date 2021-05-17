#include "stdafx.h"
#include "animationManager.h"

animationManager::animationManager()
{
}

animationManager::~animationManager()
{
}

HRESULT animationManager::init()
{
	// 애니메이션 상태에 대한 키 값 세팅
	mapAnimationStateKey.insert(make_pair(ANIMATION_STATE::ANIMATION_NONE, "Ani_None"));
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


	// 방향 상태에 따른 키 값 세팅
	mapDirectionStateKey.insert(make_pair(DIRECTION_STATE::DIRECTION_NONE, "Dir_None"));
	mapDirectionStateKey.insert(make_pair(DIRECTION_STATE::DOWN, "Down"));
	mapDirectionStateKey.insert(make_pair(DIRECTION_STATE::UP, "Up"));
	mapDirectionStateKey.insert(make_pair(DIRECTION_STATE::LEFT_UP, "Left_Up"));
	mapDirectionStateKey.insert(make_pair(DIRECTION_STATE::RIGHT_UP, "Right_Up"));
	mapDirectionStateKey.insert(make_pair(DIRECTION_STATE::LEFT, "Left"));
	mapDirectionStateKey.insert(make_pair(DIRECTION_STATE::RIGHT, "Right"));
	mapDirectionStateKey.insert(make_pair(DIRECTION_STATE::LEFT_DOWN, "Left_Down"));
	mapDirectionStateKey.insert(make_pair(DIRECTION_STATE::RIGHT_DOWN, "Right_Down"));


	// 캐릭터 타입에 대한 키 값 세팅
	mapCharacterTypeKey.insert(make_pair(CHARACTER_TYPE::CHARACTER_KID, "Kid"));


	// 적 타입에 대한 키 값 세팅
	mapEnemyTypeKey.insert(make_pair(ENEMY_TYPE::ENEMY_URA_SWORD, "Ura_Sword"));
	mapEnemyTypeKey.insert(make_pair(ENEMY_TYPE::ENEMY_URA_CROSSBOW, "Ura_Crossbow"));
	mapEnemyTypeKey.insert(make_pair(ENEMY_TYPE::ENEMY_URA_HALBERD, "Ura_Halberd"));
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

	return S_OK;
}

void animationManager::release()
{
	deleteALL();
}

void animationManager::update()
{
	iterArrAnimation iter = _animation.begin();
	for (iter; iter != _animation.end(); ++iter)
	{
		if (!iter->second->isPlay()) continue;
		iter->second->frameUpdate(TIMEMANAGER->getElapsedTime() * 1.0f);
	}
}

void animationManager::render()
{
}

void animationManager::addDefAnimation(string animationKeyName, string imageKeyName, int fps, bool reverse, bool loop)
{
	//이미지 및 애니메이션 초기화
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setDefPlayFrame(reverse, loop);
	ani->setFPS(fps);

	//이미지와 애니메이션을 초기화 후 맵에 추가한다.
	_animation.insert(make_pair(animationKeyName, ani));
}

void animationManager::addAnimation(string animationKeyName, string imageKeyName, int * playArr, int arrLen, int fps, bool loop)
{
	//이미지 및 애니메이션 초기화
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(playArr, arrLen, loop);
	ani->setFPS(fps);

	//이미지와 애니메이션을 초기화 후 맵에 추가한다.
	_animation.insert(make_pair(animationKeyName, ani));
}

void animationManager::addAnimation(string animationKeyName, string imageKeyName, int start, int end, int fps, bool reverse, bool loop)
{
	//이미지 및 애니메이션 초기화
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(start, end, reverse, loop);
	ani->setFPS(fps);

	//이미지와 애니메이션을 초기화 후 맵에 추가한다.
	_animation.insert(make_pair(animationKeyName, ani));
}

void animationManager::start(string animationKeyName)
{
	iterArrAnimation iter = _animation.find(animationKeyName);
	iter->second->start();
}

void animationManager::stop(string animationKeyName)
{
	iterArrAnimation iter = _animation.find(animationKeyName);
	iter->second->stop();
}

void animationManager::pause(string animationKeyName)
{
	iterArrAnimation iter = _animation.find(animationKeyName);
	iter->second->pause();
}

void animationManager::resume(string animationKeyName)
{
	iterArrAnimation iter = _animation.find(animationKeyName);
	iter->second->resume();
}

animation * animationManager::findAnimation(string animationKeyName)
{
	iterArrAnimation iter = _animation.find(animationKeyName);
	if (iter != _animation.end())
	{
		return iter->second;
	}

	return nullptr;
}

animation * animationManager::findAnimation_Characater(int _characterType, int _animationState, int _directionState)
{
	auto mapCharacterTypeKeyIter = mapCharacterTypeKey.find(_characterType);
	auto mapAnimationStateKeyIter = mapAnimationStateKey.find(_animationState);
	auto mapDirectionStateKeyIter = mapDirectionStateKey.find(_directionState);

	if (mapCharacterTypeKeyIter != mapCharacterTypeKey.end() && mapAnimationStateKeyIter != mapAnimationStateKey.end() && mapDirectionStateKeyIter != mapDirectionStateKey.end())
	{
		string key = mapCharacterTypeKeyIter->second + "_" + mapAnimationStateKeyIter->second + "_" + mapDirectionStateKeyIter->second;
		return findAnimation(key);
	}
	return nullptr;
}



animation * animationManager::findAnimation_Enemy(int _enemyType, int _animationState, int _directionState)
{
	auto mapEnemyTypeKeyIter = mapEnemyTypeKey.find(_enemyType);
	auto mapAnimationStateKeyIter = mapAnimationStateKey.find(_animationState);
	auto mapDirectionStateKeyIter = mapDirectionStateKey.find(_directionState);

	if (mapEnemyTypeKeyIter != mapEnemyTypeKey.end() && mapAnimationStateKeyIter != mapAnimationStateKey.end() && mapDirectionStateKeyIter != mapDirectionStateKey.end())
	{
		string key = mapEnemyTypeKeyIter->second + "_" + mapAnimationStateKeyIter->second + "_" + mapDirectionStateKeyIter->second;
		return findAnimation(key);
	}
	return nullptr;
}

animation * animationManager::findAnimation_Projectile(int _projectileType, int _directionState)
{
	auto mapProjectileTypeKeyIter = mapProjectileTypeKey.find(_projectileType);
	auto mapDirectionStateKeyIter = mapDirectionStateKey.find(_directionState);

	if (mapProjectileTypeKeyIter != mapProjectileTypeKey.end() && mapDirectionStateKeyIter != mapDirectionStateKey.end())
	{
		string key = mapProjectileTypeKeyIter->second + "_" + mapDirectionStateKeyIter->second;
		return findAnimation(key);
	}
	return nullptr;
}

animation * animationManager::findAnimation_Effect(int _effectType, int _directionState)
{
	auto mapEffectTypeKeyIter = mapEffectTypeKey.find(_effectType);
	auto mapDirectionStateKeyIter = mapDirectionStateKey.find(_directionState);

	if (mapEffectTypeKeyIter != mapEffectTypeKey.end() && mapDirectionStateKeyIter != mapDirectionStateKey.end())
	{
		string key = mapEffectTypeKeyIter->second + "_" + mapDirectionStateKeyIter->second;
		return findAnimation(key);
	}
	return nullptr;
}

animation * animationManager::findAnimation_Particle(int _particleType)
{
	auto mapParticleTypeKeyIter = mapParticleTypeKey.find(_particleType);

	if (mapParticleTypeKeyIter != mapParticleTypeKey.end())
	{
		string key = mapParticleTypeKeyIter->second;
		return findAnimation(key);
	}
	return nullptr;
}

animation * animationManager::findAnimation_Tile(int _tileType, int _animationState)
{
	auto mapTileTypeKeyIter = mapTileTypeKey.find(_tileType);
	auto mapAnimationStateKeyIter = mapAnimationStateKey.find(_animationState);
	
	if (mapTileTypeKeyIter != mapTileTypeKey.end() && mapAnimationStateKeyIter != mapAnimationStateKey.end())
	{
		string key = mapTileTypeKeyIter->second + "_" + mapAnimationStateKeyIter->second;
		return findAnimation(key);
	}
	return nullptr;
}



void animationManager::deleteALL()
{
	iterArrAnimation iter = _animation.begin();
	for (; iter != _animation.end();)
	{
		if (iter->second != NULL)
		{
			//애니메이션 클래스 삭제
			SAFE_DELETE(iter->second);
			//반복자 삭제
			iter = _animation.erase(iter);
		}
		else
		{
			++iter;
		}
	}
}
