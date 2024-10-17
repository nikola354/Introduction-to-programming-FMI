#include <iostream>

int main() {
    int x, y, r;
    std::cin >> r >> x >> y;

    // uravnenie na orkujnost
    if (x * x + y * y == r * r) {
        std::cout << "On the circle" << std::endl;
    } else if (x * x + y * y < r * r) {
        std::cout << "In the circle" << std::endl;
    } else {
        std::cout << "Out of the circle" << std::endl;
    }

    return 0;
}