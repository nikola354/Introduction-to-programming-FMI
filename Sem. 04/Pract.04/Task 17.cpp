// пьтнь шс.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int first;
int second;
int res;
int getDivision(int first, int second)
{
    std::cin >> first >> second;
    //int remainder = first % second;
    for (int i = 1; i * second <= first; i++) {
        res = i;
    } 
    return res;
}
int main() {
    std::cout << getDivision(first, second);
    //return 0;
}
