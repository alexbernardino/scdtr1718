#ifndef CUBE1_H
#define CUBE1_H
#include "solid1.h"

class Cylinder; //forward class declaration
class Cube : public Solid {
    float _s;
public: 
    Cube (float s, float d)
    : _s {s},  Solid{d}    {
        cout << "Cube Ctor" << endl;
    }
    Cube (const Cube & c) : Solid{c} {
        _s = c._s;
        cout << "Cube Copy Ctor" << endl;
    }
    Cube (Cube && c) : Solid{std::move(c)} {
        _s = std::move(c._s);
        cout << "Cube Move Ctor" << endl;
    }
    Cube & operator=(const Cube & c)
    {
        if(this != &c) {
            Solid::operator=(c);
            _s = c._s;
        }
        cout << "Cube Copy Assign" << endl;
        return *this;
    }
    Cube & operator=(Cube && c)
    {
        if(this != &c) {
            Solid::operator=(std::move(c));
            _s = std::move(c._s);
        }
        cout << "Cube Move Assign" << endl;
        return *this;
    }
    ~Cube() override {
          cout << "Cube Dtor" << endl;
    }
    friend bool SameVol(Cube &, Cylinder &);
    float CalcMass() const override final
    {
        return _s*_s*_s*_d;
    }
};
#endif //CUBE1_H

