#pragma once
#include <iostream>
#include <algorithm>

template <typename T>
class TPriorityQueue
{
	T* begin;
	T* end;
	size_t size; // кол-во элементов в очереди
	size_t capacity; // max вместимость массива

	void resize(size_t newCap) {
		T* newBegin = new T[newCap];
		for (size_t i = 0; i < size; i++) {
			newBegin[i] = begin[i];
		}
		delete[] begin;
		begin = newBegin;
		capacity = newCap;
	}
public:
	TPriorityQueue(size_t cap) {
		size = 0;
		capacity = cap;
		begin = new T[capacity];
		end = begin + size;
	}

	~TPriorityQueue() {
		delete[] begin;
	}

	void pop() {
		if (size == 0) {
			throw "Queue is empty";
		}
		std::pop_heap(begin, begin + size);
		--size;
	};

	void push(const T& val) {
		if (size >= capacity) {
			resize(capacity * 2);
		}
		begin[size++] = val;
		std::push_heap(begin, begin + size);
	};

	T top() const {
		if (size == 0) {
			throw "Queue is empty";
		}
		return begin[0];
	}

	T getMinPriority() const {
		if (size == 0) {
			throw "Queue is empty";
		}
		return end[0];
	}

	size_t getSize() const {
		return size;
	}

	bool isEmpty() const {
		return size == 0;
	}
};
