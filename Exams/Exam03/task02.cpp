#include <iostream>
const int MAX_SIZE = 1024;

using namespace std;

int smallestInSubsequence(const int *arr, int start, int end) {
    int smallest = arr[start];
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    return smallest;
}

int sumOfSmallestElements(const int *arr, int length, int K) {
    int sum = 0;
    if (K > length) {
        return sum;
    }

    int left = 0, right = K - 1;
    while (right < length) {
        sum += smallestInSubsequence(arr, left, right);
        left++;
        right++;
    }

    return sum;
}

int main() {
    int N, K;
    cin >> N >> K;

    if (N > MAX_SIZE || K > MAX_SIZE || K > N) {
        cout << "Invalid input" << endl;
        return 0;
    }

    int arr[MAX_SIZE];
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    cout << sumOfSmallestElements(arr, N, K) << endl;
}