#include <iostream>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int N = sizeof(arr) / sizeof(arr[0]);

    int *ptr1 = &arr[0];
    int *ptr2 = &arr[N - 1];
    int temp;

    for (int i = 0; i < N / 2; i++) {
        temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
        ptr1++;
        ptr2--;
    }

    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}