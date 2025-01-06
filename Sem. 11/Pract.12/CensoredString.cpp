
#include <iostream>

using namespace std;

const char SPECIAL_SYMBOL = '*';

bool isNum(char symbol)
{
    return (symbol >='0' && symbol <='9');
}

int getSizeCensored(const char * str)
{
    int size = 0; bool onNumberStreak=false;
    while(*str != '\0')
    {
        if(isNum(*str))
        {
             if(onNumberStreak == false)
             {
                 size ++;
                 onNumberStreak = true;
             }
        }
        else{
            onNumberStreak = false;
            size++;
        }

        str++;
    }

    return size;
}

char* censoreNumbers(const char* str)
{
    int size= getSizeCensored(str);

    char* censored = new char [size+1];

    int indexStr = 0; bool onNumberStreak = false;
    int indexCensored = 0; char symbol;

    while(str[indexStr]!='\0')
    {
        symbol = str[indexStr];

        if(isNum(symbol))
        {
            if(onNumberStreak==false)
            {
                onNumberStreak=true;
                censored[indexCensored] = SPECIAL_SYMBOL;
                indexCensored++;
            }
        }
        else{
            onNumberStreak = false;
            censored[indexCensored] = str[indexStr];
            indexCensored++;
        }

        indexStr++;
    }

    censored[size]='\0';


    return censored;
}

void printStr(char * str)
{
    while(*str!='\0')
    {
        cout<<*str;
        str++;
    }
}

int main() {
     const char * str = "abc1234dgg4fsdg5";

     char * censored = censoreNumbers(str);

     printStr(censored);

     delete[] censored;

    return 0;
}
