// �����
// �������� ��
// ������ ������ ���������� ũ�� �� �Ӽ� ����
// Click �Լ����� ���� ���¿� ���� ���� ������ ����� ���� ������Ʈ ����Ʈ�� ����

#include "stdafx.h"
#include "ObjectStageMap.h"
#include "ObjectUnit.h"


ObjectStageMap::ObjectStageMap(int iMapWidth, int iMapHeight)
{
	// Ÿ��
	m_iType = df_TYPE_STAGE_MAP;
	// ��ġ
	m_dX = 0;
	m_dY = 0;
	// ��������Ʈ ��ȣ
	m_iSpriteIndex = df_SPRITE_BACKGROUND_2;
	// ������Ʈ ����
	m_dLeft = 0;
	m_dTop = 0;
	m_dRight = m_dLeft + g_iDestWidth;
	m_dBottom = m_dTop + g_iDestHeight;
	// �׸��� �켱����
	m_iRenderPriority = 0;

	CreateMap(iMapWidth, iMapHeight);
}


ObjectStageMap::~ObjectStageMap()
{
	ReleaseMap();
}

bool ObjectStageMap::Action()
{
	return false;
}

void ObjectStageMap::Draw()
{
	g_cSprite->DrawSprite(m_iSpriteIndex, m_dX, m_dY, g_bypDest, g_iDestWidth, g_iDestHeight, g_iDestPitch, false);
}

