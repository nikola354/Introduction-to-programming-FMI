#include <iostream>

const char TERMINATE_SYMBOL = '\0';

unsigned myStrLen(const char* str) {
    if (!str) {
        return 0;
    }

    unsigned index = 0;
    while (str[index] != TERMINATE_SYMBOL) {
        index++;
    }

    return index;
}

bool isDigit(char ch) {
    return '0' <= ch && ch <= '9';
}

char digitToChar(unsigned digit) {
    return digit + '0';
}

unsigned charToDigit (char a) {
    return a - '0';
}

bool isLower(char ch) {
    return 'a' <= ch && ch <= 'z';
}

void toLower(char &ch) {
    ch += ('a' - 'A');
}

bool isUpper(char ch) {
    return 'A' <= ch && ch <= 'Z';
}

void toUpper(char &ch) {
    ch += ('A' - 'a');
}

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void reverseString(char* arr, unsigned length) {
    for (int i = 0; i < length / 2; i++) {
        swap(arr[i], arr[length - i - 1]);
    }
}

void convertString(char *str, char ch) {
    unsigned length = myStrLen(str);

    reverseString(str, length);

    for (int i = 0; i < length; i++) {
        if (isUpper(str[i])) {
            toLower(str[i]);
        } else if (isLower(str[i])) {
            toUpper(str[i]);
        } else if (isDigit(str[i])) {
            int remainder = charToDigit(str[i]) % 2;
            str[i] = digitToChar(remainder); //COMMON MISTAKE! - forget to reverse the int back to char
        } else {
            str[i] = ch;
        }
    }
}

int main() {
    char str[] = "up FMI 2024-2025";

    convertString(str, '!');
    std::cout << str;
}
