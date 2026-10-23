#ifndef PLAYLIST_LL_H
#define PLAYLIST_LL_H

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// Reusing your exact DoublyList node structure
template <typename T>
class DoublyList {
public:
    T data;
    DoublyList<T> *next;
    DoublyList<T> *prev;
};

// Create a node function
template <typename T>
DoublyList<T> *createNode(T newData) {
    DoublyList<T> *newNode = new DoublyList<T>;
    newNode->data = newData;
    
    // In a single-node circular list, it points to itself initially
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}

// Traverse the playlist (Prints all songs exactly once per the activity guideline)
template <typename T>

void dllTraverse(DoublyList<T> *head) {
    if (head == nullptr)
    {
        std::cout << "The playlist is empty." << std::endl;
        return;
    }

    DoublyList<T> *currentNode = head;
    std::cout << "\n>>> PLAYING ENTIRE PLAYLIST (LOOP ONCE) <<<" << std::endl;
    
    do {
        // Print the active song
        std::cout << " -> Playing: [ " << currentNode->data << " ]" << std::endl;
        
        // Pause the program for 1 second before scrolling to the next node
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        
        currentNode = currentNode->next;
    } while (currentNode != head); // Loops through the structure until it hits the starting head

    std::cout << "✔ Reached the end of the playlist loop.\n" << std::endl;
}

// Inserting a node at the head
template <typename T>
void dllInsertHead(T newData, DoublyList<T> **head) {
    DoublyList<T> *newNode = createNode(newData);

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    DoublyList<T> *tail = (*head)->prev;

    newNode->next = *head;
    newNode->prev = tail;

    tail->next = newNode;
    (*head)->prev = newNode;

    *head = newNode;
}

// General Insertion
template <typename T>
void dllInsertGen(DoublyList<T> *targetNode, T newData) {
    if (targetNode == nullptr) return;

    DoublyList<T> *newNode = createNode(newData);

    newNode->next = targetNode->next;
    newNode->prev = targetNode;

    targetNode->next->prev = newNode;
    targetNode->next = newNode;
}

// Delete Node
template <typename T>
void dllDelNode(DoublyList<T> **head, DoublyList<T> *delNode) {
    if (*head == nullptr || delNode == nullptr) return;

    // Case 1: Only one node in the list
    if (delNode->next == delNode && delNode->prev == delNode) {
        *head = nullptr;
    }
    else {
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;

        // Case 2: If we are deleting the active head pointer, move head forward
        if (*head == delNode) {
            *head = delNode->next;
        }
    }

    delete delNode;
}

#endif
