#include <iostream>
#include <memory>
#include <string>

template <class T>
struct Node
{
private:

	template<class Iter>
	class NodeIterator
	{
		friend class Node;
	public:
		typedef Iter iterator_type;
		typedef std::input_iterator_tag iterator_category;
		typedef iterator_type value_type;
		typedef ptrdiff_t difference_type;
		typedef iterator_type& reference;
		typedef iterator_type* pointer;

		iterator_type* value;

	private:
		NodeIterator(Iter* it) : value(it)
		{
		}
	public:
		NodeIterator(const NodeIterator& it) : value(it.value)
		{
		}

		bool operator!=(const NodeIterator& other) const
		{
			return value != other.value;
		}

		bool operator==(NodeIterator const& other) const
		{
			return value == other.value;
		}

	};

public:	
	T value;
	std::unique_ptr<Node> left;
	std::unique_ptr<Node> rigth;
	Node* parent;

	Node(const T& v, std::unique_ptr<Node> l, std::unique_ptr<Node> r, Node* parent) :
		value(v), left(std::move(l)), rigth(std::move(r)), parent(parent)
	{
	}

	Node(const Node&) = delete;

	typedef NodeIterator<Node> iterator;
	typedef NodeIterator<const Node> const_iterator;

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;
};

int main()
{
	auto root = std::make_unique<Node<std::string>>("a1", nullptr, nullptr, nullptr);
	root->left = std::make_unique<Node<std::string>>("b1", nullptr, nullptr, root.get());
	root->rigth = std::make_unique<Node<std::string>>("b2", nullptr, nullptr, root.get());

	auto b1 = root->left.get();
	auto b2 = root->rigth.get();

	b1->left = std::make_unique<Node<std::string>>("c1", nullptr, nullptr, b1);
	b1->rigth = std::make_unique<Node<std::string>>("c2", nullptr, nullptr, b1);
	b2->left = std::make_unique<Node<std::string>>("c3", nullptr, nullptr, b2);
	b2->rigth = std::make_unique<Node<std::string>>("c4", nullptr, nullptr, b2);

	auto c1 = b1->left.get();
	auto c2 = b1->rigth.get();
	auto c3 = b2->left.get();
	auto c4 = b2->rigth.get();
	
	std::cout << root->value << std::endl;
	std::cout << b1->value << std::endl;
	std::cout << b2->value << std::endl;
	std::cout << c1->value << std::endl;
	std::cout << c2->value << std::endl;
	std::cout << c3->value << std::endl;
	std::cout << c4->value << std::endl;
}
