#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
const char TERMINATE_SYMBOL = '\0';

bool isDigit(char s);

int getDigitsCount(const char* str);

int getNumbersCount(const char*  str);

int getStringLength(const char* str);

char* censoreNumbers(const char* str);

int main() {
    char str[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    char* result = censoreNumbers(str);

    cout << result << endl;

    delete[] result;
    return 0;
}

bool isDigit(char s) {
    if (s >= '0' && s <= '9') {
        return true;
    }

    return false;
}

int getDigitsCount(const char* str) {
    if (!str) {
        return 0;
    }

    int count = 0;
    while (*str != TERMINATE_SYMBOL) {
        if (isDigit(*str)) {
            count++;
        }
        str++;
    }

    return count;
}

int getNumbersCount(const char*  str) {
    if (!str) {
        return 0;
    }

    int count = 0;
    while (*str != TERMINATE_SYMBOL) {
        if (isDigit(*str) && !isDigit(*(str + 1))) {
            count++;
        }
        str++;
    }

    return count;
}

int getStringLength(const char* str) {
    if (!str) {
        return 0;
    }

    int length = 0;
    while (*str != TERMINATE_SYMBOL) {
        length++;
        str++;
    }

    return length;
}

char* censoreNumbers(const char* str) {
    if (!str) {
        return nullptr;
    }

    int length = getStringLength(str) - getDigitsCount(str) + getNumbersCount(str);
    char* result = new char [length + 1]; // +1 for terminate symbol

    int index = 0;
    while (*str != TERMINATE_SYMBOL) {
        if (isDigit(*str)) {
            if (!isDigit(*(str + 1))) {
                result[index++] = '*';
            }
        } else {
            result[index++] = *str;
        }

        str++;
    }

    result[index] = TERMINATE_SYMBOL;

    return result;
}
