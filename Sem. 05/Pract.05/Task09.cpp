#include <iostream>
using namespace std;

bool checkForTwoIdenticalAdjacentDigits(int num) {
    bool twoIdenticalAdjacentDigits = false;

    int lastDigit = num % 10;;
    num /= 10;
    while (num !=0) {
        int currentDigit = num % 10;
        if (lastDigit == currentDigit)
            return true;

        lastDigit = currentDigit;
        num /= 10;
    }
    return false;
}

void validNumsInTheInterval(int K, int L) {
    if (K > L || K < 0 || L>100000)
        return;
    for (int i = K; i <= L; i++) {
        if (checkForTwoIdenticalAdjacentDigits(i))
            cout << i << " ";
    }
}

int main()
{
    int K; int L;
    cin >> K >> L;
    validNumsInTheInterval(K, L);

}

