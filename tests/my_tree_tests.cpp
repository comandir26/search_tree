#include "gtest/gtest.h"
#include "my_tree/my_tree.h"

using namespace my_tree;
using std::cout;


TEST(Creating, First) {
	MySet<int> tree;
	tree.insert(30);
	tree.insert(20);
	tree.insert(50);
	tree.insert(14);
	tree.insert(45);
	tree.insert(80);
	tree.insert(9);
	tree.insert(16);
	tree.insert(47);
	tree.insert(84);
	tree.print();
	tree.erase(50);
	tree.print();
	tree.erase(20);
	tree.print();
	tree.erase(9);
	tree.print();
}

TEST(Contains, First) {
	MySet<int> tree;
	tree.insert(30);
	tree.insert(20);
	tree.insert(50);
	tree.insert(14);
	tree.insert(45);
	cout << tree.contains(30);
	cout << tree.contains(50);
	cout << tree.contains(14);
	cout << tree.contains(20);
	cout << tree.contains(45);
	cout << tree.contains(1);
}

/*TEST(Contains, First) {
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
}*/