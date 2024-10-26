#include <iostream>;
int gcd(int a, int b);
int lcm(int a, int b);
void gcdAndLcmOfMultipleNumbers();

int main(){
    gcdAndLcmOfMultipleNumbers();
}

int gcd(int a, int b) {
	int gcd = a > b ? b : a;

	while (gcd > 1) {
		if (a % gcd == 0 && b % gcd == 0)
			break;
		gcd--;
	}

	return gcd;
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
