//main_hello5.cpp

#include "hello5.h"
#include <stdio.h>

int main()
{
   Hello5 obj1;
   obj1.run();
   Hello5 obj2{5};
   obj2.run();
   getchar();
}
