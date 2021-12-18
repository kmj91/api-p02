#pragma once

template <typename T>
class CList
{
public:
	struct Node
	{
		T _data;
		Node *_Prev;
		Node *_Next;
	};

	class iterator
	{
	private:
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

		//������?
		bool operator==(const iterator& _RdGht) const
		{
			return (_node == _RdGht._node);
		}

		//�Ȱ�����?
		bool operator!=(const iterator& _RdGht) const
		{
			return (!(*this == _RdGht));
		}

		//���� ����� ������ ����
		T& operator *() const
		{
			return (_node->_data);
		}

		//������ ���~
		Node* operator->() const {
			return _node;
		}
	};

public:
	CList();
	~CList();

	iterator begin()
	{
		//ù��° ��带 ����Ű�� ���ͷ����� ����
		return iterator(_head->_Next);
	}
	iterator end()
	{
		//Tail ��带 ����Ű��(�����Ͱ� ���� ��¥ �� ���) ���ͷ����͸� ����
		//	�Ǵ� ������ ������ �� �ִ� ���ͷ����͸� ����
		return iterator(_tail);
	}
private:
	void initNode(Node *ptr);

public:
	void push_front(T data);
	void push_back(T data);
	void pop_front();
	void pop_back();
	T data();
	void clear();
	void delete_Node(T data);
	int size();
	bool is_empty();

	iterator erase(iterator itor) {
		//	- ���ͷ������� �� ��带 ����.
		//	- �׸��� ���� ����� ���� ��带 ī��Ű�� ���ͷ����� ����
		//		* ���� ����� ���� ��尡 �ƴ϶� ���� ���
		Node *node = _head->_Next;
		Node *temp = nullptr;
		while (node != _tail) {
			if (node == itor._node) {
				temp = node->_Next;
				temp->_Prev = node->_Prev;
				temp = node->_Prev;
				temp->_Next = node->_Next;
				delete node;
				--_size;
				return temp;
			}
			node = node->_Next;
		}
		return nullptr;
	}
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
	ptr->_Prev = 0;
	ptr->_Next = 0;
}

//��� �� ����
template <typename T>
void CList<T>::push_front(T data) {
	Node *node = new Node;
	Node *temp;
	if (_head->_Next != _tail) {
		temp = _head->_Next;
		node->_data = data;
		node->_Prev = _head;
		node->_Next = _head->_Next;

		temp->_Prev = node;
	}
	else {
		node->_data = data;
		node->_Prev = _head;
		node->_Next = _tail;
		_tail->_Prev = node;
	}
	_head->_Next = node;
	++_size;
}

//���� �� ����
template <typename T>
void CList<T>::push_back(T data) {
	Node *node = new Node;
	Node *temp;
	if (_tail->_Prev != _head) {
		temp = _tail->_Prev;
		node->_data = data;
		node->_Prev = _tail->_Prev;
		node->_Next = _tail;

		temp->_Next = node;
	}
	else {
		node->_data = data;
		node->_Prev = _head;
		node->_Next = _tail;
		_head->_Next = node;
	}

	_tail->_Prev = node;
	++_size;
}

template <typename T>
void CList<T>::pop_front() {
	erase(begin());
}

template <typename T>
void CList<T>::pop_back()
{
	erase(--end());
}

template <typename T>
T CList<T>::data() {
	return _head->_Next->_data;
}

//���� ����
template <typename T>
void CList<T>::clear() {
	Node *node = _head->_Next;
	Node *temp;
	while (node != _tail) {
		temp = node->_Next;
		delete node;
		node = temp;
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