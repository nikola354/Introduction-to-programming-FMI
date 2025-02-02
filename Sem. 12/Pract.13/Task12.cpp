#include <iostream>

bool isValid(int **mtx, int rows, int cols, int row, int col, bool ** visited) {
    return row >= 0 && row < rows && col >= 0 && col < cols && mtx[row][col] == 1 && !visited[row][col];
}

bool canReachEnd(int **mtx, int rows, int cols, int startRow, 
    int startCol, int endRow, int endCol, bool **visited) {

    if (startRow == endRow && startCol == endCol)
        return true;

    visited[startRow][startCol] = true;

    int dRow[] = {1, -1, 0, 0};
    int dCol[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
        int currRow = startRow + dRow[i];
        int currCol = startCol + dCol[i];

        if (isValid(mtx, rows, cols, currRow, currCol, visited) &&
            canReachEnd(mtx, rows, cols, currRow, currCol, endRow, endCol, visited))
            return true;
    }

    return false;
}

int main() {
    int rows, cols;
    std::cin >> rows >> cols;

    int **mtx = new int *[rows];
    bool **visited = new bool *[rows];

    for (int i = 0; i < rows; i++) {
        mtx[i] = new int[cols];
        visited[i] = new bool[cols]();
        
        for (int j = 0; j < cols; j++)
            std::cin >> mtx[i][j];
    }

    int startRow = 0, startCol = 0, endRow = rows - 1, endCol = cols - 1;
    std::cout << std::boolalpha << canReachEnd(mtx, rows, cols, startRow, startCol, endRow, endCol, visited);

    for (int i = 0; i < rows; i++) {
        delete[] mtx[i];
        delete[] visited[i];
    }
    delete[] mtx;
    delete[] visited;

    return 0;
}
