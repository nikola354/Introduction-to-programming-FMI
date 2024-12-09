#include <iostream>
using namespace std;

int myPow(int a, int k) {
    int result = 1;
    for (int i = 0; i < k; i++) {
        result *= a;
    }
    return result;
}

int count_digits(int num) {
    int count = 0;
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}


bool check_concatenation(int N, int K) {
    int digits = count_digits(K);
    int power = myPow(10, digits);

    N /= 10; //guarantee that B is not empty

    while (N >= K) {
        if (N % power == K) {
            int A = N / power;

            if (A >= 0) {
                return true;
            }
        }
        N /= 10;
    }

    return false;
}

int main() {
    int N, K;

    cin >> N;
    cin >> K;

    if (N <= 0 || K <= 0) {
        return 0;
    }


    cout << check_concatenation(N, K);

    return 0;
}