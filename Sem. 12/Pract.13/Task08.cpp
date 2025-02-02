#include <iostream>

bool contains(const int* arr, int x)
{
	if (!arr) return false;
	return *arr != x ? contains(arr + 1, x) : true;
}

int main()
{
	size_t N = 0;
	std::cin >> N;

	int num = 0;
	std::cin >> num;

	int* arr = new int[N];

	for (size_t i = 0; i < N; i++)
	{
		std::cin >> arr[i];
	}

	std::cout << contains(arr, num) << std::endl;

	return 0;
}
