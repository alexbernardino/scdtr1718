#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

class Vector { 
private: 
    double* elem;                                         
    int sz; 			                     
public: 
    Vector(int s)                                        
    : elem{new double[s]}, sz{s}
    {               
        for (int i=0; i!=s; ++i) elem[i]=0;
        cout << "Ctor size" << endl;         
    }
    Vector(const Vector& a)
    : elem{new double[a.sz]}, 
      sz{a.sz}
    { 
       for (int i=0; i!=sz; ++i) 
          elem[i] = a.elem[i]; 
       cout << "Ctor copy" << endl; 
    }
    Vector& operator=(const Vector& a) 
    { 
       double*p = new double[a.sz]; 
       for (int i=0; i!=a.sz; ++i)  
          p[i] = a.elem[i]; 
       delete[] elem;     // delete old elements 
       elem = p;
       sz = a.sz; 
       cout << "Assign copy" << endl; 
       return *this; 
    }
    Vector(Vector && a)
    : elem{a.elem}, // "grab the elements" from a 
      sz{a.sz} 
    { 
       a.elem = nullptr; // now a has no elements 
       a.sz = 0; 
       cout << "Ctor move" << endl; 
    } 
    Vector & operator=(Vector && a)
    {
       elem = a.elem;
       sz = a.sz;
       a.elem = nullptr;
       a.sz = 0;
       cout << "Assign move" << endl; 
       return *this;
    }

    ~Vector() {                                               
          delete[] elem; 
        cout << "Dtor" << endl;                                
   } 
   double& operator[](int i) {
          return elem[i]; 
   } 
   int size() const {
      return sz;
   } 
}; 

#endif //VECTOR_H
