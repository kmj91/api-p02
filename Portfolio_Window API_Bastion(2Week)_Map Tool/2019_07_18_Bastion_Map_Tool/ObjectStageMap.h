// 기명준
// 스테이지 맵
// 맵툴로 생성한 스테이지의 크기 및 속성 관리
// Click 함수에서 현재 상태에 따라 전역 변수로 선언된 게임 오브젝트 리스트를 관리

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

	// 맵 크기 변경시 기존 메모리를 삭제하고 다시 메모리 사이즈를 할당
	void ResizeMap(int iMapWidth, int iMapHeight);
	void SetProperties(int iPropertiesX, int iPropertiesY);
	bool CheckProperties(int iPropertiesX, int iPropertiesY);

private:
	void CreateMap(int iMapWidth, int iMapHeight);
	void ReleaseMap();

	void CheckPosition(int& iPropertiesX, int& iPropertiesY, int& iReviseX, int& iReviseY, int& iPropertiesSizeX, int& iPropertiesSizeY);
	

public:
	BYTE *m_bypMapProperties;	// 맵의 속성 배열
	int m_iPropertiesWidth;		// 맵의 가로 길이
	int m_iPropertiesHeight;	// 맵의 세로 길이
	int m_iPropertiesSize;		// 맵의 크기 = (가로 * 세로)
};

