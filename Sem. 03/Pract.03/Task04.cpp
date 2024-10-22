#include <iostream>
int main() {
    int n,sum=0;
    std::cin>>n;
    while(n>0 || sum > 9){
        if(n==0){
            n=sum;
            sum=0;
        }
        sum += n%10;
        n/=10;
    }
    std::cout<<sum;
    return 0;
}