// ���������� Ŭ�� ���� ���
// ���� ���� g_MouseState�� ���¿� ���� �б� ó��
bool ObjectStageMap::Click()
{
	CList<Object*>::iterator iter;
	CList<Object*>::iterator iter_end;
	Object *newObject;
	Object *ObjectTemp;
	int iMouseX;
	int iMouseY;
	int iTilePosX;
	int iTilePosY;
	int iPropertiesX;
	int iPropertiesY;

	//--------------------------------------
	// ȭ�� �������� �����̴� UI
	// ī�޶� ��ǥ�� ���ش�
	//--------------------------------------
	iMouseX = g_iMouseX - g_CameraRect.left;
	iMouseY = g_iMouseY - g_CameraRect.top;

	if (m_dLeft < iMouseX && iMouseX < m_dRight &&
		m_dTop < iMouseY && iMouseY < m_dBottom) {

		switch (g_MouseState)
		{
			// �ƹ��͵� ���õ��� ���� ����
		case MOUSE_STATE_EMPT:
			break;
			// 4ĭ ¥�� Ÿ��
		case MOUSE_STATE_TILE_MAKE_4:
			iPropertiesX = g_MousePointer->m_dX / df_TILE_PROPERTIES_SIZE;
			iPropertiesY = g_MousePointer->m_dY / df_TILE_PROPERTIES_SIZE;

			SetProperties(iPropertiesX, iPropertiesY);

			newObject = new ObjectUnit(df_TYPE_TILE, g_iMakeTileIndex, g_MousePointer->m_dX, g_MousePointer->m_dY);
			g_ObjectList->push_back(newObject);

			break;
			// 1ĭ ¥�� Ÿ��
		case MOUSE_STATE_TILE_MAKE_1:
			iPropertiesX = g_MousePointer->m_dX / df_TILE_PROPERTIES_SIZE;
			iPropertiesY = g_MousePointer->m_dY / df_TILE_PROPERTIES_SIZE;

			SetProperties(iPropertiesX, iPropertiesY);

			newObject = new ObjectUnit(df_TYPE_TILE, g_iMakeTileIndex, g_MousePointer->m_dX, g_MousePointer->m_dY);
			g_ObjectList->push_back(newObject);

			break;
			// �Ϲ� ������Ʈ
		case MOUSE_STATE_OBJECT_MAKE:
			// ��������Ʈ ������ǥ�� ������ x, y
			iPropertiesX = g_iMouseX / df_TILE_PROPERTIES_SIZE;
			iPropertiesY = g_iMouseY / df_TILE_PROPERTIES_SIZE;

			if (CheckProperties(iPropertiesX, iPropertiesY)) {
				iTilePosX = iPropertiesX * df_TILE_PROPERTIES_SIZE;
				iTilePosY = iPropertiesY * df_TILE_PROPERTIES_SIZE;

				SetProperties(iPropertiesX, iPropertiesY);

				newObject = new ObjectUnit(df_TYPE_OBJECT, g_iMakeTileIndex, iTilePosX, iTilePosY);
				g_ObjectList->push_back(newObject);
			}

			break;
			// �Ŵ� ����
		case MOUSE_STATE_STAGE_MAKE:
			// ��������Ʈ ������ǥ�� ������ x, y
			iPropertiesX = g_iMouseX / df_TILE_PROPERTIES_SIZE;
			iPropertiesY = g_iMouseY / df_TILE_PROPERTIES_SIZE;

			if (CheckProperties(iPropertiesX, iPropertiesY)) {
				iTilePosX = iPropertiesX * df_TILE_PROPERTIES_SIZE;
				iTilePosY = iPropertiesY * df_TILE_PROPERTIES_SIZE;

				SetProperties(iPropertiesX, iPropertiesY);

				newObject = new ObjectUnit(df_TYPE_STAGE, g_iMakeTileIndex, iTilePosX, iTilePosY);
				g_ObjectList->push_back(newObject);
			}

			break;
			// �ı��Ǵ� ������Ʈ
		case MOUSE_STATE_BROKEN_MAKE:
			// ��������Ʈ ������ǥ�� ������ x, y
			iPropertiesX = g_iMouseX / df_TILE_PROPERTIES_SIZE;
			iPropertiesY = g_iMouseY / df_TILE_PROPERTIES_SIZE;

			if (CheckProperties(iPropertiesX, iPropertiesY)) {
				iTilePosX = iPropertiesX * df_TILE_PROPERTIES_SIZE;
				iTilePosY = iPropertiesY * df_TILE_PROPERTIES_SIZE;

				SetProperties(iPropertiesX, iPropertiesY);

				newObject = new ObjectUnit(df_TYPE_BROKEN, g_iMakeTileIndex, iTilePosX, iTilePosY);
				g_ObjectList->push_back(newObject);
			}

			break;
			// 
		case MOUSE_STATE_ENEMY_MAKE:
			// ��������Ʈ ������ǥ�� ������ x, y
			iPropertiesX = g_iMouseX / df_TILE_PROPERTIES_SIZE;
			iPropertiesY = g_iMouseY / df_TILE_PROPERTIES_SIZE;

			if (CheckProperties(iPropertiesX, iPropertiesY)) {
				iTilePosX = iPropertiesX * df_TILE_PROPERTIES_SIZE;
				iTilePosY = iPropertiesY * df_TILE_PROPERTIES_SIZE;

				SetProperties(iPropertiesX, iPropertiesY);

				newObject = new ObjectUnit(df_TYPE_ENEMY, g_iMakeTileIndex, iTilePosX, iTilePosY);
				g_ObjectList->push_back(newObject);
			}

			break;
		case MOUSE_STATE_PLAYER_MAKE:
			// ��������Ʈ ������ǥ�� ������ x, y
			iPropertiesX = g_iMouseX / df_TILE_PROPERTIES_SIZE;
			iPropertiesY = g_iMouseY / df_TILE_PROPERTIES_SIZE;

			if (CheckProperties(iPropertiesX, iPropertiesY)) {
				iTilePosX = iPropertiesX * df_TILE_PROPERTIES_SIZE;
				iTilePosY = iPropertiesY * df_TILE_PROPERTIES_SIZE;

				SetProperties(iPropertiesX, iPropertiesY);

				if (g_Player != NULL) {
					g_ObjectList->delete_Node(g_Player);
				}

				g_Player = new ObjectUnit(df_TYPE_PLAYER , g_iMakeTileIndex, iTilePosX, iTilePosY);
				g_ObjectList->push_back(g_Player);
			}
			
			break;
		case MOUSE_STATE_ERASE:
			// ���� ���� Ž��
			iter = g_ObjectList->rbegin();
			iter_end = g_ObjectList->head();
			while (iter != iter_end) {
				ObjectTemp = *iter;
				
				switch (ObjectTemp->m_iType) {
				case df_TYPE_STAGE:
				case df_TYPE_TILE:
				case df_TYPE_PLAYER:
				case df_TYPE_OBJECT:
				case df_TYPE_BROKEN:
				case df_TYPE_ENEMY:
					if (((ObjectUnit *)ObjectTemp)->Erase(g_iMouseX, g_iMouseY)) {
						// �Ӽ��� �����
						//--------------------------------------
						// ������ ������Ʈ�� �ڽ��� �Ӽ���ǥ ����°�
						// �ֹ���ġ��
						// �׳� �ٽ� ��� ������Ʈ ���鼭
						// �Ӽ� ������Ʈ�ϴ°� ����
						//--------------------------------------
						g_bUpdateProperties = true;
					}
					break;
				}

				--iter;
			}


			break;
		default:
			break;
		}
		return true;
	}

	return false;
}

