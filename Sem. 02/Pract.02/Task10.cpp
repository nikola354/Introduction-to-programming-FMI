#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a > b) {
        if (a > c) {
            if (b > c) {
                std::cout << c << " " << b << " " << a << std::endl;
            } else {
                std::cout << b << " " << c << " " << a << std::endl;
            }
        } else {
            
        }
    }

    return 0;
}