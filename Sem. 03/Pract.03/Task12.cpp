// Създайте програма, която приема естествено число N и след това чете неопределен 
// брой цели положителни числа от стандартния вход. Въвеждането се прекратява при 
// прочитане на числото -1. Да се отпечата сборът на всички числа от въведените, 
// които са взаимно прости с N.
#include <iostream>;

int main() {
	int n, k = 0, sum = 0;
	std::cin >> n;
	
	do
	{
		std::cin >> k;

		// could be made into a separate method
		int gcd = n > k ? k : n;
		while (gcd > 1) {
			if (n % gcd == 0 && k % gcd == 0)
				break;
			gcd--;
		}

		if (gcd == 1)
			sum += k;

	} while (k != -1);
	std::cout << sum << '\n';
}
