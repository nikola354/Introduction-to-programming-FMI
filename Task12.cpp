void getLongestPrefix(const char* word1, const char* word2, const char* word3, char* result)
{
	if (!word1 || !word2 || !word3 || !result)
		return;

	while (*word1 && *word2 && *word3)
	{
		if (*word1 == *word2 && *word2 == *word3)
		{
			*result = *word1;
			result++;
		}
		else
			break;

		word1++; word2++; word3++;
	}

	*result = '\0';
}