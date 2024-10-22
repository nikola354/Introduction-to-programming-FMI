#include <iostream>

int main()
{
	int k, current, suffixCounter = 0, maxSuffix;
	std::cin >> k;
	std::cin >> current;
	maxSuffix = current;
	while (current != 0) {
		if (k - current % 10) {
			suffixCounter++;
			if (current > maxSuffix) {
				maxSuffix = current;
			}
		}
		std::cin >> current;
	}
	std::cout << suffixCounter << std::endl;
	std::cout << maxSuffix << std::endl;
}