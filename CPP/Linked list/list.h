#pragma once

class List;

#include <initializer_list>

struct Node
{
	int Data;
	Node* Next = nullptr;

	Node(int data) : Data(data)
	{
	}
};

class Iterator
{
private:
	Node* m_node;
public:
	Iterator(Node* node) :m_node(node)
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

	int operator*()
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

	friend class List;
};

class List
{
private:
	Node* m_head = nullptr;

	Node* GetLast()
	{
		Node* cur = m_head;
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
	Iterator begin()
	{
		return Iterator(m_head);
	}

	Iterator end()
	{
		return Iterator(nullptr);
	}

	void Insert(int value, Iterator position)
	{
		Node* curNode = position.m_node;
		Node* newNode = new Node(value); //конструктор с параметром
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
			Node* lastNode = GetLast();
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

	List() = default;
	List(std::initializer_list<int> const& list)
	{
		Node* prevNode = nullptr;
		for (int value : list)
		{
			Node* newNode = new Node(value);
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
		Node* node = m_head;
		while (node != nullptr)
		{
			Node* nextNode = node->Next;
			delete node;
			node = nextNode;
		}
		m_head = nullptr;
	}
	


	~List()
	{
		Clear();
	}
};
