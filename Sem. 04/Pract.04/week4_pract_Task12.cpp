#include <iostream>
int secondLength(unsigned int second){
    int len=0;
    while(second!=0){
        len++;
        second /= 10;
    }
    return len;
}
int pow(int ten , int len){
    int result=1;
    while(len!=0){
        int temp = ten;
        result *= 10;
        len--;
    }
    return result;
}
unsigned concat(unsigned int first, unsigned int second){
    return first * pow(10,secondLength(second)) + second;
}
int main() {
    unsigned int first ,second;
    std::cin>>first>>second;
    std::cout<<concat(first,second);
    return 0;
}
