#include <iostream>
int main(){
  	double firstNum, secondNum;
    char ch;
    std::cin>>firstNum >> ch >> secondNum;
    switch (ch) {
        case('+'): std::cout<< firstNum + secondNum; break;
        case('-'): std::cout<< firstNum - secondNum; break;
        case('*'): std::cout<< firstNum * secondNum; break;
        case('/'): std::cout<< firstNum / secondNum; break;
        default: std::cout<< "Invalid input";
    }
    return 0;
}