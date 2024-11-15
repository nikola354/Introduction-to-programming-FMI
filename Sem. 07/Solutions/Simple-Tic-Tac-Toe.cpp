#include <iostream>

using namespace std;

const int SIZE = 3;
const char DEFAULT_CHAR = '-';
const char FIRST_PLAYER_SYMBOL = 'X';
const char SECOND_PLAYER_SYMBOL = '0';


void print(const char board[][SIZE]);

void initializeBoard(char board[][SIZE], char value);

void readValidCoordinates(const char board[][SIZE], int &i, int &j);

bool areCoordinatesValid(const char board[][SIZE], int i, int j);

bool hasWinner(const char board[][SIZE]);

bool hasWinnerOnRows(const char board[][SIZE]);

bool hasWinnerOnCols(const char board[][SIZE]);

bool hasWinnerOnMainDiagonal(const char board[][SIZE]);

bool hasWinnerOnSecondDiagonal(const char board[][SIZE]);

char getPlayer(bool isFirstPlayer);

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board, DEFAULT_CHAR);

    bool isFirstPlayer = true;

    for (int roundCounter = 0; roundCounter < SIZE * SIZE; roundCounter++) {
        print(board);
        cout << "It's " << getPlayer(isFirstPlayer) << " turn" << endl;

        int i, j;
        readValidCoordinates(board, i, j);

        board[i][j] = getPlayer(isFirstPlayer);

        if (roundCounter >= 2 * SIZE - 2 && hasWinner(board)) {
            print(board);
            cout << "Player " << getPlayer(isFirstPlayer) << " has won!" << endl;
            return 0;
        }

        isFirstPlayer = !isFirstPlayer;
    }

    cout << "Tie!" << endl;

    return 0;
}

void print(const char board[][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void initializeBoard(char board[][SIZE], char value) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = value;
        }
    }
}

void readValidCoordinates(const char board[][SIZE], int &i, int &j) {
    do {
        cout << "Enter valid coordinates: " << endl;
        cin >> i >> j;
    } while (!areCoordinatesValid(board, i, j));
}

bool areCoordinatesValid(const char board[][SIZE], int i, int j) {
    if (i < 0 || j < 0 || i >= SIZE || j >= SIZE) {
        return false;
    }

    return board[i][j] == DEFAULT_CHAR;
}

bool hasWinner(const char board[][SIZE]) {
    return hasWinnerOnRows(board) || hasWinnerOnCols(board)
    || hasWinnerOnMainDiagonal(board) || hasWinnerOnSecondDiagonal(board);
}

bool hasWinnerOnRows(const char board[][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        bool hasWinner = true;

        for(int j = 0; j < SIZE - 1; j++) {
            if (board[i][j] == DEFAULT_CHAR || board[i][j] != board[i][j + 1]) {
                hasWinner = false;
                break;
            }
        }

        if (hasWinner) {
            return true;
        }
    }

    return false;
}

bool hasWinnerOnCols(const char board[][SIZE]) {
    for (int j = 0; j < SIZE; ++j) {
        bool hasWinner = true;

        for(int i = 0; i < SIZE - 1; i++) {
            if (board[i][j] == DEFAULT_CHAR || board[i][j] != board[i + 1][j]) {
                hasWinner = false;
                break;
            }
        }

        if (hasWinner) {
            return true;
        }
    }

    return false;
}

bool hasWinnerOnMainDiagonal(const char board[][SIZE]) {
    for(int i = 0; i < SIZE - 1; i++) {
        if (board[i][i] == DEFAULT_CHAR || board[i][i] != board[i + 1][i + 1]) {
            return false;
        }
    }

    return true;
}

bool hasWinnerOnSecondDiagonal(const char board[][SIZE]) {
    for(int i = 0, j = SIZE - 1; i < SIZE - 1 && j > 0; i++, j--) {
        if (board[i][j] == DEFAULT_CHAR || board[i][j] != board[i + 1][j - 1]) {
            return false;
        }
    }

    return true;
}

char getPlayer(bool isFirstPlayer) {
    return isFirstPlayer ? FIRST_PLAYER_SYMBOL : SECOND_PLAYER_SYMBOL;
}