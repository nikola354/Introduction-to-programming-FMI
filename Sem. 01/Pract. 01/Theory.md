## Теоретични въпроси

# Теоретични задачи

**Задача 1:** Какво ще се отпечата на конзолата?
```c++
#include <iostream>

int main() {
	double first = 3.75;
	double second = 5.36;
	int result = first + second;
	std::cout << result << std::endl;
	return 0;
}
```

**Задача 2:** Какво ще се отпечата на конзолата?
```c++
#include <iostream>

int main() {
	double a = 1.2; 
	double b = 0; 
	int c = 4; 
	std::cout << a / !c << std::endl; 
	std::cout << b / !!false << std::endl;
	std::cout << c / b << std::endl; 
}
```

**Задача 3:** Какво ще се отпечата на конзолата?
```c++
#include <iostream>

int main() {
	int a = 10; 
	std::cout << ++++a; 
	std::cout << ++++a++; 
}
```

**Задача 4:** Какво ще отпечата следният код?

```c++
#include <iostream>

int main()
{
    	int a = 0, b = 10;
	std::cout << (((a || b) && (a || !b)) || !a);
}
```

**Задача 5:** Какво ще отпечата следният код? Имаме ли загуба на памет?

```c++
#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = 10;
    double c = 2.2;
    double d = 2.3;
    int s = c + d;
    c = a / b;
    d = 1.0 * a / b;
    int e = d;
    cout << s << endl << c << endl << d << endl << e;
}

```

**Задача 6:** Какво ще отпечата следният код?

```c++
#include <iostream>
using namespace std;

int x = 10;

int main()
{
    cout << x << endl;
    int x = 5;
    cout << x++ << endl;
    {
        int x = 15;
        cout << ++x << endl;
    }
    {
        int x = 0;
        x = x++;
        cout << x << endl;
    }
    cout << x << endl;
    return 0;
}
```

**Задача 7:** Какво ще отпечата следният код?

```c++
#include <iostream>

int main()
{
    int a = 0;
    int b = a++;
    std::cout << (a == !b) << std::endl;
    {
        int c = ++a;
        c *= 2;
        std::cout << c << std::endl;
    }
    int sum = a + b + c;
    std::cout << sum << std::endl;
    return 0;
}
```
