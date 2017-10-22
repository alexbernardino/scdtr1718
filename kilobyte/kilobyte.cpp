#include <iostream>
using namespace std;

class Kilobyte {
private: 
   int memblock[1024];
public:
    Kilobyte() {
       for(int i = 0; i < 1024; i++)
          memblock[i] = 0;
       cout << "KB Ctor" << endl;
    }
    ~Kilobyte() {
       cout << "KB Dtor" << endl;
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
   
Kilobyte neg(const Kilobyte & kb)
{
   Kilobyte res;                    //constructor of res
   for(int i = 0; i < 1024; i++)
      res.set(i, -kb.get(i));
   return res;                      //"move" return value
}	                                //destructor of res

int main()
{
   Kilobyte kb1;
   kb1.set(1000,10);
   Kilobyte kb2 = neg(kb1);
   cout << kb1.get(1000) << endl;
   cout << kb2.get(1000) << endl;
}
