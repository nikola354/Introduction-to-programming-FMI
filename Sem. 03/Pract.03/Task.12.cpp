
#include <iostream>
using namespace std;


int main()
{
	int N;
	cin >> N;
	int num;
	int sum = 0;
	while (true) {
		cin >> num;
		if (num == - 1) {
			break;
		}
		int copyOfnum = num;
		int copyOfN = N;
		while (num != 0)
		{
			int mod = N % num;
			N= num;
			num = mod;
		}
		if (N == 1) {
			sum += copyOfnum;
		}
		N = copyOfN;

	}

	cout << sum;
}


