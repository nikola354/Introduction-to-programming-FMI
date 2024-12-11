#include <iostream>
using namespace std;

const int UPPER_TO_LOWER_DIFF = 'a'-'A';

void convertString(char* str){
    if(!str) return ;
    
    while(*str){
        if(*str >= 'a' && *str <= 'z') *str = *str - UPPER_TO_LOWER_DIFF;
        else if(*str >='A' && *str <= 'Z') *str = *str + UPPER_TO_LOWER_DIFF;
        str++;
    } 
}
int main(){
char str[]="abcd56ABCD";
convertString(str);
cout<<str;
}
