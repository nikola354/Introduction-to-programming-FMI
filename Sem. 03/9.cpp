#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int number,x,y;
    cin>>number;
    if(number<0) number=-number;
    //x+y=number;
    for (int i=2;i<=number/2;i++){
        int x=i;
        int y=number-x;
        int sqrtx= sqrt(x);
        int sqrty=sqrt(y);
        bool Primex=true;
        if (x<2) Primex=false;
        for (int j=2;j<=sqrt(x);j++){
            if(x%j==0){
                Primex=false; 
                break;
            }
            }
            bool Primey=true;
        for(int z=2;z<=sqrt(y);z++){
            if(y%z==0){ Primey=false;
            break;
            }
        }
        if(Primex==true&&Primey==true){
            cout<<x<<" + "<< y << " = "<<number<<endl;
        }
    }
}  

    

