#include <iostream>
#include <stack>
#include <stdexcept>

template <typename T>
class TStackQueue {
    size_t sz;
    std::stack<T> leftStack;
    std::stack<T> rightStack;
    std::stack<T> minStack;
    std::stack<T> maxStack;

public:
    TStackQueue() : sz(0) {}

    size_t size() const {
        return sz;
    }

    bool isEmpty() const {
        return sz == 0;
    }

    void push(const T& val) {
        leftStack.push(val);
        sz++;

        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }

        if (maxStack.empty() || val >= maxStack.top()) {
            maxStack.push(val);
        }
    }

    T pop() {
        if (rightStack.empty()) {
            while (!leftStack.empty()) {
                T val = leftStack.top();
                leftStack.pop();
                rightStack.push(val);

                if (minStack.top() == val) {
                    minStack.pop();
                }

                if (maxStack.top() == val) {
                    maxStack.pop();
                }
            }
        }

        T val = rightStack.top();
        rightStack.pop();
        sz--;
        return val;
    }

    T getMin() const {
        if (minStack.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        return minStack.top();
    }

    T getMax() const {
        if (maxStack.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        return maxStack.top();
    }
};
