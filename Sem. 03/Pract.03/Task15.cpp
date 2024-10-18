#include <iostream>

int main()
{
	int k = 0;
	std::cin >> k;

	int num = 0;
	std::cin >> num;

	int count = 0, maxSuffix = 0;

	while (num != 0)
	{
		int copyK = k, copyNum = num;
		bool isSuffix = true;

		while (copyNum != 0)
		{
			int lastKDigit = copyK % 10;
			int lastNumDigit = copyNum % 10;

			if (lastKDigit != lastNumDigit)
			{
				isSuffix = false;
			}

			copyNum /= 10;
			copyK /= 10;
		}

		if (isSuffix)
		{
			std::cout << num << " is suffix of " << k << std::endl;
			count++;

			if (num > maxSuffix)
			{
				maxSuffix = num;
			}
		}
		else
		{
			std::cout << num << " is not suffix of " << k << std::endl;
		}

		std::cin >> num;
	}

	std::cout << "Found suffix count: " << count << std::endl;
	std::cout << "Max suffix: " << maxSuffix << std::endl;

	return 0;
}