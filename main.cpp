#include <iostream>

#include "mystring.h"

int main()
{
    int *a = new int;
    *a = 89;
    std::cout << a << " " << *a << " " << &a << "\n";
    delete a;
    return 0;
}
