#pragma once
#include "singletonBase.h"

enum OBJECT_TYPE;
enum PROJECTILE_TYPE;
class Projectile;
class ProjectileManager :
	public singletonBase<ProjectileManager>
{
private:
	typedef vector<Projectile*> PROJECTILE_LIST;
	PROJECTILE_LIST m_projectileList;
private:
	int m_startTime;
public:
	HRESULT init();
	void release();
	void update();
	void render();
public:
	void AddProjectile(Projectile* _projectile) { m_projectileList.push_back(_projectile); }
	void ActivateProjectile(PROJECTILE_TYPE _projectileType, OBJECT_TYPE _userObjectType, POINTFLOAT _position, float _angle, float _attack, float _loopTime = 0);
public:
	PROJECTILE_LIST getProejectileList() { return m_projectileList; }
public:
	ProjectileManager();
	virtual ~ProjectileManager();
};

