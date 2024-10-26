#include <iostream>
int getRemainder(int first, int second){
    int timesCanBeDivided=first/second;
    return first - timesCanBeDivided*second;
}
int main(){
    int first,second;
    std::cin>>first>>second;
    std::cout<<getRemainder(first,second);
    
}