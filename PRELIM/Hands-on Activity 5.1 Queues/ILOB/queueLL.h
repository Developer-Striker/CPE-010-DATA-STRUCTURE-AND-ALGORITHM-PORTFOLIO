#ifndef QUELL_H
#define QUELL_H
#include <iostream>

template <typename T>
class qNode {
    public:
        T data;
        qNode<T>* next;
};

template <typename T>
qNode<T> *new_Node(T newData) {
    qNode<T> *newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>**backPtr) {
    //create a new node:
    qNode<T> *newNode = new_Node(newData);


    // how do we know that the queue is empty? if the front and back pointers are both null, then the queue is empty
    if(*frontPtr == nullptr && (*backPtr) == nullptr){
        *frontPtr = newNode;
        *backPtr = newNode;
        return;
    }

    //point the back next to the newNode:
    (*backPtr)->next = newNode;
    //the newnode will be the new backPtr:
    (*backPtr) = newNode;
    return; 
}

template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr) {
    //check if the queue is empty:
    if(*frontPtr == nullptr && *backPtr == nullptr){
        std::cout << "Queue is empty" << std::endl;
        return;
    }

    //store the front node in a temporary variable:
    qNode<T>* tempPtr = (*frontPtr);

    if ((*frontPtr) == (*backPtr)) {
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete tempPtr;
        return;
    }

    //move the front pointer to the next node:
    (*frontPtr) = (*frontPtr)->next;

    tempPtr->next = nullptr;

    //delete the temporary variable:
    delete tempPtr;
}

template <typename T>
void display(qNode<T>* frontPtr) {
    if (frontPtr == nullptr) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }

    qNode<T>* current = frontPtr;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif