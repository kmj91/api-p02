// �����
// ��ã�� �˰��� A*
// ���Ͱ� �÷��̾ ���� ������ �� ���

#include "stdafx.h"
#include "Astar.h"
#include "CList.h"


struct Astar::stNode;


CList<Astar::stNode *> g_openList;
CList<Astar::stNode *> g_closedList;

Astar::Astar()
{
	m_straight_line = 1;
	m_diagonal_line = 1.4;

	m_finish = false;

	m_bypMap = nullptr;

	//m_closedList = new list<stNode *>;
	//m_openList = new list<stNode *>;
	//m_outList = new list<stNode *>;
}


Astar::~Astar()
{
	//delete m_closedList;
	//delete m_openList;
	//delete m_outList;

	// �޸� ����
	Release();
}


// ��ã�� ����
// maps : �� �Ӽ� ����
// iDepaX : ����� ��ǥ X
// iDepaY : ����� ��ǥ Y
// iDestX : ������ ��ǥ X
// iDestY : ������ ��ǥ Y
// ��ȯ �� : ��ã�� ���� false, ���� true
bool Astar::Start(vector<vector<int> > maps, int iDepaX, int iDepaY, int iDestX, int iDestY)
{
	int iCntY;
	int iCntX;
	CList<stNode *>::iterator iter;			//����Ʈ ��ȯ�� ���� ���ͷ�����
	CList<stNode *>::iterator iter_end;		//����Ʈ ��ȯ�� ���� ���ͷ�����
	vector<int> *elementArrPtr;
	int *elementPtr;
	BYTE *bypTempMap;						// �ӽ� ��
	stNode *stpNode;
	int iResultX;
	int iResultY;
	int iTemp;

	elementArrPtr = maps.data();			// 0, 0 ������
	m_iMapSizeY = maps.size();				// ���� ������
	m_iMapSizeX = elementArrPtr->size();	// ���� ������

	// ����� ������
	m_iDepaX = iDepaX;
	m_iDepaY = iDepaY;
	m_iDestX = iDestX;
	m_iDestY = iDestY;

	
	// ���� ������ �� ����
	m_bypMap = new BYTE[m_iMapSizeY * m_iMapSizeX];

	bypTempMap = m_bypMap;
	iCntY = 0;
	while (iCntY < m_iMapSizeY) {
		elementPtr = elementArrPtr->data();
		iCntX = 0;
		while (iCntX < m_iMapSizeX) {
			// ������ �Է�
			*bypTempMap = *elementPtr;

			++iCntX;
			++elementPtr;
			++bypTempMap;
		}
		++iCntY;
		++elementArrPtr;
	}

	if (m_iDepaX > m_iDestX) {
		iResultX = m_iDepaX - m_iDestX;
	}
	else {
		iResultX = m_iDestX - m_iDepaX;
	}

	if (m_iDepaY > m_iDestY) {
		iResultY = m_iDepaY - m_iDestY;
	}
	else {
		iResultY = m_iDestY - m_iDepaY;
	}
	iTemp = iResultX + iResultY;


	// ���� ĳ���� ó�� ��ġ�� ��� ���� (���� ��ġ)
	stpNode = new stNode;
	stpNode->parent = NULL;					// ó�� �����ϴ� ���� �θ� ��尡 ����
	stpNode->dF = iTemp;
	stpNode->dG = 0;						// ���� ��ġ���� ��������� �Ÿ�
	stpNode->dH = iTemp;					// �� �������� ��������� �Ÿ�
	stpNode->iPosX = m_iDepaX;				// ĳ���� ó�� ��ġ�� 0, 0 �̴�
	stpNode->iPosY = m_iDepaY;
	g_openList.push_front(stpNode);

	bypTempMap = m_bypMap;
	// ������� ��ŷ
	bypTempMap = (bypTempMap + m_iDepaX) + (m_iDepaY * m_iMapSizeX);
	//*bypTempMap = *bypTempMap | DEPA;
	*bypTempMap = DEPA;

	bypTempMap = m_bypMap;
	// �������� ��ŷ
	bypTempMap = (bypTempMap + m_iDestX) + (m_iDestY * m_iMapSizeX);
	//*bypTempMap = *bypTempMap | DEST;
	*bypTempMap = DEST;


	// ��� Ž��
	while (true) {
		// ����Ʈ ����� 0�̸� ��ã�� ����
		if (g_openList.size() == 0) {
			// �޸� ����
			Release();
			// ��� Ž�� ����
			return false;
		}

		// ���ĵ� ���� ����Ʈ���� F���� ���� ���� ��带 �ϳ� ����
		stpNode = g_openList.data();
		g_openList.pop_front();

		// ������ �˻�
		bypTempMap = m_bypMap;
		bypTempMap = (bypTempMap + stpNode->iPosX) + (stpNode->iPosY * m_iMapSizeX);
		if (*bypTempMap == DEST) {
			// ������ ��� (������ ���)
			m_finishNode = stpNode;
			// ��� Ž�� ����
			return true;
		}

		// ������ ��� ����
		AdjacentNode(stpNode);
		// �̹��� Ž���� ��� Closed list��
		g_closedList.push_front(stpNode);
		// ���� ����Ʈ ����
		SortOpenList();
	}//while (!true)

	return false;
}


