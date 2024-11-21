#include <iostream>

constexpr unsigned	MAX_SIZE = 10;

// Read/Write methods
bool validateInput(size_t &rows, size_t &cols);
void readMatrix(int mtx[][MAX_SIZE], size_t rows, size_t cols);
void printMatrix(const int mtx[][MAX_SIZE], size_t rows, size_t cols);

// Matrix operations
bool isMatrixSymmetrical(const int mtx[][MAX_SIZE], size_t rows, size_t cols);


int main()
{
    int mtx[MAX_SIZE][MAX_SIZE];

	size_t rows, cols;
    if (!validateInput(rows, cols))
        return -1;
	std::cout << "Enter matrix one: \n";
	readMatrix(mtx, rows, cols);

	std::cout << "Matrix is symmetrical: " << std::boolalpha << isMatrixSymmetrical(mtx, rows, cols) << "\n";
}

bool validateInput(size_t &rows, size_t &cols) {
    std::cout << "Enter valid dimensions of matrix: ";
	std::cin >> rows >> cols;

    if (rows > MAX_SIZE || rows < 0 || cols >MAX_SIZE || cols < 0)
        return false;

    return true;
}

void readMatrix(int mtx[][MAX_SIZE], size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			std::cin >> mtx[i][j];
}

bool isMatrixSymmetrical(const int mtx[][MAX_SIZE], size_t rows, size_t cols) {
	// only square matrixes can be symmetrical
	if (rows != cols)
		return false;

	for (size_t i = 1; i < rows; i++)
		for (size_t j = i + 1; j < cols; j++)
			if (mtx[i][j] != mtx[j][i])
				return false;

	return true;
}
