#ifndef SUPPLEMENTARY_H
#define SUPPLEMENTARY_H

template<typename T>
void hybridQuickShellSort(T arr[], int low, int high) {
    if (low < high) {
        //Partition the array using your quicksort partition method
        int pi = partition(arr, low, high);
        
        //Compute sizes of the resulting left and right segments
        int leftSize = pi - low;
        int rightSize = high - pi;

        //Delegate sorting tasks to Shell Sort instead of regular recursion
        shellSort(&arr[low], leftSize);      // Sorts the left sub-list in place
        shellSort(&arr[pi + 1], rightSize);   // Sorts the right sub-list in place
    }
}



template<typename T>
void shellSort(T array[],int size){
    // Loops while the comparison gap is greater than 0
    for (int gap = size/2;gap > 0; gap /=2){
        //selection like sorting
        for (int i = gap;i < size;i++){
            int temp = array[i];
            int key = i;
            //Continues shifting elements forward as the front of the gap chain 
            // has not reached the end, and the previous gap element is larger than temp
            while (key >= gap && array[key - gap] > temp) {
                array[key] = array[key - gap];
                key -= gap;
            }
            array[key] = temp;
        }
    }
}



template<typename T>
void merge(T array[],int left,int mid,int right){
    // A helper function that takes two adjacent sorted halves of an array
    int sizeL = mid-left + 1; // Calculation for the left partition
    int sizeR = right - mid; // Calculation for the right partition
    
    // temporary array for the left and right half
    T arrL[sizeL];
    T arrR[sizeR];
    
    for (int i = 0; i < sizeL; i++){
        arrL[i] = array[left + i];
    }    
    for (int j = 0; j < sizeR; j++){
        arrR[j] = array[mid + 1 + j];
    }
    int i = 0, j = 0;
    int k = left;
    
    // Merge the temp arrays back
    while (i < sizeL && j < sizeR) {
        if (arrL[i] <= arrR[j]) {
            array[k] = arrL[i];
            i++;
        }
        else {
            array[k] = arrR[j];
            j++;
        }
        k++;
    }
    while (i < sizeL) {
        array[k] = arrL[i];
        i++;
        k++;
    }
    while (j < sizeR) {
        array[k] = arrR[j];
        j++;
        k++;
    }
}

template<typename T>
void mergeSort(T array[],int left,int right){
    if (left >= right)return;
    //calculates the midpoint
    int mid = left + (right - left) / 2;
    //recursively sorts the left and right half
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}



template<typename T>
int partition(T arr[], int low, int high) {
    
    // choose the pivot
    T pivot = arr[high];
    
    // undex of smaller element and indicates
    // the right position of pivot found so far
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    // move pivot after smaller elements and
    // return its position
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template<typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);
        
        // recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
#endif