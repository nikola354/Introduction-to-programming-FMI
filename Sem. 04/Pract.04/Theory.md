# Теоретични задачи:

**Задача.1** Какво ще се отпечата?

```c++
void f(int b) {
   	b++;
   	a += 100;
   	std::cout << (b % 2 == 0) << std::endl;
}
 
int main() {
   	int a = 200, b = 3;
   	f(b);
   	std::cout << a << " " << b << std::endl;
}
```

**Задача.2** Какво ще се отпечата на конзолата?

```c++
#include <iostream>
int a = 100;
int main()
{
    {
        int a = 10;
        {
            a += 5;
            ::a += 5;
            int a = 3;
            a += 2;
        }
        std::cout << a << std::endl;
    }
    std::cout << a << std::endl;
}
```

**Задача.3** Какво ще се отпечата?

```c++
void f(double a = 2, double b) {
 
}
 
void print(int a) {
   	std::cout << a;
}
 
void print(double a) {
   	std::cout << a;
}

int main() {
   	double b = 22.2;
   	char c = 'A';
 
   	print(b);
   	print(c);
 
   	f(b);
}
```

**Задача.4** Какво ще се отпечата?

```c++
int num = 10;
int fun(int num) {
	std::cout << ++num << std::endl;
	return num * 3;
}

int main() {
	int num = 10;
	int res = fun(num);
	std::cout << num << " " << res;
}
```
