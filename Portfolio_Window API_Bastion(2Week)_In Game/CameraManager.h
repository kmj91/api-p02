#pragma once
#include "singletonBase.h"

typedef struct renderInfo RENDER_INFO;
enum LAYER_TYPE;
enum SCENE_TYPE;
class Camera;
class CameraManager :
	public singletonBase<CameraManager>
{
private:
	typedef vector<Camera*> CAMERA_LIST;
	CAMERA_LIST m_cameraList;

	int m_stageWidth;
	int m_stageHeight;

	Camera* m_mainCamera;
public:
	HRESULT init();
	void release();
	void update();
	void render();
public:
	void AddCamera(Camera* _camera) { m_cameraList.push_back(_camera); }
	void AddRenderInfo(LAYER_TYPE _layerType, RENDER_INFO _renderInfo);
public:
	int getStageWidth() { return m_stageWidth; }
	void setStageWidth(int _stageWidth) { m_stageWidth = _stageWidth; }

	int getStageHeight() { return m_stageHeight; }
	void setStageHeight(int _stageHeight) { m_stageHeight = _stageHeight; }

	Camera* getMainCamera() { return m_mainCamera; }
public:
	CameraManager();
	virtual ~CameraManager();
};

