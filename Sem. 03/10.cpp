#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int number,count=0;
    cin>>number;
    int n=number;
    while(n>0){
        count++;
        n/=10;
    }
    
    if(count%2==0){
        for(int i=1;i<=count/2;i++){
            int a= number/pow(10,count-2*i);
            int digit=a%10;
            cout<<digit<<" ";
        }
    } else{ 
        number/=10;
        for(int j=1;j<=(count-1)/2;j++){
            int a= number/pow(10,(count-1)-2*j);
            int digit=a%10;
            cout<<digit<<" ";
        }
    }
}