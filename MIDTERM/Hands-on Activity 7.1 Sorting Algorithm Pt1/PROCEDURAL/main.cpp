 #include <iostream>
#include "sorting.h"
#include <cstdlib>
#include <time.h>

const int max_size = 100;

void displayAll(int arr[]);

int main() {

    int dataset[max_size];
    srand(time(0));

    for (int i = 0; i < max_size; i++){
        dataset[i] = rand()%100;
    }
    displayAll(dataset);

    std::cout << "\n\n| ------------------------------------------- |" << std::endl;

    std::cout << "\nBubble sort Testing: \n";
    bubbleSort(dataset, max_size);
    displayAll(dataset);

    std::cout << "\n\n| ------------------------------------------- |" << std::endl;

    std::cout << "\n Selection Sort testing: \n";
    selectionSort(dataset, max_size);
    displayAll(dataset);

    std::cout << "\n\n| ------------------------------------------- |" << std::endl;

    std::cout << "\n Insertion Sort testing: \n";
    insertionSort(dataset, max_size);
    displayAll(dataset);


    std::cout << "\n Insertion Sort testing: \n";
    insertionSort1(dataset, max_size);
    displayAll(dataset);


    return 0;
}



void displayAll(int arr[]) {
    for (int i = 0; i < max_size; i++) {
    std::cout << arr[i] << ", ";
    }
}