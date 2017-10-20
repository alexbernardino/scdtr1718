//main_hello8.cpp

#include "hello8.h"
#include <iostream>
using namespace std;
#include <stdio.h>

int main()
{
   Hello8 obj1;
   Hello8 obj2 {8};
   
   *obj1;
   obj1.operator*();
   obj1.run();
   
   obj2.run(2,4);
   getchar();
}
