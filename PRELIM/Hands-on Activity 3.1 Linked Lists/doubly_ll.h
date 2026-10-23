#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

// Doublist node

template <typename T>
class DoublyList
{
public:
    T data;
    DoublyList<T> *next;
    DoublyList<T> *prev;
};
// create a node function
template <typename T>
DoublyList<T> *createNode(T newData)
{

    // dynamic memory allocation for a new node
    DoublyList<T> *newNode = new DoublyList<T>;

    newNode->data = newData;

    // point it to the next node

    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

template <typename T>
void dllTraverse(DoublyList<T> *currentNode)
{
    // check if the list is empty
    if (currentNode == nullptr)
    {
        std::cout << "The list is empty:" << std::endl;
        return;
    }
    DoublyList<T> *tail;
    std::cout << "FORWARD" << std::endl;
    // forward traverse
    while (currentNode != nullptr)
    {
        std::cout << currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;
    }

    std::cout << std::endl;
    // reverse traverse
    std::cout << "REVERSE" << std::endl;
    while (tail != nullptr)
    {
        std::cout << tail->data << " ";
        tail = tail->prev;
    }
    std::cout << std::endl;
}
// inserting a node to the head
template <typename T>
void dllInsertHead(T newData, DoublyList<T> **currentNode)
{
    // create a new node
    DoublyList<T> *newNode = createNode(newData);

    // print the newNode to the currentNode (head)
    newNode->next = *currentNode;
    // print the currentNode (head) to the newNode
    (*currentNode)->prev = newNode;
    // update the header pointer
    *currentNode = newNode;
}
// inserting at the end
template <typename T>
void dllInsertEnd(T newData, DoublyList<T> *currentHead)
{
    // create a new node
    DoublyList<T> *newNode = createNode(newData);

    // traverse until we reach the last node
    while (currentHead->next != nullptr)
    {
        currentHead = currentHead->next;
    }
    // connect the new node back to the last node
    newNode->prev = currentHead;
    // connect the current node back to the new node
    currentHead->next = newNode;
}

template <typename T>
void dllInsertGen(T newData, DoublyList<T> *currentNode) {

    DoublyList<T>* newNode = createNode(newData);

    newNode->next = currentNode->next;
    newNode->prev = currentNode;

    if(currentNode->next != nullptr) {
        currentNode->next->prev = newNode;
    }

    currentNode->next = newNode;    
}


template <typename T>
void dllDelNode(T findData, DoublyList<T> **head)
{

    if(*head == nullptr) return;

    //Traverse to the tail of the list
    DoublyList<T>* currNode =  *head;
    while (currNode->next != nullptr) {
        currNode = currNode->next;
    }

    // Traverse backward from tail to head to find the data
    while(currNode != nullptr && currNode->data != findData){
        currNode = currNode->prev;
    }

    // if the data wasn't found in the list
    if(currNode == nullptr) return;
    // Update the 'next' pointer of the previous node
    if(currNode->prev != nullptr){
        currNode->prev->next = currNode->next;
    }
    else {
        *head = currNode->next;
    }
    // Update the 'prev' pointer of the next node
    if (currNode->next != nullptr) {
        currNode->next->prev = currNode->prev;
    }

    delete currNode;

}


#endif