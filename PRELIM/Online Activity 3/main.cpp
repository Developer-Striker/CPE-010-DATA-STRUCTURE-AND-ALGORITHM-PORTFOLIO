#include <iostream>
#include "singly_ll.h"

int main() {
    
    //create nodes:
    singlyList<char>* head = nullptr;
    singlyList<char>* second = nullptr;
    singlyList<char>* third = nullptr;
    singlyList<char>* fourth = nullptr;

    //
    head = new singlyList<char>;
    second = new singlyList<char>;
    third = new singlyList<char>;
    fourth = new singlyList<char>;

    //added the data to the node
    head->data = 'J';
    second->data = 'D';
    third->data = 'M';
    fourth->data = 'V';

    //assign the next to the next node
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    std::cout<< "Testing the ListTraversal Function \n";
    ListTraversal(head);

    std::cout<< "Testing the Insert at Head Function \n";
    sllInsertHead('A', &head);
    ListTraversal(head);

    std::cout<< "Testing the Insert at any location Function \n";
    sllGeneralInsert('X', head->next->next);
    ListTraversal(head);

    std::cout<< "Testing the Insert at end Function \n";
    sllInsertEnd('U', &head);
    ListTraversal(head);

    std::cout<< "Testing the delete a node Function \n";
    sllDeleteNode('X', &head);
    ListTraversal(head);

    std::cout<< "Deleting the whole list. \n";
    sllDeleteList(&head);
    ListTraversal(head);


    return 0;

}