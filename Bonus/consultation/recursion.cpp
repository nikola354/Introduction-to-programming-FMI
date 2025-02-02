#include <iostream>

using namespace std;

bool findPath(int currentI, int currentJ, const bool *const* labyrinth, int n, int m, bool **visited) {
    if (currentI >= n || currentJ >= m) {
        return false;
    }

    if (!labyrinth[currentI][currentJ] || visited[currentI][currentJ]) {
        return false;
    }

    if (currentI == n - 1 && currentJ == m - 1) {
        return true;
    }


    visited[currentI][currentJ] = true;
    return findPath(currentI + 1, currentJ, labyrinth, n, m, visited)
    || findPath(currentI, currentJ + 1, labyrinth, n, m, visited);
}

int main() {


}