#include <iostream>
int main() {
    int num,n,k,sum,maxDifference=0;
    std::cin>>num>>n>>k;
    sum = n + k;
    bool isEqual=true;
    for(int i=1;i<num;i++){
        int n,k,localDifference;
        std::cin>>n>>k;
        if(sum != n+k){
            if(n>k)localDifference = n - k;
            else localDifference = k - n;
            isEqual=false;
            if(localDifference > maxDifference) maxDifference = localDifference;
        }
    }
    if(isEqual) std::cout<<"Equal sums: "<<sum;
    else std::cout<<"Different sums. Max Difference: "<<maxDifference;
}