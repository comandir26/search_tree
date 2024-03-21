#pragma once
#include <iostream>
#include <utility>
#include <complex>

namespace my_tree {
	template<class T>
	struct Tree {
		T _data;
		Tree *_left, *_right;
		Tree(T data) : _data(data), _left(nullptr), _right(nullptr) {}
	};

	template<class T>
	class MySet {
	public:
		MySet() : _root(nullptr) {}

		MySet(const MySet& rhs): _root(nullptr){
			copy_data(rhs.get_root());
		}

		MySet& operator=(const MySet& rhs){
			MySet copy(rhs);
			swap(copy);
			return *this;
		}
		
		bool insert(T key) {
			if (!_root) {
				_root = new Tree<T>(key);
				return true;
			}
			if (contains(key)) return false;
			Tree<T>* node = _root;
			bool left = false;
			while (node) {
				if (key < node->_data){
					if (node->_left != nullptr) {
						node = node->_left;
						continue;
					}
					left = true;
					break;
				}
				else if (key > node->_data) {
					if (node->_right != nullptr) {
						node = node->_right;
						continue;
					}
					break;
				}
			}
			if (left) node->_left = new Tree<T>(key);
			else node->_right = new Tree<T>(key);
			return true;
		}

		bool contains(T key) {
			Tree<T>* node = _root;
			while (node) {
				if (key < node->_data) node = node->_left;
				else if (key > node->_data) node = node->_right;
				else return true;
			}
			return false;
		}

		bool erase(T key) {
			bool deleted = false;
			_root = erase_node(_root, key, deleted);
			return deleted;
		}

		void print(){
			subprint(_root);
			std::cout << std::endl;
		}

		Tree<T>*& get_root() {
			return _root;
		}

		Tree<T>* get_root() const {
			return _root;
		}

		~MySet() {
			delete_node(_root);
		}

	private:
		Tree<T>* _root;

		void copy_data(Tree<T>* node) {
			if (node != nullptr) {
				this->insert(node->_data);
				copy_data(node->_left);
				copy_data(node->_right);
			}
		}

		void swap(MySet& rhs) noexcept {
			std::swap(_root, rhs.get_root());
		}

		Tree<T>* erase_node(Tree<T>* node, T key, bool& deleted) {
			if (node == nullptr) return node;
			if (key < node->_data) node->_left = erase_node(node->_left, key, deleted);
			else if (key > node->_data) node->_right = erase_node(node->_right, key, deleted);
			else {
				if (node->_left == nullptr) {
					Tree<T>* temp = node->_right;
					delete node;
					deleted = true;
					return temp;
				}
				else if (node->_right == nullptr) {
					Tree<T>* temp = node->_left;
					delete node;
					deleted = true;
					return temp;
				}
				Tree<T>* temp = max_left(node->_left);//Самый правый узел левого поддерева
				node->_data = temp->_data;
				node->_left = erase_node(node->_left, temp->_data, deleted);
			}
			return node;
		}

		void subprint(Tree<T>* node) {
			if (node != nullptr) {
				subprint(node->_left);
				std::cout << node->_data << ' ';
				subprint(node->_right);
			}
			return;
		}

		void delete_node(Tree<T>* node) {
			if (node != nullptr) {
				delete_node(node->_left);
				delete_node(node->_right);
				delete node;
			}
		}
	};

	template<class T>
	Tree<T>* max_left(Tree<T>* node) {
		while (node->_right != nullptr) {
			node = node->_right;
		}
		return node;
	}

	template<class T>
	MySet<T> intersection(MySet<T>& lhs, MySet<T>& rhs) {
		MySet<T> dif = difference(lhs, rhs);
		return difference(lhs, dif);
	}

	template<class T>
	MySet<T> difference(MySet<T>& lhs, MySet<T>& rhs) {
		MySet dif(lhs);
		delete_same(dif, rhs.get_root());
		return dif;
	}

	template<class T>
	void delete_same(MySet<T>& tree, Tree<T>* node){
		if (node) {
			delete_same(tree, node->_left);
			if(tree.contains(node->_data)) tree.erase(node->_data);
			delete_same(tree, node->_right);
		}
	}

	template<class T>
	bool operator<(std::complex<T> lhs, std::complex<T> rhs)
}