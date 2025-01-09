main.cpp#include <iostream>

unsigned countResultSize(unsigned A, unsigned B) {
    unsigned resultLength = 0;

    while (A != 0 || B != 0) {
        if ((A & 1) != (B & 1)) {
            resultLength++;
        }

        A >>= 1;
        B >>= 1;
    }

    return resultLength;
}

unsigned *findIndexes(unsigned A, unsigned B, unsigned &resultLength) {
    resultLength = countResultSize(A, B);
    if (resultLength == 0) {
        return nullptr;
    }

    unsigned *result = new unsigned[resultLength];

    unsigned index = 0;
    unsigned resultIndex = 0;
    while (resultIndex < resultLength && (A != 0 || B != 0)) {
        if ((A & 1) != (B & 1)) {
            result[resultIndex++] = index;
        }

        index++;
        A >>= 1;
        B >>= 1;
    }

    return result;
}

void printArr(const unsigned *arr, unsigned length) {
    for (unsigned i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
}

int main()
{
    unsigned length = 0;
    unsigned *indexes = findIndexes(10, 20, length);

    if (indexes == nullptr) {
        std::cout << "Equal numbers" << std::endl;
        return 0;
    }

    printArr(indexes, length);
    std::cout << std::endl;

    delete [] indexes;
}