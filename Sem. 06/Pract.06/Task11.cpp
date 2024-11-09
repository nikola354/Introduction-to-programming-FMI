#include <iostream>
using namespace std;

bool findSubarray(const int[], int, const int[], int);

int main() {
    int arr1[4] = { 1, 2, 3, 4 };
    int arr2[3] = { 1, 2, 3 };
    
    cout << boolalpha << findSubarray(arr1, 4, arr2, 3) << endl;

    return 0;
}

bool findSubarray(const int arr1[], int size1, const int arr2[], int size2) {
    if (size2 > size1) return false;

    for (int i = 0; i <= size1 - size2; i++) {
        bool areEqual = true;
        for (int j = 0; j < size2; j++) {
            if (arr1[i + j] != arr2[j]) {
                areEqual = false;
                break;
            }
        }

        if (areEqual) return true;
    }

    return false;
}