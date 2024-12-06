//Задача 2 Напишете функции toUpper и toLower, които приемат стринг и променят всички главни букви в малки/всички малки букви в главни.
#include <iostream>
constexpr int DIFFERENCE = ('a' - 'A');

void printArr(const char *arr) {
  if(!arr) return;
  std::cout << '\n';
  while (*arr != '\0')
  {
    std::cout << *arr;
    arr++;
  }
  std::cout << '\n';
}

void toUpper(char *str) {
  if(!str) return;
  while(*str != '\0') {
    if(*str >= 'a' && *str <= 'z') {
      (*str) -= DIFFERENCE; 
    }
    str++;
  }
}
void toLower(char *str) {
  if(!str) return;
  while(*str != '\0') {
    if(*str >= 'A' && *str <= 'Z') {
      (*str) += DIFFERENCE; 
    }
    str++;
  }
}

int main() {
  char str[] = "HeLlo WORLD!";
  toUpper(str);
  printArr(str);
  toLower(str);
  printArr(str);

  return 0;
}