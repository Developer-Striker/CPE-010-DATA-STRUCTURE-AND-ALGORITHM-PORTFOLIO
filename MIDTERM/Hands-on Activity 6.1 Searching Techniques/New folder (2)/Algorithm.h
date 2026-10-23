#ifndef ALGORITHM_H
#define ALGORITHM_H

template <typename T>
class Node {
    public:
        T data;
        Node *next;
};

template <typename T>
Node<T> *new_node(T newData){ 
    Node<T> *newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

// -------------------------------------------- //
/* LINEAR SEARCH ARRAY */

template <typename T>
void linearSearchArr(int maxSize, T dataFind, T data[]){
    int i = 0;
    int comparisons = 0;
    while(i <= maxSize){
        comparisons++;
        if(dataFind == data[i]){
            std::cout << "Searching is successful\n";
            std::cout << "Number of comparisons: " << comparisons << "\n";
            return;
        }
        i++;
    }
    std::cout << "the search is unsuccessful\n";
}

// -------------------------------------------- //
/* LINEAR SEARCH LINKED LIST */

template <typename T>
void linearSearchLL(Node<T> *node, T dataFind) {
    int comparisons = 0;
    while(node != nullptr){
        comparisons++;
        if(node->data == dataFind){
            std::cout << "the search was successful.\n";
            std::cout << "Number of comparisons: " << comparisons << "\n";
            return;
        }
        node = node->next;
    }
    std::cout << "the search was unsuccessful\n";
}

// -------------------------------------------- //
/* LINEAR SEARCH COUNTING REPEATING INSTANCES */

template <typename T>
void countOccurrencesArr(int maxSize, T dataFind, T data[]) {
    int count = 0;
    int comparisons = 0;
    int i = 0;
    while(i <= maxSize) {
        comparisons++;
        if(data[i] == dataFind) {
            count++;
        }
        i++;
    }
    
    if(count > 0) {
        std::cout << "Element found with " << count << " repeating instance(s).\n";
    } else {
        std::cout << "Element not found.\n";
    }
    std::cout << "Total full scan comparisons: " << comparisons << "\n";
}

// -------------------------------------------- //
/* BINARY SEARCH ARRAY & recursive*/ 

template <typename T>
void binarySearchArrRecursive(T data[], int low, int up, T dataFind){
    if(low > up){
        std::cout << "Data key [ " << dataFind << " ] was not found.\n";
    }
    
    int middle = (int)((low+up)/2);

    if(dataFind == data[middle]){
        std::cout << "Searching is successful\nValue [" << dataFind << "] Found.\n\n";
        return;
    }
    else if(dataFind > data[middle]){
        binarySearchArrRecursive(data, middle + 1, up, dataFind);
    }else {
        binarySearchArrRecursive(data, low, middle - 1, dataFind);
    }    
}

#endif