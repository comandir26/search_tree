#pragma once
#include <initializer_list>
#include <iostream>
#include <utility>

namespace my_tree {
	template<class T>
	class MyTree {
	public:
		MyTree() : _data(nullptr), _size(0) {}
		
		MyTree(std::initializer_list<T> list) : _size(list.size()) {
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
		}
		
		bool insert(T key) {
			if (contains(key)) return false;

			if (_size == 0) {
				_data = new T(key);
				++_size;
				return true;
			}

			T* new_data = new T[_size + 1];
			int high = _size;
			int low = 0;
			while (low < high) {
				int mid = (high + low) / 2;
				if (key < _data[mid]) high = mid;
				else low = mid + 1;
			}
			new_data[high] = key;
			int j = 0;
			for (size_t i = 0; i < _size + 1; i++)
			{
				if (i == high) continue;
				new_data[i] = _data[j];
				++j;
			}
			delete[] _data;
			_data = new_data;
			++_size;
			return true;
		}

		bool contains(T key) {
			int high = _size;
			int low = 0;
			while (low < high) {
				int mid = (high + low) / 2;
				if (key == _data[mid]) return true;
				else if (key < _data[mid]) {
					high = mid;// high = mid + 1;
				}
				else if (key > _data[mid]) {
					low = mid + 1;
				}
			}
			return false;
		}

		void print() const{
			for (T* p = _data; p < _data + _size; ++p)
			{
				std::cout << *p << ' ';
			}
			std::cout << '\n';
		}

		size_t get_size() const{
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
		}

	private:
		T* _data;
		size_t _size;
	};
}