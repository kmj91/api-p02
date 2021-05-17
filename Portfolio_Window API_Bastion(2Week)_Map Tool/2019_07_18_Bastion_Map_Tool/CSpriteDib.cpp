#include "stdafx.h"
#include <windows.h>
#include "CSpriteDib.h"
#include "stdio.h"

CSpriteDib::CSpriteDib()
{
	int iCount;

	//-----------------------------------------------------------------
	// �ִ� �о�� ���� ��ŭ �̸� �Ҵ� �޴´�.
	//-----------------------------------------------------------------
	m_iMaxSprite = 100;
	m_dwColorKey = 0x00ff00ff;
	m_stpSprite = new st_SPRITE[100];

	// �ʱ�ȭ
	iCount = 0;
	while (iCount < 100) {
		m_stpSprite[iCount].bypImage = NULL;
		++iCount;
	}

	//�⺻ ī�޶� ��ġ
	m_iCameraPosX = 0;
	m_iCameraPosY = 0;
}

////////////////////////////////////////////////////////////////////
// ������, �ı���.
//
// Parameters: (int)�ִ� ��������Ʈ ����. (DWORD)����Į��.
////////////////////////////////////////////////////////////////////
CSpriteDib::CSpriteDib(int iMaxSprite, DWORD dwColorKey)
{
	int iCount;

	//-----------------------------------------------------------------
	// �ִ� �о�� ���� ��ŭ �̸� �Ҵ� �޴´�.
	//-----------------------------------------------------------------
	m_iMaxSprite = iMaxSprite;
	m_dwColorKey = dwColorKey;
	m_stpSprite = new st_SPRITE[iMaxSprite];

	// �ʱ�ȭ
	iCount = 0;
	while (iCount < iMaxSprite) {
		m_stpSprite[iCount].bypImage = NULL;
		++iCount;
	}

	//�⺻ ī�޶� ��ġ
	m_iCameraPosX = 0;
	m_iCameraPosY = 0;
}

CSpriteDib::~CSpriteDib()
{
	int iCount;
	//-----------------------------------------------------------------
	// ��ü�� ���鼭 ��� ������.
	//-----------------------------------------------------------------
	for (iCount = 0; iCount < m_iMaxSprite; iCount++)
	{
		ReleaseSprite(iCount);
	}
	delete[] m_stpSprite;
}

///////////////////////////////////////////////////////
// LoadDibSprite. 
// BMP������ �о �ϳ��� ���������� �����Ѵ�.
//
// Parameters: (int)SpriteIndex. (const wchar_t *)FileName. (int)CenterPointX. (int)CenterPointY.
// Return: (BOOL)TRUE, FALSE.
///////////////////////////////////////////////////////
BOOL CSpriteDib::LoadDibSprite(int iSpriteIndex, const wchar_t * szFileName, int iCenterPointX,
	int iCenterPointY)
{
	//HANDLE		hFile;
	//DWORD		dwRead;
	int		iPitch;
	size_t		iImageSize;
	BITMAPFILEHEADER	stFileHeader;
	BITMAPINFOHEADER	stInfoHeader;
	
	FILE *fp;
	int err;
	int iCount;
	int iColorByte;
	//-----------------------------------------------------------------
	// ��Ʈ�� ����� ���� BMP ���� Ȯ��.
	//-----------------------------------------------------------------
	err = _wfopen_s(&fp, szFileName, L"rb");
	if (err != 0) {
		return 0;
	}
	fread(&stFileHeader, sizeof(BITMAPFILEHEADER), 1, fp);
	if (stFileHeader.bfType != 0x4d42) {
		return 0;
	}
	
	//-----------------------------------------------------------------
	// ����, ������ ��ġ���� ���Ѵ�.
	//-----------------------------------------------------------------
	fread(&stInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);
	iColorByte = stInfoHeader.biBitCount / 8;
	iPitch = (stInfoHeader.biWidth * iColorByte + 3) & ~3;

	//-----------------------------------------------------------------
	// ��������Ʈ ����ü�� ũ�� ����.
	//-----------------------------------------------------------------
	m_stpSprite[iSpriteIndex].iWidth = stInfoHeader.biWidth;
	m_stpSprite[iSpriteIndex].iHeight = stInfoHeader.biHeight;
	m_stpSprite[iSpriteIndex].iPitch = iPitch;
	m_stpSprite[iSpriteIndex].iCenterPointX = iCenterPointX;
	m_stpSprite[iSpriteIndex].iCenterPointY = iCenterPointY;
	m_stpSprite[iSpriteIndex].iColorByte = iColorByte;

	//-----------------------------------------------------------------
	// �̹����� ���� ��ü ũ�⸦ ���ϰ�, �޸� �Ҵ�.
	//-----------------------------------------------------------------
	iImageSize = iPitch * stInfoHeader.biHeight;
	m_stpSprite[iSpriteIndex].bypImage = new BYTE[iImageSize];
	
	//-----------------------------------------------------------------
	// �̹��� �κ��� ��������Ʈ ���۷� �о�´�.
	// DIB �� �������� �����Ƿ� �̸� �ٽ� ������.
	// �ӽ� ���ۿ� ���� �ڿ� �������鼭 �����Ѵ�.
	//-----------------------------------------------------------------
	BYTE *buffer = new BYTE[iImageSize];
	BYTE *tempBuffer;
	BYTE *tempSprite = m_stpSprite[iSpriteIndex].bypImage;
	fread(buffer, iImageSize, 1, fp);
	tempBuffer = buffer +(iPitch * (stInfoHeader.biHeight - 1));

	for (iCount = 0; iCount < stInfoHeader.biHeight; iCount++) {
		//memcpy(tempSprite, tempBuffer, stInfoHeader.biWidth * 4);
		memcpy(tempSprite, tempBuffer, stInfoHeader.biWidth * iColorByte);
		tempBuffer = tempBuffer - iPitch;
		tempSprite = tempSprite + iPitch;
	}

	delete[] buffer;
	fclose(fp);
	//CloseHandle(hFile);
	
	return FALSE;
}
///////////////////////////////////////////////////////
// ReleaseSprite. 
// �ش� ��������Ʈ ����.
//
// Parameters: (int)SpriteIndex.
// Return: (BOOL)TRUE, FALSE.
///////////////////////////////////////////////////////
void CSpriteDib::ReleaseSprite(int iSpriteIndex)
{
	//-----------------------------------------------------------------
	// �ִ� �Ҵ�� ��������Ʈ�� �Ѿ�� �ȵ�����
	//-----------------------------------------------------------------
	if (m_iMaxSprite <= iSpriteIndex)
		return;

	if (NULL != m_stpSprite[iSpriteIndex].bypImage)
	{
		//-----------------------------------------------------------------
		// ���� �� �ʱ�ȭ.
		//-----------------------------------------------------------------
		delete[] m_stpSprite[iSpriteIndex].bypImage;
		memset(&m_stpSprite[iSpriteIndex], 0, sizeof(st_SPRITE));
	}
}

