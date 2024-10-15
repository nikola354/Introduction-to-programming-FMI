#include <iostream>
#include <cmath>


int main() {
    const double EPSILON = 0.0001;

    double x, y,r;
    std::cin >> x >> y>>r;
    

    double length = sqrt((x * x) + (y * y));

    if (std::fabs(length - r) < EPSILON) {
        std::cout << "On the circle" << std::endl;
    }
    else if (length < r) {
        std::cout << "In the circle" << std::endl;
    }
    else {
        std::cout << "Out of the circle" << std::endl;
    }
}