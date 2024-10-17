#include <iostream>
int main(){
    double fisrtSide,secondSide,thirdSide;
    std::cin>>fisrtSide>>secondSide>>thirdSide;
    bool marker_1 = fisrtSide + secondSide > thirdSide;
    bool marker_2 = thirdSide + secondSide > fisrtSide;
    bool marker_3 = fisrtSide + thirdSide > secondSide;
    if(marker_1 && marker_2 && marker_3) std::cout<<"This thriangle exists.";
    else std::cout<<"This triangle doesn't exist.";
    return 0;
}