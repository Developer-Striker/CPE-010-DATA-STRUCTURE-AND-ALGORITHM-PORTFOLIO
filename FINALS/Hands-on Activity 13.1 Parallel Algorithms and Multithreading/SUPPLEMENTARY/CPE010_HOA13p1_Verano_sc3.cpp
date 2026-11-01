#include <iostream>
#include <thread>
#include <chrono>

int global = 0;

// create an add function that will take an integer parameter
void add(int value) {
    //processing time
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    // add the value to the global variable
    global += value;
}

int main() {
    // create 3 threads passing the function and values
    std::thread T1(add, 10);
    std::thread T2(add, 20);    
    std::thread T3(add, 30);

    // display the value of global varialbe at different
    //combinations of using the join() per thread.
    std::cout << "First Display: " << global << std::endl;
    T1.join();

    std::cout << "Display after 1st join(): " << global << std::endl;
    T2.join();
    
    std::cout << "Display after 2nd join(): " << global << std::endl;
    T3.join();
    
    std::cout << "Display after 3rd join(): " << global << std::endl;
    
    return 0;
}

