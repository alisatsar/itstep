#include "binaryTree.h"
#include <iostream>

int main()
{
	BinaryTree Tree;
	Tree.Insert(8);
	Tree.Insert(5);
	Tree.Insert(3);
	Tree.Insert(10);
	Tree.Insert(12);
	Tree.Insert(0);

	Tree.Print();

	TreeNode* node = Tree.Find(23);
	Tree.Erase(node);
	std::cout << "\n";
	Tree.Print();

	return 0;
}
