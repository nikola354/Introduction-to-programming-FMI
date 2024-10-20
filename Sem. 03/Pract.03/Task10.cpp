#include <iostream>
int main() {
    int n,copyOfN,position,length=0,evenPositions=0;
    std::cin>>n;
    copyOfN=n;
    while(copyOfN!=0){
        length++;
        copyOfN /= 10;
    }
    copyOfN=n;
    position=length;
    while(copyOfN!=0){
        int digit=copyOfN%10;
        if(digit%2==0){
            evenPositions = evenPositions*10 + digit;
        }
        copyOfN /= 10;
    }
    while(evenPositions!=0){
        std::cout<<evenPositions%10<<" ";
        evenPositions /= 10;
    }
}