// TASK_10.cpp 
#include <iostream>

int main() { 
	
	int a,b,k;
	std::cin >> a>>b>>k;

	int k_a = 0;
	int power = 0;

	for (int i = 1; i <= k; i++) {
		
		k_a = k_a + (a % 10) * pow(10, power);
		
		a = a/10;
		power++;
	}

	for (int i = b; i != 0; i /= 10) {
		k_a *= 10;
}
	std::cout << k_a  + b;
}

