#include "stdafx.h"
#include "sceneManager.h"
#include"gameNode.h"
#include "Scene_Loading.h"
#include "Scene_Title.h"
#include "Scene_MainMenu.h"
#include "Scene_MainGame.h"

sceneManager::sceneManager()
{
}
sceneManager::~sceneManager()
{
}

//현재씬을 널값으로 초기화 하기
gameNode* sceneManager::_currentScene = nullptr;
HRESULT sceneManager::init()
{
	addScene("Scene_Title", new Scene_Title);
	addScene("Scene_MainMenu", new Scene_MainMenu);
	addScene("Scene_Loading", new Scene_Loading);
	addScene("Scene_MainGame", new Scene_MainGame);

	changeScene("Scene_Title");

	return S_OK;
}

void sceneManager::release()
{
	miSceneList iter = _mSceneList.begin();
	for (iter; iter != _mSceneList.end();)
	{
		//삭제
		if (iter->second != NULL)
		{
			if (iter->second == _currentScene)iter->second->release();
			SAFE_DELETE(iter->second);
			iter = _mSceneList.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	_mSceneList.clear();
}

void sceneManager::update()
{
	if (_currentScene)
	{
		_currentScene->update();
	}
}

void sceneManager::render()
{
	if (_currentScene)_currentScene->render();
}
gameNode * sceneManager::addScene(string sceneName, gameNode * scene)
{

	if (!scene) return nullptr;

	_mSceneList.insert(make_pair(sceneName, scene));

	return nullptr;
}

HRESULT sceneManager::changeScene(string sceneName)
{

	miSceneList find = _mSceneList.find(sceneName);

	//못찾으면 E_FAIL
	if (find == _mSceneList.end())return E_FAIL;

	//바꾸려는 씬이 현재씬과 같아도 E_FAIL
	if (find->second == _currentScene)return E_FAIL;

	//여기까지 왔다는건 문제가 없다. 즉 씬을 초기화 하고 변경해라.
	if (SUCCEEDED(find->second->init()))
	{
		//혹시 기존에 씬이 있다면 릴리즈
		if (_currentScene)_currentScene->release();
		_currentScene = find->second;
		return S_OK;
	}
	return E_FAIL;
}
