#include <iostream>
bool sameNeigbouringDigits(int k){
    int previousDigit=k % 10;
    k /= 10;
   
    while(k > 0){
        int lastDigitOfK= k % 10;
        if(lastDigitOfK == previousDigit) return true;
        previousDigit = lastDigitOfK;
        k /= 10;
    }
    
    return false;
}
void run(){
  int k,l;
  std::cin>>k>>l; 
  for(int i = k;i <= l;i++){
      if(sameNeigbouringDigits(i)) std::cout<<i<<" ";
  }
}
int main() {
 run();
}
