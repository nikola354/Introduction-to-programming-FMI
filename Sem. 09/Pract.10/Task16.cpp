
#include <iostream>
using namespace std;
constexpr int SIZE = 1024;

unsigned int strLen(const char* str) {
    if (!str)
        return 0;

    unsigned int length = 0;
    while (*str) {
        length++;
        str++;
    }
    return length;
}

void convertInput(char* str) {
    if (!str)
        return;

    unsigned int length = strLen(str);
    unsigned int newLength = 0;
    for (unsigned int i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[newLength++] = str[i];
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[newLength++] = str[i] - 'A' + 'a';

    }
    str[newLength] = '\0';
}


void swap(char*& first, char*& second) {
    char* third = second;
    second = first;
    first = third;
}

void copy(const char* str, char* result) {
    if (!str)
        return;

    while (*str) {
        *result = *str;
        str++;
        result++;
    }
    *result = '\0';
}

void sortCharacters(const char* str, char* result) {
    if (!str)
        return;

    copy(str, result);
    unsigned int length = strLen(result);

    for (unsigned int i = 0; i < length; i++) {
        char* min = (result + i);
        for (unsigned int j = i + 1; j < length; j++) {
            if (*min > *(result + j))
                min = (result + j);
        }

        if (*min != *(result + i))
            swap(*min, *(result + i));

    }
}


int main()
{
    const int BUFFER_SIZE = 1024;
    char str[BUFFER_SIZE];
    cin.getline(str, BUFFER_SIZE);
    char result[SIZE];
    convertInput(str);
    sortCharacters(str, result);
    cout << result;
}