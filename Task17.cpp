#include <iostream>
using namespace std;

int getAbs(int num){
    return (num < 0 ? -num : num);
}

int getDivision(int first, int second) {
    if (second == 0)
        return 0;//impossible division

    int sign = (((first * second) > 0) ? +1 : -1);

    first = getAbs(first);
    second = getAbs(second);
    

    int count = 0;
    while (first - second >= 0) {
        first -= second;
        count++;
    }


    return count * sign;
}

int main()
{
    cout << getDivision(-8, 2);
    
}

