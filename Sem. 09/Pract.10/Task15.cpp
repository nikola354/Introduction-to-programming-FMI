#include <iostream>
using namespace std;
constexpr int MAX_SIZE = 1024;

unsigned int getWordsCount(const char* words) {
	if (!words)
		return 0;

	unsigned int count = 0;
	while (*words) {
		if (*words == ' ' && *(words - 1) != ' ')
			count++;

		words++;
	}

	if (count == 0)
		return count;
	return count + 1;
}


int main()
{
	char str[MAX_SIZE];
	cin.getline(str, MAX_SIZE);
	cout << getWordsCount(str);

}