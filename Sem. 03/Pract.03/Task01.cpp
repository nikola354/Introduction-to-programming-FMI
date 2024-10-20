#include <iostream>
int main() {
    int n,m;
    std::cin>>n>>m;
    if(n<0 || m > 255 || n > 255 || (n>m) || m<0){
        std::cout<<"Invalid codes";
        return 0;
    }
    for(int i=n;i<=m;i++){
        std::cout<<i<<" --> " <<(char)i<<"\n";
    }
}
