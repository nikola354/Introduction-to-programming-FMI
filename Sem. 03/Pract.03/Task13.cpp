#include <iostream>
using namespace std;
int main()
{
int num, n, k, sum, maxDifference = 0;
cin >> num;
if (num <= 0) return 0;
cin >> n >> k;
sum = n + k;
bool isEqual = true;

for (int i = 1; i < num; i++) {
	int first, second;
	cin >> first >> second;
	int sum1 = first + second;
	if (sum != sum1) {
		isEqual = false;
		if (sum > sum1) {
			maxDifference = sum - sum1;
		}
		else {
			maxDifference = sum1 - sum;
		}
		sum = sum1;
	}
}
if (isEqual) {
	cout << "Equal sums: " << sum;
}
else {
	cout << "Different sums. Max Difference: " << maxDifference;
}
}
