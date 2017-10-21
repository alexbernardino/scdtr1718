//main_hello9.cpp

#include "hello9.h"
#include <iostream>
using namespace std;
#include <stdio.h>


Hello9 create_consecutive(const Hello9 & obj)
{
   int new_id = obj.get_id() + 1;
   Hello9 new_hello {new_id};
   return new_hello;
}


int main()
{
   Hello9 obj1;
   Hello9 obj2 = create_consecutive(obj1);
   obj1.run();
   obj2.run();
   getchar();
}
