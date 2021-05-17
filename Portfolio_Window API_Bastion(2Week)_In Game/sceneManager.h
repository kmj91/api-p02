#pragma once
#include"singletonBase.h"

class gameNode;
class sceneManager : public singletonBase<sceneManager>
{
private:
	typedef map<string, gameNode*> mSceneList;
	typedef map<string, gameNode*>::iterator miSceneList;
private:
	mSceneList _mSceneList; 	// ¾À¸ñ·Ï
	static gameNode* _currentScene; 	// ÇöÀç¾À
public:
	HRESULT init();
	void release();
	void update();
	void render();
public:
	gameNode* addScene(string sceneName, gameNode* scene);
	HRESULT changeScene(string sceneName); 
public:
	sceneManager();
	~sceneManager();
};

