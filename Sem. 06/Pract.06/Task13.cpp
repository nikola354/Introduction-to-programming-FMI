#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void unionArrays(const int[], int, const int[], int, int[], int &);

void intersectionArrays(const int[], int, const int[], int, int[], int &);

void printArray(const int[], int);

int main() {
    int arr1[5] = { 2, 4, 1, 7, 8 };
    int arr2[4] = { 1, 2, 3, 5 };

    int unionArray[MAX_SIZE];
    int unionArrLength = 0;

    int intersectionArray[MAX_SIZE];
    int interArrLength = 0;

    unionArrays(arr1, 5, arr2, 4, unionArray, unionArrLength);
    cout << "Union: ";
    printArray(unionArray, unionArrLength);

    intersectionArrays(arr1, 5, arr2, 4, intersectionArray, interArrLength);
    cout << "Intersection: ";
    printArray(intersectionArray, interArrLength);

    return 0;
}

void unionArrays(const int arr1[], int size1, const int arr2[], int size2, int result[], int& size3) {
    for(int i = 0; i < size1; i++) {
        bool isPresent = false;

        // check if element is already in result
        for (int j = 0; j < size3; j++) {
            if (arr1[i] == result[j]) {
                isPresent = true;
                break;
            }
        }

        if (!isPresent) {
            result[size3] = arr1[i];
            size3++;
        }
    }

    for(int i = 0; i < size2; i++) {
        bool isPresent = false;

        // check if element is already in result
        for (int j = 0; j < size3; j++) {
            if (arr2[i] == result[j]) {
                isPresent = true;
                break;
            }
        }

        if (!isPresent) {
            result[size3] = arr2[i];
            size3++;
        }
    }
}

void intersectionArrays(const int arr1[], int size1, const int arr2[], int size2, int result[], int& size3) {
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                bool isPresent = false;
                // check if alredy is in result
                for (int k = 0; k < size3; k++) {
                    if (arr1[i] == result[k]) {
                        isPresent = true;
                        break;
                    }
                }

                if (!isPresent) {
                    result[size3] = arr1[i];
                    size3++;
                }
            }
        }
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}