#pragma once
#include "gameNode.h"

class Object :
	public gameNode
{
protected:
	OBJECT_TYPE m_objectType;	// 객체 타입
protected:
	LAYER_TYPE m_layerType;		// 레이어 타입
protected:
	POINTFLOAT m_position;		// 객체 좌표
	image* m_image;
	RECT m_imageRect;			// 객체 렌더용 사각형(그려야할 이미지의 좌상단 좌표를 알기위한 용도)
	RECT m_colliderRect;		// 객체 충돌용 사각형
protected:
	int m_imageWidth;			// 이미지 가로크기
	int m_imageHeight;			// 이미지 세로크기
	int m_colliderWidth;		// 충돌체 가로크기
	int m_colliderHeight;		// 충돌체 세로크기
protected:
	bool m_isActive;			// 활성화여부
protected:
	float m_alpha = 255;		// 알파값
public:
	virtual HRESULT init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
public:
	OBJECT_TYPE getObjectType() { return m_objectType; }
	void setObjectType(OBJECT_TYPE _objectType) { m_objectType = _objectType; }

	POINTFLOAT getPosition() { return m_position; }
	void setPosition(POINTFLOAT _position) { m_position = _position; }	

	RECT getColliderRect() { return m_colliderRect; }
	void setColliderRect(RECT _colliderRect) { m_colliderRect = _colliderRect; }

	RECT getImageRect() { return m_imageRect; }
	void setImageRect(RECT _renderRect) { m_imageRect = _renderRect; }

	bool getIsActive() { return m_isActive; }
	void setIsActive(bool _isActive) { m_isActive = _isActive; }

	int getImageWidth() { return m_imageWidth; }
	void setImageWidth(int _imageWidth) { m_imageWidth = _imageWidth; }

	int getImageHeight() { return m_imageHeight; }
	void setImageHeight(int _imageHeight) { m_imageHeight = _imageHeight; }

	int getColliderWidth() { return m_colliderWidth; }
	void setColliderWidth(int _colliderWidth) { m_colliderWidth = _colliderWidth; }

	int getColliderHeight() { return m_colliderHeight; }
	void setColliderHeight(int _colliderHeight) { m_colliderHeight = _colliderHeight; }
public:
	Object();
	virtual ~Object();
};