///////////////////////////////////////////////////////
// DrawCompatibilitySprite. 
// Ư�� �޸� ��ġ�� ��������Ʈ�� ����Ѵ�. (Į��Ű, Ŭ���� ó��)
// �̹������� ��Ʈ�÷� 24, 32 ȣȯ
///////////////////////////////////////////////////////
void CSpriteDib::CompatibleDrawSprite(int iSpriteIndex, int iDrawX, int iDrawY, BYTE * bypDest, int iDestWidth,
	int iDestHeight, int iDestPitch, int iDestColorByte)
{
	//-----------------------------------------------------------------
	// �ִ� ��������Ʈ ������ �ʰ� �ϰų�, �ε���� �ʴ� ��������Ʈ��� ����
	//-----------------------------------------------------------------
	if (m_iMaxSprite < iSpriteIndex)
		return;

	if (m_stpSprite[iSpriteIndex].bypImage == NULL)
		return;

	//-----------------------------------------------------------------
	// ���������� �ʿ����� ����
	//-----------------------------------------------------------------
	st_SPRITE *stpSprite = &m_stpSprite[iSpriteIndex];

	int iCountY;
	int iCountX;
	int iSpriteHeight = stpSprite->iHeight;
	int iSpriteWidth = stpSprite->iWidth;
	int iSpritePitch = stpSprite->iPitch;
	int iSpriteCenterX = stpSprite->iCenterPointX;
	int iSpriteCenterY = stpSprite->iCenterPointY;
	int iSpriteColorByte = stpSprite->iColorByte;
	BYTE *bypSprite = stpSprite->bypImage;
	BYTE *bypCopyDest = bypDest;
	BYTE *bypTempSprite;
	BYTE *bypTempDest;
	int iR;
	int iG;
	int iB;

	iR = GetRValue(m_dwColorKey);
	iG = GetGValue(m_dwColorKey);
	iB = GetBValue(m_dwColorKey);

	//-----------------------------------------------------------------
	// ��� �������� ��ǥ ���
	//-----------------------------------------------------------------
	iDrawX = iDrawX - iSpriteCenterX;
	iDrawY = iDrawY - iSpriteCenterY;

	//-----------------------------------------------------------------
	// ��� �� ���� ��������Ʈ ��� ��ġ ���. (��� Ŭ����)
	// �ϴܿ� ������ ���. (�ϴ� Ŭ����)
	// ���� ��� ��ġ ���. (���� Ŭ����)
	// ������ ��� ��ġ ���. (���� Ŭ����)
	//-----------------------------------------------------------------

	//2018.02.08
	//ī�޶� �������� ��������Ʈ �� Ŭ���� ó��
	int clippingY;
	int clippingX;

	if (iDrawY < m_iCameraPosY) {
		//2018.02.08
		clippingY = m_iCameraPosY - iDrawY;
		iSpriteHeight = iSpriteHeight - clippingY;
		if (iSpriteHeight > 0) {
			bypSprite = bypSprite + iSpritePitch * clippingY;
		}
		iDrawY = m_iCameraPosY;
	}

	if (iDrawY + iSpriteHeight >= m_iCameraPosY + iDestHeight) {
		iSpriteHeight = iSpriteHeight - ((iDrawY + iSpriteHeight) - (m_iCameraPosY + iDestHeight));
	}

	if (iDrawX < m_iCameraPosX) {
		//2018.02.08
		clippingX = m_iCameraPosX - iDrawX;
		iSpriteWidth = iSpriteWidth - clippingX;
		if (iSpriteWidth > 0) {
			bypSprite = bypSprite + (clippingX * iSpriteColorByte);
		}
		iDrawX = m_iCameraPosX;
	}

	if (iDrawX + iSpriteWidth >= m_iCameraPosX + iDestWidth) {
		iSpriteWidth = iSpriteWidth - ((iDrawX + iSpriteWidth) - (m_iCameraPosX + iDestWidth));
	}


	if (iSpriteWidth <= 0 || iSpriteHeight <= 0) {
		return;
	}

	//2018.02.08
	//ī�޶� �������� iDrawX iDrawY �� ��ǥ ���߱�
	iDrawX = iDrawX - m_iCameraPosX;
	iDrawY = iDrawY - m_iCameraPosY;

	//-----------------------------------------------------------------
	// ȭ�鿡 ���� ��ġ�� �̵��Ѵ�.
	//-----------------------------------------------------------------
	bypCopyDest = bypCopyDest + (iDrawX * iDestColorByte) + (iDrawY * iDestPitch);
	bypTempSprite = bypSprite;
	bypTempDest = bypCopyDest;

	//-----------------------------------------------------------------
	// ��ü ũ�⸦ ���鼭 �ȼ����� ����� ó���� �ϸ� �׸� ���.
	//-----------------------------------------------------------------
	for (iCountY = 0; iSpriteHeight > iCountY; iCountY++)
	{
		for (iCountX = 0; iSpriteWidth > iCountX; iCountX++)
		{

			if (iR != *(bypSprite + 2)
				|| iG != *(bypSprite + 1)
				|| iB != *(bypSprite + 0)) {

				*((BYTE *)bypCopyDest + 2) = *(bypSprite + 2);
				*((BYTE *)bypCopyDest + 1) = *(bypSprite + 1);
				*((BYTE *)bypCopyDest + 0) = *(bypSprite + 0);

			}

			//����ĭ �̵�
			bypCopyDest = bypCopyDest + iDestColorByte;
			bypSprite = bypSprite + iDestColorByte;
		}
		//-----------------------------------------------------------------
		// �����ٷ� �̵�, ȭ��� ��������Ʈ ���..
		//-----------------------------------------------------------------
		bypTempDest = bypTempDest + iDestPitch;
		bypTempSprite = bypTempSprite + iSpritePitch;

		bypCopyDest = bypTempDest;
		bypSprite = bypTempSprite;
	}
}

// 24, 32 ��Ʈ �÷� ȣȯ �ռ� ���
void CSpriteDib::CompatibleDrawSpriteCompose(int iSpriteIndex, int iDrawX, int iDrawY, BYTE * bypDest, int iDestWidth,
	int iDestHeight, int iDestPitch, int iDestColorByte, double dCompose)
{
	//-----------------------------------------------------------------
	// �ִ� ��������Ʈ ������ �ʰ� �ϰų�, �ε���� �ʴ� ��������Ʈ��� ����
	//-----------------------------------------------------------------
	if (m_iMaxSprite < iSpriteIndex)
		return;

	if (m_stpSprite[iSpriteIndex].bypImage == NULL)
		return;

	//-----------------------------------------------------------------
	// ���������� �ʿ����� ����
	//-----------------------------------------------------------------
	st_SPRITE *stpSprite = &m_stpSprite[iSpriteIndex];

	int iCountY;
	int iCountX;
	int iSpriteHeight = stpSprite->iHeight;
	int iSpriteWidth = stpSprite->iWidth;
	int iSpritePitch = stpSprite->iPitch;
	int iSpriteCenterX = stpSprite->iCenterPointX;
	int iSpriteCenterY = stpSprite->iCenterPointY;
	int iSpriteColorByte = stpSprite->iColorByte;
	BYTE *bypSprite = stpSprite->bypImage;
	BYTE *bypCopyDest = bypDest;
	BYTE *bypTempSprite;
	BYTE *bypTempDest;
	double dDestCompose = 1.0;
	int iR;
	int iG;
	int iB;

	iR = GetRValue(m_dwColorKey);
	iG = GetGValue(m_dwColorKey);
	iB = GetBValue(m_dwColorKey);

	dDestCompose = dDestCompose - dCompose;

	//-----------------------------------------------------------------
	// ��� �������� ��ǥ ���
	//-----------------------------------------------------------------
	iDrawX = iDrawX - iSpriteCenterX;
	iDrawY = iDrawY - iSpriteCenterY;

	//-----------------------------------------------------------------
	// ��� �� ���� ��������Ʈ ��� ��ġ ���. (��� Ŭ����)
	// �ϴܿ� ������ ���. (�ϴ� Ŭ����)
	// ���� ��� ��ġ ���. (���� Ŭ����)
	// ������ ��� ��ġ ���. (���� Ŭ����)
	//-----------------------------------------------------------------

	//2018.02.08
	//ī�޶� �������� ��������Ʈ �� Ŭ���� ó��
	int clippingY;
	int clippingX;

	if (iDrawY < m_iCameraPosY) {
		//2018.02.08
		clippingY = m_iCameraPosY - iDrawY;
		iSpriteHeight = iSpriteHeight - clippingY;
		if (iSpriteHeight > 0) {
			bypSprite = bypSprite + iSpritePitch * clippingY;
		}
		iDrawY = m_iCameraPosY;
	}

	if (iDrawY + iSpriteHeight >= m_iCameraPosY + iDestHeight) {
		iSpriteHeight = iSpriteHeight - ((iDrawY + iSpriteHeight) - (m_iCameraPosY + iDestHeight));
	}

	if (iDrawX < m_iCameraPosX) {
		//2018.02.08
		clippingX = m_iCameraPosX - iDrawX;
		iSpriteWidth = iSpriteWidth - clippingX;
		if (iSpriteWidth > 0) {
			bypSprite = bypSprite + (clippingX * iSpriteColorByte);
		}
		iDrawX = m_iCameraPosX;
	}

	if (iDrawX + iSpriteWidth >= m_iCameraPosX + iDestWidth) {
		iSpriteWidth = iSpriteWidth - ((iDrawX + iSpriteWidth) - (m_iCameraPosX + iDestWidth));
	}


	if (iSpriteWidth <= 0 || iSpriteHeight <= 0) {
		return;
	}

	//2018.02.08
	//ī�޶� �������� iDrawX iDrawY �� ��ǥ ���߱�
	iDrawX = iDrawX - m_iCameraPosX;
	iDrawY = iDrawY - m_iCameraPosY;

	//-----------------------------------------------------------------
	// ȭ�鿡 ���� ��ġ�� �̵��Ѵ�.
	//-----------------------------------------------------------------
	bypCopyDest = bypCopyDest + (iDrawX * iDestColorByte) + (iDrawY * iDestPitch);
	bypTempSprite = bypSprite;
	bypTempDest = bypCopyDest;

	//-----------------------------------------------------------------
	// ��ü ũ�⸦ ���鼭 �ȼ����� ����� ó���� �ϸ� �׸� ���.
	//-----------------------------------------------------------------
	for (iCountY = 0; iSpriteHeight > iCountY; iCountY++)
	{
		for (iCountX = 0; iSpriteWidth > iCountX; iCountX++)
		{
			if (iR != *(bypSprite + 2)
				|| iG != *(bypSprite + 1)
				|| iB != *(bypSprite + 0)) {

				*((BYTE *)bypCopyDest + 2) = (*((BYTE *)bypCopyDest + 2) * dDestCompose) + (*(bypSprite + 2) * dCompose);
				*((BYTE *)bypCopyDest + 1) = (*((BYTE *)bypCopyDest + 1) * dDestCompose) + (*(bypSprite + 1) * dCompose);
				*((BYTE *)bypCopyDest + 0) = (*((BYTE *)bypCopyDest + 0) * dDestCompose) + (*(bypSprite + 0) * dCompose);
			}

			//����ĭ �̵�
			bypCopyDest = bypCopyDest + iDestColorByte;
			bypSprite = bypSprite + iDestColorByte;
		}
		//-----------------------------------------------------------------
		// �����ٷ� �̵�, ȭ��� ��������Ʈ ���..
		//-----------------------------------------------------------------
		bypTempDest = bypTempDest + iDestPitch;
		bypTempSprite = bypTempSprite + iSpritePitch;

		bypCopyDest = bypTempDest;
		bypSprite = bypTempSprite;
	}
}

