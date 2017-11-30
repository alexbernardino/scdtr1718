#ifndef SOLID1_H
#define SOLID1_H
#include <iostream>
using namespace std;

class Solid {
protected: 
    float _d;
public:
    Solid( float d )  : _d {d}  {cout << "Solid Ctor" << endl;}
    Solid( const Solid & s) : _d {s._d} { cout << "Solid Copy Ctor" << endl;}
    Solid( Solid && s) : _d {std::move(s._d)} {cout << "Solid Move Ctor" << endl;}
    Solid & operator=(const Solid & s) {
        if(this != &s) {_d = s._d;}
        cout << "Solid Copy Assign" << endl;
        return *this;
    }
    Solid & operator=(Solid && s) {
        if(this != &s) {_d = std::move(s._d);}
        cout << "Solid Move Assign" << endl;
        return *this;
    }
    virtual ~Solid()  {cout << "Solid Dtor" << endl;}
    friend float Density(Solid &);
    virtual float CalcMass() const = 0;
};

class A {
public:
    int a;
    void f() {cout << "A::f()" << endl;}
    virtual void v() {cout << "A::v()" << endl;}
};

class B : public A {
public:
    int b;
    void f() {cout << "B::f()" << endl;}
    void v() override {cout << "B::v()" << endl;}
};

class C : public B  {
public:
    int c;
    void f() {cout << "C::f()" << endl;}
    void v() override {cout << "C::v()" << endl;}
};





#endif // SOLID1_H

