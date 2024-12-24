#include <iostream>

const unsigned MAX_SIZE = 1024;

void mySwap(char& first, char& second) {
	char temp = first;
	first = second;
	second = temp;
}

int charToDigit(char a) {
  if (a < '0' || a > '9') {
    	return 0;
  }

  return a - '0';
}

char digitToChar(unsigned digit){
	if (digit > 9) {
          return 0;
   }

   return digit + '0';
}

void reverseArray(char* arr, unsigned length) {
	for (unsigned i = 0; i < length / 2; i++) {
		mySwap(arr[i], arr[length - i - 1]);
	}
}

void decimalToBinary(unsigned decimal, char result[], unsigned& resultLength) {
	resultLength = 0;
	while (decimal != 0) {
		unsigned lastDigit = decimal % 2;
		result[resultLength++] = digitToChar(lastDigit);
		decimal /= 2;
	}

	reverseArray(result, resultLength);
}

unsigned binaryToDecimal(const char source[], unsigned& length) {
	unsigned result = 0;
    int multiplier = 1;
	for (int i = length - 1; i >= 0; i--) {
		result += charToDigit(source[i]) * multiplier;
		multiplier *= 2;
	}

	return result;
}

void printArr(const char* result, unsigned length) {
	for (unsigned i = 0; i < length; i++) {
		std::cout << result[i];
	}
	std::cout << std::endl;
}


int main() {

	unsigned decimalNumber = 125;
	char binaryNumber[MAX_SIZE];
	unsigned binaryNumberLength = 0;
	decimalToBinary(decimalNumber, binaryNumber, binaryNumberLength);

	printArr(binaryNumber, binaryNumberLength);

	unsigned afterConversionDecimal = binaryToDecimal(binaryNumber, binaryNumberLength);
	std::cout << afterConversionDecimal;
}
