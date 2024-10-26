#include <iostream>
using namespace std;

int getGCD(int a, int b) {
    //Euclidean algorithm
    if (b > a) {
        unsigned int temp = a;
        a = b;
        b = temp;
    }
    while (b != 0) {
        unsigned int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int getLCM(int a, int b) {
    int i = a < b ? b : a;
    while (i % a != 0 || i % b != 0) {
        i++;
    }
    return i;
}

void getGCDandLCMofMoreNums() {
    int N;
    cin >> N;
    int num;
    cin >> num;
    int gcd = num;
    int lcm = num;

    for (int i = 2; i <= N; i++) {
        int currentNumber;
        cin >> currentNumber;

        int currentGCM = getGCD(gcd, currentNumber);
        gcd = currentGCM;
        int currentLCM = getLCM(lcm, currentNumber);

        lcm = currentLCM;

    }
    cout << "GCD: " << gcd;
    cout << "LCM: " << lcm;
}
int main()
{
    getGCDandLCMofMoreNums();
}