bool Astar::GetFinishNode(_Node * outNode)
{
	CList<stNode *>::iterator iter;				//����Ʈ ��ȯ�� ���� ���ͷ�����
	CList<stNode *>::iterator iter_end;			//����Ʈ ��ȯ�� ���� ���ͷ�����
	stNode *stpNode;

	if (m_finishNode->parent == NULL) {
		// �޸� ����
		Release();

		return false;
	}

	// ����
	if (m_finishNode == m_finishNode->parent->parent) {
		// �޸� ����
		Release();

		return false;
	}

	//outNode->iPosX = m_finishNode->iPosX * m_iSize;
	//outNode->iPosY = m_finishNode->iPosY * m_iSize;

	//outNode->iPosX = m_finishNode->parent->iPosX;
	//outNode->iPosY = m_finishNode->parent->iPosY;

	outNode->iPosX = m_finishNode->iPosX;
	outNode->iPosY = m_finishNode->iPosY;

	m_finishNode = m_finishNode->parent;

	return true;
}




// �޸� ����
void Astar::Release()
{
	CList<stNode*>::iterator iter;			//����Ʈ ��ȯ�� ���� ���ͷ�����
	CList<stNode*>::iterator iter_end;		//����Ʈ ��ȯ�� ���� ���ͷ�����

	// ���� ����Ʈ �޸� ����
	iter = g_openList.begin();
	iter_end = g_openList.end();
	while (iter != iter_end) {
		delete* iter;
		++iter;
	}
	g_openList.clear();

	// Ŭ����� ����Ʈ �޸� ����
	iter = g_closedList.begin();
	iter_end = g_closedList.end();
	while (iter != iter_end) {
		delete* iter;
		++iter;
	}
	g_closedList.clear();

	// �׸��� �� ����
	if (m_bypMap != nullptr)
	{
		delete[] m_bypMap;
		m_bypMap = nullptr;
	}
}

// ���� ����Ʈ ����
void Astar::SortOpenList()
{
	if (g_openList.size() < 2)
		return;

	int iListNum = 0;						// ���� ������ġ
	int iListEnd = g_openList.size() - 1;	// ����Ʈ ��
	int iSortNum = 0;						// ���� ���� ��ġ
	stNode* compareObject;					// ���� ��
	stNode* sortObject;						// ������ ��

	CList<stNode*>::iterator iter = g_openList.begin();
	CList<stNode*>::iterator iterSort = nullptr;
	while (iListNum != iListEnd) {
		iterSort = iter;
		compareObject = iterSort._node->_Next->_data;

		iSortNum = iListNum;
		while (iSortNum >= 0) {
			sortObject = iterSort._node->_data;
			// F ���� �۴ٸ� �Ѿ
			if (sortObject->dF <= compareObject->dF)
				break;

			//F �� ������ �ڷ� ����
			iterSort._node->_Next->_data = sortObject;
			iterSort._node->_data = compareObject;

			--iterSort;
			--iSortNum;
		}
		++iListNum;
		++iter;
	}// while (iListNum != iListEnd)
}


