#ifndef LIST_STACK_H
#define LIST_STACK_H
#include <iostream>

template <typename T>
class ListStack {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* topNode = nullptr;

public:
    ~ListStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    void push(T val) {
        topNode = new Node{val, topNode};
    }

    T pop() {
        if (isEmpty()) return T();
        Node* temp = topNode;
        T val = temp->data;
        topNode = topNode->next;
        delete temp;
        return val;
    }
};

#endif
