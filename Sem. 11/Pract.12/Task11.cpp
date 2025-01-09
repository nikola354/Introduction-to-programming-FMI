#include <iostream>
using namespace std;

 int* readArr(size_t len) {
     int* arr = new int[len];
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    return arr;
}

void insertAt(int*& arr, size_t& len, int index, int elem) {
    if (!arr) {
        return;
    }

    if (index < 0 || index > len) {
        return;
    }

    len++;
    int* result = new int[len];
    int currentIndex = 0;
    int oldArrIndex = 0;
    for (int i = 0; i < len; i++) {
        if (index == i) {
            result[currentIndex++] = elem;
        }
        else {
            result[currentIndex++] = arr[oldArrIndex++];
        }
    }

    delete[] arr;
    arr = result;
}

void removeAt(int*& arr, size_t& len, int index) {
    if (!arr) {
        return;
    }

    if (index < 0 || index >= len) {
        return;
    }

    len--;
    int* result = new int[len];

    int resultIndex = 0;
    int oldIndex = 0;
    for (int i = 0; i < len + 1; i++) {
        if (index == i) {
            oldIndex++;
        }
        else {
            result[resultIndex++] = arr[oldIndex++];
        }
    }

    delete[] arr;
    arr = result;
}

void printArr(const int* arr, size_t len) {
    if (!arr) {
        return;
    }

    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
}

int main()
{
    size_t len;
    cin >> len;
    int* arr = readArr(len);
    insertAt(arr, len, 4, 123);
    removeAt(arr, len, 1);
    printArr(arr, len);

    delete[] arr;

}