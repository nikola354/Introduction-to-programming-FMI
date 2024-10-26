#include <iostream>
using namespace std;

int getRemainder(int first, int second) {
    first = first < 0 ? first * (-1) : first;
    second = second < 0 ? second * (-1) : second;

    while (first >= second) {
        first -= second;
    }

    return first;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    cout << getRemainder(n1, n2) << endl;

    return 0;
}