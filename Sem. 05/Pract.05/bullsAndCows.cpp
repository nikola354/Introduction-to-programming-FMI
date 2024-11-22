#include <iostream>

const unsigned int DIGIT_COUNT = 4;

unsigned int countDigitOccurences(unsigned int n, unsigned int digit)
{
	if (n == 0 && digit == 0) return 1;

	unsigned int count = 0;

	while (n != 0)
	{
		unsigned lastDigit = n % 10;

		if (lastDigit == digit)
		{
			count++;
		}

		n /= 10;
	}

	return count;
}

bool areDistinctDigits(unsigned int n)
{
	for (unsigned int i = 0; i <= 9; i++)
	{
		if (countDigitOccurences(n, i) > 1)
		{
			return false;
		}
	}

	return true;
}

unsigned int digitsCount(unsigned int n)
{
	if (n == 0) return 1;

	unsigned int count = 0;

	while (n != 0)
	{
		count++;
		n /= 10;
	}

	return count;
}

bool isValidInput(unsigned int n)
{
	return areDistinctDigits(n) && digitsCount(n) == DIGIT_COUNT;
}

unsigned int getBulls(unsigned int toGuess, unsigned int myGuess)
{
	unsigned int bullsCount = 0;

	while (toGuess != 0)
	{
		if (toGuess % 10 == myGuess % 10)
		{
			bullsCount++;
		}

		toGuess /= 10;
		myGuess /= 10;
	}

	return bullsCount;
}

unsigned int getBullsAndCowsSum(unsigned int toGuess, unsigned int myGuess)
{
	unsigned int sum = 0;

	while (toGuess != 0)
	{
		unsigned int lastDigit = toGuess % 10;

		if (countDigitOccurences(myGuess, lastDigit) == 1)
		{
			sum++;
		}

		toGuess /= 10;
	}

	return sum;
}

void getBullsAndCows(unsigned int toGuess, unsigned int myGuess, unsigned int& bulls, unsigned int& cows)
{
	bulls = getBulls(toGuess, myGuess);
	cows = getBullsAndCowsSum(toGuess, myGuess) - bulls;
}

unsigned int input()
{
	unsigned int n = 0;

	do
	{
		std::cin >> n;
	} while (!isValidInput(n));

	return n;
}

void runGame()
{
	unsigned int toGuess = input();
	std::cout << "Success! You provided a valid secret code!" << std::endl;

	unsigned int bulls = 0, cows = 0;

	do
	{
		unsigned int myGuess = input();

		getBullsAndCows(toGuess, myGuess, bulls, cows);

		std::cout << "Bulls: " << bulls << " Cows: " << cows << std::endl;
	} while (bulls != DIGIT_COUNT);

	std::cout << "Congratulations! You guessed the secret code: " << toGuess << std::endl;
}

int main()
{
	runGame();

	return 0;
}
