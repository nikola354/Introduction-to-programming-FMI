#include <iostream>

using namespace std;

void concat(int& num, int digit)
{
	num = num * 10 + digit;
}

int reverse(int number) {
	int res = 0;

	while (number != 0) {
		int digit = number % 10;
		concat(res, digit);
		number /= 10;
	}

	return res;
}

void evensAndOdds(int num, int& evens, int& odds)
{
	int reversed = reverse(num);
	int idx = 1;

	while (reversed != 0) {
		int lastDigit = reversed % 10;

		if (idx % 2 == 0) {
			concat(evens, lastDigit);
		}
		else {
			concat(odds, lastDigit);
		}

		idx++;
		reversed /= 10;
	}
}

int main() {
	int a;
	cin >> a;

	int evens = 0, odds = 0;

	evensAndOdds(a, evens, odds);

	std::cout << evens << " " << odds << std::endl;

	return 0;
}
