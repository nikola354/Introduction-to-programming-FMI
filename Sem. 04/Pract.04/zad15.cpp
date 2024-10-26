#include <iostream>
using namespace std;

int reverseNumber(int n) {
    int reversedNumber = 0;

    while (n != 0) {
        reversedNumber = reversedNumber * 10 + n % 10;
        
        n /= 10;
    }

    return reversedNumber;
}

int digitsCount(int n) {
    int count = 0;

    while (n != 0) {
        count++;
        n /= 10;
    }

    return count;
}

int sortDigits(unsigned int number) {
    unsigned int sortedNumber = 0;
    int copyNumber = number;

    while (copyNumber > 0) {
        int lastDigit = copyNumber % 10;
        copyNumber /= 10;

        int temp = reverseNumber(sortedNumber);
        int newNum = 0;
        bool isPlaced = false;

        while (temp != 0) {
            int currentDigit = temp % 10;

            if (lastDigit > currentDigit && !isPlaced) {
                newNum = newNum * 10 + lastDigit;
                
                isPlaced = true;
            }

            newNum = newNum * 10 + currentDigit;
            temp /= 10;
        }

        if (!isPlaced) {
            newNum = newNum * 10 + lastDigit;
        }

        sortedNumber = newNum;
    }

    for (int i = digitsCount(sortedNumber); i < digitsCount(number); i++) {
        sortedNumber *= 10;
    }

    return sortedNumber;
}

int main() {
    int num;
    cin >> num;

    cout << sortDigits(num) << endl;

    return 0;
}