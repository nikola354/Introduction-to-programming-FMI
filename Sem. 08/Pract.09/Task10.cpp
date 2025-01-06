#include <iostream>

constexpr unsigned	MAX_SIZE = 10;
// Read/Write methods
void readMatrix(int mtx[][MAX_SIZE], size_t rows, size_t cols);
void printMatrix(const int mtx[][MAX_SIZE], size_t rows, size_t cols);
bool validateInput(size_t &rows, size_t &cols);

// Matrix operations
bool canMatrixesBeMultiplied(size_t cols1, size_t rows2);
int rowByColumn(const int mtx1[][MAX_SIZE], size_t cols1, const int mtx2[][MAX_SIZE],
	size_t rowIndex, size_t colIndex);
void multiplyMatrixes(const int mtx1[][MAX_SIZE], size_t rows1, size_t cols1,
	const int mtx2[][MAX_SIZE], size_t rows2, size_t cols2,
	int resultMtx[][MAX_SIZE], size_t resRows, size_t resCols);
bool canMatrixesBeSummed(size_t rows1, size_t cols1, size_t rows2, size_t cols2);
void sumMatrixes(const int mtx1[][MAX_SIZE], size_t rows1, size_t cols1, const int mtx2[][MAX_SIZE],	
    int resultMtx[][MAX_SIZE], size_t resRows, size_t resCols);
void subtractMatrixes(const int mtx1[][MAX_SIZE], size_t rows1, size_t cols1, const int mtx2[][MAX_SIZE],
	int resultMtx[][MAX_SIZE], size_t resRows, size_t resCols);

int main()
{
	int mtx1[MAX_SIZE][MAX_SIZE];
	int mtx2[MAX_SIZE][MAX_SIZE];
	int resultMtx[MAX_SIZE][MAX_SIZE];

	size_t rows1, cols1;
    if (!validateInput(rows1, cols1))
        return -1;
	std::cout << "Enter matrix one: \n";
	readMatrix(mtx1, rows1, cols1);

	size_t rows2, cols2;
    if (!validateInput(rows2, cols2))
        return -1;
	std::cout << "Enter matrix one: \n";
	readMatrix(mtx2, rows2, cols2);

    if (canMatrixesBeSummed(rows1, cols1, rows2, cols2)) {

		sumMatrixes(mtx1, rows1, cols1, mtx2, resultMtx, rows1, cols2);
		std::cout << "Sum of matrix one and matrix two: " << "\n";
		printMatrix(resultMtx, rows1, cols2);

   		subtractMatrixes(mtx1, rows1, cols1, mtx2, resultMtx, rows1, cols2);
		std::cout << "Subtraction of matrix one and matrix two: " << "\n";
		printMatrix(resultMtx, rows1, cols2);
	}
    else {
        std::cout << "Sum or substraction of matrix one and matrix two is impossible " << "\n";
    }

	if (canMatrixesBeMultiplied(cols1, rows2)) {
		multiplyMatrixes(mtx1, rows1, cols1, mtx2, rows2, cols2, resultMtx, rows1, cols2);
		std::cout << "Multiplication of matrix one and matrix two: " << "\n";
		printMatrix(resultMtx, rows1, cols2);
	}
    else {
        std::cout << "Multiplication of matrix one and matrix two is impossible " << "\n";
    }
}

bool validateInput(size_t &rows, size_t &cols) {
    std::cout << "Enter valid dimensions of matrix: ";
	std::cin >> rows >> cols;

    if (rows > MAX_SIZE || rows < 0 || cols > MAX_SIZE || cols < 0)
        return false;

    return true;
}

void readMatrix(int mtx[][MAX_SIZE], size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			std::cin >> mtx[i][j];
}

bool canMatrixesBeMultiplied(size_t cols1, size_t rows2) {
	return cols1 == rows2;
}

bool canMatrixesBeSummed(size_t rows1, size_t cols1, size_t rows2, size_t cols2) {
	return rows1 == rows2 && cols1 == cols2;
}

int rowByColumn(const int mtx1[][MAX_SIZE], size_t cols1, const int mtx2[][MAX_SIZE],
	size_t rowIndex, size_t colIndex) {
	
    int result = 0;

for (size_t i = 0; i < cols1; i++)  // Iterate over columns of mtx1 and rows of mtx2
        result += mtx1[rowIndex][i] * mtx2[i][colIndex];
    return result;
}

void multiplyMatrixes(const int mtx1[][MAX_SIZE], size_t rows1, size_t cols1,
	const int mtx2[][MAX_SIZE], size_t rows2, size_t cols2,
	int resultMtx[][MAX_SIZE], size_t resRows, size_t resCols) {

	for (size_t i = 0; i < resRows; i++)
		for (size_t j = 0; j < resCols; j++)
			resultMtx[i][j] = rowByColumn(mtx1, cols1, mtx2, i, j);
}

void sumMatrixes(const int mtx1[][MAX_SIZE], size_t rows1, size_t cols1, const int mtx2[][MAX_SIZE],
	int resultMtx[][MAX_SIZE], size_t resRows, size_t resCols) {

	for (size_t i = 0; i < rows1; i++)
		for (size_t j = 0; j < cols1; j++)
			resultMtx[i][j] = mtx1[i][j] + mtx2[i][j];
}

void subtractMatrixes(const int mtx1[][MAX_SIZE], size_t rows1, size_t cols1, const int mtx2[][MAX_SIZE],
	int resultMtx[][MAX_SIZE], size_t resRows, size_t resCols) {

	for (size_t i = 0; i < rows1; i++)
		for (size_t j = 0; j < cols1; j++)
			resultMtx[i][j] = mtx1[i][j] - mtx2[i][j];
}

void printMatrix(const int mtx[][MAX_SIZE], size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++)
			std::cout << mtx[i][j] << ", ";

		std::cout << "\n";
	}
}