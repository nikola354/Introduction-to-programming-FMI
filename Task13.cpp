unsigned charToDigit(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		return 10 + (ch - 'A');
	}
	else if (ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}

	return 0;
}

unsigned getLength(const char* src)
{
	unsigned length = 0;

	while (*src)
	{
		length++;
	}

	return length;
}

unsigned fromAnyBaseToDecimal(const char* src, unsigned srcBase)
{
	unsigned result = 0, unsigned multiplyer = 1, unsigned srcLegth = getLength(src);

	for (unsigned index = srcLength - 1; index >= 0; index--, multiplyer *= srcBase)
	{
		result += multiplyer * charToDigit(src[index]);
	}

	return result;
}
