// Task 16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int first;
int second;
int getRemainder(int first, int second)
{
	std::cin >> first >> second;
	int div_res = first / second;
	int remainder = first - div_res * second;
	return remainder;
}
int main() {
	std::cout << getRemainder(first, second);
}
