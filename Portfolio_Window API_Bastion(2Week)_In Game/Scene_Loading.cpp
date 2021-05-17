#include "stdafx.h"
#include "Scene_Loading.h"
#include "loading.h"

HRESULT Scene_Loading::init()
{
	m_sceneType = SCENE_TYPE::SCENE_LOADING;

	_loading = new loading;
	_loading->init();

	// 이미지 로딩
	BackGroundImageLoading();
	StageImageLoading();
	TileImageLoading();
	ObstacleImageLoading();
	CharacterImageLoading();
	EnemyImageLoading();
	ProjectileImageLoading();
	EffectImageLoading();
	ParticleImageLoading();
	UIImageLoading();
	ETCImageLoading();

	//사운드 로딩
	SoundLoading();
	return S_OK;
}

void Scene_Loading::release()
{
	SAFE_DELETE(_loading)
}

void Scene_Loading::update()
{
	_loading->update();

	if (_loading->loadingDone())
	{
		SCENEMANAGER->changeScene("Scene_MainGame");
	}
}

void Scene_Loading::render()
{
	_loading->render();
}

void Scene_Loading::BackGroundImageLoading()
{
	_loading->loadImage("Background0", "images/Background/Background0.bmp", 1536, 768);
	_loading->loadImage("Background1", "images/Background/Background1.bmp", 1536, 768);
	_loading->loadImage("Background2", "images/Background/Background2.bmp", 1486, 768);
	_loading->loadImage("Background3", "images/Background/Background3.bmp", 1365, 768);
}

