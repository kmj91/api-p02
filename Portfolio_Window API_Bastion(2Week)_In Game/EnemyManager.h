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
	int m_activeEnemyCount;			// ����ִ� �� ��ü��
	int m_enemyIndex;				// Ȱ��ȭ��ų �� �ε���
	int m_startTime;				// �Լ� �����ֱ⸦ �����ϱ� ���� ����
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

