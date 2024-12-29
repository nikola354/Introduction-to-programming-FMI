#include <iostream>;

constexpr size_t SIZE = 1024;

void getLongestPrefix(const char* const* mtx, char* result) 
{
	if (!mtx || !result) return;

	const char* firstWord = mtx[0];
	unsigned prefixLength = 0;

	while (true) 
	{
		char currentChar = firstWord[prefixLength];

		for (unsigned i = 0; mtx[i] != nullptr; i++) 
		{
			if (mtx[i][prefixLength] != currentChar) 
			{
				result[prefixLength] = '\0';
				return;
			}
		}

		result[prefixLength++] = currentChar;
	}
}

int main()
{
	// another variant would be to pass an additional variable rows to the function
	const char* mtx[4]{ "flower", "flow", "flight", nullptr };
	char result[SIZE]{ '\0' };

	getLongestPrefix(mtx, result);

	std::cout << result << std::endl;

	return 0;
}
