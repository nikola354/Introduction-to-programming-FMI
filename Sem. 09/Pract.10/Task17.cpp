#include <iostream>
using namespace std; 
constexpr int MAX_STR=10000;
constexpr int MAX_WORDS=100;
constexpr int MAX_SYMBOLS_WORDS=1024;

const char NULL_TERMINATOR = '\0';

bool isSpaceOrPunctuation(char a){
    return (a>=32 && a<=47 || a>=58 && a<=64 || a>=91 && a<=96 || a>=123 && a<=126);
}

void strToMatrix(char *str, char matrix[MAX_WORDS][MAX_SYMBOLS_WORDS]){
    if(!str || !matrix) return;
    
    int symbol = 0;
    int word = 0;
    bool inWord = false;
    
    for(char* ptr= str; *ptr; ptr++){
        
        if(!isSpaceOrPunctuation(*ptr)){
            inWord=true;
            matrix[word][symbol++]=*ptr;
        }
        else{
            if(inWord) {
            matrix[word][symbol]=NULL_TERMINATOR;
            word++;
            symbol=0;
            }

            inWord=false;
        }
        
    }
    matrix[word][symbol] = NULL_TERMINATOR;
}
void printMatrix(char matrix[MAX_WORDS][MAX_SYMBOLS_WORDS]){
    for(int i = 0; i < MAX_WORDS && matrix[i][0] != '\0'; i++){
        cout<<matrix[i]<<endl;
    }
}
int main(){

    char str[MAX_STR];
    char matrix[MAX_WORDS][MAX_SYMBOLS_WORDS];
    cin.getline(str,MAX_STR);
    strToMatrix(str,matrix);
    printMatrix(matrix);
    
}
