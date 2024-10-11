#include <iostream>
#include <cmath>

 const double EPSILON = 0.0001;

 int main() {
     double x, y;
     std::cin >> x >> y;
     double r;
     std::cin >> r;

     double length = sqrt((x * x) + (y * y));

     if (std::fabs(length - r) < EPSILON) {
         std::cout << "On the border" << std::endl;
     } else if (length < r) {
         std::cout << "Inside" << std::endl;
     } else {
         std::cout << "Outside" << std::endl;
     }
 }