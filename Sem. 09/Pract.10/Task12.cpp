#include <iostream>
using namespace std;
void convertString(char* str){
    if(!str) return ;
    while(*str){
        if(*str >= 'a' && *str <= 'z') *str=*str-32;
        else if(*str >='A' && *str <= 'Z') *str= *str+32;
        str++;
    } 
}
int main(){
char str[]="abcd56ABCD";
convertString(str);
cout<<str;
}