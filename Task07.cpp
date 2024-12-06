#include <iostream>

unsigned flipRightmostSetBit(unsigned num) {
	return num & (num - 1);
}

int main()
{
	unsigned n;
	std::cin >> n;
	std::cout << flipRightmostSetBit(n);
}
