#include <iostream>

int charToDigit(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return 10 + (ch - 'A');
	else if (ch >= '0' && ch <= '9')
		return ch - '0';

	return -1;
}

unsigned int getLength(const char* src)
{
	if (!src) return 0;

	unsigned int length = 0;

	while (*src)
	{
		length++;
		src++;
	}

	return length;
}

int fromAnyBaseToDecimal(const char* src, unsigned srcBase)
{
	if (!src) return -1;

	int result = 0, mult = 1, srcLength = getLength(src);

	for (int index = srcLength - 1; index >= 0; index--, mult *= srcBase)
	{
		int nextDigit = charToDigit(src[index]);
		
		if (nextDigit < 0) return -1;

		result += mult * nextDigit;
	}

	return result;
}

int main()
{
	std::cout << fromAnyBaseToDecimal("IC7", 24) << std::endl;
	std::cout << fromAnyBaseToDecimal("11001", 2) << std::endl;

	return 0;
}
