#include <iostream>
using namespace std;
constexpr int MAX=100000;
char digitToChar(int digit){
    char a = '\0';
    if(digit>=0 && digit<=9){
     a = digit + '0'; 
    } 
    return a;
}

int charToDigit(char a){
    int n = 0;
    if(a >= '0' && a<= '9') {
        n = a - '0';
    }
    return n;
}

void getDigitOccurences (const char* digit, char* result){
    if(!digit || !result) return;

    int counter[10]={0};
    for (const char* ptr = digit; *ptr; ptr++){
        if(*ptr>='0'&& *ptr<='9'){
            counter[charToDigit(*ptr)]++;
        }
    }

    for(int i=0; i<10; i++){
        if(counter[i]>0){
        int count=counter[i];
        if(count>=10){
            *result=digitToChar(count/10);
            result++;
         }
         *result=digitToChar(count%10);
         result++;
         *result= 'x';
         result++;
         *result= digitToChar(i);
         result++;
         *result=',';
         result++;
    } 

}
    *(result-1)='\0';
}

int main(){
    const char* digits="123458432345434";
    char result[MAX]{'\0'};
    getDigitOccurences(digits, result);
    cout<<result;
}

