#include <iostream>
using namespace std;

const int MAX_SIZE = 50;

bool chekcIfDistinct(const int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    int arr[MAX_SIZE];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << boolalpha << chekcIfDistinct(arr, n) << endl;
}