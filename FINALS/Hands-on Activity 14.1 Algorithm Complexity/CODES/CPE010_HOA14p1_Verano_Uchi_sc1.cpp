#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>

// --- Insertion Sort ---
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// --- Merge Sort Helpers ---
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    const int N = 10000; // Dataset size
    
    // --- Safe Data Initialization ---
    std::vector<int> bestCaseData(N);
    std::vector<int> worstCaseData(N);
    
    for (int i = 0; i < N; ++i) {
        bestCaseData[i] = i + 1;       // 1, 2, 3, ..., N
        worstCaseData[i] = N - i;       // N, N-1, ..., 1
    }

    std::vector<int> tempArr;
    double insBestTime, insWorstTime, mrgBestTime, mrgWorstTime;

    // 1. Insertion Sort - Best Case
    tempArr = bestCaseData;
    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(tempArr);
    auto end = std::chrono::high_resolution_clock::now();
    insBestTime = std::chrono::duration<double, std::milli>(end - start).count();

    // 2. Insertion Sort - Worst Case
    tempArr = worstCaseData;
    start = std::chrono::high_resolution_clock::now();
    insertionSort(tempArr);
    end = std::chrono::high_resolution_clock::now();
    insWorstTime = std::chrono::duration<double, std::milli>(end - start).count();

    // 3. Merge Sort - Best Case
    tempArr = bestCaseData;
    start = std::chrono::high_resolution_clock::now();
    mergeSort(tempArr, 0, tempArr.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    mrgBestTime = std::chrono::duration<double, std::milli>(end - start).count();

    // 4. Merge Sort - Worst Case
    tempArr = worstCaseData;
    start = std::chrono::high_resolution_clock::now();
    mergeSort(tempArr, 0, tempArr.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    mrgWorstTime = std::chrono::duration<double, std::milli>(end - start).count();

    // --- Stream-Safe Table Formatting ---
    std::cout << "\nTable 14-2. Best- and Worst-Case Analysis (N = " << N << ")\n";
    std::cout << std::string(70, '=') << std::endl;
    std::cout << std::left << std::setw(15) << "Case" 
              << std::setw(28) << "Algorithm 1: Insertion" 
              << std::setw(28) << "Algorithm 2: Merge" << std::endl;
    std::cout << std::string(70, '-') << std::endl;

    // Print rows with strict double precision control
    std::cout << std::fixed << std::setprecision(2);
    
    std::cout << std::left << std::setw(15) << "Best Case"
              << "O(n) (" << insBestTime << " ms) "
              << "O(n log n) (" << mrgBestTime << " ms)" << std::endl;

    std::cout << std::left << std::setw(15) << "Worst Case"
              << "O(n^2) (" << insWorstTime << " ms) "
              << "O(n log n) (" << mrgWorstTime << " ms)" << std::endl;
              
    std::cout << std::string(70, '=') << std::endl;

    return 0;
}
