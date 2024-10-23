
#include <iostream>
#include <cmath>
using namespace std;
int main()
{ int sum=0;
    
    for (int i=100;i<=999;i++){
        int sum_digit=0;
        int n=i;
        while(n>0){
        int digit=n%10;
        sum_digit+=digit;
        n/=10;
        }
        bool Prime = true; 
        if (sum_digit < 2) Prime = false; 
        else {
            int sqrtn = sqrt(sum_digit);
            for (int j = 2; j <= sqrtn; j++) {
                if (sum_digit % j == 0) {
                    Prime = false; 
                    break;
                    }
        }
        } if(sum_digit >= 10 && sum_digit <= 99 && Prime){
            sum+=i;
        }
    } cout<<sum;
    return 0;
}

