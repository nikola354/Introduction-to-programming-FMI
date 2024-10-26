#include <iostream>

int squareRootToLower(int num){
   int power=1;
   while(power*power<=num){
    power++;
   }
   return --power;
}
int main(){
    int num;
    std::cin>>num;
    std::cout<<squareRootToLower(num);
}