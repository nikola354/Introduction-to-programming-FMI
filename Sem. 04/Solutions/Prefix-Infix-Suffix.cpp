#include <iostream>

bool isSuffix(unsigned int number, unsigned int sufix) {
	if (number < sufix) {
		return false;
	}

	while (sufix != 0) {
		if (number % 10 != sufix % 10) {
			return false;
		}

		number /= 10;
		sufix /= 10;
	}

	return true;
}

bool isPrefix(unsigned int number, unsigned int expectedPrefix) {
    // this check is done in the loop condition
	// if (number < expectedPrefix) {
	// 	return false;
	// }

	while (number >= expectedPrefix) {
		if (number == expectedPrefix) {
			return true;
		}

		number /= 10;
	}

	return false;
}

bool isInfix(unsigned int number, unsigned int expectedInfix) {
    // this check is done in the loop condition
	// if (number < expectedInfix) {
	// 	return false;
	// }

	while (number >= expectedInfix) {
		if (isSuffix(number, expectedInfix)) {
			return true;
		}

		number /= 10;
	}

	return false;
}

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << isPrefix(a, b);
}