// �� ũ�� ����
// iMapWidth : ������ ���� ����
// iMapHeight : ������ ���� ����
void ObjectStageMap::ResizeMap(int iMapWidth, int iMapHeight)
{
	ReleaseMap();
	CreateMap(iMapWidth, iMapHeight);
}

// �� �Ӽ� ����
// iMapWidth : �� �Ӽ� ���� ����
// iMapHeight : �� �Ӽ� ���� ����
void ObjectStageMap::CreateMap(int iMapWidth, int iMapHeight)
{
	// ����
	m_iPropertiesWidth = iMapWidth / df_TILE_PROPERTIES_SIZE;
	if (iMapWidth % df_TILE_PROPERTIES_SIZE) {
		++m_iPropertiesWidth;
	}
	// ����
	m_iPropertiesHeight = iMapHeight / df_TILE_PROPERTIES_SIZE;
	if (iMapHeight % df_TILE_PROPERTIES_SIZE) {
		++m_iPropertiesHeight;
	}
	// ũ��
	m_iPropertiesSize = m_iPropertiesWidth * m_iPropertiesHeight;

	// ���� ����
	m_bypMapProperties = (BYTE*)malloc(m_iPropertiesSize);

	// 1������ ��� 1���� �� ������
	memset(m_bypMapProperties, 1, m_iPropertiesSize);
}

void ObjectStageMap::ReleaseMap()
{
	free(m_bypMapProperties);
}

// �Ӽ� �� ��
// iPropertiesX : ������ �Ӽ� ���� ��ǥ X
// iPropertiesY : ������ �Ӽ� ���� ��ǥ Y
void ObjectStageMap::SetProperties(int iPropertiesX, int iPropertiesY)
{
	int iCntX;						// ī��Ʈ X
	int iCntY;						// ī��Ʈ Y
	int iArrayCntX;					// �� �Ӽ� �迭�� ������ ��� ��� ������ ��ǥ X
	int iArrayCntY;					// �� �Ӽ� �迭�� ������ ��� ��� ������ ��ǥ Y
	int iPropertiesSizeX;			// ������ �Ӽ� ���� ����
	int iPropertiesSizeY;			// ������ �Ӽ� ���� ����
	int iArrayPropertiesIndex;		// ������ �Ӽ� �迭 �ε���
	int iMapPropertiesIndex;		// ������ �� �Ӽ� �迭 �ε���

	//--------------------------------------
	// Ÿ�� ����
	// ���� ��ǥ�� �� ���� ���� ��ġ ��ǥ
	//--------------------------------------
	iPropertiesX = iPropertiesX - g_iPropertiesCenterPointX;
	iPropertiesY = iPropertiesY - g_iPropertiesCenterPointY;


	iPropertiesSizeX = g_iMakePropertiesSizeX;	// ������ �Ӽ� ���� ����
	iPropertiesSizeY = g_iMakePropertiesSizeY;	// ������ �Ӽ� ���� ����

	// �� �Ӽ� �迭�� ������ ��� ��� ����Ȱ ��ǥ
	iArrayCntX = 0;
	iArrayCntY = 0;

	// ȭ������� ������������?
	// ���������� ��ǥ�� ���̵� ����
	if (iPropertiesX < 0) {
		iArrayCntX = -iPropertiesX;
		iPropertiesSizeX = iPropertiesSizeX + iPropertiesX;
		iPropertiesX = 0;
	}
	if (iPropertiesX + iPropertiesSizeX > m_iPropertiesWidth) {
		iPropertiesSizeX = iPropertiesSizeX - ((iPropertiesX + iPropertiesSizeX) - m_iPropertiesWidth);
	}
	if (iPropertiesY < 0) {
		iArrayCntY = -iPropertiesY;
		iPropertiesSizeY = iPropertiesSizeY + iPropertiesY;
		iPropertiesY = 0;
	}
	if (iPropertiesY + iPropertiesSizeY > m_iPropertiesHeight) {
		iPropertiesSizeY = iPropertiesSizeY - ((iPropertiesY + iPropertiesSizeY) - m_iPropertiesHeight);
	}


	// �Ӽ� ����
	iCntY = 0;
	while (iCntY < iPropertiesSizeY) {

		iCntX = 0;
		while (iCntX < iPropertiesSizeX) {
			// ������ �Ӽ� 1���� �ε��� ��
			iArrayPropertiesIndex = (iArrayCntX + iCntX) + ((iArrayCntY + iCntY) * g_iMakePropertiesSizeX);

			// ���� ���� 1���� �� ���� �Ӽ���
			if (g_bypArrayMAkeTileProperties[iArrayPropertiesIndex] == 1) {
				++iCntX;
				continue;
			}

			// ������ �� �Ӽ� 1���� �ε��� ��
			iMapPropertiesIndex = (iPropertiesX + iCntX) + ((iPropertiesY + iCntY) * m_iPropertiesWidth);

			// �Ӽ� ����
			m_bypMapProperties[iMapPropertiesIndex] = g_bypArrayMAkeTileProperties[iArrayPropertiesIndex];
			++iCntX;
		}
		++iCntY;
	}
}

