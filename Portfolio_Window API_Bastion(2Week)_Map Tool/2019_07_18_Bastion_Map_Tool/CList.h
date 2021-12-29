// �����
// �ڷᱸ�� ����Ʈ
// ����� ���� ����Ʈ�� ����

#pragma once

template <typename T>
class CList
{
public:
	// ���
	struct Node
	{
		T _data;
		Node *_Prev;
		Node *_Next;
	};

	// ���ͷ�����
	class iterator
	{
	public:
		Node *_node;
	public:
		iterator(Node *node = nullptr)
		{
			//���ڷ� ���� Node �����͸� ����
			this->_node = node;
		}

		//���� ����
		iterator& operator ++()
		{
			//���� ��带 ���� ���� �̵�
			_node = _node->_Next;
			return (*this);
		}

		//���� ����
		iterator operator ++(int)
		{
			//���� ��带 ���� ���� �̵�
			const iterator temp = *this;
			++*this;
			return (temp);
		}

		//���� ����
		iterator& operator--()
		{
			_node = _node->_Prev;
			return (*this);
		}

		//���� ����
		iterator operator--(int)
		{
			const iterator temp = *this;
			--*this;
			return (temp);
		}

		// ������ ��
		bool operator==(const iterator& _Right) const
		{
			return (_node == _Right._node);
		}

		// ������ ������ == ������ �̿�
		bool operator!=(const iterator& _Right) const
		{
			return (!(*this == _Right));
		}

		// ���� ����� ������ ��ȯ
		T& operator *() const
		{
			return (_node->_data);
		}

		// ������ ��� ����ü ��ȯ
		Node* operator->() const {
			return _node;
		}
	};

public:
	CList();
	~CList();

	iterator begin()
	{
		//ù ��° ��带 ����Ű�� ���ͷ����� ����
		return iterator(_head->_Next);
	}
	iterator rbegin()
	{
		//������ ��Ͽ��� ù ��° ��带 ����Ű�� ���ͷ����� ����
		return iterator(_tail->_Prev);
	}
	
	iterator head()
	{
		// head ����
		return iterator(_head);
	}
	iterator end()
	{
		//Tail ��带 ����Ű��(�����Ͱ� ���� ��¥ �� ���) ���ͷ����͸� ����
		//	�Ǵ� ������ ������ �� �ִ� ���ͷ����͸� ����
		return iterator(_tail);
	}

	// ��� ����
	iterator erase(iterator iter) {
		Node *node = _head->_Next;
		Node *temp = nullptr;
		while (node != _tail) {				// ����Ʈ�� ������ ��ȸ
			if (node == iter._node) {		// ������ ���� ��
				temp = node->_Prev;			// ������ ����� �� ��� ������
				temp->_Next = node->_Next;	// �� ����� ���� ���� ���� ����� ���� ���
				temp = node->_Next;			// ������ ����� ���� ��� ������
				temp->_Prev = node->_Prev;	// ���� ����� �� ���� ������ ����� �� ���
				delete node;				// ��� ����
				--_size;					// ����Ʈ ������ ����
				return temp;				// ������ ����� ���� ��� ���ͷ����� ��ȯ
			}
			node = node->_Next;				// ���� ����
		}
		return _tail;						// ������ ��尡 ����Ʈ�� ���ٸ� ����Ʈ�� �� ��ȯ
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


//������
template <typename T>
CList<T>::CList() {
	_head = new Node;
	initNode(_head);
	_tail = new Node;
	initNode(_tail);
	_head->_Next = _tail;
	_tail->_Prev = _head;
}

//�ı���
template <typename T>
CList<T>::~CList() {
	clear();
	delete _head;
	delete _tail;
}

//��� �ʱ�ȭ
template <typename T>
void CList<T>::initNode(Node *ptr) {
	ptr->_Prev = NULL;
	ptr->_Next = NULL;
}

//��� �� ����
template <typename T>
void CList<T>::push_front(T data) {
	Node *node = new Node;			// �ű� ���
	Node *nextNode = _head->_Next;	// ����� ���� ��� ������ ����
	node->_data = data;				// ���� ������
	node->_Prev = _head;			// �ű� ����� ���� ���
	node->_Next = nextNode;			// �ű� ����� ������ ������ ����� ���� ���
	nextNode->_Prev = node;			// ���� ����� ���� ����� ������ �ű� ���
	_head->_Next = node;			// ����� ���� ���� �ű� ���
	++_size;						// ����Ʈ ������ ����
}

//���� �� ����
template <typename T>
void CList<T>::push_back(T data) {
	Node *node = new Node;			// �ű� ���
	Node *prevNode = _tail->_Prev;	// ������ �� ��� ������ ����
	node->_data = data;				// ���� ������
	node->_Prev = prevNode;			// �ű� ����� ���� ���� ���� ����� �� ���
	node->_Next = _tail;			// �ű� ����� ���� ���� ����
	prevNode->_Next = node;			// ���� ���� ����� �� ����� ������ �ű� ���
	_tail->_Prev = node;			// ������ �� ���� �ű� ���
	++_size;						// ����Ʈ ������ ����
}

//���� ����
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

//�ش� ��� ����
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