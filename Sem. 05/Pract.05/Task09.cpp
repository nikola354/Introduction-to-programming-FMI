#include <iostream>

void swap(int& a, int& b);
void getNumsWithTwoAdjacentEqualDigits(int k, int l);
bool hasAdjacentDigits(int num);

int main() {
	std::cout << "Enter interval [k l]: ";
	int k, l;
	std::cin >> k >> l;
	std::cout << "\n";
	getNumsWithTwoAdjacentEqualDigits(k, l);
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

bool hasAdjacentDigits(int num) {
	while (num >= 10) {
		int lastDigit = num % 10;
		int secondLastDigit = (num / 10) % 10;

		if (lastDigit == secondLastDigit) {
			return true;
		}
		num /= 10;
	}

	return false;
}

void getNumsWithTwoAdjacentEqualDigits(int k, int l) {
	if (k > l) swap(k, l);

	for (int num = k; num <= l; num++) {
		if (hasAdjacentDigits(num))
		{
			std::cout << num << " ";
		}
	}
}