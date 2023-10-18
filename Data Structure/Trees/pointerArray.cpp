#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int m = 5;
    int n = 3;


    int arr1[m];
    srand(time(0));
    for (int i = 0; i < m; i++) {
        arr1[i] = rand() % 100;
    }

    int arr2[n];
    for (int i = 0; i < n; i++) {
        arr2[i] = rand() % 100;
    }

    int concatSize = m + n; 
    int concatArr[concatSize];
    int *ptr = concatArr;


    for (int i = 0; i < m; i++) {
        *ptr = arr1[i];
        ptr++;
    }


    ptr = concatArr + m;

    for (int i = 0; i < n; i++) {
        *ptr = arr2[i];
        ptr++;
    }

    ptr = concatArr;
    for (int i = 0; i < concatSize; i++) {
        std::cout << *ptr << " ";
        ptr++;
    }
    std::cout << std::endl;

    return 0;
}