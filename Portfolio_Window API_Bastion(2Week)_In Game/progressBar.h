#pragma once
#include"gameNode.h"
class progressBar : public gameNode
{
private:

	RECT _rcProgress;	//체력바 렉트
	int _x, _y;			//좌표
	int _width;			//체력바 가로길이(이걸로 조정함)

	image* _progressBarFront;	//체력바 앞 이미지
	image* _progressBarBack;	//체력바 뒤 이미지
public:
	progressBar();
	~progressBar();

	//체력바 초기화(앞이미지, 뒤이미지, x, y, 가로길이, 세로길이)
	HRESULT init(char* frontImage, char* backImage, float x, float y, int width, int height);
	void release();
	void update();
	void render();

	//프로그래스바 게이지 셋팅
	void setGauge(float currentGauge, float maxGauge);

	//프로그래스바 위치
	int getX() { return _x; }
	void setX(int x) { _x = x; }

	int getY() { return _y; }
	void setY(int y) { _y = y; }

	int getWidth() { return _width; }
	void setWidth(int width) { _width = width; }

	//체력바 렉트
	RECT getRect() { return _rcProgress; }
};

