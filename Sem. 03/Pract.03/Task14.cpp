#include <iostream>
int main() {
    int numbers,sum=0,max=0;
    std::cin>>numbers;
    for(int i=0;i<numbers;i++)
    {
        int k;
        std::cin>>k;
        sum +=k;
        if(k>max)max = k;
    }
    if(sum % 2 == 0 && sum % max == 0) std::cout<<"Yes: " <<max;
    else std::cout<<"No";
}