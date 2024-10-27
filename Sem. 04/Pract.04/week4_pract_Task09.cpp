#include <iostream>
int lcm(int a, int b){
    if(a%b==0) return a;
    if(b%a==0) return b;
    if(b>a){
        int temp=a;
        a=b;
        b=temp;
    }
    int lcm=a;
    while(lcm%a!=0 || lcm%b!=0){
        lcm++;
    }
    return lcm;
}
int main() {
    int a,b;
    std::cin>>a>>b;
    std::cout<<lcm(a,b);
    return 0;
}
