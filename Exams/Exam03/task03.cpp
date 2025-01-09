#include <iostream>
long nums[] = { 15, 60, 90 };

int fun1(long* const a, char b[]) {
    char* p = new char[10]; //УТЕЧКА

    for (size_t i = 0; i < 10; i++)
        p[i] = b[i];

    for (size_t i = 0; i < 10; i++)
        std::cout << b[i] << ' '; //h e l l o 0 //още 4 символа, които не може да определим предварително
     
    std::cout << a[9] << std::endl; //недефинирано поведение (или се извежда 0 - и двата варианта са ок)
    a[9] = 200;
    std::cout << a[9] << std::endl;//200
    
    std::cout << *nums << std::endl; //15 (заради ред 2)

    return 0;
}

int main()
{
    long nums[10] = { 0, 10, 20, 30 };
    char str[10] = "hello";

    fun1(nums, str);
    std::cout << *nums << std::endl//0
        << ::nums; //адресът на глобалния масив

}

