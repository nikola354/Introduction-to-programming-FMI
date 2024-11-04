#include <iostream>
using namespace std;

int getDigitsCount(int n) {
	if (n == 0)
		return 1;

	int count = 0;
	while (n != 0) {
		count++;
		n /= 10;
	}
	return count;

}

int getSumOfDigits(int n) {
	int sum = 0;
	while (n != 0) {
		int lastDigit = n % 10;
		sum += lastDigit;
		n /= 10;
	}

	return sum;
}

double getArithmeticMean(int n) {
	int sumOfDigits = getSumOfDigits(n);
	int countOfDigits = getDigitsCount(n);
	double arithmeticMean = sumOfDigits / countOfDigits;

	return arithmeticMean;
}

void checkNums(int m, int n, int k) {
	if (n < m || m <= 0 || n>1000000 || k <= 0 || k >= 10)
		return;

	for (int i = m; i <= n; i++) {
		double arithmeticMean = getArithmeticMean(i);
		if (arithmeticMean >= k)
			cout << i << " ";
	}
}
int main()
{
	int m; int n; int k;
	cin >> m >> n >> k;

	checkNums(m, n, k);

}