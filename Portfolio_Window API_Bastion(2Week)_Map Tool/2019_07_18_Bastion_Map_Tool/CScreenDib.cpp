#include "stdafx.h"
#include <windows.h>
#include "CScreenDib.h"

CScreenDib::CScreenDib(int iWidth, int iHeight, int iColorBit) {
	// 스크린 버퍼 생성
	CreateDibBuffer(iWidth, iHeight, iColorBit);
}

CScreenDib::~CScreenDib() {
	ReleaseDibBuffer();
}


// 스크린 버퍼 생성
// iWidth : 윈도우 가로 길이
// iHeight : 윈도우 세로 길이
// iColorBit : 비트맵 컬러 비트 ex) 24Bit 컬러 or 32Bit 컬러
void CScreenDib::CreateDibBuffer(int iWidth, int iHeight, int iColorBit) {
	m_iWidth = iWidth;
	m_iHeight = iHeight;
	m_iColorBit = iColorBit;

	// 비트맵 헤더 파일 초기화
	m_stDibInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_stDibInfo.bmiHeader.biWidth = iWidth;
	m_stDibInfo.bmiHeader.biHeight = -iHeight;
	m_stDibInfo.bmiHeader.biPlanes = 1;
	m_stDibInfo.bmiHeader.biBitCount = iColorBit;
	m_stDibInfo.bmiHeader.biSizeImage = 0;
	m_stDibInfo.bmiHeader.biClrUsed = 0;
	m_stDibInfo.bmiHeader.biClrImportant = 0;
	/*
	m_stDibInfo.bmiColors[0].rgbRed = 0;
	m_stDibInfo.bmiColors[0].rgbGreen = 0;
	m_stDibInfo.bmiColors[0].rgbBlue = 0;
	m_stDibInfo.bmiColors[0].rgbReserved = 0;
	*/

	// 비트맵의 피치 값 구하기
	m_iPitch = (iWidth * (iColorBit / 8) + 3) & ~3;
	// 피치 값(가로) * 화면의 세로 길이 = 버퍼의 크기
	m_iBufferSize = m_iPitch * m_iHeight;

	// 윈도우 크기의 버퍼 생성
	m_bypBuffer = (BYTE*)malloc(m_iBufferSize);
}


void CScreenDib::ReleaseDibBuffer(void) {
	free(m_bypBuffer);
}


// 메인 DC에 픽셀 버퍼 출력
void CScreenDib::DrawBuffer(HWND hWnd, int iX, int iY) {
	HDC hdc;
	hdc = GetDC(hWnd);

	// m_bypBuffer 픽셀 데이터를 hdc에 출력
	StretchDIBits(hdc, iX, iY, m_iWidth, m_iHeight, iX, iY, m_iWidth, m_iHeight, m_bypBuffer,
					&m_stDibInfo, DIB_RGB_COLORS, SRCCOPY);


	ReleaseDC(hWnd, hdc);
}


BYTE * CScreenDib::GetDibBuffer(void) {
	return m_bypBuffer;
}


int CScreenDib::GetWidth(void) {
	return m_iWidth;
}


int CScreenDib::GetHeight(void) {
	return m_iHeight;
}


int CScreenDib::GetPitch(void) {
	return m_iPitch;
}

BITMAPINFO * CScreenDib::GetDibInfo()
{
	return &m_stDibInfo;
}

int CScreenDib::GetColorByte()
{
	return m_iColorBit / 8;
}

void CScreenDib::ResizeScreenDib(int iWidth, int iHeight, int iColorBit)
{
	ReleaseDibBuffer();
	//스크린 버퍼 생성
	CreateDibBuffer(iWidth, iHeight, iColorBit);
}
