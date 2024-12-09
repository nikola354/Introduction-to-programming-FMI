#include <iostream>
using namespace std;

constexpr int DIGIT_SIZE = 5;

void printArray(const int[], int);

void addOneToArray(int[]);

int main() {
    int num[DIGIT_SIZE] = { 0, 1, 0, 0, 9 };

    addOneToArray(num);

    printArray(num, DIGIT_SIZE); 

    return 0;
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void addOneToArray(int num[]) {
    int memory = 0;

    num[DIGIT_SIZE - 1]++;

    if (num[DIGIT_SIZE - 1] == 10) {
        num[DIGIT_SIZE - 1] = 0;
        memory = 1;

        for (int i = DIGIT_SIZE - 2; i >= 0; i--) {
            num[i] += memory;
            memory = 0;

            if (num[i] == 10) {
                num[i] = 0;
                memory = 1;
            } else {
                break;
            }
        }
    }
}