#include <iostream>

int squareRootToLower(int number);
unsigned int log(unsigned int n, unsigned int k);

int main()
{
    int n;
    std::cin >> n;
    std::cout << squareRootToLower(n);
}

int squareRootToLower(int number) {
	return log(number, 2);
}

unsigned int log(unsigned int n, unsigned int k) {
	unsigned int powerOfK = 1;
	unsigned int count = 0;

	while (powerOfK <= n) {
		powerOfK *= k;
		count++;
	}

	return count - 1;
}