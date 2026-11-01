#ifndef SINGLY_LL_H
#define SINGLY_LL_H

template <typename T>
class singlyList {
    public:
    T data;
    singlyList<T>* next;
};

template <typename T>

void ListTraversal(singlyList<T>* node){

    while (node != nullptr){
        std::cout << node->data;
        if(node->next != nullptr){
            std::cout << "->";
        }
        node = node->next;
    }
     std::cout << std::endl;
};

template <typename T>
void sllInsertHead(T newData, singlyList<T>** currentHead) {
    singlyList<T>* newNode = new singlyList<T>;
    
    newNode->data = newData;

    newNode->next = *currentHead;

    *currentHead = newNode;
};

template <typename T>
void sllGeneralInsert(T newData, singlyList<T>* previNode){

    if(previNode == nullptr) {

        std::cout << "previous node cannot be null" << std::endl;
    }

    singlyList<T>* newNode = new singlyList<T>;

    newNode->data = newData;

    newNode->next = previNode->next;
    
    previNode->next = newNode;

};

template <typename T>
void sllInsertEnd(T newData, singlyList<T>** head) {
    
    singlyList<T>* newNode = new singlyList<T>;

    singlyList<T>* currentNode = *head;

    newNode->data = newData;

    newNode->next = nullptr;

    while(currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }

    currentNode->next= newNode;

}

template <typename T>
void sllDeleteNode(T findData, singlyList<T>** head) {

    if(*head == nullptr) return;

    singlyList<T>* currNode = *head;
    singlyList<T>* prevNode = nullptr;

    while(currNode != nullptr && currNode->data != findData) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if(currNode == nullptr) return;

    if(prevNode == nullptr){
        *head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }
    
    delete currNode;
};

template <typename T>
void sllDeleteList(singlyList<T>** head){
    singlyList<T>* current = *head;

    while(current != nullptr){
        singlyList<T>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = nullptr;
}

#endif
