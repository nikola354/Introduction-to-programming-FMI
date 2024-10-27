#include <iostream>;

int gcd(int a, int b);
int lcm(int a, int b);
void gcdAndLcmOfMultipleNumbers();

int main()
{
    	gcdAndLcmOfMultipleNumbers();

	return 0;
}

int gcd(int a, int b) {
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	while (b != 0)
	{
		int mod = a % b;
		a = b;
		b = mod;
	}

	return a;
}

int lcm(int a, int b) {
	return (a / gcd(a, b)) * b;
}

void gcdAndLcmOfMultipleNumbers() {
	int a, n;
	std::cin >> n >> a;
	int gcdRes = a;
	int lcmRes = a;

	for (; n - 1 > 0; n--)
	{
		std::cin >> a;
		gcdRes = gcd(gcdRes, a);
		lcmRes = lcm(lcmRes, a);
	}

	std::cout << "GCD: " << gcdRes << '\n';
	std::cout << "LCM: " << lcmRes << '\n';
}
