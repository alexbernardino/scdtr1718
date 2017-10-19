//hello7.cpp

#include "hello7.h"
#include <iostream>
using namespace std;

int Hello7::obj_count = 0;

int Hello7::Total()  {
	return obj_count;
}

void Hello7::run(int l, int c) {
   for(int i = 0; i < l; i++) {
      for(int j = 0; j < c; j++)
   	cout<<"Hello " << id << ", ";
      cout << endl;
   }
}

void Hello7::operator*()
{
	run();
}
