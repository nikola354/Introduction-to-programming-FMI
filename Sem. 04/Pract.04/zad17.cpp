#include <iostream>
using namespace std;

int getDivision(int first, int second) {
    first = first < 0 ? first * (-1) : first;
    second = second < 0 ? second * (-1) : second;

    int result = 0;

    while (first >= second) {
        first -= second;
        result++;
    }

    return result;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    cout << getDivision(n1, n2) << endl;

    return 0;
}