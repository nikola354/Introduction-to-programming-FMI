#include <iostream>

int getRemainder(int first, int second) {
    int bigger = (first >= second ? first : second);
    int smaller = (first < second ? first : second);
    int result = 0;
    result = bigger / smaller;
    result = bigger - (smaller * result);

    return result;
}

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
    std::cout << getRemainder(17, 3) << '\n';
    std::cout << getDivision(12, 2) << '\n';
    return 0;
}