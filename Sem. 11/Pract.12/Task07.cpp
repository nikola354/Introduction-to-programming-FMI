#include <iostream>
using namespace std;

void swapRows(int** matrix, int from, int to);

void swapPlayers(int* players, int from, int to);

void initializeMatrix(int** matrix, int teams, int* players);

int** createMatrix(int teams, int* players);

int getSum(const int* const* matrix, int row, int players);

void printMatrix(const int* const* matrix, int teams, int* players);

void reorderMatrix(int** matrix, int currentTeam, int* players);

void enterPoints(int** matrix, int teams, int* players);

void freeMatrix(const int* const* matrix, int rows);

int main() {
    int teams;
    cin >> teams;

    int* players = new int [teams];

    int** matrix = createMatrix(teams, players);

    printMatrix(matrix, teams, players);

    enterPoints(matrix, teams, players);

    freeMatrix(matrix, teams);
    delete[] players;
    return 0;
}

void swapRows(int** matrix, int from, int to) {
    if (!matrix) {
        return;
    }

    int* temp = matrix[from];
    matrix[from] = matrix[to];
    matrix[to] = temp;
}

void swapPlayers(int* players, int from, int to) {
    if (!players) {
        return;
    }

    int tempPl = players[from];
    players[from] = players[to];
    players[to] = tempPl;
}

void initializeMatrix(int** matrix, int teams, int* players) {
    if (!matrix || !players) {
        return;
    }

    for (int i = 0; i < teams; i++) {
        int pl;
        cin >> pl;

        matrix[i] = new int [pl];
        players[i] = pl;

        for (int j = 0; j < pl; j++) {
            matrix[i][j] = 0;
        }
    }
}

int** createMatrix(int teams, int* players) {
    int** matrix = new int* [teams];

    initializeMatrix(matrix, teams, players);

    return matrix;
}

int getSum(const int* const* matrix, int row, int players) {
    if (!matrix) {
        return 0;
    }

    int sum = 0;

    for (int i = 0; i < players; i++) {
        sum += matrix[row][i];
    }

    return sum;
}

void printMatrix(const int* const* matrix, int teams, int* players) {
    if (!matrix || !players) {
        return;
    }

    for (int i = 0; i < teams; i++) {
        for (int j = 0; j < players[i]; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void reorderMatrix(int** matrix, int currentTeam, int* players) {
    if (!matrix || !players) {
        return;
    }

    for (int i = currentTeam; i > 0; i--) {
        int sumCurrent = getSum(matrix, i, players[i]);
        int sumPrevious = getSum(matrix, i - 1, players[i - 1]);

        if (sumCurrent > sumPrevious) {
            swapRows(matrix, i, i - 1);
            swapPlayers(players, i, i - 1);
        } else {
            break;
        }
    }
}

void enterPoints(int** matrix, int teams, int* players) {
    if (!matrix || !players) {
        return;
    }

    while (true) {
        int team, player, points;
        cin >> team >> player >> points;

        if (team < 0 || team > teams) {
            cout << "Error" << endl;
            continue;
        }

        if (player < 0 || player > players[team]) {
            cout << "Error" << endl;
            continue;
        }

        matrix[team][player] += points;

        reorderMatrix(matrix, team, players);

        printMatrix(matrix, teams, players);
    }
}

void freeMatrix(const int* const* matrix, int rows) {
    if (!matrix) {
        return;
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}
