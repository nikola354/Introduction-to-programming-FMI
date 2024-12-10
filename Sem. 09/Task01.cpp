#include <iostream>

constexpr int MAX_SIZE = 1024;

unsigned int myStrLen(const char* str);
void myStrCpy(char* dest, const char* src);
void myStrCat(char* first, const char* second);

void findMatch(const char* arr, char* updatedArray, const char* searched, const char* replacing);
bool isPrefix(const char* searched, const char*& text);
void replace(const char* replacing, char*& updatedArray);

int main()
{
	char str[MAX_SIZE + 1] = "i am the best of the best!";

	char updatedArray[MAX_SIZE + 1]{ '\0' };
	updatedArray[MAX_SIZE] = '\0';

	findMatch(str, updatedArray, "best", "worst");

	std::cout << updatedArray << std::endl;

	return 0;
}

unsigned int myStrLen(const char* str)
{
	if (!str) return 0;

	unsigned int result = 0;
	while (*str++ && ++result);
	return result;
}

void myStrCpy(char* dest, const char* src)
{
	if (!dest || !src) return;

	while (*dest++ = *src++);
}

void myStrCat(char* first, const char* second)
{
	if (!first || !second) return;

	first += myStrLen(first);
	myStrCpy(first, second);
}

bool isPrefix(const char* searched, const char*& text)
{
	if (!searched || !text) return false;

	while (*searched)
	{
		if (*searched != *text)
		{
			return false;
		}

		searched++;
		text++;
	}

	return true;
}

void replace(const char* replacing, char*& updatedArray)
{
	if (!replacing || !updatedArray) return;

	myStrCat(updatedArray, replacing);

	updatedArray += myStrLen(replacing);
}

void findMatch(const char* arr, char* updatedArray, const char* searched, const char* replacing)
{
	if (!arr || !updatedArray || !searched || !replacing) return;

	while (*arr)
	{
		if (*arr == *searched)
		{
			if (isPrefix(searched, arr))
			{
				replace(replacing, updatedArray);
				continue;
			}
		}
		else
		{
			*updatedArray = *arr;
		}

		updatedArray++;
		arr++;
	}
}
