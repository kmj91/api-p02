#pragma once
#include "Object.h"
class ObjectStageMap : public Object
{
public:
	ObjectStageMap(int iMapWidth, int iMapHeight);
	virtual ~ObjectStageMap();

	virtual bool Action();
	virtual void Draw();
	virtual bool Click();

	// �� ũ�� ����� ���� �޸𸮸� �����ϰ� �ٽ� �޸� ����� �Ҵ�
	void ResizeMap(int iMapWidth, int iMapHeight);
	bool CheckProperties(int iPropertiesX, int iPropertiesY);

private:
	void CreateMap(int iMapWidth, int iMapHeight);
	void ReleaseMap();

public:
	void SetProperties(int iPropertiesX, int iPropertiesY);
	

public:
	BYTE *m_bypMapProperties;
	int m_iPropertiesWidth;
	int m_iPropertiesHeight;
	int m_iPropertiesSize;
};

