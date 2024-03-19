#include "my_tree/my_tree.h"
#include <random>
#include <chrono>

using namespace my_tree;
using std::cout, std::endl;

void average_filling(size_t size) {
	double result = 0.0;
	for (size_t i = 0; i < 100; i++)
	{
		std::mt19937 gen(i);
		std::uniform_int_distribution<> distrib(-2000000, 2000000);
		MySet<int> data;
		auto start = std::chrono::high_resolution_clock::now();
		for (size_t i = 0; i < size; i++)
		{
			data.insert(distrib(gen));
		}
		auto end = std::chrono::high_resolution_clock::now();
		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 100;
		//cout << i + 1 << " try: " << seconds << " seconds" << endl;
	}
	cout << "Average(100) filling time with " << size << " items: " << result << endl;
}

void average_finding(size_t size) {
	double result = 0.0;
	MySet<int> data;
	std::mt19937 gen(42);
	std::uniform_int_distribution<> distrib(-2000000, 2000000);
	for (size_t i = 0; i < size; i++)
	{
		data.insert(distrib(gen));
	}
	for (size_t i = 0; i < 1000; i++)
	{
		auto start = std::chrono::high_resolution_clock::now();
		data.contains(distrib(gen));
		auto end = std::chrono::high_resolution_clock::now();
		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 1000;
	}
	cout << "Average(1000) finding time in " << size << " items: " << result << endl;
}

void average_erasing(size_t size) {
	double result = 0.0;
	for (size_t i = 0; i < 1000; i++)
	{
		std::mt19937 gen(i);
		std::uniform_int_distribution<> distrib(-2000000, 2000000);
		MySet<int> data;
		for (size_t i = 0; i < size; i++)
		{
			data.insert(distrib(gen));
		}
		auto start = std::chrono::high_resolution_clock::now();
		data.erase(distrib(gen));
		auto end = std::chrono::high_resolution_clock::now();
		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 1000;
	}
	cout << "Average(1000) erasing time in " << size << " items: " << result << endl;
}

void average_insertion(size_t size) {
	double result = 0.0;
	for (size_t i = 0; i < 1000; i++)
	{
		std::mt19937 gen(i);
		std::uniform_int_distribution<> distrib(-2000000, 2000000);
		MySet<int> data;
		for (size_t i = 0; i < size; i++)
		{
			data.insert(distrib(gen));
		}
		auto start = std::chrono::high_resolution_clock::now();
		data.insert(distrib(gen));
		auto end = std::chrono::high_resolution_clock::now();
		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 1000;
	}
	cout << "Average(1000) erasing time in " << size << " items: " << result << endl;
}

int main() {
	average_insertion(1000);
}