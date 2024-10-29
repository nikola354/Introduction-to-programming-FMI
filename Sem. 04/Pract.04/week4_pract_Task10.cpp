#include <iostream>
int reverse(int num){
    int reversed = 0;
    while(num != 0){
        reversed = reversed*10 + num%10;
        num /= 10;
    }
    return reversed;
}
int kThNumber(int n,int k){
     n = reverse(n);
    while(k - 1 != 0){
        n /= 10;
        k--;
    }
    return n % 10;
}
int main() {
    int n,k;
    std::cin>>n>>k;
    std::cout<<kThNumber(n,k);    

    return 0;
}
