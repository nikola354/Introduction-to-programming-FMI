#include <iostream>

int digitsInNum(int num) {
    int count = 0;

    while (num != 0) {
        count++;
        num /= 10;
    }

    return count;
}

int sumOfDigitsInNum(int num) {
    int sum = 0;

    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int aritmeticMean(int num) {
    return sumOfDigitsInNum(num) / digitsInNum(num);
}

bool aritmeticMeanGreaterOrEqual(int num, int k) {
    return aritmeticMean(num) >= k;
}

void run() {
    int m, n, k;
    std::cin >> m >> n >> k;
    
    for (int i = m; i <= n; i++) {
        if (aritmeticMeanGreaterOrEqual(i, k)) std::cout << i << " ";
    }
}

int main() {
    run();
}

