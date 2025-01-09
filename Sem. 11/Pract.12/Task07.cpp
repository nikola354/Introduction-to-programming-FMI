#include <iostream>
using namespace std;

void initializeMatrix(int** matrix, int teams, int* players);

int getSum(const int* const* matrix, int row, int players);

void sortMatrix(int** matrix, int teams, int* players);

void printMatrix(int** matrix, int teams, int* players);

void enterPoints(int** matrix, int teams, int* players);

int main() {
    int teams;
    cin >> teams;

    int** matrix = new int* [teams];
    int* players = new int [teams];

    initializeMatrix(matrix, teams, players);

    printMatrix(matrix, teams, players);

    enterPoints(matrix, teams, players);

    for (int i = 0; i < teams; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
    delete[] players;
    return 0;
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

void sortMatrix(int** matrix, int teams, int* players) {
    if (!matrix || !players) {
        return;
    }

    for (int i = 0; i < teams - 1; i++) {
        int sum = getSum(matrix, i, players[i]);
        int maxIndex = i;

        for (int k = i + 1; k < teams; k++) {
            int currentSum = getSum(matrix, k, players[k]); 

            if (currentSum > sum) {
                maxIndex = k;
            }
        }

        if (maxIndex != i) {
            int* temp = matrix[i];
            matrix[i] = matrix[maxIndex];
            matrix[maxIndex] = temp;

            int tempPl = players[i];
            players[i] = players[maxIndex];
            players[maxIndex] = tempPl;
        }
    }

}

void printMatrix(int** matrix, int teams, int* players) {
    if (!matrix || !players) {
        return;
    }

    sortMatrix(matrix, teams, players);

    for (int i = 0; i < teams; i++) {
        for (int j = 0; j < players[i]; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
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
        printMatrix(matrix, teams, players);
    }
}
