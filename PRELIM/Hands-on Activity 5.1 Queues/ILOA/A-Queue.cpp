#include <iostream>
#include <queue>

void display(std::queue<char> q) {
    std::queue <char> c = q;
    while (!c.empty()) {
        std::cout << c.front() << " ";
        c.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::queue<char> a;
    a.push('J');
    a.push('A');
    a.push('M');
    a.push('E');
    a.push('S');
    
    std::cout << "Queue a is: ";
    display(a);

    std::cout << "a.empty() : " << a.empty() << std::endl;
    std::cout << "a.size() : " << a.size() << std::endl;
    std::cout << "a.front() : " << a.front() << std::endl;
    std::cout << "a.back() : " << a.back() << std::endl;

    std::cout << "a.pop() : ";
    a.pop();
    display(a);

    a.push('J');
    std::cout << "The queue a is : ";
    display(a);

    return 0;

}