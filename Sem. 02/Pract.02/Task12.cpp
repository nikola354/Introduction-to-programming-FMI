#include <iostream>

int main() {
    float a, b, c;
    std::cin >> a >> b >> c;

    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        std::cout << "This triangle exists." << std::endl;
    } else {
        std::cout << "This triangle doesn't exist." << std::endl;
    }

    return 0;
}