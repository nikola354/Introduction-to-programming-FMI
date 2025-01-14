#include <iostream>
using namespace std;

bool isIncreasing(const int* arr, int n) {
   
    if (n <= 1) 
        return true;
    
    if (arr[0] > arr[1]) 
        return false;
    
    return isIncreasing(arr + 1, n - 1);
}

bool contains(const int* arr, int n, int x) {
    
    if (n == 0) 
        return false;
    
    if (arr[0] == x) 
        return true;
    
    if (arr[0] > x) 
        return false;
    
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

    if (!isIncreasing(arr, n)) {
        cout << "Invalid input!" << endl;
    }
    else {
        cout << boolalpha << contains(arr, n, x) << endl;
    }

    delete[] arr;
    return 0;
}

