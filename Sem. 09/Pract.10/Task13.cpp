#include <iostream>
using namespace std;
constexpr int MAX=1024;
int len(const char * text){
    int len=0;
    while(*text){
        len++;
        text++;
    } return len;
}
void insertSymbol( const char* text, char* result, char symbol, unsigned int index){
    unsigned int currentIndex=0;
    if(!text || !result) return;
    int lengthText=len(text);
    if((lengthText - 1)<index) {
        cout<< "invalid index!";
        return;
    }
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