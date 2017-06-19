#pragma once
#include <initializer_list>


template<class T>
class List;

template<class T>
struct Node
{
	T Data;
	Node* Next = nullptr;

	Node(T data) : Data(data)
	{
	}
};

template<class T>
class Iterator
{
private:
	Node<T>* m_node;
public:
	Iterator(Node<T>* node) :m_node(node)
	{
	}

	Iterator operator++()
	{
		if (m_node != nullptr)
		{
			m_node = m_node->Next;
		}
		return *this;
	}

	T& operator*()
	{
		return m_node->Data;
	}

	bool operator==(Iterator const& rhs) const
	{
		return m_node == rhs.m_node;
	}

	bool operator!=(Iterator const& rhs) const
	{
		return !(*this == rhs);
	}

	friend class List<T>;
};

template<class T>
class List
{
private:
	Node<T>* m_head = nullptr;

	Node<T>* GetLast()
	{
		Node<T>* cur = m_head;
		if (m_head == nullptr)
		{
			return cur;
		}
		while (cur->Next != nullptr)
		{
			cur = cur->Next;
		}
		return cur;
	}


public:

	typedef Iterator<T> iterator;

	List() = default;
	List(std::initializer_list<T> const& list)
	{
		Node<T>* prevNode = nullptr;
		for (T value : list)
		{
			Node<T>* newNode = new Node<T>(value);
			if (prevNode != nullptr)
			{
				prevNode->Next = newNode;
			}
			else
			{
				m_head = newNode;
			}
			prevNode = newNode;
		}
	}

	void Clear()
	{
		Node<T>* node = m_head;
		while (node != nullptr)
		{
			Node<T>* nextNode = node->Next;
			delete node;
			node = nextNode;
		}
		m_head = nullptr;
	}

	~List()
	{
		Clear();
	}

	iterator begin()
	{
		return iterator(m_head);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	void insert(int value, iterator position)
	{
		Node<T>* curNode = position.m_node;
		Node<T>* newNode = new Node<T>(value);
		if (curNode)
		{
			newNode->Next = curNode->Next;
			curNode->Next = newNode;

			int buff = newNode->Data;
			newNode->Data = curNode->Data;
			curNode->Data = buff;
		}
		else
		{
			Node<T>* lastNode = GetLast();
			if (lastNode == nullptr)
			{
				m_head = newNode;
			}
			else
			{
				lastNode->Next = newNode;
			}
		}
	}

	void erase(iterator position)
	{
		Node<T>* cur = position.m_node;

		if (cur == nullptr)
		{
			return;
		}

		if (cur->Next == nullptr && cur == m_head)
		{
			delete cur;
			m_head = nullptr;
			return;
		}

		Node<T>* next = cur->Next;

		if (next != nullptr)
		{
			cur->Data = next->Data;
			cur->Next = next->Next;
			delete next;
		}
		else
		{
			Node<T>* preLast = m_head;
			while (preLast->Next != cur)
			{
				preLast = preLast->Next;
			}
			preLast->Next = nullptr;
			delete cur;
		}
	}

	int GetCount() const
	{
		int count = 0;
		Node<T>* node = m_head;

		while (node != nullptr)
		{
			count++;
			node = node->Next;
		}
		return count;
	}
};
