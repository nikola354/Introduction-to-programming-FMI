#include <iostream>
int main() {
    int n,factorialOfN=1;
    std::cin>>n;
    while(n!=0){
        factorialOfN *=n;
        n--;
    }
    std::cout<<factorialOfN;
}
