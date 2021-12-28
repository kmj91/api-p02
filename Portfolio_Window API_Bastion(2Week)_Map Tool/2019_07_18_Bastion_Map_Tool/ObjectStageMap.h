// �����
// �������� ��
// ������ ������ ���������� ũ�� �� �Ӽ� ����
// Click �Լ����� ���� ���¿� ���� ���� ������ ����� ���� ������Ʈ ����Ʈ�� ����

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
	void SetProperties(int iPropertiesX, int iPropertiesY);
	bool CheckProperties(int iPropertiesX, int iPropertiesY);

private:
	void CreateMap(int iMapWidth, int iMapHeight);
	void ReleaseMap();

	void CheckPosition(int& iPropertiesX, int& iPropertiesY, int& iReviseX, int& iReviseY, int& iPropertiesSizeX, int& iPropertiesSizeY);
	

public:
	BYTE *m_bypMapProperties;	// ���� �Ӽ� �迭
	int m_iPropertiesWidth;		// ���� ���� ����
	int m_iPropertiesHeight;	// ���� ���� ����
	int m_iPropertiesSize;		// ���� ũ�� = (���� * ����)
};

