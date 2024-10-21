#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "Its even" << endl;
    }

    // 3 -> 5  2
    // 5 -> 9  4
    // 9 -> 17 8

    int lines =  n + n - 1;
    int halfLines = lines / 2;
    int halfLinesWithoutN = (lines - n) / 2;
    int halfNPlusOne = n / 2 + 1;

    // First Line
    for (int j = 0; j < halfLinesWithoutN; j++) {
        cout << "." << " ";
    }

    for (int j = 0; j < n; j++) {
        cout << "#" << " ";
    }

    for (int j = 0; j < halfLinesWithoutN; j++) {
        cout << "." << " ";
    }

    cout << endl;

    // Next Lines
    for (int i = 1; i < halfLines; i++) {
        for (int j = 0; j < halfLinesWithoutN; j++) {
            cout << "." << " ";
        }

        cout << "#" << " ";

        for (int j = 0; j < n - 2; j++) {
            cout << "." << " ";
        }

        cout << "#" << " ";

            for (int j = 0; j < halfLinesWithoutN; j++) {
            cout << "." << " ";
        }

        cout << endl;
    }

    // Middle Line
    for (int j = 0; j < halfNPlusOne; j++) {
        cout << "#" << " ";
    }

    int middleDotSize = lines - n - 1;
    for (int j = 0; j < middleDotSize; j++) {
        cout << "." << " ";
    }

    for (int j = 0; j < halfNPlusOne; j++) {
        cout << "#" << " ";
    }

    cout << endl;

    // Next Lines
    for (int i = 1; i < halfLines; i++) {
        for (int k = 0; k < i; k++) {
            cout << "." << " ";
        }

        cout << "#" << " ";
        
        int dotSize = lines - 2 - i * 2;
        for (int k = 0; k < dotSize; k++) {
            cout << "." << " ";
        }

        cout << "#" << " ";

        for (int k = 0; k < i; k++) {
            cout << "." << " ";
        }

        cout << endl;
    }

    // End Line
    for(int i = 0; i < n - 1; i++) {
        cout << "." << " ";
    }

    cout << "#" << " ";

    for(int i = 0; i < n - 1; i++) {
        cout << "." << " ";
    }

    cout << endl;
}