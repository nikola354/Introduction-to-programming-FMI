#include <iostream>
using namespace std;

constexpr int MAX_SIZE = 100;
constexpr char TERMINATE_SYMBOL = '\0';

int countLength(const char* str);

char* censorNumbers(const char* str);

int main() {
    char str[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    char* result = censorNumbers(str);

    cout << result << endl;

    delete[] result;
    return 0;
}

int countLength(const char* str) {
    if (!str) {
        return 0;
    }

    bool isNumber = false;
    int length = 0;
    while (*str != TERMINATE_SYMBOL) {
        if (*str >= '0' && *str <= '9') {
            isNumber = true;
        } else {
            length++;

            if (isNumber) {
                length++;
                isNumber = false;
            }
        }

        str++;
    }

    if (isNumber) {
        length++;
    }

    return length;
}

char* censorNumbers(const char* str) {
    if (!str) {
        return nullptr;
    }

    int length = countLength(str);
    char* result = new char [length + 1]; // +1 for terminate symbol

    bool isNumber = false;
    int index = 0;
    while (*str != TERMINATE_SYMBOL) {
        if (*str >= '0' && *str <= '9') {
            isNumber = true;
        } else {
            if (isNumber) {
                result[index++] = '*';
                isNumber = false;
            }

            result[index++] = *str;
        }

        str++;
    }

    if (isNumber) {
        result[index++] = '*';
    }

    result[index] = TERMINATE_SYMBOL;

    return result;
}