///////////////////////////////////////////////////////
// DrawSprite. 
// Ư�� �޸� ��ġ�� ��������Ʈ�� ����Ѵ�. (Ŭ���� ó��)
// ü�¹� ó��
//
///////////////////////////////////////////////////////
void CSpriteDib::DrawSprite(int iSpriteIndex, int iDrawX, int iDrawY, BYTE *bypDest, int iDestWidth,
	int iDestHeight, int iDestPitch, bool bCameraOption)
{
	//-----------------------------------------------------------------
	// �ִ� ��������Ʈ ������ �ʰ� �ϰų�, �ε���� �ʴ� ��������Ʈ��� ����
	//-----------------------------------------------------------------
	if (m_iMaxSprite < iSpriteIndex)
		return;

	if (m_stpSprite[iSpriteIndex].bypImage == NULL)
		return;

	//-----------------------------------------------------------------
	// ���������� �ʿ����� ����
	//-----------------------------------------------------------------
	st_SPRITE *stpSprite = &m_stpSprite[iSpriteIndex];

	int iCountY;
	int iCountX;
	int iSpriteHeight = stpSprite->iHeight;
	int iSpriteWidth = stpSprite->iWidth;
	int iSpritePitch = stpSprite->iPitch;
	int iSpriteCenterX = stpSprite->iCenterPointX;
	int iSpriteCenterY = stpSprite->iCenterPointY;
	int iSpriteColorByte = stpSprite->iColorByte;
	DWORD *dwpSprite = (DWORD *)stpSprite->bypImage;
	DWORD *dwpDest = (DWORD *)bypDest;
	BYTE *bypTempSprite;
	BYTE *bypTempDest;

	//-----------------------------------------------------------------
	// ��� �������� ��ǥ ���
	//-----------------------------------------------------------------
	iDrawX = iDrawX - iSpriteCenterX;
	iDrawY = iDrawY - iSpriteCenterY;

	//-----------------------------------------------------------------
	// ��� �� ���� ��������Ʈ ��� ��ġ ���. (��� Ŭ����)
	// �ϴܿ� ������ ���. (�ϴ� Ŭ����)
	// ���� ��� ��ġ ���. (���� Ŭ����)
	// ������ ��� ��ġ ���. (���� Ŭ����)
	//-----------------------------------------------------------------

	if (bCameraOption) {
		//2018.02.08
		//ī�޶� �������� ��������Ʈ �� Ŭ���� ó��
		int clippingY;
		int clippingX;

		if (iDrawY < m_iCameraPosY) {
			//2018.02.08
			clippingY = m_iCameraPosY - iDrawY;
			iSpriteHeight = iSpriteHeight - clippingY;
			if (iSpriteHeight > 0) {
				dwpSprite = (DWORD *)((BYTE *)dwpSprite + iSpritePitch * clippingY);
			}
			iDrawY = m_iCameraPosY;
		}

		if (iDrawY + iSpriteHeight >= m_iCameraPosY + iDestHeight) {
			iSpriteHeight = iSpriteHeight - ((iDrawY + iSpriteHeight) - (m_iCameraPosY + iDestHeight));
		}

		if (iDrawX < m_iCameraPosX) {
			//2018.02.08
			clippingX = m_iCameraPosX - iDrawX;
			iSpriteWidth = iSpriteWidth - clippingX;
			if (iSpriteWidth > 0) {
				dwpSprite = dwpSprite + clippingX;
			}
			iDrawX = m_iCameraPosX;
		}

		if (iDrawX + iSpriteWidth >= m_iCameraPosX + iDestWidth) {
			iSpriteWidth = iSpriteWidth - ((iDrawX + iSpriteWidth) - (m_iCameraPosX + iDestWidth));
		}

		//2018.02.08
		//ī�޶� �������� iDrawX iDrawY �� ��ǥ ���߱�
		iDrawX = iDrawX - m_iCameraPosX;
		iDrawY = iDrawY - m_iCameraPosY;
	}
	else {
		// 2019.07.22
			// ȭ�� �������� Ŭ���� ó��
		int clippingY;
		int clippingX;

		if (iDrawY < 0) {
			//2018.02.08
			clippingY = -iDrawY;
			iSpriteHeight = iSpriteHeight - clippingY;
			iDrawY = 0;
		}

		if (iDrawY + iSpriteHeight >= iDestHeight) {
			iSpriteHeight = iSpriteHeight - ((iDrawY + iSpriteHeight) - iDestHeight);
		}

		if (iDrawX < 0) {
			//2018.02.08
			clippingX = -iDrawX;
			iSpriteWidth = iSpriteWidth - clippingX;
			iDrawX = 0;
		}

		if (iDrawX + iSpriteWidth >= iDestWidth) {
			iSpriteWidth = iSpriteWidth - ((iDrawX + iSpriteWidth) - iDestWidth);
		}
	}

	if (iSpriteWidth <= 0 || iSpriteHeight <= 0) {
		return;
	}

	//-----------------------------------------------------------------
	// ȭ�鿡 ���� ��ġ�� �̵��Ѵ�.
	//-----------------------------------------------------------------
	dwpDest = (DWORD *)((BYTE *)(dwpDest + iDrawX) + (iDrawY * iDestPitch));
	bypTempSprite = (BYTE *)dwpSprite;
	bypTempDest = (BYTE *)dwpDest;

	//-----------------------------------------------------------------
	// ��ü ũ�⸦ ���鼭 �ȼ����� ����� ó���� �ϸ� �׸� ���.
	//-----------------------------------------------------------------
	for (iCountY = 0; iSpriteHeight > iCountY; iCountY++)
	{
		for (iCountX = 0; iSpriteWidth > iCountX; iCountX++)
		{
			if (m_dwColorKey != (*dwpSprite & 0x00ffffff)) {
				*dwpDest = *dwpSprite;
			}

			//����ĭ �̵�
			++dwpDest;
			++dwpSprite;
		}
		//-----------------------------------------------------------------
		// �����ٷ� �̵�, ȭ��� ��������Ʈ ���..
		//-----------------------------------------------------------------
		bypTempDest = bypTempDest + iDestPitch;
		bypTempSprite = bypTempSprite + iSpritePitch;

		dwpDest = (DWORD *)bypTempDest;
		dwpSprite = (DWORD *)bypTempSprite;
	}
}


