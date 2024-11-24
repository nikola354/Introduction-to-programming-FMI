#include <iostream>

constexpr size_t N = 50;
constexpr size_t CLOCK_SIZE = 3;

void readMatrix(int mtx[][N], size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cin >> mtx[i][j];
		}
	}
}

int getRowSummation(const int mtx[][N], size_t row, size_t startX, size_t endX)
{
	int rowSum = 0;

	for (size_t i = startX; i <= endX; i++)
	{
		rowSum += mtx[row][i];
	}

	return rowSum;
}

// This way our code is working for arbitrary size of the sand clock
// Depending on what we give in CLOCK_SIZE
int calculateSandClockSummation(const int mtx[][N], size_t startX, size_t endX, size_t startY, size_t endY)
{
	int sum = 0;

	size_t i, j;

	for (i = startY, j = endY; i != j; i++, j--)
	{
		sum += getRowSummation(mtx, i, startX, endX) + getRowSummation(mtx, j, startX, endX);
		startX++;
		endX--;
	}

	return sum + mtx[i][startX];
}

void findSandClocks(const int mtx[][N], size_t rows, size_t cols,
	size_t& centerX, size_t& centerY, int& maximumSummation)
{
	size_t outset = CLOCK_SIZE / 2;
	size_t start = outset;
	size_t end = rows - outset;

	for (size_t i = start; i < end; i++)
	{
		for (size_t j = start; j < end; j++)
		{
			int sum = calculateSandClockSummation(mtx, j - outset, j + outset, i - outset, i + outset);

			if (sum > maximumSummation)
			{
				maximumSummation = sum;
				centerX = j;
				centerY = i;
			}
		}
	}
}

int main()
{
	size_t ROWS = 0, COLUMNS = 0;
	std::cin >> ROWS >> COLUMNS;

	int mtx[N][N]{ 0 };

	readMatrix(mtx, ROWS, COLUMNS);

	size_t centerX = 0, centerY = 0;
	int maximumSummation = INT_MIN;

	findSandClocks(mtx, ROWS, COLUMNS, centerX, centerY, maximumSummation);

	std::cout << "Row: " << centerY << std::endl;
	std::cout << "Column: " << centerX << std::endl;
	std::cout << "Sum: " << maximumSummation << std::endl;

	return 0;
}