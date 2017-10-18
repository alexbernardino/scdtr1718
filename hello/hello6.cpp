//hello6.cpp

#include "hello6.h"
#include <iostream>
using namespace std;

int Hello6::obj_count = 0;

void Hello6::run(int l, int c) {
   for(int i = 0; i < l; i++) {
      for(int j = 0; j < c; j++)
   	cout<<"Hello " << id << ", ";
      cout << endl;
   }
}

int Hello6::Total()  {
	return obj_count;
}
