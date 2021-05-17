//#pragma once

#ifndef __SCREEN_DIB__
#define __SCREEN_DIB__

//DIB�� ����� GDI�� ��ũ�� ����
//�������� HDC�� DIB�� ����Ͽ� �׸��� ����ش�.
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

	// 2019.07.12	�߰�
	// �̹��� ���� 24��Ʈ 32��Ʈ ȣȯ�� ���� �ʿ��ϴ�
	int GetColorByte();
	// 2019.07.19	�߰�
	// ��ũ�� ũ�� ������ ���� �ʿ��ϴ�
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