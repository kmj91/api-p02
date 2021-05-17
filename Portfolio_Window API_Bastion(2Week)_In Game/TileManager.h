#pragma once
#include "singletonBase.h"


class Tile;
class TileManager :
	public singletonBase<TileManager>
{
private:
	typedef vector<Tile*> TILE_LIST;
	TILE_LIST m_tileList;

	BYTE* m_tilePropertyInfo;
	int m_tilePropertyWidth;
	int m_tilePropertyHeight;
	int m_tilePropertySize;
public:
	HRESULT init();
	void release();
	void update();
	void render();
public:
	void AddTile(Tile* _tile) { m_tileList.push_back(_tile); }
	void ResizeTilePropertyInfo()
	{
		if(m_tilePropertyInfo) 
			delete m_tilePropertyInfo; 

		m_tilePropertyInfo = new BYTE[m_tilePropertySize];
	}
public:
	TILE_LIST getTileList() { return m_tileList; }

	BYTE* getTilePropertyInfo() { return m_tilePropertyInfo; }
	void setTilePropertyInfo(int _index, int _value) { m_tilePropertyInfo[_index] = _value; }

	int getTilePropertyWidth() { return m_tilePropertyWidth; }
	void setTilePropertyWidth(int _tilePropertyWidth) { m_tilePropertyWidth = _tilePropertyWidth; }

	int getTilePropertyHeight() { return m_tilePropertyHeight; }
	void setTilePropertyHeight(int _tilePropertyHeight) { m_tilePropertyHeight = _tilePropertyHeight; }

	int getTilePropertySize() { return m_tilePropertySize; }
	void setTilePropertySize(int _tilePropertySize) { m_tilePropertySize = _tilePropertySize; }
public:
	TileManager();
	virtual ~TileManager();
};

