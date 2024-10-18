#include <iostream>

int zad15(), zad16(), zad17();

int main()
{
    zad15();
}

int zad15() {
    int num;
    std::cin >> num;
    int a = num / 1000;
    int b = (num / 100) % 10;
    int c = (num / 10) % 10;
    int d = num % 10;

    int num1 = a * 10 + d;
    int num2 = b * 10 + c;
    if (num1 > num2) {
        std::cout << "greater (" << num1 << ">" << num2 << ")";
    }
    else if (num1 == num2) {
        std::cout << "equal (" << num1 << "=" << num2 << ")";
    }
    else {
        std::cout << "less (" << num1 << "<" << num2 << ")";
    }
    return 0;
}

int zad16() {
    unsigned int input;
    std::cin >> input;
    switch (input) {
    case 1:
        std::cout << "1 ";
    case 3:
        std::cout << "3";
    case 5:
        std::cout << "5 ";
    case 7:
        std::cout << "7 ";
    case 9:
        std::cout << "9 ";
    case 11:
        std::cout << "11";
        break;
    case 0:
        std::cout << "0 ";
    case 2:
        std::cout << "2 ";
    case 4:
        std::cout << "4 ";
    case 6:
        std::cout << "6 ";
    case 8:
        std::cout << "8 ";
    case 10:
        std::cout << "10 ";
    case 12:
        std::cout << "12";
        break;
    }

    return 0;
}

int zad17() {
    char a, b, c, d, e;
    std::cin >> a >> b >> c >> d >> e;
    int beginA = (int)a + 32, endA = int(b) + 32, beginB = (int)c, endB = int(d);
    int input = (int)e <= 90 ? (int)e + 32 : (int)e;

    bool unification = (input >= beginA && input <= endA) || (input >= beginB && input <= endB);
    bool section = (input >= beginA && input <= endA) && (input >= beginB && input <= endB);
    bool subtraction = (input >= beginA && input <= endA) && !(input >= beginB && input <= endB);

    std::cout << std::boolalpha << unification << '\n';
    std::cout << std::boolalpha << section << '\n';
    std::cout << std::boolalpha << subtraction << '\n';
    std::cout << std::boolalpha << subtraction || (!section && !subtraction) << '\n';


    return 0;
}
