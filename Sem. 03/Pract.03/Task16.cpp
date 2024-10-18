#include <iostream>
#include <cmath>
int main(){
    int n,start=1;
    std::cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
      {
            if(i%2==1)
          {
                std::cout<< start << " ";
                start ++;
            }
            if(i%2==0)
            {
                start--;
                std::cout<< start<< " ";
            }
        }
        std::cout << "\n";
        start+=n;
    }

}