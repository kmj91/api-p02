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

	//ó������ ������
	void addDefAnimation(string animationKeyName, string imageKeyName, int fps, bool reverse = false, bool loop = false);
	//�迭�� ��Ƽ�
	void addAnimation(string animationKeyName, string imageKeyName, int* playArr, int arrLen, int fps, bool loop = false);
	//���� ���ؼ�
	void addAnimation(string animationKeyName, string imageKeyName, int start, int end, int fps, bool reverse = false, bool loop = false);

	//�÷���
	void start(string animationKeyName);
	//����
	void stop(string animationKeyName);
	//�Ͻ�����
	void pause(string animationKeyName);
	//�ٽ� ���
	void resume(string animationKeyName);

	//�ִϸ��̼� ã��
	animation* findAnimation(string animationKeyName);
	animation* findAnimation_Tile(int _tileType, int _animationState);
	animation* findAnimation_Characater(int _characterType, int _animationState, int _directionState);
	animation* findAnimation_Enemy(int _enemyType, int _animationState, int _directionState);
	animation* findAnimation_Projectile(int _projectileType, int _directionState);
	animation* findAnimation_Effect(int _effectType, int _directionState);
	animation* findAnimation_Particle(int _particleType);


	//�ִϸ��̼� ã�� ����
	void deleteALL();
};

