#include <iostream>
using namespace std;

bool contains(const int* arr, int n, int x) {
    if (n == 0) 
        return false;
    
    if (arr[0] == x) 
        return true;
    
    return contains(arr + 1, n - 1, x);
}

int main() {
    int n, x;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> x;
    cout << boolalpha << contains(arr, n, x) << endl;
    delete[] arr;

    return 0;
}




