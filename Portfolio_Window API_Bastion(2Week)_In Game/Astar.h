// 기명준
// 길찾기 알고리즘 A*
// 몬스터가 플레이어를 향해 추적할 때 사용

#pragma once

#include <list>
#include <vector>

using namespace std;

class Astar
{
public:
	//외부로 나갈 노드 정보 좌표값
	struct _Node {
		int iPosX;
		int iPosY;
	};

	struct stNode
	{
		stNode *parent;		// 부모 포인터
		double dF;			// G + H 합
		double dG;			// 출발점에서의 거리
		double dH;			// 도착점에서의 거리
		int iPosX;			// 노드 위치 좌표 X
		int iPosY;			// 노드 위치 좌표 Y
	};

	enum {
		EMPT = 0,		// 비어있다
		WALL = 1,		// 벽
		EMPT_2 = 2,		// 통과 가능
		DEPA = 10,		// 출발지
		DEST = 20,		// 도착지
		NODE = 30,		// 노드
	};

public:
	Astar();
	~Astar();

	bool Start(vector<vector<int> > maps, int iDepaX, int iDepaY, int iDestX, int iDestY);
	void CheckNode(int iPosX, int iPosY, stNode *stpNode, double dPlus);
	void CreateNode(int iPosX, int iPosY, stNode *ParentNode, double dPlus);

	bool GetFinishNode(_Node *outNode);			// 길찾기 완료 마지막 노드 얻기

private:
	void Release();			// 메모리 정리
	void SortOpenList();	// 오픈 리스트 정렬
	void AdjacentNode(stNode *stpNode);			// 인접한 노드 생성

private:
	int m_iDepaX;			// 출발지 x
	int m_iDepaY;			// 출발지 y
	int m_iDestX;			// 도착지 x
	int m_iDestY;			// 도착지 y
	int m_iMapSizeX;		// map 가로 길이
	int m_iMapSizeY;		// map 세로 길이
	int m_iSize;			// 칸 사이즈
	double m_straight_line;
	double m_diagonal_line;

	bool m_finish;			// 길찾기 종료 여부 플래그
	stNode * m_finishNode;	// 길찾기 종료시 도착지 노드

	BYTE * m_bypMap;		// 길찾기 바이트 맵

	//CList<stNode *> *g_openList;
	//CList<stNode *> *g_closedList;
	//CList<BaseObject *> *m_objectList;
	//list<stNode *> *m_openList;
	//list<stNode *> *m_closedList;
	//list<stNode *> *m_outList;		// 외부로 나갈 노드 리스트
};

