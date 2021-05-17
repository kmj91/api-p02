#pragma once
#include "Scene.h"

class loading;
class Scene_Loading :
	public Scene
{
private:
	loading* _loading;
public:
	HRESULT init();
	void release();
	void update();
	void render();
public:
	void BackGroundImageLoading();
	void StageImageLoading();
	void TileImageLoading();
	void ObstacleImageLoading();
	void CharacterImageLoading();
	void EnemyImageLoading();
	void ProjectileImageLoading();
	void EffectImageLoading();
	void ParticleImageLoading();
	void UIImageLoading();
	void ETCImageLoading();



	void SoundLoading();
public:
	Scene_Loading();
	virtual ~Scene_Loading();
};

