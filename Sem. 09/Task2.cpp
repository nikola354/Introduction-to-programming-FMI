//Задача 2 Напишете функции toUpper и toLower, които приемат стринг и променят всички главни букви в малки/всички малки букви в главни.
#include <iostream>
constexpr int DIFFERENCE = ('a' - 'A');

void printArr(const char *arr) {
  if(!arr) return;
  
  while (*arr != '\0'){
    std::cout << *arr;
    arr++;
  }
  std::cout << '\n';
}

bool isLower(char letter) {
  return (letter >= 'a' && letter <= 'z');
}
bool isUpper(char letter) {
  return (letter >= 'A' && letter <= 'Z');
}
void convertString(char *str) {
  if(!str) return;

  while(*str != '\0') {
    if(isLower(*str)) {
      (*str) -= DIFFERENCE; 
    } else if(isUpper(*str)) {
      (*str) += DIFFERENCE; 
    }
    str++;
  }
}


int main() {
  char str[] = "HaLlo WORLD!";
  convertString(str);
  std::cout << str;

  return 0;
}