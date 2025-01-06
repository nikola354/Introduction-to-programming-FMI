#include <iostream>
using namespace std;

void readArr(size_t* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void reverseNum(size_t& num) {
    size_t result = 0;
    while (num) {
        result *= 10;
        result += (num % 10);
        num /= 10;
    }
    num = result;
}

// - first<second
// + first>second
// 0 first==second
int compareLex(size_t first, size_t second) {
    reverseNum(first);
    reverseNum(second);
    while (first && second) {
        if ((first % 10) < (second % 10)) {
            return -1;
        }
        else if ((first % 10) > (second % 10)) {
            return 1;
        }
        else {
            first /= 10;
            second /= 10;
        }
    }

    return first - second;
}

void swap(size_t& first, size_t& second) {
    size_t temp = first;
    first = second;
    second = temp;
}

void sortLex(size_t*& nums, size_t N) {
    if (!nums) {
        return;
    }

    for (size_t i = 0; i < N; i++) {
        size_t smallest = i;
        for (int j = i + 1; j < N; j++) {
            if (compareLex(nums[smallest], nums[j]) > 0) {
                smallest = j;
            }
        }
        if (smallest != i) {
            swap(nums[i], nums[smallest]);
        }
    }
}

void printArr(const size_t* arr, size_t size) {
    if (!arr)
        return;

    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
int main()
{
    size_t size;
    cin >> size;

    size_t* arr = new size_t[size];
    readArr(arr, size);
    sortLex(arr, size);
    printArr(arr, size);

    delete[] arr;
}
