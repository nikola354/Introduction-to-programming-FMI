#include <iostream>


int main()
{
	int numToCheck,sum = 0;
	std::cin >> numToCheck;

	int current = 0;
	while (current != -1) {
		int res = numToCheck > current ? current : numToCheck;
		while (res > 1) {
			if (numToCheck % res == 0 && current % res == 0) {
				break;
			}
			res--;
		}
		if (res == 1) {
			sum += current;
		}
		std::cin >> current;
	}
	std::cout << sum;
}