//main_hello6.cpp

#include "hello6.h"
#include <iostream>
using namespace std;
#include <stdio.h>

int main()
{
   {
      Hello6 obj1;
      cout << obj1.Total() << endl;
      Hello6 obj2{5};
      cout << obj2.Total() << endl;
   }
   cout << Hello6::Total() << endl;
   getchar();
}
