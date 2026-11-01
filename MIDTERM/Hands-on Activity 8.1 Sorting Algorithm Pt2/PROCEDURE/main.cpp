#include <iostream>
#include "algorithmp2.h"

const int maxSize = 100;
void displayArr(int arr[]);

int main(){
    
    //create an array with unsorted list
    int unsortedArr[maxSize];
    // use time (0) as seed for random
    srand(time(0));
    //populate the array with random val
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand()%100;
    }
     
    std::cout << "Unsorted Array:\n";
    //display the randomly generated arr
    displayArr(unsortedArr);
    std::cout << std::endl;
    // std::cout << "Sorted Array Using Shell Sort:\n ";
    // shellSort(unsortedArr, maxSize);
    // displayArr(unsortedArr);

    // std::cout << "Sorted Array Using mergeSort Sort:\n ";
    // shellSort(unsortedArr, maxSize);
    // displayArr(unsortedArr);

    std::cout << "Sorted Array Using Quick Sort:\n ";
    shellSort(unsortedArr, maxSize);
    displayArr(unsortedArr);
    return 0;
}

void displayArr(int arr[]){
    for(int i = 0; i < maxSize; i++){
        std::cout << arr[i] << " ";
        if ((i%10) == 9){
            std::cout << '\n';
        }
    }
}

