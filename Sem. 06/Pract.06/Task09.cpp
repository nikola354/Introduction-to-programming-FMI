#include <iostream>
constexpr int MAX_SIZE = 100;

void gettingTheNumbersIn(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
}

void sortingTheArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printingTheAnswers(int arr[], int n) {
    std::cout << arr[0] << std::endl;
    std::cout << arr[--n];
}

void run() {
    int arr[MAX_SIZE];
    int n;
    std::cin >> n;
    gettingTheNumbersIn(arr, n);
    sortingTheArray(arr, n);
    printingTheAnswers(arr, n);
}

int main() {
    run();
}
