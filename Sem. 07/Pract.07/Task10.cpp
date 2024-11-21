#include <iostream>
   
constexpr int MAX_SIZE = 100;

int getTheNumnber(int arr1[][MAX_SIZE], int arr2[][MAX_SIZE], int row, int col, int commonDimension) {
    int result = 0;
    for (int i = 0;i < commonDimension;i++) {
        result += arr1[row][i] * arr2[i][col];
    }
    return result;
}

void multipliedArrays(int arrMultiplied[][MAX_SIZE], int arr1[][MAX_SIZE], int arr1_row, int arr1_col,
    int arr2[][MAX_SIZE], int arr2_row, int arr2_col) {
    for (int i = 0;i < arr1_row;i++) {      
        for (int j = 0; j < arr2_col;j++) {
            arrMultiplied[i][j] = getTheNumnber(arr1, arr2, i , j, arr1_col);
        }
    }
}


void  sumOfArrays(int arrSum[][MAX_SIZE], int arr1[][MAX_SIZE], int arr2[][MAX_SIZE],int arr1_row,int arr1_col) {
    for (int i = 0;i < arr1_row;i++) {
        for (int j = 0; j < arr1_col;j++) {
            arrSum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

void readArray(int arr[][MAX_SIZE],int arr_row, int arr_col) {
    for (int i = 0;i < arr_row;i++) {

        for (int j = 0;j < arr_col;j++) {

            std::cin >> arr[i][j];

        }
    }
}

void printArray(int arr[][MAX_SIZE], int arr_row, int arr_col) {
    for (int i = 0;i < arr_row;i++) {

        for (int j = 0;j < arr_col;j++) {

            std::cout << arr[i][j] << " ";

        }

        std::cout << std::endl;

    }
}

void run() {
    int arr1[MAX_SIZE][MAX_SIZE], arr2[MAX_SIZE][MAX_SIZE];
 
    int arr1_row, arr1_col, arr2_row, arr2_col;

    std::cin >> arr1_row >> arr1_col;
    readArray(arr1, arr1_row, arr1_col);

    std::cin >> arr2_row >> arr2_col;
    readArray(arr2, arr2_row, arr2_col);
    
    int arrSum[MAX_SIZE][MAX_SIZE], arrMultiplied[MAX_SIZE][MAX_SIZE];

    sumOfArrays(arrSum,arr1,arr2,arr1_row,arr1_col);
    multipliedArrays(arrMultiplied, arr1, arr1_row, arr1_col, arr2, arr2_row,arr2_col);
    printArray(arrSum,arr1_row,arr1_col);
    printArray(arrMultiplied,arr1_row,arr2_col);
}

int main()
{
    run();
}

