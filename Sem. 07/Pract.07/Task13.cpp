#include <iostream>

constexpr size_t SIZE = 100;
constexpr char SPECIAL_SYMBOL = '^';

size_t getAbs(int n)
{
	return n >= 0 ? n : -n;
}

double getArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return getAbs(x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1) / 2.00;
}

void fillCoordinates(int coordinatesX[], int coordinatesY[], size_t& symbolsCounter, size_t N, size_t M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char symbol;
			std::cin >> symbol;

			if (symbol == SPECIAL_SYMBOL)
			{
				coordinatesX[symbolsCounter] = i;
				coordinatesY[symbolsCounter] = j;

				symbolsCounter++;
			}
		}
	}
}

size_t countTriangles(const int coordinatesX[], const int coordinatesY[], size_t symbolsCounter)
{
	size_t counter = 0;

	for (size_t i = 0; i < symbolsCounter; i++)
	{
		int x1 = coordinatesX[i];
		int y1 = coordinatesY[i];

		for (size_t j = i + 1; j < symbolsCounter; j++)
		{
			int x2 = coordinatesX[j];
			int y2 = coordinatesY[j];

			for (size_t s = j + 1; s < symbolsCounter; s++)
			{
				int x3 = coordinatesX[s];
				int y3 = coordinatesY[s];

				if (getArea(x1, y1, x2, y2, x3, y3) != 0)
				{
					counter++;
				}

			}
		}
	}

	return counter;
}

void run()
{
	size_t N, M;
	std::cin >> N >> M;

	size_t symbolsCounter = 0;

	int coordinatesX[SIZE];
	int coordinatesY[SIZE];

	fillCoordinates(coordinatesX, coordinatesY, symbolsCounter, N, M);

	std::cout << countTriangles(coordinatesX, coordinatesY, symbolsCounter) << std::endl;
}

int main()
{
	run();

	return 0;
}