void CSpriteDib::DrawImage(int iSpriteIndex, int iDrawX, int iDrawY, BYTE *bypDest, int iDestWidth,
	int iDestHeight, int iDestPitch, bool bCameraOption)
{
	//-----------------------------------------------------------------
	// �ִ� ��������Ʈ ������ �ʰ� �ϰų�, �ε���� �ʴ� ��������Ʈ��� ����
	//-----------------------------------------------------------------
	if (m_iMaxSprite < iSpriteIndex)
		return;

	if (m_stpSprite[iSpriteIndex].bypImage == NULL)
		return;
		

	//-----------------------------------------------------------------
	// ���������� �ʿ����� ����
	//-----------------------------------------------------------------
	st_SPRITE *stpSprite = &m_stpSprite[iSpriteIndex];

	int iCountY;
	int iCountX;
	int iSpriteHeight = stpSprite->iHeight;
	int iSpriteWidth = stpSprite->iWidth;
	int iSpritePitch = stpSprite->iPitch;
	int iSpriteCenterX = stpSprite->iCenterPointX;
	int iSpriteCenterY = stpSprite->iCenterPointY;
	DWORD *dwpSprite = (DWORD *)stpSprite->bypImage;
	DWORD *dwpDest = (DWORD *)bypDest;
	BYTE *bypTempSprite;
	BYTE *bypTempDest;

	//-----------------------------------------------------------------
	// ��� �������� ��ǥ ���
	//-----------------------------------------------------------------
	iDrawX = iDrawX - iSpriteCenterX;
	iDrawY = iDrawY - iSpriteCenterY;
	
	//-----------------------------------------------------------------
	// ��� �� ���� ��������Ʈ ��� ��ġ ���. (��� Ŭ����)
	// �ϴܿ� ������ ���. (�ϴ� Ŭ����)
	// ���� ��� ��ġ ���. (���� Ŭ����)
	// ������ ��� ��ġ ���. (���� Ŭ����)
	//-----------------------------------------------------------------
	
	if (bCameraOption) {
		//2018.02.08
		//ī�޶� �������� ��������Ʈ �� Ŭ���� ó��
		int clippingY;
		int clippingX;

		if (iDrawY < m_iCameraPosY) {
			//2018.02.08
			clippingY = m_iCameraPosY - iDrawY;
			iSpriteHeight = iSpriteHeight - clippingY;
			if (iSpriteHeight > 0) {
				dwpSprite = (DWORD *)((BYTE *)dwpSprite + iSpritePitch * clippingY);
			}
			iDrawY = m_iCameraPosY;
		}

		if (iDrawY + iSpriteHeight >= m_iCameraPosY + iDestHeight) {
			iSpriteHeight = iSpriteHeight - ((iDrawY + iSpriteHeight) - (m_iCameraPosY + iDestHeight));
		}

		if (iDrawX < m_iCameraPosX) {
			//2018.02.08
			clippingX = m_iCameraPosX - iDrawX;
			iSpriteWidth = iSpriteWidth - clippingX;
			if (iSpriteWidth > 0) {
				dwpSprite = dwpSprite + clippingX;
			}
			iDrawX = m_iCameraPosX;
		}

		if (iDrawX + iSpriteWidth >= m_iCameraPosX + iDestWidth) {
			iSpriteWidth = iSpriteWidth - ((iDrawX + iSpriteWidth) - (m_iCameraPosX + iDestWidth));
		}

		//2018.02.08
		//ī�޶� �������� iDrawX iDrawY �� ��ǥ ���߱�
		iDrawX = iDrawX - m_iCameraPosX;
		iDrawY = iDrawY - m_iCameraPosY;
	}
	else {
		// 2019.07.22
			// ȭ�� �������� Ŭ���� ó��
		int clippingY;
		int clippingX;

		if (iDrawY < 0) {
			//2018.02.08
			clippingY = -iDrawY;
			iSpriteHeight = iSpriteHeight - clippingY;
			iDrawY = 0;
		}

		if (iDrawY + iSpriteHeight >= iDestHeight) {
			iSpriteHeight = iSpriteHeight - ((iDrawY + iSpriteHeight) - iDestHeight);
		}

		if (iDrawX < 0) {
			//2018.02.08
			clippingX = -iDrawX;
			iSpriteWidth = iSpriteWidth - clippingX;
			iDrawX = 0;
		}

		if (iDrawX + iSpriteWidth >= iDestWidth) {
			iSpriteWidth = iSpriteWidth - ((iDrawX + iSpriteWidth) - iDestWidth);
		}
	}

	if (iSpriteWidth <= 0 || iSpriteHeight <= 0) {
		return;
	}

	//-----------------------------------------------------------------
	// ȭ�鿡 ���� ��ġ�� �̵��Ѵ�.
	//-----------------------------------------------------------------
	dwpDest = (DWORD *)((BYTE *)(dwpDest + iDrawX) + (iDrawY * iDestPitch));
	bypTempSprite = (BYTE *)dwpSprite;
	bypTempDest = (BYTE *)dwpDest;

	//-----------------------------------------------------------------
	// ��ü ũ�⸦ ���鼭 �ȼ����� �׸� ���.
	//-----------------------------------------------------------------
	for (iCountY = 0; iSpriteHeight > iCountY; iCountY++)
	{
		for (iCountX = 0; iSpriteWidth > iCountX; iCountX++)
		{
			*dwpDest = *dwpSprite;
			//����ĭ �̵�
			++dwpDest;
			++dwpSprite;
		}
		//-----------------------------------------------------------------
		// �����ٷ� �̵�, ȭ��� ��������Ʈ ���..
		//-----------------------------------------------------------------
		bypTempDest = bypTempDest + iDestPitch;
		bypTempSprite = bypTempSprite + iSpritePitch;
		
		dwpDest = (DWORD *)bypTempDest;
		dwpSprite = (DWORD *)bypTempSprite;
	}
}



