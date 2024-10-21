#include <iostream>

int main() {
    float num;
    std::cin >> num;

    // if (num == (int)num) {
    //     std::cout << "Integer" << std::endl;
    // } else {
    //     std::cout << "Not an integer" << std::endl;
    // }

    std::cout << (num == (int)num ? "Integer" : "Not an integer") << std::endl;

    return 0;
}