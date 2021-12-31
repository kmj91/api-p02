// �����
// ��ã�� �˰��� A*
// ���Ͱ� �÷��̾ ���� ������ �� ���

#pragma once

#include <list>
#include <vector>

using namespace std;

class Astar
{
public:
	//�ܺη� ���� ��� ���� ��ǥ��
	struct _Node {
		int iPosX;
		int iPosY;
	};

	struct stNode
	{
		stNode *parent;		// �θ� ������
		double dF;			// G + H ��
		double dG;			// ����������� �Ÿ�
		double dH;			// ������������ �Ÿ�
		int iPosX;			// ��� ��ġ ��ǥ X
		int iPosY;			// ��� ��ġ ��ǥ Y
	};

	enum {
		EMPT = 0,		// ����ִ�
		WALL = 1,		// ��
		EMPT_2 = 2,		// ��� ����
		DEPA = 10,		// �����
		DEST = 20,		// ������
		NODE = 30,		// ���
	};

public:
	Astar();
	~Astar();

	bool Start(vector<vector<int> > maps, int iDepaX, int iDepaY, int iDestX, int iDestY);
	void CheckNode(int iPosX, int iPosY, stNode *stpNode, double dPlus);
	void CreateNode(int iPosX, int iPosY, stNode *ParentNode, double dPlus);

	bool GetFinishNode(_Node *outNode);			// ��ã�� �Ϸ� ������ ��� ���

private:
	void Release();			// �޸� ����
	void SortOpenList();	// ���� ����Ʈ ����
	void AdjacentNode(stNode *stpNode);			// ������ ��� ����

private:
	int m_iDepaX;			// ����� x
	int m_iDepaY;			// ����� y
	int m_iDestX;			// ������ x
	int m_iDestY;			// ������ y
	int m_iMapSizeX;		// map ���� ����
	int m_iMapSizeY;		// map ���� ����
	int m_iSize;			// ĭ ������
	double m_straight_line;
	double m_diagonal_line;

	bool m_finish;			// ��ã�� ���� ���� �÷���
	stNode * m_finishNode;	// ��ã�� ����� ������ ���

	BYTE * m_bypMap;		// ��ã�� ����Ʈ ��

	//CList<stNode *> *g_openList;
	//CList<stNode *> *g_closedList;
	//CList<BaseObject *> *m_objectList;
	//list<stNode *> *m_openList;
	//list<stNode *> *m_closedList;
	//list<stNode *> *m_outList;		// �ܺη� ���� ��� ����Ʈ
};

