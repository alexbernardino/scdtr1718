//hello9.cpp

#include "hello9.h"
#include <iostream>
using namespace std;

int Hello9::obj_count = 0;

int Hello9::Total()  {
	return obj_count;
}

void Hello9::run(int l, int c) const {
   for(int i = 0; i < l; i++) {
      for(int j = 0; j < c; j++)
   	cout<<"Hello " << id << ", ";
      cout << endl;
   }
}

void Hello9::operator*() const
{
	run();
}
