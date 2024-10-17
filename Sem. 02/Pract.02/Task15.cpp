#include <iostream>

int main() {
    int num;
    std::cin >> num;

    int ed = num % 10;
    int des = (num / 10) % 10;
    int stot = (num / 100) % 10;
    int hil = num / 1000;

    int n1 = hil * 10 + ed;
    int n2 = stot * 10 + des;

    if (n1 > n2) {
        std::cout << "bigger (" << n1 << " > " << n2 << ")" << std::endl; 
    } else  if (n1 < n2) {
        std::cout << "less (" << n1 << " < " << n2 << ")" << std::endl; 
    } else {
        std::cout << "equal (" << n1 << " = " << n2 << ")" << std::endl; 
    }
}