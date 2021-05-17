#pragma once
#include "Camera.h"
class Camera_FollowCam :
	public Camera
{
private:
	Object* m_targetObject;			// Å¸°Ù °´Ã¼
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Object* getTarget() { return m_targetObject; }
	void setTarget(Object* _targetObject) { m_targetObject = _targetObject; }
public:
	Camera_FollowCam();
	virtual ~Camera_FollowCam();
};
