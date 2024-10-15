#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int firstDigit = n / 1000;
	n %= 1000;
	int secondDigit = n / 100;
	n %= 100;
	int thirdDigit = n / 10;
	n %= 10;
	int fourthDigit = n;

	int firstNum = firstDigit * 10 + fourthDigit;
	int secondNum = secondDigit * 10 + thirdDigit;

	if (firstNum< secondNum) {
		cout << "Less";
	}
	else if (firstNum == secondNum) {
		cout << "Equal";
		}

}
