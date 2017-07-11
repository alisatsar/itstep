////////////////////////////////////////
#include <utility>
 X x;
coll.insert(x); // Вставляет копию x (x можно использовать)

coll.insert(x+x); // перемещает (или копирует) содержимое временного rvalue-значения

coll.insert(std::move(x)); //перемещает (или копирует) содержимое x в объект coll


namespace std
{
tepmlate<typename T, ...>
class multiset
{
public:
	insert(const T& x); //для lvalue-значений (копирует значение)
	insert(T&& x); //для rvalue-значений (перемещает значение)
};
}

class X
{
public:
	X(const X& lvalue);//копирующий конструктор
	X(X&& rvalue);//перемещающий конструктор
};

class X
{
public:
	X& operator=(const X& lvalue); //оператор копирующего присваивания
	X& operator=(X&& rvalue);//оператор перемещающего присваивания
};
///////////////////////////////////////////////////////////////////////

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
