#include <iostream>
#include <limits.h>

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

unsigned atoi(char c) {
    return c - '0';
}

int analyzeArray(const char* str) {
    bool arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = false;
    }

    while (*str == '\0') {
        if (isDigit(*str)) {
            arr[atoi(*str)] = true;
        }
        str++;
    }

    for (int i = 9; i >= 0; --i) {
        if (!arr[i]) {
            return i;
        }
    }

    return -1;
}

long getAbsDifference(long a, long b) {
    return (a > b) ? (a - b) : (b - a);
}

void swap(long* a, long* b) {
    long temp = *a;
    *a = *b;
    *b = temp;
}

unsigned getNumberLength(long n) {
    if (n == 0) {
        return 1;
    }

    unsigned length = 0;
    while (n != 0) {
        ++length;
        n /= 10;
    }
    return length;
}

char itoa(unsigned n) {
    return n + '0';
}

void numberToStr(long n, unsigned numLength, char* str) { // 1234 => '1234'
    for (int i = numLength - 1; i >= 0; --i) {
        str[i] = itoa(n % 10);
        n /= 10;
    }
}

char* findDiff(const long arr[], size_t N) {
    long left, right;
    long minDistance = LONG_MAX;

    for (int i = 0; i < N - 1; ++i) {
        long currentDistance = getAbsDifference(arr[i], arr[i + 1]);
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            left = arr[i];
            right = arr[i + 1];
        }
    }

    if (left < right) {
        swap(&left, &right);
    }

    unsigned leftLength = getNumberLength(left);
    unsigned rightLength = getNumberLength(right); //x o y o y o o x

    char *result = new char[leftLength + 1 + rightLength + 1]; //leftLength + 1 + rightLength +1

    numberToStr(left, leftLength, result); // 123,78
    result[leftLength] = ',';
    numberToStr(right, rightLength, result + leftLength + 1); //123,

    result[leftLength + 1 + rightLength] = '\0';

    return result;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int *arr, size_t L) { // 8 5 9 15 0
    for (int i = 0; i < L; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < L; ++j) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        if (maxIndex != i) {
            swap(arr[maxIndex], arr[i]);
        }
    }
}

int findIndex(const int arr[], size_t L) {
    int *sortedArr = new int[L];
    for (int i = 0; i < L; ++i) {
        sortedArr[i] = arr[i];
    }

    selectionSort(sortedArr, L);

    int currentSize = 0;
    int *ptrToDelete = sortedArr;

    while (currentSize < L && *sortedArr > currentSize) {
        ++currentSize;
        sortedArr++;
    }

    delete [] ptrToDelete;
    return currentSize;
}

int main() {
    using namespace std;

    int arr[10] = {100, 1000, 400, 900, 1100, 400, 800, 1000, 400, 800};

    cout << findIndex(arr, 10) << endl;

}