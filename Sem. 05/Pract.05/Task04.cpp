#include<iostream>
using namespace std; 
int reverse(int number){
    int digit,newnum=0;
    while(number>0){
        digit=number%10;
        newnum=newnum*10+digit;
        number/=10;
    } return newnum;
    }
int even(int& number){
 int reversednumber=reverse(number);
 int evennum=0;
 reversednumber/=10;
 while(reversednumber>0){
    int digit=reversednumber%10;
    evennum=evennum*10+digit;
    reversednumber/=100;
 } return evennum;
} 
int odd(int& number){
    int reversednumber=reverse(number);
    int oddnum=0;
    while(reversednumber>0){
        int digit=reversednumber%10;
        oddnum=oddnum*10+digit;
        reversednumber/=100;
    } return oddnum;
}
int main(){
    int a;
    cin>>a;
    cout<<even(a)<<endl;
    cout<<odd(a);
}
