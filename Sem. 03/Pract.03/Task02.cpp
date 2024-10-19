#include <iostream>
int main() {
    int n,a=0,b=1,sum;
    std::cin>>n;
    for(int i=0;i<n;i++){
        if(i==0){
            std::cout<<a<<" ";
        }
        else if(i==1){
            std::cout<<b<<" ";
        }else{
            sum = a + b;
            a = b;
            b = sum;
            std::cout<<sum<<" ";
        }
    }
}