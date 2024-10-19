#include <iostream>

using namespace std;

int main()
{
	const char CAPITAL_TO_LOWER = 'a' - 'A';

	char capitalStart, capitalEnd, lowerStart, lowerEnd, symbol;
	cin >> capitalStart >> capitalEnd >> lowerStart >> lowerEnd >> symbol;

	if (symbol >= 'A' && symbol <= 'Z')
	{
		symbol += CAPITAL_TO_LOWER;
	}

	capitalStart += CAPITAL_TO_LOWER;
	capitalEnd += CAPITAL_TO_LOWER;

	bool isInFirst = symbol >= capitalStart && symbol <= capitalEnd;
	bool isInSecond = symbol >= lowerStart && symbol <= lowerEnd;

	bool isUnion = isInFirst || isInSecond;
	bool isIntersection = isInFirst && isInSecond;
	bool isDifference = isInFirst && !isInSecond;
	bool isInOnlySet = isUnion && !isIntersection;

	cout << (isUnion ? "true" : "false") << endl;
	cout << (isIntersection ? "true" : "false") << endl;
	cout << (isDifference ? "true" : "false") << endl;
	cout << (isInOnlySet ? "true" : "false") << endl;
}
