#include <iostream>
#include "algorithms.hpp"

int main() {

    char arrs[] = {'d', 'c', 'b', 'a', 'f', 'x', 'n', 'm', 'z', 'y'};
    size_t arrLength = sizeof(arrs)/sizeof(arrs[0]);
    // bubbleSort(arrs, arrLength);
    insertionSort(arrs, arrLength);
    for (int i = 0; i < arrLength; i++) {
        std::cout << arrs[i] << " ";
    }

}