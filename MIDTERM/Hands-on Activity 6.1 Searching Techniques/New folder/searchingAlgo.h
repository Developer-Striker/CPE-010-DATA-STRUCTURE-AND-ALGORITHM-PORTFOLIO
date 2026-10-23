#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

/* 
    LINEAR SEARCH ALGORITHM
    N -> Boundary of the list
    Item -> Searching number
    Data -> Linear array
    Step 1: I:= 0
    Step 2: Repeat while I <= n
    Exit
    Else print "searching is unsuccessful"
    Exit
*/

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
    while(i <= maxSize){
        if(dataFind == data[i]){
            std::cout << "Searching is successful\n";
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
    while(node != nullptr){

        if(node->data == dataFind){
            std::cout << "the search was successful.\n";
        }
        node = node->next;
    }
    std::cout << "the search was unsuccessful\n";
}

// -------------------------------------------- //
/* BINARY SEARCH ARRAY */

template <typename T>
void binarySearchArr(T dataFind, T data[], int maxSize){
    int low = 0, up = maxSize-1, middle;
    while(low <= up){
        middle = (int)((low+up)/2);
        if(dataFind == data[middle]){
            std::cout << "\nSearching is successful\n";
            return;
        }
        else if(dataFind > data[middle]){
            low = middle + 1;
        }else {
            up = middle - 1;
        }
    }
    std::cout << "Search element was not found.\n";
}



template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){

    Node<T>* slow = start;
    Node<T>* fast = start;

    while(fast != last && fast->next != last){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template <typename T>
void binarySearhLL(Node<T>* start, T dataFind){
    
    Node<T>* last = nullptr;

    while (start != last) {
        Node<T>* middle = getMiddle(start, last);

        if(middle->data == dataFind){
            std::cout << "The data was found.\n";
            return;
        }
        else if(middle->data > dataFind){
            last = middle;
        }
        else {
            start = middle->next;
        }
    }
    std::cout << "Search element was not found.\n";
}


#endif