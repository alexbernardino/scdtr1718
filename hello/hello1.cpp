//hello1.cpp

#include "hello1.h"
#include <iostream>
using namespace std;

void Hello1::set_id(int x)
{
   if(x>0) id = x;
   else    id = 1;
} 

void Hello1::run() {
   cout<<"Hello " << id << endl;
}
