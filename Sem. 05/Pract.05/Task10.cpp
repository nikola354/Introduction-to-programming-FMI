// Задача 10: Напишете програма, която по подадени 3 цели числа a, b и k прехвърля последните k цифри на a в началото на b.
#include <iostream>
int getNumLength(int num);
int pow(int number, int power);
void moveKDigitsToBeginning(int& a, int& b, int k);

int main() {
    std::cout << "Enter two number [a b] and how many nums from a's end to move the b's beginning [k]: ";
    int a, b, k;
    std::cin >> a >> b >> k;
    std::cout << "\n";
    moveKDigitsToBeginning(a, b, k);
}


int getNumLength(int num) {
	int numDigits = 0;
	for (int temp = num; temp > 0; temp /= 10)
		numDigits++;
	return numDigits;
}

int pow(int number, int power) {
	if (power == 0) return 1;

	for (int i = number; power > 1; power--)
		number *= i;
	return number;
}

void moveKDigitsToBeginning(int& a, int& b, int k) {
	int aLastDigits = 0, power = 1, bDigitCount = getNumLength(b);
	while (k > 0) {
		aLastDigits += (a % 10) * power;
		power *= 10;
		a /= 10;
		k--;
	}
	b = aLastDigits * pow(10, bDigitCount) + b;
	std::cout << a << " " << b;
}
