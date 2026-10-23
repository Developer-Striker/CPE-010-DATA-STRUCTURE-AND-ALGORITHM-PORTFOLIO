#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include <iostream>

template <typename T>
class ArrayStack {
private:
    int topIndex;
    int capacity;
    T* arr;

public:
    ArrayStack(int size) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }

    ~ArrayStack() {
        delete[] arr;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    void push(T val) {
        if (topIndex < capacity - 1) {
            arr[++topIndex] = val;
        }
    }

    T pop() {
        if (!isEmpty()) {
            return arr[topIndex--];
        }
        return T();
    }
};

#endif
