#include <iostream>

bool binarySearch(const int* arr, int x, size_t len)
{
	if (!arr || len == 0) return false;

	size_t mid = len / 2;

	if (arr[mid] == x)
	{
		return true;
	}
	else if (arr[mid] < x)
	{
		return binarySearch(arr + mid + 1, x, len - mid - 1);
	}
	else
	{
		return binarySearch(arr, x, mid);
	}
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

	std::cout << binarySearch(arr, num, N) << std::endl;

	return 0;
}
