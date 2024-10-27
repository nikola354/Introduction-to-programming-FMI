

#include <iostream>
using namespace std;

int concat(unsigned int first,unsigned int second) {
    int reverseSecond = 0;
    int result = first;


    while (second > 0) {
        reverseSecond *= 10;
        int digit = second % 10;
        second /= 10;
        reverseSecond += digit;
    }

    while (reverseSecond > 0) {
        result *= 10;
        int digit = reverseSecond % 10;
        reverseSecond /= 10;
        result += digit;
    }

    return result;

    

}


int main()
{
    unsigned int numberOne, numberTwo;

    cin >> numberOne >> numberTwo;

    cout << concat(numberOne, numberTwo) << endl;
}

