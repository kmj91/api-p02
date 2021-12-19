//#pragma once

#ifndef __SPRITE_DIB__
#define __SPRITE_DIB__




class CSpriteDib
{
public:

	// **************************************************************** 
	// DIB ��������Ʈ ����ü. 
	//
	// ��������Ʈ �̹����� ������ ������ ����.
	// **************************************************************** 
	struct st_SPRITE
	{
		BYTE	*bypImage;				// ��������Ʈ �̹��� ������.
		int		iWidth;					// Widht
		int		iHeight;				// Height
		int		iPitch;					// Pitch

		int		iCenterPointX;			// ���� X
		int		iCenterPointY;			// ���� Y
		int		iColorByte;				// �̹����� ���ȼ��� ǥ���ϴµ� �ʿ��� ����Ʈ �� (��Ʈ �÷� ex.24��Ʈ �÷� , 32��Ʈ �÷�)
	};
	////////////////////////////////////////////////////////////////////
	// ������, �ı���.
	//
	// Parameters: (int)�ִ� ��������Ʈ ����. (DWORD)����Į��.
	////////////////////////////////////////////////////////////////////
	CSpriteDib();
	CSpriteDib(int iMaxSprite, DWORD dwColorKey);
	virtual ~CSpriteDib();

	///////////////////////////////////////////////////////
	// LoadDibSprite. 
	// BMP������ �о �ϳ��� ���������� �����Ѵ�.
	//
	///////////////////////////////////////////////////////
	BOOL LoadDibSprite(int iSpriteIndex, const wchar_t * szFileName, int iCenterPointX, int iCenterPointY);

	///////////////////////////////////////////////////////
	// ReleaseSprite. 
	// �ش� ��������Ʈ ����.
	//
	///////////////////////////////////////////////////////
	void ReleaseSprite(int iSpriteIndex);


	///////////////////////////////////////////////////////
	// DrawCompatibilitySprite. 
	// Ư�� �޸� ��ġ�� ��������Ʈ�� ����Ѵ�. (Į��Ű, Ŭ���� ó��)
	// sprite ��Ʈ�÷� 24, 32 ȣȯ
	// dest ��Ʈ�÷� 24, 32 ȣȯ
	///////////////////////////////////////////////////////
	void CompatibleDrawSprite(int iSpriteIndex, int iDrawX, int iDrawY, BYTE *bypDest, int iDestWidth,
		int iDestHeight, int iDestPitch, int iDestColorByte);

	// 24, 32 ��Ʈ �÷� ȣȯ �ռ� ���
	void CompatibleDrawSpriteCompose(int iSpriteIndex, int iDrawX, int iDrawY, BYTE *bypDest, int iDestWidth,
		int iDestHeight, int iDestPitch, int iDestColorByte, double dCompose);


	///////////////////////////////////////////////////////
	// DrawSprite. 
	// Ư�� �޸� ��ġ�� ��������Ʈ�� ����Ѵ�. (Į��Ű, Ŭ���� ó��)
	//
	///////////////////////////////////////////////////////
	void DrawSprite(int iSpriteIndex, int iDrawX, int iDrawY, BYTE *bypDest, int iDestWidth,
		int iDestHeight, int iDestPitch, bool bCameraOption = true);
	///////////////////////////////////////////////////////
	// DrawImage. 
	// Ư�� �޸� ��ġ�� �̹����� ����Ѵ�. (Ŭ���� ó��)
	//
	///////////////////////////////////////////////////////
	void DrawImage(int iSpriteIndex, int iDrawX, int iDrawY, BYTE *bypDest, int iDestWidth,
		int iDestHeight, int iDestPitch, bool bCameraOption = true);

	// ��������Ʈ Ư������ �߷����� ���
	void DrawCutOutImage(int iSpriteIndex, int iDrawX, int iDrawY, BYTE *bypDest, int iDestWidth,
		int iDestHeight, int iDestPitch, RECT SpriteCutOutRect, bool bCameraOption = true);

	// ������ ������ ���
	void DrawSpriteRed(int iSpriteIndex, int iDrawX, int iDrawY, BYTE *bypDest, int iDestWidth,
		int iDestHeight, int iDestPitch);

	// �ռ� ���
	void DrawSpriteCompose(int iSpriteIndex, int iDrawX, int iDrawY, BYTE *bypDest, int iDestWidth,
		int iDestHeight, int iDestPitch, double dCompose = 1.0, bool bCameraOption = true);

	// ü�¹� ��
	void DrawPercentage(int iSpriteIndex, int iDrawX, int iDrawY, BYTE *bypDest, int iDestWidth,
		int iDestHeight, int iDestPitch, int iPercentage = 100);

	// dest�� Ư�� ������ ä��� (���)
	void DrawBackground(COLORREF RGBColor, BYTE *bypDest, int iDestWidth, int iDestHeight, int iDestPitch, int iDestColorByte);
	void DrawBackground(DWORD dwRGBColor, int iDrawX, int iDrawY, int iWidth, int iHeight, 
		BYTE *bypDest, int iDestWidth, int iDestHeight, int iDestPitch,
		double dCompose = 1.0, bool bCameraOption = false, bool bComposeOption = false);

	//ī�޶� ��ġ
	void SetCameraPosition(int iPosX, int iPosY);

	void Reset(int iMaxSprite, DWORD dwColorKey);

protected:

	//------------------------------------------------------------------
	// Sprite �迭 ����.
	//------------------------------------------------------------------
	int		m_iMaxSprite;

public:
	st_SPRITE	*m_stpSprite;

protected:
	//------------------------------------------------------------------
	// ���� �������� ����� �÷�.
	//------------------------------------------------------------------
	DWORD		m_dwColorKey;

	//�÷��̾� ī�޶� ���� �� ������ 0,0 �κ� ��ǥ
	int	m_iCameraPosX;
	int m_iCameraPosY;
};

#endif