// ������ ��� ����
// stpNode : �θ� �Ǵ� ���
void Astar::AdjacentNode(stNode* stpNode)
{
	int iPosX = stpNode->iPosX;		// ��� ��ġ X
	int iPosY = stpNode->iPosY;		// ��� ��ġ Y
	int iTempX;
	int iTempY;
	BYTE* bypTempMap = m_bypMap;	// �ӽ� ��

	// ��
	if (iPosY - 1 >= 0) {
		iTempY = iPosY - 1;
		bypTempMap = (bypTempMap + iPosX) + (iTempY * m_iMapSizeX);
		if (*bypTempMap != WALL && *bypTempMap != DEPA) {
			if (*bypTempMap == NODE) {
				// ��� ��
				CheckNode(iPosX, iTempY, stpNode, m_straight_line);
			}
			else if (*bypTempMap == EMPT || *bypTempMap == DEST || *bypTempMap == EMPT_2) {
				// ��� ����
				CreateNode(iPosX, iTempY, stpNode, m_straight_line);
			}
		}
		//��ġ ����
		bypTempMap = m_bypMap;

		// �� ������
		if (iPosX + 1 < m_iMapSizeX) {
			iTempY = iPosY - 1;
			iTempX = iPosX + 1;

			bypTempMap = (bypTempMap + iTempX) + (iTempY * m_iMapSizeX);
			if (*bypTempMap != WALL && *bypTempMap != DEPA) {
				if (*bypTempMap == NODE) {
					CheckNode(iTempX, iTempY, stpNode, m_diagonal_line);
				}
				else if (*bypTempMap == EMPT || *bypTempMap == DEST || *bypTempMap == EMPT_2) {
					CreateNode(iTempX, iTempY, stpNode, m_diagonal_line);
				}
			}
			//��ġ ����
			bypTempMap = m_bypMap;
		}

		// �� ����
		if (iPosX - 1 >= 0) {
			iTempY = iPosY - 1;
			iTempX = iPosX - 1;

			bypTempMap = (bypTempMap + iTempX) + (iTempY * m_iMapSizeX);
			if (*bypTempMap != WALL && *bypTempMap != DEPA) {
				if (*bypTempMap == NODE) {
					CheckNode(iTempX, iTempY, stpNode, m_diagonal_line);
				}
				else if (*bypTempMap == EMPT || *bypTempMap == DEST || *bypTempMap == EMPT_2) {
					CreateNode(iTempX, iTempY, stpNode, m_diagonal_line);
				}
			}
			//��ġ ����
			bypTempMap = m_bypMap;
		}
	}

	// ������
	if (iPosX + 1 < m_iMapSizeX) {
		iTempX = iPosX + 1;

		bypTempMap = (bypTempMap + iTempX) + (iPosY * m_iMapSizeX);
		if (*bypTempMap != WALL && *bypTempMap != DEPA) {
			if (*bypTempMap == NODE) {
				CheckNode(iTempX, iPosY, stpNode, m_straight_line);
			}
			else if (*bypTempMap == EMPT || *bypTempMap == DEST || *bypTempMap == EMPT_2) {
				CreateNode(iTempX, iPosY, stpNode, m_straight_line);
			}
		}
		//��ġ ����
		bypTempMap = m_bypMap;
	}

	// �Ʒ�
	if (iPosY + 1 < m_iMapSizeY) {
		iTempY = iPosY + 1;

		bypTempMap = (bypTempMap + iPosX) + (iTempY * m_iMapSizeX);
		if (*bypTempMap != WALL && *bypTempMap != DEPA) {
			if (*bypTempMap == NODE) {
				CheckNode(iPosX, iTempY, stpNode, m_straight_line);
			}
			else if (*bypTempMap == EMPT || *bypTempMap == DEST || *bypTempMap == EMPT_2) {
				CreateNode(iPosX, iTempY, stpNode, m_straight_line);
			}
		}
		//��ġ ����
		bypTempMap = m_bypMap;


		// �Ʒ� ������
		if (iPosX + 1 < m_iMapSizeX) {
			iTempY = iPosY + 1;
			iTempX = iPosX + 1;

			bypTempMap = (bypTempMap + iTempX) + (iTempY * m_iMapSizeX);
			if (*bypTempMap != WALL && *bypTempMap != DEPA) {
				if (*bypTempMap == NODE) {
					CheckNode(iTempX, iTempY, stpNode, m_diagonal_line);
				}
				else if (*bypTempMap == EMPT || *bypTempMap == DEST || *bypTempMap == EMPT_2) {
					CreateNode(iTempX, iTempY, stpNode, m_diagonal_line);
				}
			}
			//��ġ ����
			bypTempMap = m_bypMap;
		}


		// �Ʒ� ����
		if (iPosX - 1 >= 0) {
			iTempY = iPosY + 1;
			iTempX = iPosX - 1;

			bypTempMap = (bypTempMap + iTempX) + (iTempY * m_iMapSizeX);
			if (*bypTempMap != WALL && *bypTempMap != DEPA) {
				if (*bypTempMap == NODE) {
					CheckNode(iTempX, iTempY, stpNode, m_diagonal_line);
				}
				else if (*bypTempMap == EMPT || *bypTempMap == DEST || *bypTempMap == EMPT_2) {
					CreateNode(iTempX, iTempY, stpNode, m_diagonal_line);
				}
			}
			//��ġ ����
			bypTempMap = m_bypMap;
		}
	}

	// ����
	if (iPosX - 1 >= 0) {
		iTempX = iPosX - 1;

		bypTempMap = (bypTempMap + iTempX) + (iPosY * m_iMapSizeX);
		if (*bypTempMap != WALL && *bypTempMap != DEPA) {
			if (*bypTempMap == NODE) {
				CheckNode(iTempX, iPosY, stpNode, m_straight_line);
			}
			else if (*bypTempMap == EMPT || *bypTempMap == DEST || *bypTempMap == EMPT_2) {
				CreateNode(iTempX, iPosY, stpNode, m_straight_line);
			}
		}
		//��ġ ����
		bypTempMap = m_bypMap;
	}
}


