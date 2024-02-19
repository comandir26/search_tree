#pragma once
#include <initializer_list>
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
		
		/*MySet(std::initializer_list<T> list) : _size(list.size()) {
			_data = new T[_size]();
			auto list_data = list.begin();
			for (T* p = _data; p < _data + _size; ++p)
			{
				*p = *list_data;
				++list_data;
			}
		}

		MyTree(const MyTree& rhs) : _size(rhs.get_size()), _data(new T[rhs.get_size()]) {
			for (size_t i = 0; i < _size; i++)
			{
				_data[i] = rhs[i];
			}
		}

		MyTree& operator=(const MyTree& rhs) {
			MyTree copy(rhs);
			swap(copy);
			return *this;
		}

		void swap(MyTree& rhs) noexcept {
			std::swap(_data, rhs.get_data());
			std::swap(_size, rhs.get_size());
		}

		T& operator[](int index) {
			if (index < 0 || index >= _size) {
				throw std::out_of_range("MyTree::operator[], index is out of range");
			}
			return _data[index];
		}

		const T& operator[](int index) const {
			if (index < 0 || index >= _size) {
				throw std::out_of_range("MyTree::operator[] const, index is out of range");
			}
			return _data[index];
		}*/
		
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
			return find(_root, key);
		}

		Tree<T>* find(Tree<T>* node, T key) {
			if (node) {
				if (key == node->_data) return node;
				else if (key < node->_data) return find(node->_left, key);
				else return find(node->_right, key);
			}
			return nullptr;
		}

		bool erase(T key) {
			if (!contains(key)) return false;
			Tree<T>* del = find(_root, key);
			if (del->_left == nullptr && del->_right == nullptr) {
				delete del;
				del = nullptr;
			}
			else {
				Tree<T>* max_left = max_leftf(del->_left);
				if (max_left) {				
					del->_data = max_left->_right->_data;
					if (max_left->_right->_left == nullptr) {
						delete max_left -> _right;
						max_left -> _right= nullptr;
					}
					else {
						max_left->_right->_data = max_left->_right->_left->_data;
						delete max_left->_right->_left;
						max_left->_right->_left = nullptr;
					}
					return true;
				}
				Tree<T>* min_right = min_rightf(del->_right);
				if (min_right) {
					del->_data = min_right->_data;
					if (min_right->_right == nullptr) {
						//delete min_right;
						min_right = nullptr;
					}
					else {
						min_right->_data = min_right->_right->_data;
						//delete min_right->_right;
						min_right->_right = nullptr;
					}
					return true;
				}
			}
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

		/*void print() {
			if (!_size) return;
			subprint(0, _size, 0);
		}
		void subprint(int low, int high, int tabs) {
			tabs += 5;
			while (low < high - 1) {
				int mid = (high + low) / 2;

				subprint(mid, high, tabs);
				
				for (int i = 0; i < tabs; i++) std::cout << " ";
				std::cout << _data[low] << std::endl;//??? mid or high?

				//subprint(0, mid, tabs);

				tabs -= 5;
				if (tabs == 5) break;
			}
			return;
		}*/

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
	Tree<T>*& max_leftf(Tree<T>* node) {
		if (!node) return node;
		while (node->_right != nullptr && node->_right->_right != nullptr) {
			node = node->_right;
		}
		return node;
	}

	template<class T>
	Tree<T>*& min_rightf(Tree<T>* node) {
		if (!node) return node;
		while (node->_left != nullptr && node->_left->_left != nullptr) {
			node = node->_left;
		}
		return node;
	}
}