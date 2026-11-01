#include <iostream>
#include <chrono>
#include <iomanip>

bool linearSearch (int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}

bool binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return true;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        }

        if (arr[mid] > target) {
            right = mid - 1;
        }
    }
    return false;
}

void executeSearching(int N) {
    int* arr = new int[N];

    for (int i = 0; i < N; i++) {
        arr[i] = i;
    }

    int target = -1;

    auto startLinearSearch = std::chrono::high_resolution_clock::now();
    linearSearch(arr, N, target);
    auto endLinearSearch = std::chrono::high_resolution_clock::now();
    auto linearSearchDuration = std::chrono::duration_cast<std::chrono::nanoseconds>
    (endLinearSearch - startLinearSearch).count();

    auto startBinarySearch = std::chrono::high_resolution_clock::now();
    binarySearch(arr, N, target);
    auto endBinarySearch = std::chrono::high_resolution_clock::now();
    auto binarySearchDuration = std::chrono::duration_cast<std::chrono::nanoseconds>
    (endBinarySearch - startBinarySearch).count();

    std::cout << "N = " << N << " \nLinear | Elapsed Time: " << std::fixed 
    << std::setprecision(10) << linearSearchDuration << " nanoseconds\n\n";

    std::cout << "N = " << N << " \nBinary | Elapsed Time: " << std::fixed 
    << std::setprecision(10) << binarySearchDuration << " nanoseconds\n\n";

    delete[] arr;
}

int main() {

    std::cout << " == Worst-case time complexity == " << std::endl;

    executeSearching(1000);
    executeSearching(10000);
    executeSearching(100000);


}