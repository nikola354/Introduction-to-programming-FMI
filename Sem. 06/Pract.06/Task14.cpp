#include <iostream>
using namespace std;

constexpr int MAX_SIZE = 100;

void mergeArrays(const int[], int, const int[], int, int[], int &);

void printArray(const int[], int);

int main() {
    int arr1[4] = { 1, 5, 7, 8 };
    int arr2[3] = { 2, 3, 6 };
    int result[MAX_SIZE];

    int size3 = 0;

    mergeArrays(arr1, 4, arr2, 3, result, size3);
    printArray(result, size3);

    return 0;
}

void mergeArrays(const int arr1[], int size1, const int arr2[], int size2, int result[], int & size3) {
    int i = 0, j = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] > arr2[j]) {
            result[size3++] = arr2[j++];
        } else {
            result[size3++] = arr1[i++];
        }
    }

    while (i < size1) {
        result[size3++] = arr1[i++];
    }
    
    while (j < size2) {
        result[size3++] = arr2[j++];
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}