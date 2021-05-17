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

	//m_closedList = new list<stNode *>;
	//m_openList = new list<stNode *>;
	//m_outList = new list<stNode *>;
}


Astar::~Astar()
{
	//delete m_closedList;
	//delete m_openList;
	//delete m_outList;
}


bool Astar::Start(vector<vector<int> > maps, int iDepaX, int iDepaY, int iDestX, int iDestY)
{
	int iMapSizeY;					// �� ���� ����
	int iMapSizeX;					// �� ���� ����
	int iCntY;
	int iCntX;
	int answer = 0;				// ��� ��ȯ��
	int iPosX;					// ��� ��ġ X
	int iPosY;					// ��� ��ġ Y
	int iTempX;
	int iTempY;
	int iListSize;				// ���� ����Ʈ ũ��
	int iListNum;				// ���� ������ġ
	int iListEnd;				// ����Ʈ ��
	int iSortNum;				// ���� ���� ��ġ
	stNode *compareObject;					//���� ��
	stNode *sortObject;						//������ ��
	CList<stNode *>::iterator iter;			//����Ʈ ��ȯ�� ���� ���ͷ�����
	CList<stNode *>::iterator iter_end;			//����Ʈ ��ȯ�� ���� ���ͷ�����
	CList<stNode *>::iterator iterSort;		//������ ���� ���ͷ�����
	vector<int> *elementArrPtr;
	int *elementPtr;
	BYTE *bypTempMap;				// �ӽ� ��
	stNode *stpNode;
	int iResultX;
	int iResultY;
	int iTemp;

	elementArrPtr = maps.data();			// 0, 0 ������
	iMapSizeY = maps.size();				// ���� ������
	iMapSizeX = elementArrPtr->size();		// ���� ������

	// ����� ������
	m_iDepaX = iDepaX;
	m_iDepaY = iDepaY;
	m_iDestX = iDestX;
	m_iDestY = iDestY;

	m_iMapSizeY = iMapSizeY;
	m_iMapSizeX = iMapSizeX;
	// ���� ������ �� ����
	m_bypMap = new BYTE[iMapSizeY * iMapSizeX];

	bypTempMap = m_bypMap;
	iCntY = 0;
	while (iCntY < iMapSizeY) {
		elementPtr = elementArrPtr->data();
		iCntX = 0;
		while (iCntX < iMapSizeX) {
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
	bypTempMap = (bypTempMap + m_iDepaX) + (m_iDepaY * iMapSizeX);
	//*bypTempMap = *bypTempMap | DEPA;
	*bypTempMap = DEPA;

	bypTempMap = m_bypMap;
	// �������� ��ŷ
	bypTempMap = (bypTempMap + m_iDestX) + (m_iDestY * iMapSizeX);
	//*bypTempMap = *bypTempMap | DEST;
	*bypTempMap = DEST;


	// Ž��
	while (true) {
		iListSize = g_openList.size();

		if (iListSize == 0) {
			// ��ã��

			iter = g_openList.begin();
		 	iter_end = g_openList.end();
			while (iter != iter_end) {
				stpNode = *iter;
				delete stpNode;
				++iter;
			}
			g_openList.clear();
			iter = g_closedList.begin();
			iter_end = g_closedList.end();
			while (iter != iter_end) {
				stpNode = *iter;
				delete stpNode;
				++iter;
			}
			g_closedList.clear();

			delete[] m_bypMap;

			return false;
		}

		// ���� ����Ʈ ����
		if (iListSize >= 2) {
			iListNum = 0;
			iListEnd = iListSize - 1;

			iter = g_openList.begin();
			while (iListNum != iListEnd) {
				iterSort = iter;
				compareObject = iterSort._node->_Next->_data;

				iSortNum = iListNum;
				while (iSortNum >= 0) {
					sortObject = iterSort._node->_data;

					//F �� ������ �ڷ� ����
					if (sortObject->dF > compareObject->dF) {
						iterSort._node->_Next->_data = sortObject;
						iterSort._node->_data = compareObject;
					}
					else {
						break;
					}
					--iterSort;
					--iSortNum;
				}

				++iListNum;
				++iter;
			}//while (iListNum != iListEnd)
		}//dF (iListSize >= 2)



		stpNode = g_openList.data();
		g_openList.pop_front();


		bypTempMap = m_bypMap;
		iPosX = stpNode->iPosX;
		iPosY = stpNode->iPosY;
		bypTempMap = (bypTempMap + iPosX) + (iPosY * iMapSizeX);
		if (*bypTempMap == DEST) {
			// ã��

			// ������ ��� (������ ���)
			m_finishNode = stpNode;

			//delete[] m_bypMap;

			return true;
		}
		else {
			bypTempMap = m_bypMap;
			// ��
			if (iPosY - 1 >= 0) {
				iTempY = iPosY - 1;
				bypTempMap = (bypTempMap + iPosX) + (iTempY * iMapSizeX);
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

					bypTempMap = (bypTempMap + iTempX) + (iTempY * iMapSizeX);
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

					bypTempMap = (bypTempMap + iTempX) + (iTempY * iMapSizeX);
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
			if (iPosX + 1 < iMapSizeX) {
				iTempX = iPosX + 1;

				bypTempMap = (bypTempMap + iTempX) + (iPosY * iMapSizeX);
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
			if (iPosY + 1 < iMapSizeY) {
				iTempY = iPosY + 1;

				bypTempMap = (bypTempMap + iPosX) + (iTempY * iMapSizeX);
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
				if (iPosX + 1 < iMapSizeX) {
					iTempY = iPosY + 1;
					iTempX = iPosX + 1;

					bypTempMap = (bypTempMap + iTempX) + (iTempY * iMapSizeX);
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

					bypTempMap = (bypTempMap + iTempX) + (iTempY * iMapSizeX);
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

				bypTempMap = (bypTempMap + iTempX) + (iPosY * iMapSizeX);
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


			g_closedList.push_front(stpNode);
		}

	}//while (!bFinish)



	return false;
}


// ��� F�� üũ
void Astar::CheckNode(int iPosX, int iPosY, stNode *stpNode, double dPlus) {
	stNode *stpCheckNode;
	CList<stNode *>::iterator iter;			//����Ʈ ��ȯ�� ���� ���ͷ�����
	CList<stNode *>::iterator iter_end;		//����Ʈ�� ��

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


void Astar::CreateNode(int iPosX, int iPosY, stNode *ParentNode, double dPlus) {
	stNode *newNode;
	int iResultX;
	int iResultY;
	//double dH;
	double dG;
	BYTE * bypTempMap;
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


bool Astar::GetFinishNode(_Node * outNode)
{
	CList<stNode *>::iterator iter;				//����Ʈ ��ȯ�� ���� ���ͷ�����
	CList<stNode *>::iterator iter_end;			//����Ʈ ��ȯ�� ���� ���ͷ�����
	stNode *stpNode;

	if (m_finishNode->parent == NULL) {

		// �޸� ����
		iter = g_openList.begin();
		iter_end = g_openList.end();
		while (iter != iter_end) {
			stpNode = *iter;
			delete stpNode;
			++iter;
		}
		g_openList.clear();
		iter = g_closedList.begin();
		iter_end = g_closedList.end();
		while (iter != iter_end) {
			stpNode = *iter;
			delete stpNode;
			++iter;
		}
		g_closedList.clear();

		delete[] m_bypMap;

		return false;
	}

	// ����
	if (m_finishNode == m_finishNode->parent->parent) {

		// �޸� ����
		iter = g_openList.begin();
		iter_end = g_openList.end();
		while (iter != iter_end) {
			delete *iter;
			++iter;
		}
		g_openList.clear();
		iter = g_closedList.begin();
		iter_end = g_closedList.end();
		while (iter != iter_end) {
			delete *iter;
			++iter;
		}
		g_closedList.clear();

		delete[] m_bypMap;

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
