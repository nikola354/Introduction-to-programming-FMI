#include <iostream>;

int main() {
	int n, k = 0, sum = 0;
	std::cin >> n >> k;
	
	while (k != -1)
	{
		int first = n;
		int second = k;

		if (first < second)
		{
			int temp = first;
			first = second;
			second = temp;
		}

		while (second != 0)
		{
			int mod = first % second;
			first = second;
			second = mod;
		}

		if (first == 1)
		{
			sum += k;
		}

		std::cin >> k;
	}

	std::cout << sum << std::endl;

	return 0;
}
