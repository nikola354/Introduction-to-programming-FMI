#include <iostream>
constexpr int MAX_SIZE = 50;

void gettingTheNumbersIn(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
}

bool isItInTheArray(int arr[], int n) {
    bool numberIsInArray[n + 1] = {false};

    for (int i = 0; i < n; i++) {
        int number = arr[i];

        if (numberIsInArray[number]) return false;

        numberIsInArray[number] = true;
    }
    return true;
}

void run() {
    int arr[MAX_SIZE];
    int n;
    std::cin >> n;
    gettingTheNumbersIn(arr, n);
    std::cout << std::boolalpha << isItInTheArray(arr, n);
}

int main() {
    run();
}
