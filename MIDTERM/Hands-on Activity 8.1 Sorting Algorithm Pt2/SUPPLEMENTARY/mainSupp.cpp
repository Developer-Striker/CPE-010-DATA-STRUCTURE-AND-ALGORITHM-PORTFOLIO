#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <chrono>  
#include "supplementary.h"

const int maxSize = 15; // Set to match your assignment's array size requirement
void displayArr(int arr[]);
void resetArray(int target[], const int source[]);

int main() {
    int originalArr[maxSize] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};
    int workingArr[maxSize];
    
    std::cout << "========================================\n";
    std::cout << "Original Unsorted Array:\n";
    displayArr(originalArr);
    std::cout << "========================================\n\n";

    // --- |TESING OF SHELL SORT| ---
    resetArray(workingArr, originalArr);
    auto start = std::chrono::high_resolution_clock::now();
    shellSort(workingArr, maxSize);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "1. Shell Sort Results:\n";
    displayArr(workingArr);
    std::cout << "Runtime: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns\n\n";

    // --- |TESTING OF MERGE SORT| ---
    resetArray(workingArr, originalArr);
    start = std::chrono::high_resolution_clock::now();
    mergeSort(workingArr, 0, maxSize - 1);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "2. Merge Sort Results:\n";
    displayArr(workingArr);
    std::cout << "Runtime: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns\n\n";

    // --- |TESTING OF QUICK SORT| ---
    resetArray(workingArr, originalArr);
    start = std::chrono::high_resolution_clock::now();
    quickSort(workingArr, 0, maxSize - 1);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "3. Quick Sort Results:\n";
    displayArr(workingArr);
    std::cout << "Runtime: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns\n";
    std::cout << "========================================\n";

    return 0;
}

// Helper function to print arrays
void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
        if ((i % 10) == 9) {
            std::cout << '\n';
        }
    }
    std::cout << '\n';
}

// Helper function to reset the array back to the original 
//unsorted order before each sort test
void resetArray(int target[], const int source[]) {
    for (int i = 0; i < maxSize; i++) {
        target[i] = source[i];
    }
}
