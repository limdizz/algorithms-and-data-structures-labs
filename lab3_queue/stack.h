#pragma once
#ifndef __STACK_H__
#define __STACK_H__
#include <iostream>

using namespace std;

template <typename T>
class TDynamicStack
{
	int top;
	size_t memSize;
	T* pMem;
public:
	TDynamicStack() {
		top = -1;
		memSize = 1;
		pMem = new T[memSize];
	}

	TDynamicStack(int sz) {
		top = -1;
		memSize = sz;
		pMem = new T[memSize];
	}

	TDynamicStack(const TDynamicStack& a) {
		memSize = a.memSize;
		top = a.top;
		pMem = new T[memSize];
		for (int i = 0; i <= top; i++) {
			pMem[i] = a.pMem[i];
		}
	}

	bool operator==(TDynamicStack<T>& a) {
		if (top != a.top) {
			return false;
		}
		for (int i = 0; i <= top; i++) {
			if (pMem[i] != a.pMem[i]) {
				return false;
			}
		}
		return true;
	}

	~TDynamicStack() {
		delete[] pMem;
	}

	bool isEmpty() const {
		return top == -1;
	}

	T pop() {
		if (isEmpty()) {
			throw std::runtime_error("Cannot pop from an empty stack");
		}
		return pMem[top--];
	}

	bool isFull() const {
		return top == memSize - 1;
	}

	void push(const T& val) {
		if (isFull()) {
			T* tmpMem = new T[memSize * 2];
			std::copy(pMem, pMem + memSize, tmpMem);
			delete[] pMem;
			pMem = tmpMem;
			memSize *= 2;
		}
		pMem[++top] = val;
	}

	int size() const {
		return top + 1;
	}

	T getTopValue() {
		if (isEmpty()) {
			return 0;
		}
		else return pMem[top];
	}

	size_t getMemSize() {
		return memSize;
	}

	void clear() {
		top = -1;
	}

	friend ostream& operator<<(ostream& out, const TDynamicStack& a) {
		for (int i = 0; i < a.size(); i++) {
			out << a.pMem[i] << ' ';
		}
		return out;
	}
};
#endif
