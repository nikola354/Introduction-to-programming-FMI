#include <iostream>
using namespace std;
constexpr int MAX=1024;
void insertSymbol( const char* text, char* result, char symbol, unsigned int index){
    unsigned int currentIndex=0;
    while(*text){

       if (currentIndex==index){
        *result=symbol;
        result++;
       }
       *result=*text;
       result++;
       text++;
        currentIndex++;
    } 
    *result='\0';
}
int main(){
    const char* text="hello, y friend!";
    char symbol; unsigned int index;
    cin>> symbol>> index;
    char result[MAX]{'\0'};
    insertSymbol(text, result, symbol, index );
    cout<<result;
}