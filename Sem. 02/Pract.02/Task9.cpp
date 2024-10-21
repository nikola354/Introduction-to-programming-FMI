#include <iostream>

int main() {
    int num;
    std::cin >> num;

    int ed = num % 10;
    int des = (num / 10) % 10;
    int stot = (num / 100) % 10;
    int hil = num / 1000;

    int newNum = ed * 1000 + des * 100 + stot * 10 + hil;

    std::cout << (num == newNum ? 1 : 0) << std::endl;
    return 0;
}