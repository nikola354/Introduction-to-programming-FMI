
#include <iostream>
using namespace std;


int main()
{
	double a, b, c;
	cin >> a >> b >> c;

	if ((a + b >c) && (b + c > a) && (a + c > b)) {
		cout << "This triangle exists.";
	}
	else {
		cout << "This triangle doesn't exist.";
	}
}

