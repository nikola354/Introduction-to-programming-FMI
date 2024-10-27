// Problem 18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int squareRootToLower(int number) {

    if (number == 0)
    {
        return 0;
    }

    int left = 0;
    int right = number;
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid * mid == number) {
            return mid;
        }
        
        if (mid * mid < number) {
            left = mid + 1;
            result = mid;
        }
        else {
            right = mid - 1;
        }

    }

    return result;


}

int main()
{
    int number;

    cin >> number;

    cout << squareRootToLower(number) << endl;
}

