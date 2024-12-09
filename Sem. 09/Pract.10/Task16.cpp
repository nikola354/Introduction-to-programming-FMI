#include <iostream>
using namespace std; 
void swap(int & ptr1, int &ptr2){
    int temp=ptr1;
    ptr1=ptr2;
    ptr2=temp;
    
}
void copyArr(const char* str, char* result){
    while(*str){
        if(*str >= 'A' && *str <= 'Z'){
            *result = *str + 32;
            result++;
        }
        else if(*str >= 'a' && *str <= 'z'){
                *result = *str;
                result++;
        }
        str++;
  } *result = '\0';
}

void sortCharacters(const char* str, char* result){
    if(!str || *result) return;
    copyArr(str, result);
    
    for(char *ptr = result; *ptr; ptr++){
         char *min = ptr;
         for(char *jtr= (ptr+1); *jtr; jtr++){
            if(*min > *jtr) min=jtr;
         }
         if(*min != *ptr) swap(*min,*ptr);
    } 
}
int main(){
    const char* str="Hello World!";
    char result[1024]{'\0'};
    sortCharacters(str,result);
    cout<<result;
}

