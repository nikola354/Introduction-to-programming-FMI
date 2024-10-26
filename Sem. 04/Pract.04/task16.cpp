#include <iostream>

int getRemainder(int first, int second) {
    int bigger = (first >= second ? first : second);
    int smaller = (first < second ? first : second);
    int result = 0;
    result = bigger / smaller;
    result = bigger - (smaller * result);

    return result;
}

int main() {
    std::cout << getRemainder(17, 3) << '\n';
    return 0;
}