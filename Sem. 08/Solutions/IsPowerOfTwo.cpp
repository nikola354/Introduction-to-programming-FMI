bool isPowerOfTwo(unsigned number) {
    if (number == 0) {
        return false;
    }

    int mask = number - 1;     // 16 (10000) - 1 = 15 (01111)

    // 10000 & 01111 = 0 => powerOfTwo
    return (number & mask) == 0;
}