/*********************************
	DrawCutOutImage
	��������Ʈ Ư������ �߷����� ���
**********************************/
void CSpriteDib::DrawCutOutImage(int iSpriteIndex, int iDrawX, int iDrawY, BYTE * bypDest, int iDestWidth,
	int iDestHeight, int iDestPitch, RECT SpriteCutOutRect, bool bCameraOption)
{
	//-----------------------------------------------------------------
	// �ִ� ��������Ʈ ������ �ʰ� �ϰų�, �ε���� �ʴ� ��������Ʈ��� ����
	//-----------------------------------------------------------------
	if (m_iMaxSprite < iSpriteIndex)
		return;

	if (m_stpSprite[iSpriteIndex].bypImage == NULL)
		return;


	//-----------------------------------------------------------------
	// ���������� �ʿ����� ����
	//-----------------------------------------------------------------
	st_SPRITE *stpSprite = &m_stpSprite[iSpriteIndex];

	int iCountY;
	int iCountX;
	int iSpriteHeight = stpSprite->iHeight;
	int iSpriteWidth = stpSprite->iWidth;
	int iSpritePitch = stpSprite->iPitch;
	int iSpriteCenterX = stpSprite->iCenterPointX;
	int iSpriteCenterY = stpSprite->iCenterPointY;
	DWORD *dwpSprite = (DWORD *)stpSprite->bypImage;
	DWORD *dwpDest = (DWORD *)bypDest;
	BYTE *bypTempSprite;
	BYTE *bypTempDest;
	int clippingY = 0;
	int clippingX = 0;

	//-----------------------------------------------------------------
	// ��� �������� ��ǥ ���
	//-----------------------------------------------------------------
	iDrawX = iDrawX - iSpriteCenterX;
	iDrawY = iDrawY - iSpriteCenterY;

	// 2019.08.02
	// ��������Ʈ �߶󳻱�

	// ��
	if (iSpriteHeight < SpriteCutOutRect.top) {
		return;
	}
	else {
		iSpriteHeight = iSpriteHeight - SpriteCutOutRect.top;
		dwpSprite = (DWORD *)((BYTE *)dwpSprite + iSpritePitch * SpriteCutOutRect.top);
	}

	// �Ʒ�
	if (iSpriteHeight < SpriteCutOutRect.bottom) {
		return;
	}
	else {
		iSpriteHeight = iSpriteHeight - SpriteCutOutRect.bottom;
	}

	// ����
	if (iSpriteWidth < SpriteCutOutRect.left) {
		return;
	}
	else {
		iSpriteWidth = iSpriteWidth - SpriteCutOutRect.left;
		dwpSprite = dwpSprite + SpriteCutOutRect.left;
	}

	// ������
	if (iSpriteHeight < SpriteCutOutRect.right) {
		return;
	}
	else {
		iSpriteHeight = iSpriteHeight - SpriteCutOutRect.right;
	}


	//-----------------------------------------------------------------
	// ��� �� ���� ��������Ʈ ��� ��ġ ���. (��� Ŭ����)
	// �ϴܿ� ������ ���. (�ϴ� Ŭ����)
	// ���� ��� ��ġ ���. (���� Ŭ����)
	// ������ ��� ��ġ ���. (���� Ŭ����)
	//-----------------------------------------------------------------

	if (bCameraOption) {
		//2018.02.08
		//ī�޶� �������� ��������Ʈ �� Ŭ���� ó��
		if (iDrawY < m_iCameraPosY) {
			//2018.02.08
			clippingY = m_iCameraPosY - iDrawY;
			iSpriteHeight = iSpriteHeight - clippingY;
			if (iSpriteHeight > 0) {
				dwpSprite = (DWORD *)((BYTE *)dwpSprite + iSpritePitch * clippingY);
			}
			iDrawY = m_iCameraPosY;
		}

		if (iDrawY + iSpriteHeight >= m_iCameraPosY + iDestHeight) {
			iSpriteHeight = iSpriteHeight - ((iDrawY + iSpriteHeight) - (m_iCameraPosY + iDestHeight));
		}

		if (iDrawX < m_iCameraPosX) {
			//2018.02.08
			clippingX = m_iCameraPosX - iDrawX;
			iSpriteWidth = iSpriteWidth - clippingX;
			if (iSpriteWidth > 0) {
				dwpSprite = dwpSprite + clippingX;
			}
			iDrawX = m_iCameraPosX;
		}

		if (iDrawX + iSpriteWidth >= m_iCameraPosX + iDestWidth) {
			iSpriteWidth = iSpriteWidth - ((iDrawX + iSpriteWidth) - (m_iCameraPosX + iDestWidth));
		}

		//2018.02.08
		//ī�޶� �������� iDrawX iDrawY �� ��ǥ ���߱�
		iDrawX = iDrawX - m_iCameraPosX;
		iDrawY = iDrawY - m_iCameraPosY;
	}
	else {
		// 2019.07.22
		// ȭ�� �������� Ŭ���� ó��
		if (iDrawY < 0) {
			//2018.02.08
			clippingY = -iDrawY;
			iSpriteHeight = iSpriteHeight - clippingY;
			iDrawY = 0;
		}

		if (iDrawY + iSpriteHeight >= iDestHeight) {
			iSpriteHeight = iSpriteHeight - ((iDrawY + iSpriteHeight) - iDestHeight);
		}

		if (iDrawX < 0) {
			//2018.02.08
			clippingX = -iDrawX;
			iSpriteWidth = iSpriteWidth - clippingX;
			iDrawX = 0;
		}

		if (iDrawX + iSpriteWidth >= iDestWidth) {
			iSpriteWidth = iSpriteWidth - ((iDrawX + iSpriteWidth) - iDestWidth);
		}
	}

	if (iSpriteWidth <= 0 || iSpriteHeight <= 0) {
		return;
	}


	//-----------------------------------------------------------------
	// ȭ�鿡 ���� ��ġ�� �̵��Ѵ�.
	//-----------------------------------------------------------------
	dwpDest = (DWORD *)((BYTE *)(dwpDest + iDrawX) + (iDrawY * iDestPitch));
	bypTempSprite = (BYTE *)dwpSprite;
	bypTempDest = (BYTE *)dwpDest;

	//-----------------------------------------------------------------
	// ��ü ũ�⸦ ���鼭 �ȼ����� �׸� ���.
	//-----------------------------------------------------------------
	for (iCountY = 0; iSpriteHeight > iCountY; iCountY++)
	{
		for (iCountX = 0; iSpriteWidth > iCountX; iCountX++)
		{
			*dwpDest = *dwpSprite;
			//����ĭ �̵�
			++dwpDest;
			++dwpSprite;
		}
		//-----------------------------------------------------------------
		// �����ٷ� �̵�, ȭ��� ��������Ʈ ���..
		//-----------------------------------------------------------------
		bypTempDest = bypTempDest + iDestPitch;
		bypTempSprite = bypTempSprite + iSpritePitch;

		dwpDest = (DWORD *)bypTempDest;
		dwpSprite = (DWORD *)bypTempSprite;
	}
}



