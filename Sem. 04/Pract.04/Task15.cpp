
#include <iostream>
using namespace std;

int getCountOfADigit(int number, int digit) {
    int count = 0;
    while (number != 0) {
        int lastDigit = number % 10;
        if (lastDigit == digit)
            count++;
        number /= 10;
    }
    return count;
}

int sortDigits( int num) {
    int result = 0;
    for (int i = 9; i >= 0; i--){
        int count = getCountOfADigit(num, i);
        while (count > 0) {
            (result *= 10) += i;
            count--;
        }
    }
    return result;
}
int main()
{
    cout << sortDigits(536241);
}

