#include <iostream>

using namespace std;

int main()
{
	int sum = 0;

	for (int i = 100; i <= 999; i++)
	{
		int sumDigits = 0;
		int n = i;

		while (n != 0)
		{
			int lastDigit = n % 10;
			sumDigits += lastDigit;
			n /= 10;
		}

		if (sumDigits < 10 || sumDigits > 99) continue;

		bool isPrime = true;

		if (sumDigits < 2) isPrime = false;

		double sqrtn = sqrt(sumDigits);

		for (int j = 2; j <= sqrtn; j++)
		{
			if (sumDigits % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime) sum += i;
	}
	
	cout << sum;
	
	return 0;
}
