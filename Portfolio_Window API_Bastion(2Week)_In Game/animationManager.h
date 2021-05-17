#pragma once
#include"singletonBase.h"
//#include"image.h"
class animationManager : public singletonBase<animationManager>
{
private:
	typedef map<string, animation*> arrAnimation;
	typedef map<string, animation*>::iterator iterArrAnimation;

	arrAnimation _animation;

	map<int/*ANIMATION_STATE*/, string> mapAnimationStateKey;
	map<int/*DIRECTION_STATE*/, string> mapDirectionStateKey;

	map<int/*TILE_TYPE*/, string> mapTileTypeKey;
	map<int/*CHARACTER_TYPE*/, string> mapCharacterTypeKey;
	map<int/*ENEMY_TYPE*/, string> mapEnemyTypeKey;
	map<int/*PROJECTILE_TYPE*/, string> mapProjectileTypeKey;
	map<int/*EFFECT_TYPE*/, string> mapEffectTypeKey;
	map<int/*PARTICLE_TYPE*/, string> mapParticleTypeKey;
public:
	animationManager();
	~animationManager();


	HRESULT init();
	void release();
	void update();
	void render();

	//처음부터 끝까지
	void addDefAnimation(string animationKeyName, string imageKeyName, int fps, bool reverse = false, bool loop = false);
	//배열에 담아서
	void addAnimation(string animationKeyName, string imageKeyName, int* playArr, int arrLen, int fps, bool loop = false);
	//구간 정해서
	void addAnimation(string animationKeyName, string imageKeyName, int start, int end, int fps, bool reverse = false, bool loop = false);

	//플레이
	void start(string animationKeyName);
	//정지
	void stop(string animationKeyName);
	//일시정지
	void pause(string animationKeyName);
	//다시 재생
	void resume(string animationKeyName);

	//애니메이션 찾기
	animation* findAnimation(string animationKeyName);
	animation* findAnimation_Tile(int _tileType, int _animationState);
	animation* findAnimation_Characater(int _characterType, int _animationState, int _directionState);
	animation* findAnimation_Enemy(int _enemyType, int _animationState, int _directionState);
	animation* findAnimation_Projectile(int _projectileType, int _directionState);
	animation* findAnimation_Effect(int _effectType, int _directionState);
	animation* findAnimation_Particle(int _particleType);


	//애니메이션 찾기 삭제
	void deleteALL();
};

