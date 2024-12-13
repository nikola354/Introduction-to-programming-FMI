char toLower(char ch)
{
	return ch + ('a' - 'A');
}

char toUpper(char ch)
{
	return ch - ('a' - 'A');
}

int strCmp(char* str1, const char* str2)
{
	while (toLower(*str1) == *str2 || toUpper(*str1) == *str2)
	{
		str1++; str2++;
	}

	return *str2;
}

void replaceText(char*& text, const char* substring)
{
	while (*substring)
	{
		*text = '*';
		text++;
		substring++;
	}
}

void censor(char* text, const char* substring)
{
	if (!text || !substring)
		return;

	while (*text)
	{
		if (!strCmp(text, substring))
			replaceText(text, substring);

		text++;
	}
}