// ��� F�� üũ
void Astar::CheckNode(int iPosX, int iPosY, stNode* stpNode, double dPlus) {
	stNode* stpCheckNode;
	CList<stNode*>::iterator iter;			//����Ʈ ��ȯ�� ���� ���ͷ�����
	CList<stNode*>::iterator iter_end;		//����Ʈ�� ��

	iter = g_closedList.begin();
	iter_end = g_closedList.end();
	while (iter != iter_end) {
		stpCheckNode = *iter;
		if (stpCheckNode->iPosX == iPosX && stpCheckNode->iPosY == iPosY) {
			// F�� ��
			//if (stpCheckNode->dF > stpNode->dF) {
			//	stpCheckNode->parent = stpNode;
			//}

			// F�� ��
			if ((int)(stpCheckNode->dF + 0.5) > (int)(stpNode->dF + 0.5)) {
				stpCheckNode->parent = stpNode;
			}

			//if (stpCheckNode->dF > stpNode->dF) {
			//	stpCheckNode->parent = stpNode;
			//	stpCheckNode->dG = stpNode->dG + dPlus;
			//	stpCheckNode->dF = stpCheckNode->dG + stpCheckNode->dH;
			//}
			break;
		}
		++iter;
	}//while(iter != iter_end)
}


// ��� ����
void Astar::CreateNode(int iPosX, int iPosY, stNode* ParentNode, double dPlus) {
	stNode* newNode;
	int iResultX;
	int iResultY;
	//double dH;
	double dG;
	BYTE* bypTempMap;
	double dTemp;
	double dTempStraight;
	double dTempDiagonal;

	newNode = new stNode;

	if (iPosX > m_iDestX) {
		iResultX = iPosX - m_iDestX;
	}
	else {
		iResultX = m_iDestX - iPosX;
	}

	if (iPosY > m_iDestY) {
		iResultY = iPosY - m_iDestY;
	}
	else {
		iResultY = m_iDestY - iPosY;
	}

	//dH = iResultX + iResultY;
	// H�� ����
	if (iResultX > iResultY) {
		dTempStraight = iResultX - iResultY;
		dTempDiagonal = iResultY * m_diagonal_line;
		dTemp = dTempStraight + dTempDiagonal;
	}
	else {
		dTempStraight = iResultY - iResultX;
		dTempDiagonal = iResultX * m_diagonal_line;
		dTemp = dTempStraight + dTempDiagonal;
	}


	//dG = ParentNode->dG + 1;
	dG = ParentNode->dG + dPlus;


	newNode->parent = ParentNode;
	//newNode->dF = dG + dH;
	newNode->dF = dG + dTemp;
	newNode->dG = dG;
	//newNode->dH = dH;
	newNode->dH = dTemp;
	newNode->iPosX = iPosX;
	newNode->iPosY = iPosY;
	g_openList.push_front(newNode);

	bypTempMap = m_bypMap;
	bypTempMap = (bypTempMap + iPosX) + (iPosY * m_iMapSizeX);
	if (*bypTempMap != DEST) {
		*bypTempMap = NODE;
	}
}