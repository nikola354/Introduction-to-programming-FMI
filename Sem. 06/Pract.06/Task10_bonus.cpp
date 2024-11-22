#include <iostream>
using namespace std;

constexpr int MAX_SIZE = 50;
constexpr int MAX_ELEMENT = 30;

bool chekcIfDistinct(const int arr[], int size) {
    int seen[MAX_ELEMENT] = { false };

    for (int i = 0; i < size; i++) {
        int num = arr[i];

        if (num < 1 || num >= MAX_ELEMENT) return false;

        if (seen[num]) return false;

        seen[num] = true;
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

    cout << (chekcIfDistinct(arr, n) ? "true" : "false") << endl;
}