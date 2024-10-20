#include <iostream>;

int main()
{
	int a, b, c, d, e;
	std::cin >> a >> b >> c >> d >> e;

	for (int x = -100; x <= 100; x++)
	{
		int f_x = a * x * x * x * x + b * x * x * x + c * x * x + d * x + e;
		
		if (f_x >= 0)
		{
			std::cout << "x = " << x << " is a solution. f(x) = " << f_x << std::endl;
		}
	}

	return 0;
}
