#include <iostream>

using namespace std;

void an(double& a, int n) {
	double c;

	for (int i = 1; i <= n; i++) {
		c = (a * 3) / 2;
		a = c;
	}
}

bool isRowEvenOrOdd(int n) {
	double a = 1.0;

	an(a, n);

	int number = a;
	return number % 2 == 0;
}

int main() {
	int n;
	cin >> n;

	if (isRowEvenOrOdd(n)) {
		cout << "is even";
	}
	else {
		cout << "not even";
	}

	return 0;
}
