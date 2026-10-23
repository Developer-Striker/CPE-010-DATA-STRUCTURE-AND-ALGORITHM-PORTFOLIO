#include <iostream>
#include <string>
#include "GT.h"

int main(){

    GeneralTree<char> tree('A');
    GeneralTree<char>* b = tree.addChild('B');
    GeneralTree<char>* c = tree.addChild('C');
    GeneralTree<char>* d = tree.addChild('D');
    d->addChild('H');
    GeneralTree<char>* e = tree.addChild('E');
    e->addChild('I');
    GeneralTree<char>* j = e->addChild('J');
    j->addChild('P');
    j->addChild('Q');
    GeneralTree<char>* f = tree.addChild('F');
    f->addChild('K');
    f->addChild('L');
    f->addChild('M');
    GeneralTree<char>* g = tree.addChild('G');
    g->addChild('N');


    std::cout << "---|Tree Traversals|---" << std::endl;
    std::cout << "Pre-order:  "; tree.preOrder();  std::cout << std::endl;
    std::cout << "In-order:   "; tree.inOrder();   std::cout << std::endl;
    std::cout << "Post-order: "; tree.postOrder(); std::cout << std::endl;
    std::cout << "-----------------------\n" << std::endl;

    // Task 3.3 FindData
    
    std::cout << "Searching for 'P' using PRE:  " << std::endl;
    tree.findData("PRE", 'P');

    std::cout << std::endl;

    std::cout << "Searching for 'Z' using POST: " << std::endl;
    tree.findData("POST", 'Z'); // No output expected if not found

    std::cout << std::endl;

    std::cout << "Searching for 'M' using IN:   " << std::endl;
    tree.findData("IN", 'M');
    
    std::cout << std::endl;

    std::cout << "---|Insertion|---" << std::endl;
    tree.insert('G', 'O');
    std::cout << "Pre-order:  "; tree.preOrder();  std::cout << std::endl;
    std::cout << "In-order:   "; tree.inOrder();   std::cout << std::endl;
    std::cout << "Post-order: "; tree.postOrder(); std::cout << std::endl;
    std::cout << "-----------------------\n" << std::endl;
    return 0;

}
