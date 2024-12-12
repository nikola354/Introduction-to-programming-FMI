#include <iostream>

void mySwap(char& first, char& second) 
{
	char temp = first;
	first = second;
	second = temp;
}

void reverseArray(char* array, unsigned length) 
{
	for (unsigned i = 0; i < length / 2; i++) {
		mySwap(array[i], array[length - i - 1]);
	}
}

int charToDigit(char ch) 
{

	if (ch >= '0' && ch <= '9') {
		return ch - '0';
	}
	else if (ch >= 'A' && ch <= 'Z') {
		return 10 + ch - 'A';
	}

	return 0;
}

char digitToChar(unsigned digit) 
{
	if (digit >= 0 && digit <= 9) {
		return digit + '0';
	}
	else if (digit >= 10 && digit <= 26) {
		return digit - 10 + 'A';
	}

	return 0;
}

void decimalToRandom(unsigned decimal, unsigned short base, char* result, unsigned short& resultLength) 
{
	resultLength = 0;
	while (decimal != 0) {
		unsigned lastDigit = decimal % base;
		result[resultLength++] = digitToChar(lastDigit);
		decimal /= base;
	}

	reverseArray(result, resultLength);
}

unsigned randomToDecimal(const char* source, unsigned short base, unsigned short& sourceLength) 
{
	unsigned result = 0;
	unsigned multiplier = 1;
	for (int i = sourceLength - 1; i >= 0; i--) {
		result += charToDigit(source[i]) * multiplier;
		multiplier *= base;
	}

	return result;
}

void printArray(const char* array, unsigned short length) 
{
	for (unsigned i = 0; i < length; i++) {
		std::cout << array[i];
	}
}

unsigned short readBase(bool isSource) 
{
	unsigned short base;

	do
	{
		std::cout << "Enter number base [2, 36] for " << (isSource ? "source":"result") << ": ";
		std::cin >> base;
	} while (base < 2 || base > 36); // retry

	return base;
}

// Open to improvements
bool isInPossibleChars(char ch, unsigned short base) 
{
	char possibleCharacter[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVXYZ";
	for (size_t i = 0; i < base; i++)
		if (ch == possibleCharacter[i])
			return true;

	return false;
}

void readNumber(char *number, unsigned short &numberLength, unsigned short base) 
{
	std::cout << "Enter source number [positive integer less than 16 symbols in length]: ";
	std::cin >> number;

	// validation
	for (size_t i = 0; number[i] != '\0'; i++, numberLength++) {
		if (!isInPossibleChars(number[i], base)) {
			std::cout << "Invalid number\n";
			numberLength = 0;
			return readNumber(number, numberLength, base); // retry
		}
	}
}

int main() {

	unsigned short sourceBase = readBase(1);
	char source[16];
	unsigned short sourceLength = 0;
	readNumber(source, sourceLength, sourceBase);

	unsigned short resultBase = readBase(0);
	char result[64];
	unsigned short resultLength = 0;

	unsigned decimal = randomToDecimal(source, sourceBase, sourceLength);

	std::cout << "\nsource -> decimal -> result\n";
	decimalToRandom(decimal, resultBase, result, resultLength);
	printArray(source, sourceLength);
	std::cout << " -> " << decimal << " -> ";
	printArray(result, resultLength);
}