//hello5.cpp

#include "hello5.h"
#include <iostream>
using namespace std;

void Hello5::run(int l, int c) {
   for(int i = 0; i < l; i++) {
      for(int j = 0; j < c; j++)
   		cout<<"Hello " << id << ", ";
      cout << endl;
   }
}

