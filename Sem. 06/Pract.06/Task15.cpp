#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int binarySearch(const int[], int, int, int);

int main() {
    int n;
    cin >> n;
    int arr[MAX_SIZE];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = binarySearch(arr, 0, n - 1, 0);
    cout << result << endl;

    return 0;
}

int binarySearch(const int arr[], int left, int right, int lookupVal) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == lookupVal) {
            return mid;
        }

        if (arr[mid] % 2 == 0) {
            left = mid + 1;
        }

        if (arr[mid] % 2 == 1) {
            right = mid - 1;
        }
    }

    return -1;
}