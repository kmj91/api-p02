#pragma once
#include "Object.h"

class Camera :
	public Object
{
protected:
	CAMERA_TYPE m_cameraType;	// 카메라 타입
protected:
	typedef vector<RENDER_INFO> RENDER_LIST;
	RENDER_LIST m_renderList[LAYER_MAX];
public:
	virtual HRESULT init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
public:
	void AddRenderInfo(LAYER_TYPE _layerType, RENDER_INFO _renderInfo) { m_renderList[_layerType].push_back(_renderInfo); }
	void SortRenderInfo() { for(int i = 0; i < LAYER_MAX; ++i) sort(m_renderList[i].begin(), m_renderList[i].end()); }
public:
	CAMERA_TYPE getCameraType() { return m_cameraType; }
	void setCameraType(CAMERA_TYPE _cameraType) { m_cameraType = _cameraType; }
public:
	Camera();
	virtual ~Camera();
};



