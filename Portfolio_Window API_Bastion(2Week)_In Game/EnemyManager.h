#pragma once
#include "singletonBase.h"

class Enemy;
class EnemyManager :
	public singletonBase<EnemyManager>
{
private:
	typedef vector<Enemy*> ENEMY_LIST;
	ENEMY_LIST m_enemyList;
private:
	int m_activeEnemyCount;			// 살아있는 적 개체수
	int m_enemyIndex;				// 활성화시킬 적 인덱스
	int m_startTime;				// 함수 실행주기를 조절하기 위한 변수
public:
	HRESULT init(int _stage);
	void release();
	void update();
	void render();
public:
	void AddEnemy(Enemy* _enemy) { m_enemyList.push_back(_enemy); }
	bool CheckEnemyDie();
public:
	ENEMY_LIST getEnemyList() { return m_enemyList; }

	int GetActiveEnemyCount();
public:
	EnemyManager();
	virtual ~EnemyManager();
};

