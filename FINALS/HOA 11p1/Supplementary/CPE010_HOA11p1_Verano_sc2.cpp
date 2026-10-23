#include <iostream>
#include <vector>
#include <chrono>

bool Unique(const std::vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if(A[i] == A[j]) return false;
        }
    }
    return true;
}

int main() {
    std::cout << "=> Worst Time Complexity: \n" << std::endl;
    std::vector<int> sizes = {1000, 10000, 100000};
    for (int n : sizes) {
        std::vector<int> A(n);
        for (int i = 0; i < n; i++) A[i] = i;

        auto start = std::chrono::high_resolution_clock::now();
        Unique(A);
        auto end = std::chrono:: high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << "N = " << n << " | Time: " << duration << " microseconds\n";
    
    }

    std::cout << "\n=> Best Time Complexity: \n" << std::endl;
    for (int n : sizes) {
        std::vector<int> A(n);
        for ( int i = 0; i < n; i++) {
            A[i] = i + 1;
        }
        A[1] = A[0];

        
        auto start = std::chrono::high_resolution_clock::now();
        Unique(A);
        auto end = std::chrono:: high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << "N = " << n << " | Time: " << duration << " microseconds\n";
    }
    return 0;
}