#include "vector.h"
#include <iostream>
using namespace std;


Vector neg(Vector& x)
{
    cout << "Enter neg &" << endl;
    Vector res(x.size());
    for(int i=0; i < x.size(); i++)
        res[i] = -x[i];
    return res;
}
   
/*Vector neg(Vector x)
{
    cout << "Enter neg" << endl;
    Vector res(x.size());
    for(int i=0; i < x.size(); i++)
        res[i] = -x[i];
    return res;
}*/

Vector neg(Vector x)
{
    cout << "Enter neg &&" << endl;
    for(int i=0; i < x.size(); i++)
        x[i] = -x[i];
    return x;
}

   
int main(int argc, char *argv[])
{
   //Vector v1 {10};
   Vector v4 {10};
   v4 = neg(std::move(Vector{10}));
   //Vector v4 = neg(std::move(v1));
   //Vector v4 = neg(std::move(Vector{10}));
   //cout << v1[5] << endl;
   //cout << v2[5] << endl;
   //cout << v3[5] << endl; 
   cout << v4[5] << endl;  
}  
