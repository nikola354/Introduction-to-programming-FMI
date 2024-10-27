#include <iostream>
int reverse(int num){
    int reversed = 0;
    while(num!=0){
        reversed = reversed*10 + num%10;
        num/=10;
    }
    return reversed;
}
int kThNumber(int reversed,int k){
    int digit;
    while(k-1!=0){
        reversed/=10;
        k--;
    }
    return reversed%10;
}
int main() {
    int n,k;
    std::cin>>n>>k;
    std::cout<<kThNumber(reverse(n),k);    

    return 0;
}
