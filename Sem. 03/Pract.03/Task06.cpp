#include <iostream>
#include <cmath>
int main() {
   int sumOfPrimes=0;
   for(int i=100;i<=999;i++){
       int sum=i%10 + (i/10)%10 + i/100;
       if(sum>1){
           int sqrtOfSum=sqrt(sum);
           bool isPrime=true;
           for(int j = 2;j<=sqrtOfSum;j++){
            if(sum%j==0) {
               isPrime = false;
               break;
            }
         }
         if(isPrime && sum>9 )sumOfPrimes+=i;
       }
   }
   std::cout<<sumOfPrimes;
}