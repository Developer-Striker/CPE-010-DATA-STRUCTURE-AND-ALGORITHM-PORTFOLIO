#include <iostream>
#include "stackList.h"

int main() {
    std::cout << " >>> Pushing 'C' 'P' 'E' onto the stack <<< \n";

    push('C');
    push('P');
    push('E');

    Top<char>();
    displayAll<char>();
    std::cout << "\n >>> Popping all the elements <<< \n";

    while(!isEmpty<char>()){
        std::cout <<" Popped: " << pop<char>() << std::endl;
    }

    std::cout << "\n>>> Testing the Underflow <<< \n";
    pop<char>();

    return 0;
}




