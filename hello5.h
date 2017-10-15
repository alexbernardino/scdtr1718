//hello5.h

#ifndef HELLO5_H
#define HELLO5_H
#include <iostream>
using namespace std;

class Hello5 {
private: int id;
public:
	void run(int=1,int=1);
    Hello5(int v = 1) 
    : id{ v > 0 ? v : 1}
    {
    	cout << "Ctor " << id << endl;
    }
    ~Hello5() {
    	cout << "Dtor " << id << endl;
	}
};

#endif //HELLO5_H
