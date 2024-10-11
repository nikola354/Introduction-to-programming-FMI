## Теоретични въпроси:

1)    Еквивалентни ли са двете парчета код?


```c++
if (a > 0) if (b > 0) std::cout << 1; else std::cout << 3;
```

```c++
if (a > 0) {
if (b > 0) {
    std::cout << 1;
 }
}
else std::cout << 3;
```

2)	Какво ще се отпечата на конзолата?

```c++
int num = 25;
int a = 7;
if (++num, num += 2, num > 27) {
	num % 2 == 0 ? num /= 2 : a -= 4;
}
if (num==12, num - 2 * a)  {
	std::cout << num+1;
}
else {
	std::cout << num+2;
}
```

3)    Какво ще се отпечата на конзолата?

```c++
int x = 5;
char ch = 'A';
switch (x % 3) {
case 0:
	std::cout << "Zero\n";
	break;
case 1:
	std::cout << "One\n";
case 2:
	std::cout << "Two\n";
	ch = 'C';
case 3:
	std::cout << "Three\n";
	break;
default:
	std::cout << "Default\n";
}
switch (ch) {
case 'A':
	std::cout << "Character A\n";
	break;
case 'B':
	std::cout << "Character B\n";
	break;
case 'C':
	std::cout << "Character C\n";
default:
	std::cout << "Character Default\n";
}
return 0;
```

4)    Преобразувайте кода, като използвате switch, вместо if и if else

```c++

unsigned a;
std::cin>>a;
if (a == 2) {
	std::cout << "Two" << std::endl;
}
if (a <= 1) {
	std::cout << "Less" << std::endl;
}
else if (a == 3) {
	std::cout << "Three" << std::endl;
}
else {
	std::cout << "Dont know" << std::endl;
}
```
