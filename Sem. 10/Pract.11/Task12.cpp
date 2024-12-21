#include <iostream>;

void getLongestPrefix(const char * const * mtx, char * result) {
    if (!mtx || !result || !mtx[0]) {
        *result = '\0';
        return;
    }

    const char* firstWord = mtx[0];
    unsigned prefixLength = 0;

    while (true) {
        char currentChar = firstWord[prefixLength];

        for (unsigned i = 0; mtx[i]; ++i) {
            if (!mtx[i][prefixLength] || mtx[i][prefixLength] != currentChar) {
                result[prefixLength] = '\0';
                return;
            }
        }

        result[prefixLength] = currentChar;
        ++prefixLength;
    }
}