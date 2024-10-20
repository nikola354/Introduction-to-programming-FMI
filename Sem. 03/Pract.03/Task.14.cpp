#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int sum = 0;
	int max = 0;

	for (int i = 0; i < n; i++)
	{
		int currentNum = 0;
		cin >> currentNum;

		sum += currentNum;

		if (currentNum > max)
		{
			max = currentNum;
		}
	}

	if (max == (sum - max)) {
		cout << "Yes: " << max << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
