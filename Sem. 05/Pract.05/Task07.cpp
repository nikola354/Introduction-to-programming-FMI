#include <iostream>
using namespace std;

void reverseNum(int& num) {
	int result = 0;
	while (num != 0) {
		int lastDigit = num % 10;
		(result *= 10) += lastDigit;
		num /= 10;
	}
	num = result;
}
void newNum(int& number, int i, int k) {
	if (i > k)
		return;

	reverseNum(number);
	int newNum = 0;
	int position = 0;

	while (number != 0) {
		int lastDigit = number % 10;
		if (position >= i && position <= k)
			(newNum *= 10) += lastDigit;

		number /= 10;
		position++;
	}

	number = newNum;
}

int main()
{
	int number; int i; int k;
	cin >> number >> i >> k;

	newNum(number, i, k);
	cout << number;
}