void Scene_Loading::StageImageLoading()
{
	_loading->loadFrameImage("Stage1", "images/Stage/Stage1.bmp", 1550, 1000, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Stage2", "images/Stage/Stage2.bmp", 1550, 1000, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Stage3", "images/Stage/Stage3.bmp", 1550, 1000, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Stage4", "images/Stage/Stage4.bmp", 1550, 1000, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Stage5", "images/Stage/Stage5.bmp", 3600, 2450, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Stage6", "images/Stage/Stage6.bmp", 1856, 1488, 1, 1, true, RGB(255, 255, 255));
}

void Scene_Loading::CharacterImageLoading()
{
	// 플레이어 이미지
	_loading->loadFrameImage("Kid_Idle", "images/Character/Kid/Kid_Idle.bmp", 3968, 1056, 32, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Kid_Move", "images/Character/Kid/Kid_Move.bmp", 3200, 1120, 20, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Kid_Tumbling", "images/Character/Kid/Kid_Tumbling.bmp", 3250, 2000, 13, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Kid_Smash", "images/Character/Kid/Kid_Smash.bmp", 6500, 4000, 13, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Kid_Shoot", "images/Character/Kid/Kid_Shoot.bmp", 3600, 2400, 12, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Kid_Drink", "images/Character/Kid/Kid_Drink.bmp", 2200, 128, 22, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Kid_Wake_Up", "images/Character/Kid/Kid_Wake_Up.bmp", 11352, 128, 66, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Kid_Stand_Up", "images/Character/Kid/Kid_Stand_Up.bmp", 13200, 200, 66, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Kid_Die", "images/Character/Kid/Kid_Die.bmp", 6536, 148, 38, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Kid_Fall", "images/Character/Kid/Kid_Fall.bmp", 5828, 200, 31, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Kid_Upper", "images/Character/Kid/Kid_Upper.bmp", 4800, 3200, 12, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Kid_Finish", "images/Character/Kid/Kid_Finish.bmp", 7168, 300, 56, 1, true, RGB(255, 255, 255));
}

void Scene_Loading::EnemyImageLoading()
{
	// 몬스터 이미지
	_loading->loadFrameImage("Ura_Sword_Idle", "images/Enemy/Ura_Sword/Ura_Sword_Idle.bmp", 960, 1290, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Sword_Move", "images/Enemy/Ura_Sword/Ura_Sword_Move.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Sword_Hit", "images/Enemy/Ura_Sword/Ura_Sword_Hit.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Sword_Attack", "images/Enemy/Ura_Sword/Ura_Sword_Attack.bmp", 4160, 1920, 13, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Sword_Die", "images/Enemy/Ura_Sword/Ura_Sword_Die.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));

	_loading->loadFrameImage("Ura_Crossbow_Idle", "images/Enemy/Ura_Crossbow/Ura_Crossbow_Idle.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Crossbow_Move", "images/Enemy/Ura_Crossbow/Ura_Crossbow_Move.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Crossbow_Hit", "images/Enemy/Ura_Crossbow/Ura_Crossbow_Hit.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Crossbow_Attack", "images/Enemy/Ura_Crossbow/Ura_Crossbow_Attack.bmp", 1920, 1920, 6, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Crossbow_Die", "images/Enemy/Ura_Crossbow/Ura_Crossbow_Die.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));

	_loading->loadFrameImage("Ura_Halberd_Idle", "images/Enemy/Ura_Halberd/Ura_Halberd_Idle.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Halberd_Move", "images/Enemy/Ura_Halberd/Ura_Halberd_Move.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Halberd_Hit", "images/Enemy/Ura_Halberd/Ura_Halberd_Hit.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Halberd_Attack", "images/Enemy/Ura_Halberd/Ura_Halberd_Attack.bmp", 4160, 1920, 13, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Halberd_Die", "images/Enemy/Ura_Halberd/Ura_Halberd_Die.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));

	_loading->loadFrameImage("Ura_Rifle_Idle", "images/Enemy/Ura_Rifle/Ura_Rifle_Idle.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Rifle_Move", "images/Enemy/Ura_Rifle/Ura_Rifle_Move.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Rifle_Hit", "images/Enemy/Ura_Rifle/Ura_Rifle_Hit.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Rifle_Attack", "images/Enemy/Ura_Rifle/Ura_Rifle_Attack.bmp", 2880, 1920, 9, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Rifle_Die", "images/Enemy/Ura_Rifle/Ura_Rifle_Die.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));

	_loading->loadFrameImage("Ura_Boss_Idle", "images/Enemy/Ura_Boss/Ura_Boss_Idle.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Boss_Move", "images/Enemy/Ura_Boss/Ura_Boss_Move.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Boss_Hit", "images/Enemy/Ura_Boss/Ura_Boss_Hit.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Boss_Attack", "images/Enemy/Ura_Boss/Ura_Boss_Attack.bmp", 4160, 1920, 13, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Ura_Boss_Die", "images/Enemy/Ura_Boss/Ura_Boss_Die.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));

	_loading->loadFrameImage("Pecker_Idle", "images/Enemy/Pecker/Pecker_Idle.bmp", 6804, 1072, 42, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Pecker_Die", "images/Enemy/Pecker/Pecker_Die.bmp", 6804, 1072, 42, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Pecker_Hit", "images/Enemy/Pecker/Pecker_Hit.bmp", 6804, 1072, 42, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Pecker_Move", "images/Enemy/Pecker/Pecker_Move.bmp", 6804, 1072, 42, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Pecker_Attack", "images/Enemy/Pecker/Pecker_Attack.bmp", 5120, 1216, 32, 8, true, RGB(255, 255, 255));

	_loading->loadFrameImage("RattleTail_Idle", "images/Enemy/RattleTail/RattleTail_Idle.bmp", 484, 927, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("RattleTail_Hit", "images/Enemy/RattleTail/RattleTail_Hit.bmp", 484, 927, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("RattleTail_Die", "images/Enemy/RattleTail/RattleTail_Die.bmp", 484, 927, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("RattleTail_Move", "images/Enemy/RattleTail/RattleTail_Move.bmp", 2640, 784, 20, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("RattleTail_Attack", "images/Enemy/RattleTail/RattleTail_Attack.bmp", 2640, 784, 20, 8, true, RGB(255, 255, 255));

	_loading->loadFrameImage("Mechanical_Pyth_Idle", "images/Enemy/Mechanical_Pyth/Mechanical_Pyth_Idle.bmp", 468, 1216, 2, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Mechanical_Pyth_Move", "images/Enemy/Mechanical_Pyth/Mechanical_Pyth_Move.bmp", 468, 1216, 2, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Mechanical_Pyth_Hit", "images/Enemy/Mechanical_Pyth/Mechanical_Pyth_Hit.bmp", 468, 1216, 2, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Mechanical_Pyth_Attack", "images/Enemy/Mechanical_Pyth/Mechanical_Pyth_Attack.bmp", 468, 1216, 2, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Mechanical_Pyth_Die", "images/Enemy/Mechanical_Pyth/Mechanical_Pyth_Die.bmp", 468, 1216, 2, 8, true, RGB(255, 255, 255));

	_loading->loadFrameImage("Turret_Idle", "images/Enemy/Turret/Turret_Idle.bmp", 172, 880, 2, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Turret_Move", "images/Enemy/Turret/Turret_Move.bmp", 172, 880, 2, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Turret_Hit", "images/Enemy/Turret/Turret_Hit.bmp", 172, 880, 2, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Turret_Attack", "images/Enemy/Turret/Turret_Attack.bmp", 172, 880, 2, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Turret_Die", "images/Enemy/Turret/Turret_Die.bmp", 172, 880, 2, 8, true, RGB(255, 255, 255));
}

void Scene_Loading::ProjectileImageLoading()
{
	//투사체 이미지
	_loading->loadFrameImage("Projectile_Arrow", "images/Projectile/Projectile_Arrow.bmp", 140, 560, 2, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Projectile_Bullet_Red", "images/Projectile/Projectile_Bullet_Red.bmp", 50, 27, 2, 1, true, RGB(0, 0, 0));
	_loading->loadFrameImage("Projectile_Bullet_Green", "images/Projectile/Projectile_Bullet_Green.bmp", 50, 27, 2, 1, true, RGB(0, 0, 0));
	_loading->loadFrameImage("Projectile_Bullet_Blue", "images/Projectile/Projectile_Bullet_Blue.bmp", 50, 27, 2, 1, true, RGB(0, 0, 0));
	_loading->loadFrameImage("Projectile_Aura", "images/Projectile/Projectile_Aura.bmp", 12000, 250, 48, 1, true, RGB(0, 0, 0));
}

void Scene_Loading::EffectImageLoading()
{
	_loading->loadFrameImage("Effect_Breath", "images/Effect/Effect_Breath.bmp", 3500, 4000, 7, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Bullet", "images/Effect/Effect_Bullet.bmp", 600, 150, 4, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Counter", "images/Effect/Effect_Counter.bmp", 2304, 256, 9, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Crack", "images/Effect/Effect_Crack.bmp", 1256, 130, 8, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Explosion", "images/Effect/Effect_Explosion.bmp", 22528, 768, 22, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Fire", "images/Effect/Effect_Fire.bmp", 1680, 134, 12, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Meteor", "images/Effect/Effect_Meteor.bmp", 6016, 369, 16, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Smoke", "images/Effect/Effect_Smoke.bmp", 512, 129, 4, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Bullet_Fire_Red", "images/Effect/Effect_Bullet_Fire_Red.bmp", 3180 / 2, 260 / 2, 12, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Bullet_Fire_Blue", "images/Effect/Effect_Bullet_Fire_Blue.bmp", 3180 / 2, 260 / 2, 12, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Bullet_Fire_Green", "images/Effect/Effect_Bullet_Fire_Green.bmp", 3180 / 2, 260 / 2, 12, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Bullet_Hit_Red", "images/Effect/Effect_Bullet_Hit_Red.bmp", 750, 150, 5, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Bullet_Hit_Green", "images/Effect/Effect_Bullet_Hit_Green.bmp", 750, 150, 5, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Bullet_Hit_Blue", "images/Effect/Effect_Bullet_Hit_Blue.bmp", 750, 150, 5, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Restore", "images/Effect/Effect_Restore.bmp", 5760, 192, 30, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Spectrum_Ura_Boss", "images/Effect/Effect_Spectrum_Ura_Boss.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Spectrum_Ura_Halberd", "images/Effect/Effect_Spectrum_Ura_Halberd.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Spectrum_Ura_Crossbow", "images/Effect/Effect_Spectrum_Ura_Crossbow.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Spectrum_Ura_Rifle", "images/Effect/Effect_Spectrum_Ura_Rifle.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Effect_Spectrum_Ura_Sword", "images/Effect/Effect_Spectrum_Ura_Sword.bmp", 960, 1920, 3, 8, true, RGB(255, 255, 255));
}

void Scene_Loading::ParticleImageLoading()
{
	_loading->loadFrameImage("Particle_Leaf1", "images/Particle/Particle_Leaf1.bmp", 1950, 50, 39, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Particle_Leaf2", "images/Particle/Particle_Leaf2.bmp", 1200, 50, 24, 1, true, RGB(255, 255, 255));
}

void Scene_Loading::TileImageLoading()
{
	_loading->loadFrameImage("Tile0", "images/Tile/Tile0.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile1", "images/Tile/Tile1.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile2", "images/Tile/Tile2.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile3", "images/Tile/Tile3.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile4", "images/Tile/Tile4.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile5", "images/Tile/Tile5.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile6", "images/Tile/Tile6.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile7", "images/Tile/Tile7.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile8", "images/Tile/Tile8.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile9", "images/Tile/Tile9.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile10", "images/Tile/Tile10.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile11", "images/Tile/Tile11.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile12", "images/Tile/Tile12.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile13", "images/Tile/Tile13.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile14", "images/Tile/Tile14.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile15", "images/Tile/Tile15.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile16", "images/Tile/Tile16.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile17", "images/Tile/Tile17.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile18", "images/Tile/Tile18.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile19", "images/Tile/Tile19.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile20", "images/Tile/Tile20.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile21", "images/Tile/Tile21.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile22", "images/Tile/Tile22.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile23", "images/Tile/Tile23.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile24", "images/Tile/Tile24.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile25", "images/Tile/Tile25.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile26", "images/Tile/Tile26.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile27", "images/Tile/Tile27.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile28", "images/Tile/Tile28.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile29", "images/Tile/Tile29.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile30", "images/Tile/Tile30.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile31", "images/Tile/Tile31.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile32", "images/Tile/Tile32.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile33", "images/Tile/Tile33.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile34", "images/Tile/Tile34.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile35", "images/Tile/Tile35.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile36", "images/Tile/Tile36.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile37", "images/Tile/Tile37.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile38", "images/Tile/Tile38.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile39", "images/Tile/Tile39.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile40", "images/Tile/Tile40.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile41", "images/Tile/Tile41.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile42", "images/Tile/Tile42.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile43", "images/Tile/Tile43.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile44", "images/Tile/Tile44.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile45", "images/Tile/Tile45.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile46", "images/Tile/Tile46.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile47", "images/Tile/Tile47.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile48", "images/Tile/Tile48.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile55", "images/Tile/Tile55.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile56", "images/Tile/Tile56.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile57", "images/Tile/Tile57.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile58", "images/Tile/Tile58.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("Tile59", "images/Tile/Tile59.bmp", 1000, 200, 5, 1, true, RGB(255, 0, 255));
}

void Scene_Loading::ObstacleImageLoading()
{
	_loading->loadFrameImage("Obstacle_Non_Broken_0", "images/Obstacle/Non_Broken/0_1.bmp", 188, 172, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_1", "images/Obstacle/Non_Broken/1_1.bmp", 78, 130, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_2", "images/Obstacle/Non_Broken/2_1.bmp", 88, 139, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_3", "images/Obstacle/Non_Broken/3_1.bmp", 168, 114, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_4", "images/Obstacle/Non_Broken/4_1.bmp", 206, 103, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_5", "images/Obstacle/Non_Broken/5_1.bmp", 127, 153, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_6", "images/Obstacle/Non_Broken/6_1.bmp", 214, 403, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_7", "images/Obstacle/Non_Broken/7_1.bmp", 93, 500, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_8", "images/Obstacle/Non_Broken/8_1.bmp", 108, 130, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_9", "images/Obstacle/Non_Broken/9_1.bmp", 158, 177, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_10", "images/Obstacle/Non_Broken/10_1.bmp", 83, 70, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_11", "images/Obstacle/Non_Broken/11_1.bmp", 127, 92, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_12", "images/Obstacle/Non_Broken/12_1.bmp", 152, 98, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_13", "images/Obstacle/Non_Broken/13_1.bmp", 345, 455, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_14", "images/Obstacle/Non_Broken/14_1.bmp", 75, 69, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_15", "images/Obstacle/Non_Broken/15_1.bmp", 312, 159, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_16", "images/Obstacle/Non_Broken/16_1.bmp", 91, 90, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_17", "images/Obstacle/Non_Broken/17_1.bmp", 125, 76, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_18", "images/Obstacle/Non_Broken/18_1.bmp", 80, 405, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_19", "images/Obstacle/Non_Broken/19_1.bmp", 79, 62, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_20", "images/Obstacle/Non_Broken/20_1.bmp", 112, 82, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_21", "images/Obstacle/Non_Broken/21_1.bmp", 106, 83, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_22", "images/Obstacle/Non_Broken/22_1.bmp", 172, 319, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_23", "images/Obstacle/Non_Broken/23_1.bmp", 147, 248, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_24", "images/Obstacle/Non_Broken/24_1.bmp", 136, 244, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_25", "images/Obstacle/Non_Broken/25_1.bmp", 162, 95, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_26", "images/Obstacle/Non_Broken/26_1.bmp", 500, 500, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_27", "images/Obstacle/Non_Broken/27_1.bmp", 149, 139, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Non_Broken_28", "images/Obstacle/Non_Broken/28_1.bmp", 294, 241, 1, 1, true, RGB(255, 255, 255));

	_loading->loadFrameImage("Obstacle_Broken_27", "images/Obstacle/Broken/27_1.bmp", 50, 90, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Broken_28", "images/Obstacle/Broken/28_1.bmp", 117, 176, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Broken_29", "images/Obstacle/Broken/29_1.bmp", 173, 140, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Broken_30", "images/Obstacle/Broken/30_1.bmp", 192, 138, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Broken_31", "images/Obstacle/Broken/31_1.bmp", 162, 137, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Broken_32", "images/Obstacle/Broken/32_1.bmp", 166, 146, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Broken_33", "images/Obstacle/Broken/33_1.bmp", 143, 125, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Broken_34", "images/Obstacle/Broken/34_1.bmp", 159, 110, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Broken_37", "images/Obstacle/Broken/35_1.bmp", 68, 60, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Broken_35", "images/Obstacle/Broken/36_1.bmp", 116, 97, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Broken_36", "images/Obstacle/Broken/37_1.bmp", 112, 94, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Broken_38", "images/Obstacle/Broken/38_1.bmp", 127, 140, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Broken_39", "images/Obstacle/Broken/39_1.bmp", 74, 94, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Broken_40", "images/Obstacle/Broken/40_1.bmp", 173, 140, 1, 1, true, RGB(255, 255, 255));
	_loading->loadFrameImage("Obstacle_Broken_41", "images/Obstacle/Broken/41_1.bmp", 60, 48, 1, 1, true, RGB(255, 255, 255));
}

void Scene_Loading::UIImageLoading()
{
	//UI 관련 이미지
	_loading->loadImage("UI_Background", "images/UI/Background/Background.bmp", 1024, 768, true, RGB(255, 255, 255));


	_loading->loadImage("Pack", "images/UI/Pack/Pack.bmp", 1024, 576, true, RGB(255, 0, 255));
	_loading->loadImage("Equip", "images/UI/Equip/Equip.bmp", 1024, 576 - 100, true, RGB(255, 0, 255));
	_loading->loadImage("Distillery_1", "images/UI/Distillery/Distillery_1.bmp", WINSIZEX, WINSIZEY);

	_loading->loadImage("StatusBar_PC_HP", "images/UI/StatusBar/StatusBar_PC_HP.bmp", 384, 26, true, RGB(255, 0, 255));
	_loading->loadImage("StatusBar_PC_EXP", "images/UI/StatusBar/StatusBar_PC_EXP.bmp", 151, 14, true, RGB(255, 0, 255));
	_loading->loadImage("StatusBar_Enemy_HP", "images/UI/StatusBar/StatusBar_Enemy_HP.bmp", 100, 7, true, RGB(255, 0, 255));

	_loading->loadImage("Pause_List", "images/UI/Pause/Pause_List.bmp", 600, 720, true, RGB(255, 255, 255));
	_loading->loadImage("Pause_Background", "images/UI/Pause/Pause_Background.bmp", WINSIZEX, WINSIZEY);
	_loading->loadImage("Pause_Button_ResumeGame", "images/UI/Pause/Pause_Button_ResumeGame.bmp", 146, 26, true, RGB(255, 255, 255));
	_loading->loadImage("Pause_Button_ResumeGame_Bold", "images/UI/Pause/Pause_Button_ResumeGame_Bold.bmp", 146, 26, true, RGB(255, 255, 255));
	_loading->loadImage("Pause_Button_ExitMenu", "images/UI/Pause/Pause_Button_ExitMenu.bmp", 188, 25, true, RGB(255, 255, 255));
	_loading->loadImage("Pause_Button_ExitMenu_Bold", "images/UI/Pause/Pause_Button_ExitMenu_Bold.bmp", 188, 25, true, RGB(255, 255, 255));
	_loading->loadImage("Pause_Button_Background", "images/UI/Pause/Pause_Button_Background.bmp", 400, 75);
}

void Scene_Loading::ETCImageLoading()
{
	_loading->loadImage("Shadow", "images/Shadow.bmp", 100, 100, true, RGB(255, 255, 255));
}

void Scene_Loading::SoundLoading()
{
	// BGM
	_loading->loadForSound("BGM_Stage1", "sound/BGM/BGM_Stage1.mp3", true, true);
	_loading->loadForSound("BGM_Stage2", "sound/BGM/BGM_Stage2.mp3", true, true);

	// Player_Effect
	_loading->loadForSound("Effect_Player_Move", "sound/Effect/Effect_Player_Move.mp3");
	_loading->loadForSound("Effect_Player_Tumbling", "sound/Effect/Effect_Player_Tumbling.wav");
	_loading->loadForSound("Effect_Player_Smash", "sound/Effect/Effect_Player_Smash.wav");
	_loading->loadForSound("Effect_Player_Shoot", "sound/Effect/Effect_Player_Shoot.wav");
	_loading->loadForSound("Effect_Player_Counter", "sound/Effect/Effect_Player_Counter.wav");
	_loading->loadForSound("Effect_Player_Upper", "sound/Effect/Effect_Player_Upper.wav");
	_loading->loadForSound("Effect_Player_Meteor", "sound/Effect/Effect_Player_Meteor.mp3");
	_loading->loadForSound("Effect_Player_Restore", "sound/Effect/Effect_Player_Restore.mp3");
	_loading->loadForSound("Effect_Player_LevelUp", "sound/Effect/Effect_Player_LevelUp.mp3");
	_loading->loadForSound("Effect_Player_Fall", "sound/Effect/Effect_Player_Fall.wav");
	_loading->loadForSound("Effect_Player_Hit", "sound/Effect/Effect_Player_Hit.wav");
	_loading->loadForSound("Effect_Player_Die", "sound/Effect/Effect_Player_Die.wav");

	// Enemy_Effect
	_loading->loadForSound("Effect_Ura_Move", "sound/Effect/Effect_Ura_Move.wav");
	_loading->loadForSound("Effect_Ura_Sword_Attack", "sound/Effect/Effect_Ura_Sword_Attack.wav");
	_loading->loadForSound("Effect_Ura_Crossbow_Attack", "sound/Effect/Effect_Ura_Crossbow_Attack.wav");
	_loading->loadForSound("Effect_Ura_Halberd_Attack", "sound/Effect/Effect_Ura_Halberd_Attack.wav");
	_loading->loadForSound("Effect_Ura_Rifle_Attack", "sound/Effect/Effect_Ura_Rifle_Attack.wav");
	_loading->loadForSound("Effect_Ura_Boss_Attack", "sound/Effect/Effect_Ura_Boss_Attack.wav");
	
	_loading->loadForSound("Effect_RattleTail_Move", "sound/Effect/Effect_RattleTail_Move.wav");
	_loading->loadForSound("Effect_RattleTail_Attack", "sound/Effect/Effect_RattleTail_Attack.wav");

	_loading->loadForSound("Effect_Pecker_Move", "sound/Effect/Effect_Pecker_Move.mp3");
	_loading->loadForSound("Effect_Pecker_Attack", "sound/Effect/Effect_Pecker_Attack.wav");

	_loading->loadForSound("Effect_Mechanical_Pyth_Move", "sound/Effect/Effect_Mechanical_Pyth_Move.mp3");
	_loading->loadForSound("Effect_Mechanical_Pyth_Attack", "sound/Effect/Effect_Mechanical_Pyth_Attack.wav");

	_loading->loadForSound("Effect_Turret_Attack", "sound/Effect/Effect_Turret_Attack.wav");
}

Scene_Loading::Scene_Loading()
{
}


Scene_Loading::~Scene_Loading()
{
}
