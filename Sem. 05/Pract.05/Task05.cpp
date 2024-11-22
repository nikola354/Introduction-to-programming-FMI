#include <iostream>

using namespace std;

void concat(int& n, int digit) {
	n = n * 10 + digit;
}

void setKthdigit(int& number, int k, int newDigit) {
	int digit, reversed = 0;

	for (int i = 1; i <= k; i++) {
		digit = number % 10;
		number /= 10;
		if (i == k) digit = newDigit;
		concat(reversed, digit);
	}

	while (reversed != 0) {
		digit = reversed % 10;
		concat(number, digit);
		reversed /= 10;
	}
}

int findK(int number, int k) {
	for (int i = 1; i < k; i++) {
		number /= 10;
	}

	return number % 10;
}

void reverse(int& number) {
	int reversedNum = 0;
	int n = number;

	while (n != 0) {
		int digit = n % 10;
		concat(reversedNum, digit);
		n /= 10;
	}
	
	number = reversedNum;
}

void swapDigits(int& m, int& n, int k) {
	reverse(m); 
	reverse(n);

	int km = findK(m, k);
	int kn = findK(n, k);

	setKthdigit(n, k, km); 
	setKthdigit(m, k, kn);

	reverse(m); 
	reverse(n);
}

int main() {
	int m, n, k;
	cin >> m >> n >> k;

	swapDigits(m, n, k);

	cout << m << " " << n;

	return 0;
}
