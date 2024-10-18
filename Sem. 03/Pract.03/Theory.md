# Теоретични задачи:

**Задача 1**:   Какво ще се отпечата на конзолата?

```c++
#include <iostream>

int main()
{
	int i;

	for (i = 0; i < 5; i++) {
		if (i == 3) {
			continue;
    		}
    		std::cout << i << " ";
	}

	std::cout << i << std::endl;
	return 0;
}
```

**Задача 2**:	Какво ще се отпечата на конзолата?

```c++
#include <iostream>

int main()
{
	int i = 9;

	while (i = 12)
	{
	    	if (i == 0)
		break;
    		if (i == 9)
        	continue;
    		i--;
    		std::cout << i << std::endl;
	}

	return 0;
}
```

**Задача 3**:	Какво ще се отпечата на конзолата?

```c++
#include <iostream>

using namespace std;

int main()
{
	int iter = 10;

	while (true)
	{
	    	cout << iter << endl;

    		if (iter == 0)
    		{
        		break;
    		}

     		if (iter == 1)
    		{
        		continue;
    		}

    		iter--;
	}

	return 0;
}
```

**Задача 4**:    Какво ще се отпечата на конзолата?

```c++
#include <iostream>

int main()
{
   	for (int i = 0, j = 10; i < 2, j > 1; i++, j -= 2) {
		std::cout << i << " " << j << std::endl;
   	}

   	return 0;
}
```


**Задача 5**:	Какво ще се отпечата на конзолата?

```c++
#include <iostream>

int main() {
	int i = 0;

	do {
		std::cout << i << " ";
    		i++;
	} while (i < 5, i % 2 == 0);

	std::cout << std::endl;

	return 0;
}
```

**Задача 6**:	Какво ще се отпечата на конзолата?

```c++
do {
	int y = 1;
	std::cout << y++ << " ";
} while (y <= 10);
```
