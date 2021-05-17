#pragma once
#include "gameNode.h"

typedef struct background
{
	BACKGROUND_TYPE backgroundType;
	image* image;
	float alpha;
}BACKGROUND;

enum SCENE_TYPE;
class Scene :
	public gameNode
{
protected:
	SCENE_TYPE m_sceneType;
public:
	virtual HRESULT init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
public:
	virtual void LoadProcess();
	void UTF8toUTF16(const char *szText, WCHAR *szBuff, int iBuffLen);
public:
	Scene();
	virtual ~Scene();
};