/*********************************
	DrawSpriteRed
	������ ������ �̹��� ���
**********************************/
void CSpriteDib::DrawSpriteRed(int iSpriteIndex, int iDrawX, int iDrawY, BYTE *bypDest, int iDestWidth,
	int iDestHeight, int iDestPitch)
{
	//-----------------------------------------------------------------
	// �ִ� ��������Ʈ ������ �ʰ� �ϰų�, �ε���� �ʴ� ��������Ʈ��� ����
	//-----------------------------------------------------------------
	if (m_iMaxSprite < iSpriteIndex)
		return;

	if (m_stpSprite[iSpriteIndex].bypImage == NULL)
		return;

	//-----------------------------------------------------------------
	// ���������� �ʿ����� ����
	//-----------------------------------------------------------------
	st_SPRITE *stpSprite = &m_stpSprite[iSpriteIndex];

	int iCountY;
	int iCountX;
	int iSpriteHeight = stpSprite->iHeight;
	int iSpriteWidth = stpSprite->iWidth;
	int iSpritePitch = stpSprite->iPitch;
	int iSpriteCenterX = stpSprite->iCenterPointX;
	int iSpriteCenterY = stpSprite->iCenterPointY;
	DWORD *dwpSprite = (DWORD *)stpSprite->bypImage;
	DWORD *dwpDest = (DWORD *)bypDest;
	BYTE *bypTempSprite;
	BYTE *bypTempDest;

	//-----------------------------------------------------------------
	// ��� �������� ��ǥ ���
	//-----------------------------------------------------------------
	iDrawX = iDrawX - iSpriteCenterX;
	iDrawY = iDrawY - iSpriteCenterY;

	//-----------------------------------------------------------------
	// ��� �� ���� ��������Ʈ ��� ��ġ ���. (��� Ŭ����)
	// �ϴܿ� ������ ���. (�ϴ� Ŭ����)
	// ���� ��� ��ġ ���. (���� Ŭ����)
	// ������ ��� ��ġ ���. (���� Ŭ����)
	//-----------------------------------------------------------------

	//2018.02.08
	//ī�޶� �������� ��������Ʈ �� Ŭ���� ó��
	int clippingY;
	int clippingX;

	if (iDrawY < m_iCameraPosY) {
		//2018.02.08
		clippingY = m_iCameraPosY - iDrawY;
		iSpriteHeight = iSpriteHeight - clippingY;
		if (iSpriteHeight > 0) {
			dwpSprite = (DWORD *)((BYTE *)dwpSprite + iSpritePitch * clippingY);
		}
		iDrawY = m_iCameraPosY;
	}

	if (iDrawY + iSpriteHeight >= m_iCameraPosY + iDestHeight) {
		iSpriteHeight = iSpriteHeight - ((iDrawY + iSpriteHeight) - (m_iCameraPosY + iDestHeight));
	}

	if (iDrawX < m_iCameraPosX) {
		//2018.02.08
		clippingX = m_iCameraPosX - iDrawX;
		iSpriteWidth = iSpriteWidth - clippingX;
		if (iSpriteWidth > 0) {
			dwpSprite = dwpSprite + clippingX;
		}
		iDrawX = m_iCameraPosX;
	}

	if (iDrawX + iSpriteWidth >= m_iCameraPosX + iDestWidth) {
		iSpriteWidth = iSpriteWidth - ((iDrawX + iSpriteWidth) - (m_iCameraPosX + iDestWidth));
	}


	if (iSpriteWidth <= 0 || iSpriteHeight <= 0) {
		return;
	}

	//2018.02.08
	//ī�޶� �������� iDrawX iDrawY �� ��ǥ ���߱�
	iDrawX = iDrawX - m_iCameraPosX;
	iDrawY = iDrawY - m_iCameraPosY;

	//-----------------------------------------------------------------
	// ȭ�鿡 ���� ��ġ�� �̵��Ѵ�.
	//-----------------------------------------------------------------
	dwpDest = (DWORD *)((BYTE *)(dwpDest + iDrawX) + (iDrawY * iDestPitch));
	bypTempSprite = (BYTE *)dwpSprite;
	bypTempDest = (BYTE *)dwpDest;

	//-----------------------------------------------------------------
	// ��ü ũ�⸦ ���鼭 �ȼ����� ����� ó���� �ϸ� �׸� ���.
	//-----------------------------------------------------------------
	for (iCountY = 0; iSpriteHeight > iCountY; iCountY++)
	{
		for (iCountX = 0; iSpriteWidth > iCountX; iCountX++)
		{
			if (m_dwColorKey != (*dwpSprite & 0x00ffffff)) {
				*((BYTE *)dwpDest + 2) = *((BYTE *)dwpSprite + 2);
				*((BYTE *)dwpDest + 1) = *((BYTE *)dwpSprite + 1) / 2;
				*((BYTE *)dwpDest + 0) = *((BYTE *)dwpSprite + 0) / 2;
			}

			//����ĭ �̵�
			++dwpDest;
			++dwpSprite;
		}
		//-----------------------------------------------------------------
		// �����ٷ� �̵�, ȭ��� ��������Ʈ ���..
		//-----------------------------------------------------------------
		bypTempDest = bypTempDest + iDestPitch;
		bypTempSprite = bypTempSprite + iSpritePitch;

		dwpDest = (DWORD *)bypTempDest;
		dwpSprite = (DWORD *)bypTempSprite;
	}
}




/*********************************
	DrawSpriteCompose
	�ռ� ���
**********************************/
void CSpriteDib::DrawSpriteCompose(int iSpriteIndex, int iDrawX, int iDrawY, BYTE *bypDest, int iDestWidth,
	int iDestHeight, int iDestPitch, double dCompose, bool bCameraOption)
{
	//-----------------------------------------------------------------
	// �ִ� ��������Ʈ ������ �ʰ� �ϰų�, �ε���� �ʴ� ��������Ʈ��� ����
	//-----------------------------------------------------------------
	if (m_iMaxSprite < iSpriteIndex)
		return;

	if (m_stpSprite[iSpriteIndex].bypImage == NULL)
		return;

	//-----------------------------------------------------------------
	// ���������� �ʿ����� ����
	//-----------------------------------------------------------------
	st_SPRITE *stpSprite = &m_stpSprite[iSpriteIndex];

	int iCountY;
	int iCountX;
	int iSpriteHeight = stpSprite->iHeight;
	int iSpriteWidth = stpSprite->iWidth;
	int iSpritePitch = stpSprite->iPitch;
	int iSpriteCenterX = stpSprite->iCenterPointX;
	int iSpriteCenterY = stpSprite->iCenterPointY;
	DWORD *dwpSprite = (DWORD *)stpSprite->bypImage;
	DWORD *dwpDest = (DWORD *)bypDest;
	BYTE *bypTempSprite;
	BYTE *bypTempDest;
	double dDestCompose = 1.0;

	if (dCompose > 1.0) {
		dCompose = 1.0;
	}
	else if (dCompose < 0) {
		dCompose = 0;
	}

	dDestCompose = dDestCompose - dCompose;

	//-----------------------------------------------------------------
	// ��� �������� ��ǥ ���
	//-----------------------------------------------------------------
	iDrawX = iDrawX - iSpriteCenterX;
	iDrawY = iDrawY - iSpriteCenterY;

	//-----------------------------------------------------------------
	// ��� �� ���� ��������Ʈ ��� ��ġ ���. (��� Ŭ����)
	// �ϴܿ� ������ ���. (�ϴ� Ŭ����)
	// ���� ��� ��ġ ���. (���� Ŭ����)
	// ������ ��� ��ġ ���. (���� Ŭ����)
	//-----------------------------------------------------------------

	if (bCameraOption) {
		//2018.02.08
		//ī�޶� �������� ��������Ʈ �� Ŭ���� ó��
		int clippingY;
		int clippingX;

		if (iDrawY < m_iCameraPosY) {
			//2018.02.08
			clippingY = m_iCameraPosY - iDrawY;
			iSpriteHeight = iSpriteHeight - clippingY;
			if (iSpriteHeight > 0) {
				dwpSprite = (DWORD *)((BYTE *)dwpSprite + iSpritePitch * clippingY);
			}
			iDrawY = m_iCameraPosY;
		}

		if (iDrawY + iSpriteHeight >= m_iCameraPosY + iDestHeight) {
			iSpriteHeight = iSpriteHeight - ((iDrawY + iSpriteHeight) - (m_iCameraPosY + iDestHeight));
		}

		if (iDrawX < m_iCameraPosX) {
			//2018.02.08
			clippingX = m_iCameraPosX - iDrawX;
			iSpriteWidth = iSpriteWidth - clippingX;
			if (iSpriteWidth > 0) {
				dwpSprite = dwpSprite + clippingX;
			}
			iDrawX = m_iCameraPosX;
		}

		if (iDrawX + iSpriteWidth >= m_iCameraPosX + iDestWidth) {
			iSpriteWidth = iSpriteWidth - ((iDrawX + iSpriteWidth) - (m_iCameraPosX + iDestWidth));
		}

		//2018.02.08
		//ī�޶� �������� iDrawX iDrawY �� ��ǥ ���߱�
		iDrawX = iDrawX - m_iCameraPosX;
		iDrawY = iDrawY - m_iCameraPosY;
	}
	else {
		// 2019.07.22
			// ȭ�� �������� Ŭ���� ó��
		int clippingY;
		int clippingX;

		if (iDrawY < 0) {
			//2018.02.08
			clippingY = -iDrawY;
			iSpriteHeight = iSpriteHeight - clippingY;
			iDrawY = 0;
		}

		if (iDrawY + iSpriteHeight >= iDestHeight) {
			iSpriteHeight = iSpriteHeight - ((iDrawY + iSpriteHeight) - iDestHeight);
		}

		if (iDrawX < 0) {
			//2018.02.08
			clippingX = -iDrawX;
			iSpriteWidth = iSpriteWidth - clippingX;
			iDrawX = 0;
		}

		if (iDrawX + iSpriteWidth >= iDestWidth) {
			iSpriteWidth = iSpriteWidth - ((iDrawX + iSpriteWidth) - iDestWidth);
		}
	}

	if (iSpriteWidth <= 0 || iSpriteHeight <= 0) {
		return;
	}

	//-----------------------------------------------------------------
	// ȭ�鿡 ���� ��ġ�� �̵��Ѵ�.
	//-----------------------------------------------------------------
	dwpDest = (DWORD *)((BYTE *)(dwpDest + iDrawX) + (iDrawY * iDestPitch));
	bypTempSprite = (BYTE *)dwpSprite;
	bypTempDest = (BYTE *)dwpDest;

	//-----------------------------------------------------------------
	// ��ü ũ�⸦ ���鼭 �ȼ����� ����� ó���� �ϸ� �׸� ���.
	//-----------------------------------------------------------------
	for (iCountY = 0; iSpriteHeight > iCountY; iCountY++)
	{
		for (iCountX = 0; iSpriteWidth > iCountX; iCountX++)
		{
			if (m_dwColorKey != (*dwpSprite & 0x00ffffff)) {
				*((BYTE *)dwpDest + 2) = (*((BYTE *)dwpSprite + 2) * dDestCompose) + (*((BYTE *)dwpDest + 2) * dCompose);
				*((BYTE *)dwpDest + 1) = (*((BYTE *)dwpSprite + 1) * dDestCompose) + (*((BYTE *)dwpDest + 1) * dCompose);
				*((BYTE *)dwpDest + 0) = (*((BYTE *)dwpSprite + 0) * dDestCompose) + (*((BYTE *)dwpDest + 0) * dCompose);
			}

			//����ĭ �̵�
			++dwpDest;
			++dwpSprite;
		}
		//-----------------------------------------------------------------
		// �����ٷ� �̵�, ȭ��� ��������Ʈ ���..
		//-----------------------------------------------------------------
		bypTempDest = bypTempDest + iDestPitch;
		bypTempSprite = bypTempSprite + iSpritePitch;

		dwpDest = (DWORD *)bypTempDest;
		dwpSprite = (DWORD *)bypTempSprite;
	}
}

