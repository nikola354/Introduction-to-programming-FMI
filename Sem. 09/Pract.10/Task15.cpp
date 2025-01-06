#include <iostream>
using namespace std;
constexpr int MAX=1000;
bool isLowerCaseLetter(char c){
    return(c >='a' && c <= 'z');
}
bool isUpperCaseLetter(char c){
    return (c >= 'A' && c<='Z');
}
bool isSeparator(char c){
    return !(isUpperCaseLetter(c) || isLowerCaseLetter(c));
}
unsigned int getWordsCount(const char* words){
    if(!words) return 0;
    unsigned int counter=0;
    bool inWord=0;
    for(const char* ptr=words; *ptr; ptr++){
        if(isSeparator(*ptr)){
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
    char str[MAX]={'\0'};
    cin.getline(str,MAX);
    cout<< getWordsCount(str);
}
