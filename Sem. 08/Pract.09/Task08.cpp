#include <iostream>

using namespace std;

int main(){
    int x, m, n; //23 4 3
    cin >> x >> m >> n;

    if (m - n < -1) { //to cover cases such as 23 1 5 (we take the last 2 bits)
        int mask = 1 << (m + 1);
        mask--;
        cout << (x & mask);
        return 0;
    }

    int mask = 1 << n; //mask = (1000)
    mask--; //mask = (111)
    x >>= (m - n + 1);  //23 = (10111) => 101

    cout << (x & mask); // 101 & 111
}