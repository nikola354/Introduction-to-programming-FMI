
#include <iostream>
using namespace std;

int main()
{
    double a;
    cin >> a;
    char operation;
    cin >> operation;
    double b;
    cin >> b;

    switch (operation) {
    case'+': cout << a + b; break;
    case'-': cout << a - b; break;
    case'/': cout << a / b; break;
    case'*': cout << a * b; break;
    }


}
