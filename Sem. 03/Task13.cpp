#include <iostream>

int main()
{
	int input, min = INT_MAX, max = INT_MIN, sum = 0;
	bool isEqual = true;
	std::cin >> input;
	for (int i = 0;i < input;i++) {
		int a, b;
		std::cin >> a >> b;
		int currentSum = a + b;
		if (sum != currentSum && i!=0) {
			isEqual = false;
		}
		else {
			sum = currentSum;
		}
		if (currentSum > max) max = currentSum;
		if (currentSum < min) min = currentSum;
	}
	if (isEqual) {
		std::cout << "Equal sums: " << sum;
	}
	else {
		std::cout << "Different sums. Max difference: " << max - min;
	}
}