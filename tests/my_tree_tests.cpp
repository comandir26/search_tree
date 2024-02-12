#include "gtest/gtest.h"
#include "my_tree/my_tree.h"

using namespace my_tree;
using std::cout;

TEST(Creating, First) {
	MyTree<int> tree = { 1, 2, 3, 4, 5, 6, 7 };
	tree.print();
}

TEST(Creating, Second) {
	MyTree<int> tree;
	tree.insert(5);
	tree.insert(7);
	tree.insert(1);
	tree.insert(5);
	tree.insert(4);
	tree.insert(9);
	tree.insert(-3);
	tree.print();
}

TEST(Contains, First) {
	MyTree<int> tree;
	tree.insert(5);
	tree.insert(7);
	tree.insert(1);
	tree.insert(4);
	tree.insert(9);
	cout << tree.contains(1) << '\n';
	cout << tree.contains(4) << '\n';
	cout << tree.contains(5) << '\n';
	cout << tree.contains(10) << '\n';
	cout << tree.contains(7) << '\n';
	cout << tree.contains(9) << '\n';
}

TEST(CopyC, First) {
	MyTree<int> tree;
	tree.insert(5);
	tree.insert(7);
	tree.insert(1);
	tree.insert(4);
	tree.insert(9);
	cout << "Tree:" << "\n";
	tree.print();
	MyTree<int> tree2(tree);
	cout << "Copy of Tree:" << "\n";
	tree2.print();
}

TEST(Assign, First) {
	MyTree<int> tree;
	tree.insert(5);
	tree.insert(7);
	tree.insert(1);
	tree.insert(4);
	tree.insert(9);
	cout << "Tree:" << "\n";
	tree.print();

	MyTree<int> tree2;
	tree2.insert(6);
	tree2.insert(1);
	tree2.insert(3);
	cout << "Second Tree:" << "\n";
	tree2.print();

	tree2 = tree;

	cout << "Second Tree after assignment:" << "\n";
	tree2.print();
}