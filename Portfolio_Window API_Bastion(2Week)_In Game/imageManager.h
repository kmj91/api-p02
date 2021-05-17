#pragma once
#include"singletonBase.h"
#include"image.h"
class imageManager : public singletonBase<imageManager>
{

private:
	//������ ���� �̹��� ���
	typedef map<string, image*> mapImageList;
	//������ ���� �̹��� ����� �ݺ���
	typedef map<string, image*>::iterator mapImageListIter;

	mapImageList _mImageList;

	map<int/*ANIMATION_STATE*/, string> mapAnimationStateKey;
	map<int/*MOUSE_STATE*/, string> mapMouseStateKey;

	map<int/*BACKGROUND_TYPE*/, string> mapBackgroundTypeKey;
	map<int/*STAGE_TYPE*/, string> mapStageTypeKey;
	map<int/*TILE_TYPE*/, string> mapTileTypeKey;
	map<int/*OBSTACLE_TYPE*/, string> mapObstacleTypeKey;
	map<int/*CHARACTER_TYPE*/, string> mapCharacterTypeKey;
	map<int/*ENEMY_TYPE*/, string> mapEnemyTypeKey;
	map<int/*PROJECTILE_TYPE*/, string> mapProjectileTypeKey;
	map<int/*EFFECT_TYPE*/, string> mapEffectTypeKey;
	map<int/*PARTICLE_TYPE*/, string> mapParticleTypeKey;
public:
	imageManager();
	~imageManager();


	HRESULT init();
	void release();
	//Ű ������ �� ��Ʈ�� �ʱ�ȭ
	image* addImage(string strKey, int width, int height);
	//Ű������ �̹��� ���� �ʱ�ȭ
	image* addImage(string strKey, const char* fileName, int width, int height, bool trans = false, COLORREF transColor =  RGB(255,0,255));
	image* addImage(string strKey, const char* fileName, float x, float y, int width, int height, bool trans = false, COLORREF transColor = RGB(255, 0, 255));
	//Ű������ ������ �̹��� ���� �ʱ�ȭ
	image* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool trans = false, COLORREF transColor = RGB(255, 0, 255));
	image* addFrameImage(string strKey, const char* fileName, int width, int height, int frameX, int frameY, bool trans = false, COLORREF transColor = RGB(255, 0, 255));

	//�̹��� Ű������ ã��
	image* findImage(string strKey);
	image* findImage_Background(int _backgroundType);
	image* findImage_Stage(int _stageType);
	image* findImage_Tile(int _tileType);
	image* findImage_Obstacle(int _obstacleType);
	image* findImage_Character(int _characterType, int _animationState);
	image* findImage_Enemy(int _enemyType, int _animationState);
	image* findImage_Projectile(int _projectileType);
	image* findImage_Effect(int _effectType);
	image* findImage_Particle(int _particleType);
	image* findImage_Mouse(int _mouseState);

	//�̹��� Ű������ ����
	bool deleteImage(string strKey);
	//�̹��� ��ü����
	bool deleteAll();


	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);
	void render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

};

