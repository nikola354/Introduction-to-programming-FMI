// От конзолата се чете число в интервала [0, ..., 12]. Ако числото е четно, програмата
// принтира всички четни числа по-големи или равни на числото, намиращи се в интервала. 
// Ако е нечетно, принтираме всички по-големи или равни нечетни числа. (Опитайте се да 
// направите кода максимално четим)
#include <iostream>
int main() {
    int n;
    std::cin >> n;
    switch (n)
    {
    case 1:
        std::cout << 1 << std::endl;
    case 3:
        std::cout << 3 << std::endl;
    case 5:
        std::cout << 5 << std::endl;
    case 7:
        std::cout << 7 << std::endl;
    case 9:
        std::cout << 9 << std::endl;
    case 11:
        std::cout << 11 << std::endl;
        break;
    case 0:
        std::cout << 0 << std::endl;
    case 2:
        std::cout << 2 << std::endl;
    case 4:
        std::cout << 4 << std::endl;
    case 6:
        std::cout << 6 << std::endl;
    case 8:
        std::cout << 8 << std::endl;
    case 10:
        std::cout << 10 << std::endl;
    case 12:
        std::cout << 12 << std::endl;
        break;
    default:
        std::cout << "Incorrect input" << std::endl;
    }
}