// ü�¹� ��
void CSpriteDib::DrawPercentage(int iSpriteIndex, int iDrawX, int iDrawY, BYTE *bypDest, int iDestWidth,
	int iDestHeight, int iDestPitch, int iPercentage) {
	//-----------------------------------------------------------------
	// �ִ� ��������Ʈ ������ �ʰ� �ϰų�, �ε���� �ʴ� ��������Ʈ��� ����
	//-----------------------------------------------------------------
	if (m_iMaxSprite < iSpriteIndex)
		return;

	if (m_stpSprite[iSpriteIndex].bypImage == NULL)
		return;

	//-----------------------------------------------------------------
	// ���������� �ʿ����� ����
	//-----------------------------------------------------------------
	st_SPRITE *stpSprite = &m_stpSprite[iSpriteIndex];

	int iCountY;
	int iCountX;
	int iSpriteHeight = stpSprite->iHeight;
	int iSpriteWidth = stpSprite->iWidth;
	int iSpritePitch = stpSprite->iPitch;
	int iSpriteCenterX = stpSprite->iCenterPointX;
	int iSpriteCenterY = stpSprite->iCenterPointY;
	DWORD *dwpSprite = (DWORD *)stpSprite->bypImage;
	DWORD *dwpDest = (DWORD *)bypDest;
	BYTE *bypTempSprite;
	BYTE *bypTempDest;

	//-----------------------------------------------------------------
	// ��� �������� ��ǥ ���
	//-----------------------------------------------------------------
	iDrawX = iDrawX - iSpriteCenterX;
	iDrawY = iDrawY - iSpriteCenterY;

	//-----------------------------------------------------------------
	// ��� �� ���� ��������Ʈ ��� ��ġ ���. (��� Ŭ����)
	// �ϴܿ� ������ ���. (�ϴ� Ŭ����)
	// ���� ��� ��ġ ���. (���� Ŭ����)
	// ������ ��� ��ġ ���. (���� Ŭ����)
	//-----------------------------------------------------------------

	//2018.02.08
	//ī�޶� �������� ��������Ʈ �� Ŭ���� ó��
	int clippingY;
	int clippingX;

	if (iDrawY < m_iCameraPosY) {
		//2018.02.08
		clippingY = m_iCameraPosY - iDrawY;
		iSpriteHeight = iSpriteHeight - clippingY;
		if (iSpriteHeight > 0) {
			dwpSprite = (DWORD *)((BYTE *)dwpSprite + iSpritePitch * clippingY);
		}
		iDrawY = m_iCameraPosY;
	}

	if (iDrawY + iSpriteHeight >= m_iCameraPosY + iDestHeight) {
		iSpriteHeight = iSpriteHeight - ((iDrawY + iSpriteHeight) - (m_iCameraPosY + iDestHeight));
	}

	if (iDrawX < m_iCameraPosX) {
		//2018.02.08
		clippingX = m_iCameraPosX - iDrawX;
		iSpriteWidth = iSpriteWidth - clippingX;
		if (iSpriteWidth > 0) {
			dwpSprite = dwpSprite + clippingX;
		}
		iDrawX = m_iCameraPosX;
	}

	if (iDrawX + iSpriteWidth >= m_iCameraPosX + iDestWidth) {
		iSpriteWidth = iSpriteWidth - ((iDrawX + iSpriteWidth) - (m_iCameraPosX + iDestWidth));
	}


	if (iSpriteWidth <= 0 || iSpriteHeight <= 0) {
		return;
	}

	//2018.02.08
	//ī�޶� �������� iDrawX iDrawY �� ��ǥ ���߱�
	iDrawX = iDrawX - m_iCameraPosX;
	iDrawY = iDrawY - m_iCameraPosY;

	//-----------------------------------------------------------------
	// ȭ�鿡 ���� ��ġ�� �̵��Ѵ�.
	//-----------------------------------------------------------------
	dwpDest = (DWORD *)((BYTE *)(dwpDest + iDrawX) + (iDrawY * iDestPitch));
	bypTempSprite = (BYTE *)dwpSprite;
	bypTempDest = (BYTE *)dwpDest;

	//-----------------------------------------------------------------
	// ��ü ũ�⸦ ���鼭 �ȼ����� ����� ó���� �ϸ� �׸� ���.
	//-----------------------------------------------------------------
	for (iCountY = 0; iSpriteHeight > iCountY; iCountY++)
	{
		for (iCountX = 0; iSpriteWidth - ((100 - iPercentage) * ((double)iSpriteWidth / (double)100)) > iCountX; iCountX++)
		{
			if (m_dwColorKey != (*dwpSprite & 0x00ffffff)) {
				*dwpDest = *dwpSprite;
			}

			//����ĭ �̵�
			++dwpDest;
			++dwpSprite;
		}
		//-----------------------------------------------------------------
		// �����ٷ� �̵�, ȭ��� ��������Ʈ ���..
		//-----------------------------------------------------------------
		bypTempDest = bypTempDest + iDestPitch;
		bypTempSprite = bypTempSprite + iSpritePitch;

		dwpDest = (DWORD *)bypTempDest;
		dwpSprite = (DWORD *)bypTempSprite;
	}
}

