#include <iostream>
using namespace std;

class Kilobyte {
private: 
   int memblock[1024];
public:
    Kilobyte(int init_val = 0) {
       for(int i = 0; i < 1024; i++)
          memblock[i] = init_val;
       cout << "KB Ctor" << endl;
    }
    ~Kilobyte() {
       cout << "KB Dtor" << endl;
    }
    Kilobyte(const Kilobyte & kb) //copy constructor
    {
    	cout << "KB Copy Ctor" << endl;
    }
    Kilobyte & operator=(const Kilobyte & kb) //copy assignment
    {
       cout << "KB Copy Assignment" << endl;
       return *this;
    }
    Kilobyte(const Kilobyte && kb) //move constructor
    {
    	cout << "KB Move Ctor" << endl;
    }
    Kilobyte & operator=(const Kilobyte && kb) //move assignment
    {
       cout << "KB Move Assignment" << endl;
       return *this;
    }
    int get(int i) const   {
       if( i < 0 || i > 1023) return -1; 
       else return memblock[i];
    };
    int set(int i, int val) {
       if( i < 0 || i > 1023)
          return -1; 
       else {
          memblock[i]=val;
          return 0;
       }
    }
};
   
Kilobyte neg(Kilobyte kb)
{
   //Kilobyte res;                    //constructor of res
   for(int i = 0; i < 1024; i++)
      kb.set(i, -kb.get(i));
   return kb;                      //"move" return value
}	                                //destructor of res

int main()
{
   cout << sizeof(float) << endl;
   Kilobyte kb1;
   kb1.set(1000,10);
   Kilobyte kb2;
   kb2 = std::move(kb1); //kb1 gets invalid
   
   cout << kb1.get(1000) << endl;
   cout << kb2.get(1000) << endl;
}
