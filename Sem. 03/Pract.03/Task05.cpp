#include <iostream>
int main() {
   int n,sum=0,copyOfN;
   std::cin>>n;
   copyOfN=n;
   for(int i=1;i<=n;i++){
       sum += i*copyOfN;
       copyOfN--;
   }
   std::cout<<sum;
}