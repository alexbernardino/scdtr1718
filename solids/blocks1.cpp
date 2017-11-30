#include "cube1.h"
#include "cylinder1.h"
#include "friends.h"
#include "totalmass.h"

int main()
{
    Solid *svect[4];
    svect [0] = new Cube {1.25,1.0};
    svect [1] = new Cube {1.0,0.9};
    svect [2] = new Cylinder {1,1,0.9};
    svect [3] = nullptr;
    float tot = TotalMass(svect);
    cout << "Total Mass: " << tot << endl;
    for(int i=0; svect[i] != nullptr; i++)
        delete svect[i];

    C c;
    c.f();        //C::f();
    c.B::f();   //B::f();
    c.A::f();   //A::f();
    c.v();       //C::v();
    c.B::v();  //B::v();
    c.A::v();  //A::v();


}

