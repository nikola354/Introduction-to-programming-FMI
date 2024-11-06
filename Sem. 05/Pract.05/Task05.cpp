#include <iostream>
using namespace std;
void setkthdigit(int& number, int k, int newdigit){
    int digit,reversed=0;
    for(int i=1;i<=k;i++){
        digit=number%10;
        number/=10;
        if(i==k) digit=newdigit;
        reversed=reversed*10+digit;
       }
       while(reversed>0){
        digit=reversed%10;
        number=number*10+digit;
        reversed/=10;
       }
    }

int findk(int number,int k){
    int a,n=number;
    for(int i=1;i<=k;i++){
    a=n%10;
    n/=10;
    }
    return a;
}
void reverse(int& number){
int reversednum=0;
int digit;
int n=number;
while(n>0){
    digit=n%10;
    reversednum=reversednum*10+digit;
    n/=10;
}number=reversednum;
}
void swap(int& m,int& n, int k){
    reverse(m);reverse(n);
    int km=findk(m,k);
    int kn=findk(n,k);
    setkthdigit(n,k,km);setkthdigit(m,k,kn);
    reverse(m);reverse(n);
    
}
int main(){
    int m,n,k;
    cin>>m>>n>>k;
    swap(m,n,k);
    cout<<m<<" "<<n;
}