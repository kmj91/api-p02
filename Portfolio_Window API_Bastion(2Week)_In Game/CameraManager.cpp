#include "stdafx.h"
#include "CameraManager.h"
#include "Camera_FollowCam.h"

HRESULT CameraManager::init()
{
	Camera* camera;

	camera = new Camera_FollowCam;
	camera->init();
	AddCamera(camera);

	m_mainCamera = camera;
	return S_OK;
}

void CameraManager::release()
{
	for (auto iter = m_cameraList.begin(); iter != m_cameraList.end();)
	{
		(*iter)->release();
		SAFE_DELETE((*iter));
		iter = m_cameraList.erase(iter);
	}
}

void CameraManager::update()
{
	if (!m_mainCamera->getIsActive()) return;
	m_mainCamera->update();
}

void CameraManager::render()
{
	if (!m_mainCamera->getIsActive()) return;
	m_mainCamera->render();
}

void CameraManager::AddRenderInfo(LAYER_TYPE _layerType,  RENDER_INFO _renderInfo)
{
	m_mainCamera->AddRenderInfo(_layerType, _renderInfo);
}

CameraManager::CameraManager()
{
}


CameraManager::~CameraManager()
{
}
