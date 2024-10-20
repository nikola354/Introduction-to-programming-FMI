#include <iostream>
#include <cmath>
int main() {
    int n,length=0,armstrong=0;
    std::cin>>n;
    int copyOfN=n;
    while(copyOfN!=0){
        length++;
        copyOfN/=10;
    }
    copyOfN=n;
    while(copyOfN!=0){
        armstrong += std::pow((copyOfN%10),length);
        copyOfN/=10;
    }
    if(n==armstrong) std::cout<<true;
    else std::cout<<false;
}