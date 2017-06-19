#pragma once

#include <initializer_list>

class List2;

struct Node2
{
	int Data;
	Node2* Next = nullptr;
	Node2* Prev = nullptr;

	Node2(int data) : Data(data)
	{
	}
};

class Iterator2
{
private:
	Node2* m_node;
public:
	Iterator2(Node2* node) :m_node(node)
	{
	}

	Iterator2 operator++()
	{
		if (m_node != nullptr)
		{
			m_node = m_node->Next;
		}
		return *this;
	}

	Iterator2 operator--()
	{
		if (m_node != nullptr)
		{
			m_node = m_node->Prev;
		}
		return *this;
	}

	int& operator*()
	{
		return m_node->Data;
	}

	bool operator==(Iterator2 const& rhs) const
	{
		return m_node == rhs.m_node;
	}

	bool operator!=(Iterator2 const& rhs) const
	{
		return !(*this == rhs);
	}

	friend class List2;
};

class List2
{
	Node2* m_head = nullptr;

	Node2* GetLast()
	{
		Node2* cur = m_head;
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
	List2() = default;
	List2(std::initializer_list<int> const& list)
	{
		Node2* prevNode = nullptr;
		for (int value : list)
		{
			Node2* newNode = new Node2(value);
			if (prevNode != nullptr)
			{
				prevNode->Next = newNode;
				newNode->Prev = prevNode;
			}
			else
			{
				m_head = newNode;
			}
			prevNode = newNode;
		}
	}

	void insert(int value, Iterator2 position)
	{
		Node2* curNode = position.m_node;
		Node2* prevNode = curNode->Prev;
		Node2* newNode = new Node2(value);

		if (curNode != nullptr)
		{
			if (prevNode == nullptr)
			{
				m_head = newNode;
			}
			else
			{
				prevNode->Next = newNode;
			}
			newNode->Next = curNode;
			newNode->Prev = prevNode;
			curNode->Prev = newNode;

		}
		else
		{
			curNode = GetLast();
			if (curNode == nullptr)
			{
				m_head = newNode;
			}
			else
			{
				curNode->Next = newNode;
				newNode->Prev = curNode;
			}
		}
	}
	void erase(Iterator2 position)
	{
		Node2* curNode = position.m_node;
		if (curNode == nullptr)
		{
			return;
		}
		Node2* prevNode = curNode->Prev;
		Node2* nextNode = curNode->Next;
	}
};
