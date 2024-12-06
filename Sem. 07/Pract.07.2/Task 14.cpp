#include <iostream>

constexpr size_t SIZE = 8;
constexpr size_t QUEUE_SIZE = 100;

bool isValid(int x, int y, int size)
{
	return x >= 0 && y >= 0 && x < size && y < size;
}

int shortestPathBetweenTwoPoints(int board[][SIZE], int startX, int startY, int endX, int endY)
{
	int horseMovesX[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
	int horseMovesY[] = { 1, -1, 1, -1, 2, -2, -2, 2 };

	if (startX == endX && startY == endY)
	{
		return 0;
	}

	int queueX[QUEUE_SIZE], queueY[QUEUE_SIZE];
	int back = 0, front = 0;

	queueX[back] = startX;
	queueY[back] = startY;

	back++;

	bool visitedPoints[SIZE][SIZE] = { false };
	visitedPoints[startX][startY] = true;

	while (back >= front)
	{
		int currentX = queueX[front];
		int currentY = queueY[front];

		front++;

		for (int i = 0; i < SIZE; i++)
		{
			int newX = currentX + horseMovesX[i];
			int newY = currentY + horseMovesY[i];

			if (isValid(newX, newY, SIZE) && !visitedPoints[newX][newY])
			{
				board[newX][newY] = board[currentX][currentY] + 1;

				if (newX == endX && newY == endY)
				{
					return board[newX][newY];
				}

				visitedPoints[newX][newY] = true;

				queueX[back] = newX;
				queueY[back] = newY;

				back++;
			}
		}
	}

	return -1;
}

int main()
{
	int startX = 0, startY = 0, endX = 0, endY = 0;

	int board[SIZE][SIZE] = { 0 };

	std::cin >> startX >> startY >> endX >> endY;

	int shortestPath = shortestPathBetweenTwoPoints(board, startX, startY, endX, endY);

	std::cout << shortestPath << std::endl;

	return 0;
}
