// 기명준
// 자료구조 리스트
// 양방향 연결 리스트로 구현

#pragma once

template <typename T>
class CList
{
public:
	// 노드
	struct Node
	{
		T _data;
		Node *_Prev;
		Node *_Next;
	};

	// 이터레이터
	class iterator
	{
	public:
		Node *_node;
	public:
		iterator(Node *node = nullptr)
		{
			//인자로 들어온 Node 포인터를 저장
			this->_node = node;
		}

		//전위 증가
		iterator& operator ++()
		{
			//현재 노드를 다음 노드로 이동
			_node = _node->_Next;
			return (*this);
		}

		//후위 증가
		iterator operator ++(int)
		{
			//현재 노드를 다음 노드로 이동
			const iterator temp = *this;
			++*this;
			return (temp);
		}

		//전위 감소
		iterator& operator--()
		{
			_node = _node->_Prev;
			return (*this);
		}

		//후위 감소
		iterator operator--(int)
		{
			const iterator temp = *this;
			--*this;
			return (temp);
		}

		// 같은지 비교
		bool operator==(const iterator& _Right) const
		{
			return (_node == _Right._node);
		}

		// 위에서 구현한 == 연산자 이용
		bool operator!=(const iterator& _Right) const
		{
			return (!(*this == _Right));
		}

		// 현제 노드의 데이터 반환
		T& operator *() const
		{
			return (_node->_data);
		}

		// 포인터 찌르기 구조체 반환
		Node* operator->() const {
			return _node;
		}
	};

public:
	CList();
	~CList();

	iterator begin()
	{
		//첫 번째 노드를 가리키는 이터레이터 리턴
		return iterator(_head->_Next);
	}
	iterator rbegin()
	{
		//역방향 목록에서 첫 번째 노드를 가리키는 이터레이터 리턴
		return iterator(_tail->_Prev);
	}
	
	iterator head()
	{
		// head 리턴
		return iterator(_head);
	}
	iterator end()
	{
		//Tail 노드를 가리키는(데이터가 없는 진짜 끝 노드) 이터레이터를 리턴
		//	또는 끝으로 인지할 수 있는 이터레이터를 리턴
		return iterator(_tail);
	}

	// 노드 삭제
	iterator erase(iterator iter) {
		Node *node = _head->_Next;
		Node *temp = nullptr;
		while (node != _tail) {				// 리스트의 끝까지 순회
			if (node == iter._node) {		// 삭제할 노드와 비교
				temp = node->_Prev;			// 삭제할 노드의 앞 노드 포인터
				temp->_Next = node->_Next;	// 앞 노드의 다음 노드는 삭제 노드의 다음 노드
				temp = node->_Next;			// 삭제할 노드의 다음 노드 포인터
				temp->_Prev = node->_Prev;	// 다음 노드의 앞 노드는 삭제할 노드의 앞 노드
				delete node;				// 노드 삭제
				--_size;					// 리스트 사이즈 감소
				return temp;				// 삭제한 노드의 다음 노드 이터레이터 반환
			}
			node = node->_Next;				// 다음 노드로
		}
		return _tail;						// 삭제할 노드가 리스트에 없다면 리스트의 끝 반환
	}

	void initNode(Node *ptr);
	void push_front(T data);
	void push_back(T data);
	void clear();
	void delete_Node(T data);
	int size();
	bool is_empty();

private:
	int _size = 0;
	Node *_head;
	Node *_tail;
};


//생성자
template <typename T>
CList<T>::CList() {
	_head = new Node;
	initNode(_head);
	_tail = new Node;
	initNode(_tail);
	_head->_Next = _tail;
	_tail->_Prev = _head;
}

//파괴자
template <typename T>
CList<T>::~CList() {
	clear();
	delete _head;
	delete _tail;
}

//노드 초기화
template <typename T>
void CList<T>::initNode(Node *ptr) {
	ptr->_Prev = NULL;
	ptr->_Next = NULL;
}

//헤드 뒤 삽입
template <typename T>
void CList<T>::push_front(T data) {
	Node *node = new Node;			// 신규 노드
	Node *nextNode = _head->_Next;	// 헤드의 다음 노드 포인터 저장
	node->_data = data;				// 삽입 데이터
	node->_Prev = _head;			// 신규 노드의 앞은 헤드
	node->_Next = nextNode;			// 신규 노드의 다음은 기존의 헤드의 다음 노드
	nextNode->_Prev = node;			// 기존 헤드의 다음 노드의 이전은 신규 노드
	_head->_Next = node;			// 헤드의 다음 노드는 신규 노드
	++_size;						// 리스트 사이즈 증가
}

//꼬리 앞 삽입
template <typename T>
void CList<T>::push_back(T data) {
	Node *node = new Node;			// 신규 노드
	Node *prevNode = _tail->_Prev;	// 꼬리의 앞 노드 포인터 저장
	node->_data = data;				// 삽입 데이터
	node->_Prev = prevNode;			// 신규 노드의 앞은 기존 꼬리 헤드의 앞 노드
	node->_Next = _tail;			// 신규 노드의 다음 노드는 꼬리
	prevNode->_Next = node;			// 기존 꼬리 노드의 앞 노드의 다음은 신규 노드
	_tail->_Prev = node;			// 꼬리의 앞 노드는 신규 노드
	++_size;						// 리스트 사이즈 증가
}

//전부 삭제
template <typename T>
void CList<T>::clear() {
	Node *node = _head->_Next;
	Node *temp = node->_Next;
	while (node != _tail) {
		delete node;
		node = temp;
		temp = node->_Next;
		--_size;
	}

	_head->_Next = _tail;
	_tail->_Prev = _head;
}

//해당 노드 삭제
template <typename T>
void CList<T>::delete_Node(T data) {
	Node *node = _head->_Next;
	Node *temp;
	while (node != _tail) {
		if (node->_data == data) {
			temp = node->_Prev;
			temp->_Next = node->_Next;
			temp = node->_Next;
			temp->_Prev = node->_Prev;
			delete node;
			--_size;
			return;
		}
		node = node->_Next;
	}
}

template <typename T>
int CList<T>::size() {
	return _size;
}

template <typename T>
bool CList<T>::is_empty() {
	if (_size == 0) {
		return true;
	}
	else {
		return false;
	}
}