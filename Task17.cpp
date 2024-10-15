#include <iostream>
using namespace std;


int main()
{
    char a, b, c, d, e;
    cin >> a>> b>> c>> d>> e;
    int first = e >= a && e <= b;
    int second = e >= c && e <= d;

    bool isUnion = first || second;
    cout << isUnion;
    bool isIntersection = first && second;

    cout << isIntersection;
    cout << (first && (!second));
    cout << (isUnion && (!isIntersection));


    

}


