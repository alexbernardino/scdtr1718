#ifndef CYLINDER1_H
#define CYLINDER1_H
#include "solid1.h"

constexpr double PI {3.1415};

class Cube; //forward class declaration
class Cylinder : public Solid {
    float _r, _h;
public: 
    Cylinder (float r, float h, float d)
    : _r {r}, _h {h}, Solid {d}   {
        cout<<"Cylinder Ctor"<<endl;
    }
    Cylinder (const Cylinder & c) : Solid{c} {
        _r = c._r;
        _h = c._h;
        cout << "Cylinder Copy Ctor" << endl;
    }
    Cylinder (Cylinder && c) : Solid{std::move(c)} {
        _r = std::move(c._r);
        _h = std::move(c._h);
        cout << "Cylinder Move Ctor" << endl;
    }
    Cylinder & operator=(const Cylinder & c)
    {
        if(this != &c) {
            Solid::operator=(c);
            _r = c._r;
            _h = c._h;
        }
        cout << "Cylinder Copy Assign" << endl;
        return *this;
    }
    Cylinder & operator=(Cylinder && c)
    {
        if(this != &c) {
            Solid::operator=(std::move(c));
            _r = std::move(c._r);
            _h = std::move(c._h);
        }
        cout << "Cylinder Move Assign" << endl;
        return *this;
    }
    ~Cylinder() {
        cout <<"Cylinder Dtor"<<endl;
    }
    float CalcMass(){
        return PI*_r*_r*_h*_d;
    }
    friend bool SameVol(Cube &, Cylinder &);
};
#endif //CYLINDER1_H

