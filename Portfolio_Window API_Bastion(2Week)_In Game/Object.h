#pragma once
#include "gameNode.h"

class Object :
	public gameNode
{
protected:
	OBJECT_TYPE m_objectType;	// ��ü Ÿ��
protected:
	LAYER_TYPE m_layerType;		// ���̾� Ÿ��
protected:
	POINTFLOAT m_position;		// ��ü ��ǥ
	image* m_image;
	RECT m_imageRect;			// ��ü ������ �簢��(�׷����� �̹����� �»�� ��ǥ�� �˱����� �뵵)
	RECT m_colliderRect;		// ��ü �浹�� �簢��
protected:
	int m_imageWidth;			// �̹��� ����ũ��
	int m_imageHeight;			// �̹��� ����ũ��
	int m_colliderWidth;		// �浹ü ����ũ��
	int m_colliderHeight;		// �浹ü ����ũ��
protected:
	bool m_isActive;			// Ȱ��ȭ����
protected:
	float m_alpha = 255;		// ���İ�
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

