// Задача 9: Да се състави програма, която по зададен интервал [K,L] (K и L цели положителни числа не по-големи от 100000) 
// отпечатва всички числа в интервала [K,L], които имат две съседни еднакви цифри в записа си.
#include <iostream>

void swap(int& a, int& b);
void getNumsWithTwoAdjacentEqualDigits(int k, int l);

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

void getNumsWithTwoAdjacentEqualDigits(int k, int l) {
	if (k > l) swap(k, l);

	for (int num = k; num <= l; num++) {
		int current = num;
		bool hasAdjacentEqual = false;

		while (current >= 10) {
			int lastDigit = current % 10;
			int secondLastDigit = (current / 10) % 10;

			if (lastDigit == secondLastDigit) {
				hasAdjacentEqual = true;
				break;
			}
			current /= 10;
		}

		if (hasAdjacentEqual)
			std::cout << num << " ";
	}
}