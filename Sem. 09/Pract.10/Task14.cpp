#include <iostream>
using namespace std;
constexpr int MAX=100000;
void getDigitOccurences (const char* digit, char* result){
    if(!digit || !result) return;

    int counter[10]={0};
    for (const char* ptr = digit; *ptr; ptr++){
        if(*ptr>='0'&& *ptr<='9'){
            counter[*ptr-'0']++;
        }
    }

    for(int i=0; i<10; i++){
        if(counter[i]>0){
        int count=counter[i];
        if(count>=10){
            *result=(count/10)+'0';
            result++;
         }
         *result=(count%10) + '0';
         result++;
         *result= 'x';
         result++;
         *result= i+'0';//cifrata
         result++;
         *result=',';
         result++;
    } 
}
    *(result-1)='\0';
}

int main(){
    const char* digits="1123458432345434";
    char result[MAX]{'\0'};
    getDigitOccurences(digits, result);
    cout<<result;
}

