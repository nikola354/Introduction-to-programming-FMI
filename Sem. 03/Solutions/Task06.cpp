#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int num;
	cin >> num;

	if (num == 1) {
		cout << "Not prime" << endl;
		return 0;
	}

	int sqrtN = sqrt(num);
	for (int i = 2; i <= sqrtN; i++) {
		if (num % i == 0) {
			cout << "Not prime" << endl;
			return 0;
		}
	}

	cout << "Prime" << endl;
	return 0;
}