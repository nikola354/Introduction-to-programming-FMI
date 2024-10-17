#include <iostream>

int main() {
    int a, b, c, d, e;
    std::cin >> a >> b >> c >> d >> e;

    if (((b >= a && b >= c) || (b <= a && b <= c)) && ((c >= b && c >= d) || (c <= b && c <= d)) && ((d >= c && d >= e) || (d <= c && d <= e))) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}