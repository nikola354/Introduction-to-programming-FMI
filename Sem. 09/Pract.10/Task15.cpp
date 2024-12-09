#include <iostream>
using namespace std;
bool isSpace(char c){
    return (c == ' ' || (c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126));
}
unsigned int getWordsCount(const char* words){
    if(!words) return 0;
    unsigned int counter=0;
    bool inWord=0;
    for(const char* ptr=words; *ptr; ptr++){
        if(isSpace(*ptr)){
           if(inWord) { 
            counter++;
            inWord=false;
          }
        }
        else inWord=true;
    } 
    if(inWord) counter++;
    return counter;
}

int main(){
    char str[1000]={'\0'};
    cin.getline(str,1000);
    cout<< getWordsCount(str);
}
