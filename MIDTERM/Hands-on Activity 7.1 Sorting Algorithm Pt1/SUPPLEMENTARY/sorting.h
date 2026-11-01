#ifndef SORTING_H
#define SORTING_H

template <typename T>
void bubbleSort (T arr[], int maxSize){

    for(int i = 0; i < maxSize; i++) {
        for(int j = i + 1; j < maxSize; j++){
            if(arr[i] > arr[j]){
                std::swap(arr[j], arr[i]);
            }
        }
    }
}



template <typename T>
int routineSmallest(T arr[], int K, int maxSize){
    int position;
    T smallestElem = arr[K];
    position = K;

    for (int j = K + 1; j < maxSize; j++){
        if(arr[j] < smallestElem){
            smallestElem = arr[j];
            position = j;
        }
    }
    return position;
}



template <typename T>
void selectionSort(T arr[], int maxSize){
    int POS;
    for (int i = 0; i < maxSize; i++) {
        POS = routineSmallest(arr, i, maxSize);
        std::swap(arr[i], arr[POS]);
    }
}



template <typename T>
void insertionSort(T arr[], int maxSize){
    int k=1, j, temp;

    while (k < maxSize){
        temp = arr[k];
        j = k - 1;

        while(temp <= arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        k++;
    }
}

template <typename T>
void insertionSort1(T arr[], int maxSize){
    for(int k = 1; k < maxSize; k++){
        T temp = arr[k];
        int j = k-1;
        for (j = k-1; j >= 0 && temp <= arr[j]; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
}

#endif