//hello4.cpp

#include "hello4.h"
#include <iostream>
using namespace std;


void Hello4::run(int l, int c) {
   for(int i = 0; i < l; i++) {
      for(int j = 0; j < c; j++)
   		cout<<"Hello " << id << ", ";
      cout << endl;
   }
}

Hello4::Hello4() {
   cout << "Ctor " << id << endl;
}


Hello4::~Hello4() {
   cout << "Dtor " << id << endl;
}