// ������ �� �ִ� �Ӽ����� �˻�
// iPropertiesX : �˻��� �Ӽ� ���� ��ǥ X
// iPropertiesY : �˻��� �Ӽ� ���� ��ǥ Y
// ��ȯ �� : ���� ���� true, �Ұ� false
bool ObjectStageMap::CheckProperties(int iPropertiesX, int iPropertiesY)
{
	int iCntX;					// ī��Ʈ X
	int iCntY;					// ī��Ʈ Y
	int iPropertiesSizeX;		// �Ӽ� ���� ����
	int iPropertiesSizeY;		// �Ӽ� ���� ����
	int iArrayPropertiesIndex;	// ���� �Ӽ� �迭 �ε���
	int iMapPropertiesIndex;	// �� �Ӽ� �迭 �ε���
	BYTE byCheckMakeProperties;	// �˻��� ���� �Ӽ� ��
	BYTE byCheckMapProperties;	// �˻��� �� �Ӽ� ��

	//--------------------------------------
	// Ÿ�� ����
	// ���� ��ǥ�� �� ���� ���� ��ġ ��ǥ
	//--------------------------------------
	iPropertiesX = iPropertiesX - g_iPropertiesCenterPointX;
	iPropertiesY = iPropertiesY - g_iPropertiesCenterPointY;
	

	iPropertiesSizeX = g_iMakePropertiesSizeX;			// �Ӽ� ���� ����
	iPropertiesSizeY = g_iMakePropertiesSizeY;			// �Ӽ� ���� ����
	byCheckMakeProperties = g_byCheckMakeProperties;	// �˻��� ���� �Ӽ� ��
	byCheckMapProperties = g_byCheckMapProperties;		// �˻��� �� �Ӽ� ��

	// �˻�
	iCntY = 0;
	while (iCntY < iPropertiesSizeY) {
		// ���� ���
		if (iPropertiesY + iCntY < 0) {
			++iCntY;
			continue;
		}
		// ���� ���
		if (iPropertiesY + iCntY >= m_iPropertiesHeight) {
			break;
		}

		iCntX = 0;
		while (iCntX < iPropertiesSizeX) {
			// ������ �Ӽ� 1���� �迭 �ε��� ��
			iArrayPropertiesIndex = iCntX + (iCntY * iPropertiesSizeX);

			// ����
			if (g_bypArrayMAkeTileProperties[iArrayPropertiesIndex] != byCheckMakeProperties) {
				++iCntX;
				continue;
			}
			// ���� ���
			if (iPropertiesX + iCntX < 0) {
				++iCntX;
				continue;
			}
			// ���� ���
			if (iPropertiesX + iCntX >= m_iPropertiesWidth) {
				break;
			}

			// �˻��� �� �Ӽ� 1���� �迭 �ε��� ��
			iMapPropertiesIndex = (iPropertiesX + iCntX) + ((iPropertiesY + iCntY) * m_iPropertiesWidth);

			// �� �Ӽ� ���� ���� ������ ������ �� ����
			if (m_bypMapProperties[iMapPropertiesIndex] != byCheckMapProperties) {
				return false;
			}

			++iCntX;
		}
		++iCntY;
	}

	return true;
}
