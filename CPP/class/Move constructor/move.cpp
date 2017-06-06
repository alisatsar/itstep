//h

Stack(Stack&& stack);
Stack& operator=(Stack&& stack);


Stack::Stack(Stack&& stack)
{
	m_array = stack.m_array;
	stack.m_array = nullptr;

	m_count = stack.m_count;
	stack.m_count = 0;

	m_capacity = stack.m_capacity;
	stack.m_count = 0;
}

//cpp
Stack& Stack::operator=(Stack&& stack)
{
	if (this != &stack)
	{
		delete[] m_array;
		m_array = stack.m_array;
		stack.m_array = nullptr;

		m_count = stack.m_count;
		stack.m_count = 0;

		m_capacity = stack.m_capacity;
		stack.m_count = 0;
	}
	return *this;
}
