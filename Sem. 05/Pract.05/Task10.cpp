#include <iostream>
using namespace std;

int getCountOfDigits(int n) {
    int count = 0;
    if (n == 0)
        count = 1;
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

void reverseNum(int& num) {
    int result = 0;
    while (num != 0) {
        int lastDigit = num % 10;
        (result *= 10) += lastDigit;
        num /= 10;
    }
    num = result;
}

void newA (int& a,int k) {
    for (int i = 0; i < k; i++) {
        a /= 10;
    }
}



void newB(int a,int& b, int k) {
    int newKDigits = 0;
    int digitsOfB = getCountOfDigits(b);
    int result = 0;

    for (int i = 0; i < k; i++) {
        int lastDigitsOfA = a % 10;
        result += lastDigitsOfA;
        result *= 10;
        a /=10;
    }
    result /= 10;
    reverseNum(result);

    for (int i = 0; i < digitsOfB; i++) {
        result *= 10;
    }
    b = result + b;
}

void newNums(int& a, int& b, int k) {
    newB(a, b, k);
    newA(a, k);

    cout << a << " " << b << endl;
}

int main()
{
    int a; int b; int k;
    cin >> a >> b >> k;

    newNums(a, b, k);

}
