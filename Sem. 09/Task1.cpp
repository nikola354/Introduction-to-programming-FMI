//Задача 1: Напишете функция, която приема 3 стринга - text, where и what и замества в text всяко срещане на where с what.
#include <iostream>
constexpr int MAX_SIZE = 1024;

void printArr(const char *arr);
void findMatch(const char *arr, const char *searched, const char *replacing);

int main() {
  char str[MAX_SIZE] = "i am the best of the best!";
  findMatch(str, "best", "worst");
  return 0;
}

void findMatch(const char *arr, const char *searched, const char *replacing) {
  if(!arr || !searched || !replacing) return;
  char updatedArray[MAX_SIZE];
  int updatedArrayIndex = 0; //следи на кой индекс поставяме символ в updatedArray
  int i = 0; // следи до кой елемент в arr сме

  while(arr[i] != '\0') {
    updatedArray[updatedArrayIndex] = arr[i];
    //ако първата буква от търсената дума съвпада, проверявам и останалите букви
    if(arr[i] == searched[0]) {
      int j = 0;
      bool isMatch = true;
      while(searched[j] != '\0') {
        if(arr[i + j] == '\0' || searched[j] != arr[i + j]) {
          isMatch = false;
          break;
        }
        j++;
      }
      if(isMatch) {
        //replace logic
        int replacingWordLength = 0;
        while(replacing[replacingWordLength] != '\0') {
          updatedArray[updatedArrayIndex + replacingWordLength] = replacing[replacingWordLength];
          replacingWordLength ++;
        }
        updatedArrayIndex += replacingWordLength;
        i += j;
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
