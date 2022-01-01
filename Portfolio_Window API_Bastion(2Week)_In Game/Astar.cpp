// 기명준
// 길찾기 알고리즘 A*
// 몬스터가 플레이어를 향해 추적할 때 사용

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

	// 메모리 정리
	Release();
}


// 길찾기 시작
// maps : 맵 속성 정보
// iDepaX : 출발지 좌표 X
// iDepaY : 출발지 좌표 Y
// iDestX : 도착지 좌표 X
// iDestY : 도착지 좌표 Y
// 반환 값 : 길찾기 실패 false, 성공 true
bool Astar::Start(vector<vector<int> > maps, int iDepaX, int iDepaY, int iDestX, int iDestY)
{
	int iCntY;
	int iCntX;
	CList<stNode *>::iterator iter;			//리스트 순환을 위한 이터레이터
	CList<stNode *>::iterator iter_end;		//리스트 순환을 위한 이터레이터
	vector<int> *elementArrPtr;
	int *elementPtr;
	BYTE *bypTempMap;						// 임시 맵
	stNode *stpNode;
	int iResultX;
	int iResultY;
	int iTemp;

	elementArrPtr = maps.data();			// 0, 0 포인터
	m_iMapSizeY = maps.size();				// 세로 사이즈
	m_iMapSizeX = elementArrPtr->size();	// 가로 사이즈

	// 출발지 도착지
	m_iDepaX = iDepaX;
	m_iDepaY = iDepaY;
	m_iDestX = iDestX;
	m_iDestY = iDestY;

	
	// 로컬 변수에 맵 생성
	m_bypMap = new BYTE[m_iMapSizeY * m_iMapSizeX];

	bypTempMap = m_bypMap;
	iCntY = 0;
	while (iCntY < m_iMapSizeY) {
		elementPtr = elementArrPtr->data();
		iCntX = 0;
		while (iCntX < m_iMapSizeX) {
			// 맵정보 입력
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


	// 게임 캐릭터 처음 위치의 노드 생성 (시작 위치)
	stpNode = new stNode;
	stpNode->parent = NULL;					// 처음 시작하는 노드는 부모 노드가 없다
	stpNode->dF = iTemp;
	stpNode->dG = 0;						// 시작 위치에서 여기까지의 거리
	stpNode->dH = iTemp;					// 적 진영에서 여기까지의 거리
	stpNode->iPosX = m_iDepaX;				// 캐릭터 처음 위치는 0, 0 이다
	stpNode->iPosY = m_iDepaY;
	g_openList.push_front(stpNode);

	bypTempMap = m_bypMap;
	// 출발지점 마킹
	bypTempMap = (bypTempMap + m_iDepaX) + (m_iDepaY * m_iMapSizeX);
	//*bypTempMap = *bypTempMap | DEPA;
	*bypTempMap = DEPA;

	bypTempMap = m_bypMap;
	// 도착지점 마킹
	bypTempMap = (bypTempMap + m_iDestX) + (m_iDestY * m_iMapSizeX);
	//*bypTempMap = *bypTempMap | DEST;
	*bypTempMap = DEST;


	// 경로 탐색
	while (true) {
		// 리스트 사이즈가 0이면 길찾기 실패
		if (g_openList.size() == 0) {
			// 메모리 정리
			Release();
			// 경로 탐색 실패
			return false;
		}

		// 정렬된 오픈 리스트에서 F값이 가장 작은 노드를 하나 꺼냄
		stpNode = g_openList.data();
		g_openList.pop_front();

		// 도착지 검사
		bypTempMap = m_bypMap;
		bypTempMap = (bypTempMap + stpNode->iPosX) + (stpNode->iPosY * m_iMapSizeX);
		if (*bypTempMap == DEST) {
			// 마지막 노드 (도착지 노드)
			m_finishNode = stpNode;
			// 경로 탐색 성공
			return true;
		}

		// 인접한 노드 생성
		AdjacentNode(stpNode);
		// 이번에 탐색한 노드 Closed list로
		g_closedList.push_front(stpNode);
		// 오픈 리스트 정렬
		SortOpenList();
	}//while (!true)

	return false;
}


bool Astar::GetFinishNode(_Node * outNode)
{
	CList<stNode *>::iterator iter;				//리스트 순환을 위한 이터레이터
	CList<stNode *>::iterator iter_end;			//리스트 순환을 위한 이터레이터
	stNode *stpNode;

	if (m_finishNode->parent == NULL) {
		// 메모리 정리
		Release();

		return false;
	}

	// 에러
	if (m_finishNode == m_finishNode->parent->parent) {
		// 메모리 정리
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




// 메모리 정리
void Astar::Release()
{
	CList<stNode*>::iterator iter;			//리스트 순환을 위한 이터레이터
	CList<stNode*>::iterator iter_end;		//리스트 순환을 위한 이터레이터

	// 오픈 리스트 메모리 정리
	iter = g_openList.begin();
	iter_end = g_openList.end();
	while (iter != iter_end) {
		delete* iter;
		++iter;
	}
	g_openList.clear();

	// 클로즈드 리스트 메모리 정리
	iter = g_closedList.begin();
	iter_end = g_closedList.end();
	while (iter != iter_end) {
		delete* iter;
		++iter;
	}
	g_closedList.clear();

	// 그리드 맵 정리
	if (m_bypMap != nullptr)
	{
		delete[] m_bypMap;
		m_bypMap = nullptr;
	}
}

// 오픈 리스트 정렬
void Astar::SortOpenList()
{
	if (g_openList.size() < 2)
		return;

	int iListNum = 0;						// 정렬 진행위치
	int iListEnd = g_openList.size() - 1;	// 리스트 끝
	int iSortNum = 0;						// 정렬 진행 위치
	stNode* compareObject;					// 비교할 값
	stNode* sortObject;						// 정렬할 값

	CList<stNode*>::iterator iter = g_openList.begin();
	CList<stNode*>::iterator iterSort = nullptr;
	while (iListNum != iListEnd) {
		iterSort = iter;
		compareObject = iterSort._node->_Next->_data;

		iSortNum = iListNum;
		while (iSortNum >= 0) {
			sortObject = iterSort._node->_data;
			// F 값이 작다면 넘어감
			if (sortObject->dF <= compareObject->dF)
				break;

			//F 더 높은거 뒤로 보냄
			iterSort._node->_Next->_data = sortObject;
			iterSort._node->_data = compareObject;

			--iterSort;
			--iSortNum;
		}
		++iListNum;
		++iter;
	}// while (iListNum != iListEnd)
}


// 인접한 노드 생성
// stpNode : 부모가 되는 노드
void Astar::AdjacentNode(stNode* stpNode)
{
	int iPosX = stpNode->iPosX;		// 노드 위치 X
	int iPosY = stpNode->iPosY;		// 노드 위치 Y
	int iTempX;
	int iTempY;
	BYTE* bypTempMap = m_bypMap;	// 임시 맵

	// 위
	if (iPosY - 1 >= 0) {
		iTempY = iPosY - 1;
		bypTempMap = (bypTempMap + iPosX) + (iTempY * m_iMapSizeX);
		if (*bypTempMap != WALL && *bypTempMap != DEPA) {
			if (*bypTempMap == NODE) {
				// 노드 비교
				CheckNode(iPosX, iTempY, stpNode, m_straight_line);
			}
			else if (*bypTempMap == EMPT || *bypTempMap == DEST || *bypTempMap == EMPT_2) {
				// 노드 생성
				CreateNode(iPosX, iTempY, stpNode, m_straight_line);
			}
		}
		//위치 복구
		bypTempMap = m_bypMap;

		// 위 오른쪽
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
			//위치 복구
			bypTempMap = m_bypMap;
		}

		// 위 왼쪽
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
			//위치 복구
			bypTempMap = m_bypMap;
		}
	}

	// 오른쪽
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
		//위치 복구
		bypTempMap = m_bypMap;
	}

	// 아래
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
		//위치 복구
		bypTempMap = m_bypMap;


		// 아래 오른쪽
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
			//위치 복구
			bypTempMap = m_bypMap;
		}


		// 아래 왼쪽
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
			//위치 복구
			bypTempMap = m_bypMap;
		}
	}

	// 왼쪽
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
		//위치 복구
		bypTempMap = m_bypMap;
	}
}


// 노드 F값 체크
void Astar::CheckNode(int iPosX, int iPosY, stNode* stpNode, double dPlus) {
	stNode* stpCheckNode;
	CList<stNode*>::iterator iter;			//리스트 순환을 위한 이터레이터
	CList<stNode*>::iterator iter_end;		//리스트의 끝

	iter = g_closedList.begin();
	iter_end = g_closedList.end();
	while (iter != iter_end) {
		stpCheckNode = *iter;
		if (stpCheckNode->iPosX == iPosX && stpCheckNode->iPosY == iPosY) {
			// F값 비교
			//if (stpCheckNode->dF > stpNode->dF) {
			//	stpCheckNode->parent = stpNode;
			//}

			// F값 비교
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


// 노드 생성
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
	// H값 수정
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