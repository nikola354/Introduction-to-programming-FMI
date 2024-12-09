//Задача 1: Напишете функция, която приема 3 стринга - text, where и what и замества в text всяко срещане на where с what.
#include <iostream>
constexpr int MAX_SIZE = 1024;

void printArr(const char *arr);
void findMatch(const char *arr, const char *searched, const char *replacing);
bool isMatch(const char* searched, const char* text, int& j, const int i);
void replace(const char* replacing, char* updatedArray, int& updatedArrayIndex, const int searchedWordLength, int& i);

int main() {
  char str[MAX_SIZE] = "i am the best of the best!";
  findMatch(str, "best", "worst");
  return 0;
}

bool isMatch(const char* searched, const char* text, int& j, const int i) {
  j = 0;
  while(searched[j] != '\0') {
    if(text[i + j] == '\0' || searched[j] != text[i + j]) {
      return false;
      break;
    }
    j++;
  }
  return true;
}
void replace(const char* replacing, char* updatedArray, int& updatedArrayIndex, const int searchedWordLength, int& i) {
  int replacingWordLength = 0;
  while(replacing[replacingWordLength] != '\0') {
    updatedArray[updatedArrayIndex + replacingWordLength] = replacing[replacingWordLength];
    replacingWordLength ++;
  }
  updatedArrayIndex += replacingWordLength;
  i += searchedWordLength;
}

void findMatch(const char *arr, const char *searched, const char *replacing) {
  if(!arr || !searched || !replacing) return;
  char updatedArray[MAX_SIZE];
  int updatedArrayIndex = 0; //следи на кой индекс поставяме символ в updatedArray
  int i = 0; // следи до кой елемент в arr сме

  while(arr[i] != '\0') {
    updatedArray[updatedArrayIndex] = arr[i];
    if(arr[i] == searched[0]) {
      int searchedWordLength = 0;
      if(isMatch(searched, arr, searchedWordLength, i)) {
        replace(replacing, updatedArray, updatedArrayIndex, searchedWordLength, i);
        continue;
      }
    }
    i++;
    updatedArrayIndex++;
  }
  updatedArray[updatedArrayIndex] = '\0';
  printArr(updatedArray);
}

void printArr(const char *arr) {
  while (*arr != '\0')
  {
    std::cout << *arr;
    arr++;
  }
  std::cout << '\n';
}
