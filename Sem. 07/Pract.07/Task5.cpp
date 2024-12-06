#include <iostream>
constexpr int SIZE = 10;

void spiralPrint(const int arr[][SIZE], int size) {
  int direction = 0;// 0 - right, 1 - down, 2 - left, 3 - up
  int steps = size;
  int offset = 0;
  while(steps > 0) {
    switch(direction) {
      case 0:
        for(int i = 0;i < steps;i++) {
          std::cout << arr[offset][i + offset] << ' ';
        }
        steps--;
        break;
      case 1:
        for(int i = 1;i <= steps;i++) {
          std::cout << arr[i + offset][size - offset - 1] << ' ';
        }
        break;
      case 2:
        for(int i = steps - 1;i >= 0;i--) {
          std::cout << arr[size - offset - 1][i + offset] << ' ';
        }
        steps--;
        break;
      case 3:
        for(int i = steps;i > 0;i--) {
          std::cout << arr[i + offset][offset] << ' ';
        }
        break;
    }
    direction++;
    if(direction > 3) {
      offset++;
      direction = 0;
    }
  }
}

int main() {
  int size = 0;
  int array[SIZE][SIZE] = {0};
  do {
    std::cout << "Size of matrix: ";
    std::cin >> size;
  } while(size < 1);
  for(int i = 0;i < size;i++) { 
    for(int j = 0;j < size;j++) {
      std::cin >> array[i][j];
    }
  }
  spiralPrint(array, size);

  return 0;
}