#include <iostream>

int main()
{
	int num = 0, reversed = 0;
	std::cin >> num;

	while (num != 0)
	{
		int lastDigit = num % 10;
		(reversed *= 10) += lastDigit;
		num /= 10;
	}

	int idx = 1;

	while (reversed != 0)
	{
		int lastDigit = reversed % 10;

		if (idx++ % 2 == 0)
		{
			std::cout << lastDigit << " ";
		}

		reversed /= 10;
	}

	return 0;
}
