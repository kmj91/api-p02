//#pragma once

#ifndef __SCREEN_DIB__
#define __SCREEN_DIB__

//DIB를 사용한 GDI용 스크린 버퍼
//윈도우의 HDC에 DIB를 사용하여 그림을 찍어준다.
class CScreenDib {
public :
	CScreenDib(int iWidth, int iHeight, int iColorBit);
	~CScreenDib();

protected :
	void CreateDibBuffer(int iWidth, int iHeight, int iColorBit);
	void ReleaseDibBuffer(void);

public :
	void DrawBuffer(HWND hWnd, int iX = 0, int iY = 0);

	BYTE *GetDibBuffer();
	int GetWidth();
	int GetHeight();
	int GetPitch();
	BITMAPINFO * GetDibInfo();

	// 2019.07.12	추가
	// 이미지 파일 24비트 32비트 호환을 위해 필요하다
	int GetColorByte();
	// 2019.07.19	추가
	// 스크린 크기 변경을 위해 필요하다
	void ResizeScreenDib(int iWidth, int iHeight, int iColorBit);

protected :
	BITMAPINFO	m_stDibInfo;
	BYTE		*m_bypBuffer;

	int			m_iWidth;
	int			m_iHeight;
	int			m_iPitch;
	int			m_iColorBit;
	int			m_iBufferSize;
};

#endif