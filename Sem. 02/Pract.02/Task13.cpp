#include <iostream>
#include <cmath>
int main(){
 int radius,pointX,pointY;
 std::cin>>radius>>pointX>>pointY;
 double distanceToPoint = sqrt(pointX*pointX + pointY*pointY);
 if(distanceToPoint < radius){
     std::cout<<"In the circle";
 }else if (distanceToPoint == radius) {
     std::cout<<"On the cirlce";
 }else
     std::cout<<"Out of the circle";
}