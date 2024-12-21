int charToDigit(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return 10 + (ch - 'A');
	else if (ch >= '0' && ch <= '9')
		return ch - '0';
	else 
		return -1;

	return 0;
}

int getLength(const char* src)
{
	if (!src) 
		return -1;

	unsigned length = 0;

	while (*src)
	{
		length++;
		src++;
	}

	return length;
}

int fromAnyBaseToDecimal(const char* src, unsigned srcBase)
{
	if (!src) 
		return -1;

	int result = 0, multiplyer = 1, srcLength = getLength(src);

	for (int index = srcLength - 1; index >= 0; index--, multiplyer *= srcBase)
	{
		int nextDigit = charToDigit(src[index]);
		if (nextDigit < 0) 
			return -1;
			
		result += multiplyer * nextDigit;
	}

	return result;
}
