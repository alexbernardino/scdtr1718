//main_hello7.cpp

#include "hello7.h"
#include <iostream>
using namespace std;
#include <stdio.h>

int main()
{
   Hello7 obj1;
   Hello7 obj2 {7};
   
   *obj1;
   obj1.operator*();
   obj1.run();
   
   obj2.run(7);
   getchar();
}
