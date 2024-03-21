#include "gtest/gtest.h"
#include "my_tree/my_tree.h"
#include <complex>

using namespace my_tree;
using std::cout, std::complex;

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
	cout << '\n';
}

TEST(CopyC, First) {
	MySet<int> tree;
	tree.insert(5);
	tree.insert(7);
	tree.insert(1);
	tree.insert(4);
	tree.insert(9);
	cout << "Tree:" << "\n";
	tree.print();
	MySet<int> tree2(tree);
	cout << "Copy of Tree:" << "\n";
	tree2.print();
}

TEST(Assign, First) {
	MySet<int> tree;
	tree.insert(5);
	tree.insert(7);
	tree.insert(1);
	tree.insert(4);
	tree.insert(9);
	cout << "Tree:" << "\n";
	tree.print();

	MySet<int> tree2;
	tree2.insert(6);
	tree2.insert(1);
	tree2.insert(3);
	cout << "Second Tree:" << "\n";
	tree2.print();

	tree2 = tree;

	cout << "Second Tree after assignment:" << "\n";
	tree2.print();
}

TEST(Diff_Inter, First) {
	MySet<int> tree;
	tree.insert(5);
	tree.insert(7);
	tree.insert(1);
	tree.insert(4);
	tree.insert(9);
	tree.insert(6);
	tree.insert(2);
	cout << "Tree:" << "\n";
	tree.print();

	MySet<int> tree2;
	tree2.insert(6);
	tree2.insert(5);
	tree2.insert(9);
	tree2.insert(2);
	tree2.insert(3);
	cout << "Second Tree:" << "\n";
	tree2.print();

	MySet<int> dif = difference(tree, tree2);
	cout << "Difference:" << "\n";
	dif.print();

	MySet<int> inter = intersection(tree, tree2);
	cout << "Intersection:" << "\n";
	inter.print();
}

TEST(Creating, Second) {
	MySet<complex<float>> data;
	data.insert(complex<float>(1.0, 2.0));
	data.insert(complex<float>(1.0, 2.0));
}