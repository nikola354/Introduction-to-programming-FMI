#include <iostream>

int powOfTen(int k) {
    int powerOfTen = 1;
    
    while (k != 0) {
        powerOfTen *= 10;
        k--;
    }
    
    return powerOfTen;
}

int numbersLengthOfb(int b) {
    int length = 0;
    
    while (b != 0) {
        length++;
        b /= 10;
    }
    
    return length;
}

void newNumbers(int &a, int &b, int k) {
    int tempLastKDigits = a % powOfTen(k);
    
    b = tempLastKDigits * powOfTen(numbersLengthOfb(b)) + b;
    a /= powOfTen(k);
}

int main() {
    int a, b, k;
    std::cin >> a >> b >> k;
    
    newNumbers(a, b, k);
    
    std::cout << a << " " << b;
}
