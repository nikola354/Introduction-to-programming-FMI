#include <iostream>;

unsigned powerOfTwo(unsigned power)
{
	if (power > 31)
		return 0;

	return 1 << power;
}

unsigned getNumFromBits(unsigned number, unsigned startIndex, unsigned length) 
{
	// shift само ако има смисъл, cast защото иначе unsigned overflows
	if (startIndex > length)
		number = number >> startIndex - length + 1;
	// намали дължината така че да вземе само останалите цифри
	else
		length = startIndex;

	// степен на двойката 2^k 0001 0000, k = 4
	// вадим 1 -> 0000 1111
	unsigned mask = powerOfTwo(length) - 1; // 0000 1111

	// побитово &
	// 1011 1001
	// 0000 1111
	return number & mask;
}

int main()
{
	unsigned x, m, n;
	std::cin >> x >> m >> n;
	std::cout << getNumFromBits(x, m, n);
}
