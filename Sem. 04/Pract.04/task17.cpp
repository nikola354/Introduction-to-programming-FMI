#include <iostream>

int getDivision(int first, int second) {
    int result = 0;
    if (first >= second) {
        int remainder = (first % second);
        first -= remainder;

        while (first >= second) {
            first -= second;
            result++;
        }
    }
    return result;
}

int main() {
    std::cout << getDivision(12, 2) << '\n';
    return 0;
}