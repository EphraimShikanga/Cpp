#include <iostream>

void bubbleSort(int arr[], int arrLenth) {

    for (int i = 0; i < arrLenth; i++) {
        for (int j =i+ 1; j < arrLenth; j++) {
            if (arr[i] > arr[j]) {
                int swap = arr[i];
                arr[i] = arr[j];
                arr[j] = swap;
            }
        }
    }
}

void selectionSort(int arr[], int arrLength) {

    for (int i = 0; i < arrLength; i++) {
        int assSmallest = i;
        for(int j = i+1; j < arrLength; j++) {
            if (arr[assSmallest] > arr[j]) {
                assSmallest = j;
            }
        }
        if (assSmallest != i) {
            int swap = arr[i];
            arr[i] = arr[assSmallest];
            arr[assSmallest] = swap;
        }
    }
}

void insertionSort(int arr[], int arrLength) {

    for (int i = 1; i < arrLength; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

