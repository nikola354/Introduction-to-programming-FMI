#include <iostream>

char toLower(char ch)
{
    return (ch >= 'A' && ch <= 'Z') ? ch + ('a' - 'A') : ch;
}


bool isPrefix(const char* pattern, const char* text) {
    if (!pattern || !text)
        return false;

    while (*pattern && *text && (toLower(*pattern) == toLower(*text))) {
        pattern++;
        text++;
    }

    return !*pattern;
}

void censor(char* text, const char* substring) {
    if (!text || !substring)
        return;

    char* start = text;
    int subLen = 0;

    while (substring[subLen]) 
		subLen++;

    while (*start) {
        if (isPrefix(substring, start)) {
            for (int i = 0; i < subLen; i++)
                start[i] = '*';

            start += subLen;
        } 
		else
            start++;
    }
}

int main() {
	char text[] = "Howdy! How are you? How was your day?";
	char substring[] = "How";
	censor(text, substring);
	std::cout << text;
}
