#include <iostream>

// FUNCTION DECLARATIONS
int sumOfTwoNum(int fNum, int sNum); // Number 1
bool isGreater(int a, int b); // Number 2
bool displayLogicalOperations(bool c, bool d);

// MAIN PROGRAM
int main () {

    // ILO A #1
    std::cout << "The sum of all numbers is : " << sumOfTwoNum(10,22) << "\n" << std::endl;
    // ILO A #2
    int x = 500;
    int y = 400;
   if (isGreater(x, y)) {
        std::cout << "x is greater than y" << "\n" << std::endl;
    } else {
        std::cout << "x is not greater than y" << "\n" << std::endl;
    }
    // ILO A #3
    bool success = displayLogicalOperations(true, false);
    std::cout << "Function execution status: " << std::boolalpha << success << std::endl;

    return 0;
}

// FUNCTIONS
// ILO A #1
int sumOfTwoNum(int fNum, int sNum){
    int sum = fNum + sNum;
    return sum;
}
 // ILO A #2
bool isGreater(int a, int b){
    return a > b;
}
// ILO A #3
bool displayLogicalOperations(bool c, bool d) {
    // std::boolalpha formats outputs as "true" or "false" instead of "1" or "0"
    std::cout << std::boolalpha;    
    
    std::cout << " || Logical Operations || " << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Inputs: A = " << c << ", B = " << d << std::endl;
    std::cout << "--------------------------" << std::endl;
    
    // 1. Logical NOT 
    std::cout << "NOT A (!A)      : " << (!c) << std::endl;
    std::cout << "NOT B (!B)      : " << (!d) << std::endl;
    
    // 2. Logical AND
    std::cout << "LOGICAL AND (&&): " << (c && d) << std::endl;
    
    // 3. Logical OR
    std::cout << "LOGICAL OR (||) : " << (c || d) << std::endl;
    
    // 4. Logical XOR 
    std::cout << "LOGICAL XOR (^) : " << (c ^ d) << std::endl;
    
    return true;
} 
