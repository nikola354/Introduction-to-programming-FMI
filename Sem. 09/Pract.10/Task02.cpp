#include <iostream>

constexpr int DIFFERENCE = ('a' - 'A');

bool isLower(char letter) {
  return (letter >= 'a' && letter <= 'z');
}

bool isUpper(char letter) {
  return (letter >= 'A' && letter <= 'Z');
}

void convertString(char *str) {
  if (!str) return;

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
  char str[] = "HeLlo WORLD!";
  
  convertString(str);
  
  std::cout << str;

  return 0;
}
