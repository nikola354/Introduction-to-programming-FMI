//Задача 16: Да се напише програма, която приема цяло положително число n и отпечатва числата от 1 до n*n в спираловиден вид.

#include <iostream>

int main() {
	int n = 0;
	int row = 1;
	std::cin >> n;
	int sum = n * n;

	for(int i = 1; i <= sum;i++) {
		if(row % 2 == 1) {
			std::cout << i << ' ';
		} else {
			int swapped = i;
			swapped = n * row - (( i - 1) - (row  * n - n));
			std::cout << swapped << ' ';
		}
		if(i % n == 0) {
			row++;
			std::cout << '\n';
		}
	}

	return 0;
}