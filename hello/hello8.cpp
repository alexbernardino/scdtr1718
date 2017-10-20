//hello8.cpp

#include "hello8.h"
#include <iostream>
using namespace std;

int Hello8::obj_count = 0;

int Hello8::Total()  {
	return obj_count;
}

void Hello8::run(int l, int c) const {
   for(int i = 0; i < l; i++) {
      for(int j = 0; j < c; j++)
   	cout<<"Hello " << id << ", ";
      cout << endl;
   }
}

void Hello8::operator*() const
{
	run();
}
