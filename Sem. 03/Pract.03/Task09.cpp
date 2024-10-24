#include <iostream>

int main()
{
	int num = 0;
	std::cin >> num;

	if (num < 0) num *= -1;

	int bound = num / 2;

	for (int i = 2; i <= bound; i++)
	{
		int x = i;

		bool isPrimeX = true;
		double xSqrt = sqrt(x);

		for (int i = 2; i <= xSqrt; i++)
		{
			if (x % i == 0)
			{
				isPrimeX = false;
				break;
			}
		}

		if (!isPrimeX) continue;

		int y = num - i;

		bool isPrimeY = true;
		double ySqrt = sqrt(y);

		for (int i = 2; i <= ySqrt; i++)
		{
			if (y % i == 0)
			{
				isPrimeY = false;
				break;
			}
		}

		if (isPrimeY)
		{
			std::cout << num << " = " << x << " + " << y << std::endl;
		}
	}

	return 0;
}
