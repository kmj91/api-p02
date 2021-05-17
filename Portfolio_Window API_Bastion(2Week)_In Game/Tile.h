#pragma once
#include "Actor.h"

enum TILE_TYPE;
class Tile :
	public Actor
{
private:
	TILE_TYPE m_tileType;
private:
	float m_activeRange;		// 활성화범위
private:
	bool m_startAni;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	TILE_TYPE getTileType() { return m_tileType; }
	void setTileType(TILE_TYPE _tileType) { m_tileType = _tileType; }
public:
	Tile();
	virtual ~Tile();
};

