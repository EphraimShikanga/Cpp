#include <iostream>
#include "algorithms.hpp"

int main() {

    int arrs[] = {87,445, 4, 1,9,0, 7, 0};
    size_t arrLength = sizeof(arrs)/sizeof(arrs[0]);
    // bubbleSort(arrs, arrLength);
    selectionSort(arrs, arrLength);
    for (int i = 0; i < arrLength; i++) {
        std::cout << arrs[i] << " ";
    }

}