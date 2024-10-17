#include <iostream>

int main() {
    float n1, n2;
    char operation;

    std::cin >> n1 >> operation >> n2;

    switch (operation)  {
    case '+':
        std::cout <<  n1 + n2 << std::endl;
        break;
    case '-':
        std::cout <<  n1 - n2 << std::endl;
        break;
    case '*':
        std::cout <<  n1 * n2 << std::endl;
        break;
    case '/':
        std::cout <<  n1 / n2 << std::endl;
        break;
    default:
        std::cout << "Invalid operation" << std::endl;
        break;
    }

    return 0;
}