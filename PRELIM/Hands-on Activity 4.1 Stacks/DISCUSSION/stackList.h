#ifndef STACK_LIST_H
#define STACK_LIST_H

template <typename T>
class Node {
    public:
    T data;
    Node* next;
};

template <typename T>
Node<T> *head = nullptr;


template <typename T>
void push(T newData){

    Node<T>* newNode = new Node<T>;
    newNode->data = newData;

    newNode->next = head<T>;
    head<T> = newNode;
};

    
template<typename T>
bool isEmpty(){
    return head<T> == nullptr;
}


template <typename T>
T pop(){

    if(head<T> == nullptr){
        std::cout << "Stack overflow" << std::endl;
    }

    Node<T>* temp = head<T>;
    T tempVal = temp->data;

    head<T> = head<T>->next;
    
    delete temp;
    return tempVal;
}


template <typename T>
void Top(){

    if(isEmpty<T>()){
        std::cout << "[ Stack underflow ]" <<std::endl;
        return;
    }

    std::cout <<"Top of the Stack: " << head<T>->data << std::endl;
}


template <typename T>
void displayAll(){
    if(head<T> == nullptr) {
        std::cout << "Stack underflow\n";
        return;
    }
    std::cout << "Displaying the stack: \n";
    Node<T>* temp = head<T>;
    while(temp != nullptr){
        std::cout << temp->data << "\n";
        temp = temp->next;
    }
    std::cout <<"\n";
}

#endif