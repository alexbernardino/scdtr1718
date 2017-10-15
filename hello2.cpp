//hello2.cpp

#include "hello2.h"
#include <iostream>
using namespace std;

void Hello2::run() {
   cout<<"Hello " << id << endl;
}

void Hello2::run(int l, int c) {
   for(int i = 0; i < l; i++) {
      for(int j = 0; j < c; j++)
   		cout<<"Hello " << id << ", ";
      cout << endl;
   }
}
