#include <iostream>

// What type of recursion is this, how will it print the array?
// Array: [1, 2, 3, 4, 5], size: 5
void printArr1(int* arr, size_t size) {
    if (size == 0) {
        return;
    }

    printArr1(arr, size - 1);
    std::cout << arr[size - 1] << " ";
}

// What type of recursion is this, how will it print the array?
// Array: [1, 2, 3, 4, 5], size: 5
void printArr2(int* arr, int size) {
    if (size == 0) {
        return;
    }

    std::cout << arr[size - 1] << " ";
    printArr2(arr, size - 1);
}

// What will the function return if n = 5?
size_t fact1(size_t n) {
    if (n == 0) {
        return 1;
    }

    return n * fact1(--n);
}

// What will the function return if n = 5?
size_t fact2(size_t n) {
    if (n == 0) {
        return 1;
    }

    return n * fact2(n--);
}
