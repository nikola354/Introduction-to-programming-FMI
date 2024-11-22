
#include <iostream>
using namespace std;
constexpr int SIZE = 8;

constexpr int QUEUE_SIZE = 100;

bool isValid(int x, int y, int size) {
	return (x >= 0 && y >= 0 && x < size && y < size);
}


int shortestPathBetweenTwoPoints(int board[][SIZE], size_t size, int x1, int y1, int endX, int endY) {

	int horseMovesX[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
	int horseMovesY[] = { 1, -1, 1, -1, 2, -2, -2, 2 };

	if (x1 == endX && y1 == endY) {
		return 0;
	}

	board[size][size] = { 0 };

	int queueX[QUEUE_SIZE], queueY[QUEUE_SIZE];
	int back = 0, front = 0;

	queueX[back] = x1; 
	queueY[back] = y1;

	back++;


	bool visitedPoints[SIZE][SIZE] = { false };
	visitedPoints[x1][y1] = true;


	while (back >= front) {
		int currentX = queueX[front];
		int currentY = queueY[front];

		front++;

		for (int i = 0; i < size; i++) {
			int newX = currentX + horseMovesX[i];
			int newY = currentY + horseMovesY[i];

			if (isValid(newX, newY, SIZE) && !visitedPoints[newX][newY]) {
				board[newX][newY] = board[currentX][currentY] + 1;

				if (newX == endX && newY == endY) {
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
	int startX, startY, endX, endY = 0;

	int board[][SIZE] = { 0 };

	cin >> startX >> startY >> endX >> endY;

	int shortesPath = shortestPathBetweenTwoPoints(board, SIZE, startX, startY, endX, endY);



	cout << shortesPath << endl;

}

