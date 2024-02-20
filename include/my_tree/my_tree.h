#pragma once
#include <iostream>
#include <utility>

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
		MySet() : _root(nullptr), _size(0) {}
		
		bool insert(T key) {
			if (!_root) {
				_root = new Tree<T>(key);
				++_size;
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

		/*Tree<T>* find(Tree<T>* node, T key) {
			if (node) {
				if (key == node->_data) return node;
				else if (key < node->_data) return find(node->_left, key);
				else return find(node->_right, key);
			}
			return nullptr;
		}*/

		void erase(T key) {
			_root = erase_node(_root, key);
		}

		Tree<T>* erase_node(Tree<T>* node, T key) {
			if (node == nullptr) return node;
			if (key < node->_data) node->_left = erase_node(node->_left, key);
			else if (key > node->_data) node->_right = erase_node(node->_right, key);

			else {
				if (node->_left == nullptr) {
					Tree<T>* temp = node->_right;
					delete node;
					return temp;
				}
				else if (node->_right == nullptr) {
					Tree<T>* temp = node->_left;
					delete node;
					return temp;
				}
				Tree<T>* temp = max_left(node->_left);//Самый правый узел левого поддерева
				node->_data = temp->_data;
				node->_left = erase_node(node->_left, temp->_data);
			}
			return node;
		}

		void print(){
			subprint(_root);
			std::cout << std::endl;
		}

		void subprint(Tree<T>* node) {
			if (node!= nullptr) {
				subprint(node->_left);
				std::cout << node->_data << ' ';
				subprint(node->_right);
			}
			return;
		}

		/*size_t get_size() const{
			return _size;
		}

		size_t& get_size(){
			return _size;
		}

		T*& get_data() {
			return _data;
		}

		const T* get_data() const{
			return _data;
		}	

		~MyTree() {
			delete[] _data;
			_size = 0;
		}*/

	private:
		Tree<T>* _root;
		size_t _size;
	};

	template<class T>
	Tree<T>* max_left(Tree<T>* node) {
		while (node->_right != nullptr) {
			node = node->_right;
		}
		return node;
	}
}