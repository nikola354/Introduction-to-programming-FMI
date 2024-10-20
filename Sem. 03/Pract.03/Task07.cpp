#include <iostream>
int main() {
    int n,sum=0;
    std::cin>>n;
    for(int i=1;i<n;i++){
        if(n%i==0)sum+=i;
    }
    if(n==sum) std::cout<<true;
    else std::cout<<false;
}