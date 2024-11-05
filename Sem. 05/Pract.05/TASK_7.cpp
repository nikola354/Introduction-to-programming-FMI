// TASK_7.cpp :
#include <iostream>

void An_even(int n) {

	double a = 1.0;

	for (int i = 1; i <= n; i++) {
		a = (a * 3) / 2;
	}
	int integer_a = a;

	if (integer_a % 2 == 0) {
	std::cout << "EVEN";	
	}
	else { std::cout << "UNEven"; }
}
int main() {
	int n;
	std::cin >> n;

	An_even(n);
}
