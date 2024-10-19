#include <iostream>
int main() {
    int num, n, k, sum, maxDifference = 0;
    std::cin >> num;
    if (num <= 0) return 0;
    std::cin >> n >> k;

    if (n > k) maxDifference = n - k;
    else maxDifference = k - n;

    sum = n + k;
    bool isEqual = true;

    for (int i = 1; i < num; i++) {
        int first, second, currentDifference = 0;
        std::cin >> first >> second;

        if (sum != first + second) {
            if (first > second) currentDifference = first - second;
            else currentDifference = second - first;

            isEqual = false;
            if (currentDifference > maxDifference) maxDifference = currentDifference;
        }
    }

    if (isEqual) std::cout << "Equal sums: " << sum;
    else std::cout << "Different sums. Max Difference: " << maxDifference;
}
