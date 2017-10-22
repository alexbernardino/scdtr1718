#include "vector.h"
#include <iostream>
using namespace std;


Vector neg(Vector& x)
{
    Vector res(x.size());
    for(int i=0; i < x.size(); i++)
        res[i] = -x[i];
    return res;
}
   

   
int main(int argc, char *argv[])
{
   Vector v1 {10};
   v1[5] = 1;
   Vector v2 {10};
   v2[5] = 2;
   Vector v3 = neg(v1);
   Vector v4 = v1;
   v4 = neg(v2);
   cout << v1[5] << endl;
   cout << v2[5] << endl;
   cout << v3[5] << endl; 
   cout << v4[5] << endl;  
}  
