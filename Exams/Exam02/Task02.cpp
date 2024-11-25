#include <iostream>

constexpr size_t MAX_SIZE = 100;
constexpr size_t CLOCK_SIZE = 3;

bool areValidDimensions(size_t rows, size_t cols)
{
	return rows > 2 && rows < MAX_SIZE && cols > 2 && cols && MAX_SIZE && rows == cols;
}

void readMatrix(int mtx[][MAX_SIZE], size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cin >> mtx[i][j];
		}
	}
}

int getRowSummation(const int mtx[][MAX_SIZE], size_t row, size_t startX, size_t endX)
{
	int rowSum = 0;

	for (size_t i = startX; i <= endX; i++)
	{
		rowSum += mtx[row][i];
	}

	return rowSum;
}

int calculateSandClockSummation(const int mtx[][MAX_SIZE], size_t startX, size_t endX, size_t startY, size_t endY)
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

void findSandClocks(const int mtx[][MAX_SIZE], size_t rows, size_t cols,
	size_t& centerX, size_t& centerY, int& maximumSummation)
{
	size_t outset = CLOCK_SIZE / 2;

	size_t startX = outset, endX = rows - outset;
	size_t startY = outset, endY = cols - outset;

	while (startX < endX && startY < endY)
	{
		int sum = calculateSandClockSummation(mtx, startX - outset, startX + outset, startY - outset, startY + outset);

		if (sum > maximumSummation)
		{
			maximumSummation = sum;
			centerX = startX;
			centerY = startY;
		}

		startX++;

		if (startX == endX)
		{
			startX = 0;
			startY++;
		}
	}
}

void sandClocks()
{
	size_t ROWS = 0, COLUMNS = 0;
	std::cin >> ROWS >> COLUMNS;

	if (!areValidDimensions(ROWS, COLUMNS))
	{
		std::cout << "Invalid matrix dimensions!" << std::endl;
		return;
	}

	int mtx[MAX_SIZE][MAX_SIZE]{ 0 };

	readMatrix(mtx, ROWS, COLUMNS);

	size_t centerX = 0, centerY = 0;
	int maximumSummation = INT_MIN;

	findSandClocks(mtx, ROWS, COLUMNS, centerX, centerY, maximumSummation);

	std::cout << "Row: " << centerY << std::endl;
	std::cout << "Column: " << centerX << std::endl;
	std::cout << "Sum: " << maximumSummation << std::endl;
}

int main()
{
	sandClocks();

	return 0;
}
