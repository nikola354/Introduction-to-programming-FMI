#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            for(int j = (i - 1) * n; j < n * i; j++) {
                cout << (j + 1) << " ";
            }
        } else {
            for(int j = n * i; j > (i - 1) * n; j--) {
                cout << j << " ";
            }
        }

        cout << endl;
    }

    return 0;
}