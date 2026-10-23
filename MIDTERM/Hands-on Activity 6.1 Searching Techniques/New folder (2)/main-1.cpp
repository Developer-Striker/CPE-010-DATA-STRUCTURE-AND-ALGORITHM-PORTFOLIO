#include <iostream>
#include <cstdlib>
#include <time.h>
#include "algorithm.h"

const int maxSize = 10;

int main() {
    int targetKey = 18;
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int totalElements = sizeof(arr) / sizeof(arr[0]);
    int maxIndex = totalElements - 1; 

    std::cout << "=== | Array Sequential Search | ===" << std::endl;
    linearSearchArr(maxIndex, targetKey, arr);



    std::cout << "\n=== | Linked List Sequential Search | ===" << std::endl;
    Node<int>* head = new_node(arr[0]);
    Node<int>* current = head;
    for (int i = 1; i < totalElements; ++i) {
        current->next = new_node(arr[i]);
        current = current->next;
    }
    linearSearchLL(head, targetKey);



    std::cout << "\n=== | Counting All Instances (Array) | ===" << std::endl;
    countOccurrencesArr(maxIndex, targetKey, arr);

    // Memory clean up
    current = head;
    while (current != nullptr) {
        Node<int>* nextNode = current->next;
        delete current;
        current = nextNode;
    }



    std::cout << "\n=== | Array Recursive Binary Search | ===" << std::endl;
    
    int dataset[maxSize] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};

    binarySearchArrRecursive(dataset, 0, maxSize-1, 8);

    return 0;
}