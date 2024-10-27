// Problem 16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int getRemainder(int first, int second) {
    if (first < second) {
        return first;
    }

    if (first == second) {
        return 0;
    }

    while (first >= second) {
        first -= second;
    }

    return first;
}


int main()
{
    std::cout << getRemainder(12, 3) << endl;;
}