void CSpriteDib::DrawBackground(COLORREF RGBColor, BYTE * bypDest, int iDestWidth, int iDestHeight, int iDestPitch, int iDestColorByte)
{
	int iCountY;
	int iCountX;
	int iR;
	int iG;
	int iB;
	BYTE *bypCopyDest;
	BYTE *bypTempDest;

	bypCopyDest = bypDest;
	bypTempDest = bypCopyDest;

	
	iR = GetRValue(RGBColor);
	iG = GetGValue(RGBColor);
	iB = GetBValue(RGBColor);

	//-----------------------------------------------------------------
	// ��ü ũ�⸦ ���鼭 �ȼ����� ����� ó���� �ϸ� �׸� ���.
	//-----------------------------------------------------------------
	for (iCountY = 0; iDestHeight > iCountY; iCountY++)
	{
		for (iCountX = 0; iDestWidth > iCountX; iCountX++)
		{
			*(bypCopyDest + 2) = iR;
			*(bypCopyDest + 1) = iG;
			*(bypCopyDest + 0) = iB;

			//����ĭ �̵�
			bypCopyDest = bypCopyDest + iDestColorByte;

		}
		//-----------------------------------------------------------------
		// �����ٷ� �̵�, ȭ��� ��������Ʈ ���..
		//-----------------------------------------------------------------
		bypTempDest = bypTempDest + iDestPitch;

		bypCopyDest = bypTempDest;
	}
}

void CSpriteDib::DrawBackground(DWORD dwRGBColor, int iDrawX, int iDrawY, int iWidth, int iHeight, 
	BYTE * bypDest, int iDestWidth, int iDestHeight, int iDestPitch,
	double dCompose, bool bCameraOption, bool bComposeOption)
{
	int iCountY;
	int iCountX;
	DWORD *dwpDest = (DWORD *)bypDest;
	BYTE *bypTempDest;
	double dDestCompose = 1.0;

	if (dCompose > 1.0) {
		dCompose = 1.0;
	}
	else if (dCompose < 0) {
		dCompose = 0;
	}

	dDestCompose = dDestCompose - dCompose;

	//-----------------------------------------------------------------
	// ��� �� ���� ��������Ʈ ��� ��ġ ���. (��� Ŭ����)
	// �ϴܿ� ������ ���. (�ϴ� Ŭ����)
	// ���� ��� ��ġ ���. (���� Ŭ����)
	// ������ ��� ��ġ ���. (���� Ŭ����)
	//-----------------------------------------------------------------

	if (bCameraOption) {
		//2018.02.08
		//ī�޶� �������� ��������Ʈ �� Ŭ���� ó��
		int clippingY;
		int clippingX;

		if (iDrawY < m_iCameraPosY) {
			//2018.02.08
			clippingY = m_iCameraPosY - iDrawY;
			iHeight = iHeight - clippingY;
			iDrawY = m_iCameraPosY;
		}

		if (iDrawY + iHeight >= m_iCameraPosY + iDestHeight) {
			iHeight = iHeight - ((iDrawY + iHeight) - (m_iCameraPosY + iDestHeight));
		}

		if (iDrawX < m_iCameraPosX) {
			//2018.02.08
			clippingX = m_iCameraPosX - iDrawX;
			iWidth = iWidth - clippingX;
			iDrawX = m_iCameraPosX;
		}

		if (iDrawX + iWidth >= m_iCameraPosX + iDestWidth) {
			iWidth = iWidth - ((iDrawX + iWidth) - (m_iCameraPosX + iDestWidth));
		}

		//2018.02.08
		//ī�޶� �������� iDrawX iDrawY �� ��ǥ ���߱�
		iDrawX = iDrawX - m_iCameraPosX;
		iDrawY = iDrawY - m_iCameraPosY;
	}
	else {
		// 2019.07.22
		// ȭ�� �������� Ŭ���� ó��
		int clippingY;
		int clippingX;

		if (iDrawY < 0) {
			//2018.02.08
			clippingY = -iDrawY;
			iHeight = iHeight - clippingY;
			iDrawY = 0;
		}

		if (iDrawY + iHeight >= iDestHeight) {
			iHeight = iHeight - ((iDrawY + iHeight) - iDestHeight);
		}

		if (iDrawX < 0) {
			//2018.02.08
			clippingX = -iDrawX;
			iWidth = iWidth - clippingX;
			iDrawX = 0;
		}

		if (iDrawX + iWidth >= iDestWidth) {
			iWidth = iWidth - ((iDrawX + iWidth) - iDestWidth);
		}
	}
	


	if (iWidth <= 0 || iHeight <= 0) {
		return;
	}


	//-----------------------------------------------------------------
	// ȭ�鿡 ���� ��ġ�� �̵��Ѵ�.
	//-----------------------------------------------------------------
	dwpDest = (DWORD *)((BYTE *)(dwpDest + iDrawX) + (iDrawY * iDestPitch));
	bypTempDest = (BYTE *)dwpDest;


	if (bComposeOption) {
		//-----------------------------------------------------------------
		// ���ڷ� ���� ���� ���� ���� ��ŭ dest�� Ư�� ������ ä��� (���)
		//-----------------------------------------------------------------
		for (iCountY = 0; iHeight > iCountY; iCountY++)
		{
			for (iCountX = 0; iWidth > iCountX; iCountX++)
			{
				*((BYTE *)dwpDest + 2) = (*((BYTE *)&dwRGBColor + 2) * dCompose) + (*((BYTE *)dwpDest + 2) * dDestCompose);
				*((BYTE *)dwpDest + 1) = (*((BYTE *)&dwRGBColor + 1) * dCompose) + (*((BYTE *)dwpDest + 1) * dDestCompose);
				*((BYTE *)dwpDest + 0) = (*((BYTE *)&dwRGBColor + 0) * dCompose) + (*((BYTE *)dwpDest + 0) * dDestCompose);

				//����ĭ �̵�
				++dwpDest;

			}
			//-----------------------------------------------------------------
			// �����ٷ� �̵�
			//-----------------------------------------------------------------
			bypTempDest = bypTempDest + iDestPitch;

			dwpDest = (DWORD *)bypTempDest;
		}
	}
	else {
		//-----------------------------------------------------------------
		// ���ڷ� ���� ���� ���� ���� ��ŭ dest�� Ư�� ������ ä��� (���)
		//-----------------------------------------------------------------
		for (iCountY = 0; iHeight > iCountY; iCountY++)
		{
			for (iCountX = 0; iWidth > iCountX; iCountX++)
			{
				*dwpDest = dwRGBColor;

				//����ĭ �̵�
				++dwpDest;

			}
			//-----------------------------------------------------------------
			// �����ٷ� �̵�
			//-----------------------------------------------------------------
			bypTempDest = bypTempDest + iDestPitch;

			dwpDest = (DWORD *)bypTempDest;
		}
	}
}

//ī�޶� ��ġ
void CSpriteDib::SetCameraPosition(int iPosX, int iPosY) {
	m_iCameraPosX = iPosX;
	m_iCameraPosY = iPosY;
}

void CSpriteDib::Reset(int iMaxSprite, DWORD dwColorKey)
{
	int iCount;
	//-----------------------------------------------------------------
	// ��ü�� ���鼭 ��� ������.
	//-----------------------------------------------------------------
	for (iCount = 0; iCount < m_iMaxSprite; iCount++)
	{
		ReleaseSprite(iCount);
	}
	delete[] m_stpSprite;


	//-----------------------------------------------------------------
	// �ִ� �о�� ���� ��ŭ �̸� �Ҵ� �޴´�.
	//-----------------------------------------------------------------
	m_iMaxSprite = iMaxSprite;
	m_dwColorKey = dwColorKey;
	m_stpSprite = new st_SPRITE[iMaxSprite];

	// �ʱ�ȭ
	iCount = 0;
	while (iCount < iMaxSprite) {
		m_stpSprite[iCount].bypImage = NULL;
		++iCount;
	}

	//�⺻ ī�޶� ��ġ
	m_iCameraPosX = 0;
	m_iCameraPosY = 0;
}
