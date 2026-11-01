#include <iostream>
#include "doubly_ll.h"

int main()
{

    DoublyList<char> *head = createNode('C');
    DoublyList<char> *second = createNode('P');
    DoublyList<char> *third = createNode('E');
    DoublyList<char> *fourth = createNode('1');
    DoublyList<char> *fifth = createNode('0');
    DoublyList<char> *last = createNode('1');

    // connecting the node
    // connect the node to the next node
    head->next = second;
    second->prev = head;
    // node to node
    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    fifth->next = last;
    last->prev = fifth;

    // traversal
    std::cout << "(a) Traverse the list. " << std::endl;
    dllTraverse(head);
    std::cout << "____________________________________________\n";

    // insert at the head
    std::cout << "(b) Insert the element 'G'. " << std::endl;
    dllInsertHead('G', &head);
    dllTraverse(head);
    std::cout << "____________________________________________\n";

    // insert at the end
    std::cout << "Testing the dllInsertEnd" << std::endl;
    dllInsertEnd('T', head);
    dllTraverse(head);
    std::cout << "____________________________________________\n";

    // general insert
    std::cout << "(c) insert an element 'E' with the previous node element being 'P'. " << std::endl;
    dllInsertGen('E', head->next->next);
    dllTraverse(head);
    std::cout << "____________________________________________\n";

    // delete a node
    std::cout << "(d) Delete the node containing the element 'C'." << std::endl;
    dllDelNode('C', &head);
    dllTraverse(head);
    std::cout << "____________________________________________\n";

    // delete a node
    std::cout << "(e) Delete the node containing the element 'P'." << std::endl;
    dllDelNode('P', &head);
    dllTraverse(head);
    std::cout << "____________________________________________\n";

    //traverse last product
    std::cout << "(f) Traverse the list. Expected: 'GEE101'. " << std::endl;
    dllTraverse(head);

    return 0;
}