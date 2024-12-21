#include <iostream>;

char toLower(char ch)
{
    return (ch >= 'A' && ch <= 'Z') ? ch + ('a' - 'A') : ch;
}


bool isPrefix(const char* pattern, char* text) {
	if (!pattern || !text)
		return 0;

	while (*pattern && *text && (toLower(*pattern) == toLower(*text)))
	{
		*text = '*';
		pattern++;
		text++;
	}

	return !*pattern;
}

void censor(char* text, const char* substring)
{
	if (!text || !substring)
		return;

	while (*text)
	{
		isPrefix(substring, text);
		text++;
	}
}

int main() {
	char text[] = "Must love FMI. hates fmi.";
	char substring[] = "fMi";
	censor(text, substring);
	std::cout << text;
}