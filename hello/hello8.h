//hello8.h

#ifndef HELLO8_H
#define HELLO8_H
#include <iostream>
using namespace std;

class Hello8 {
private: 
	static int obj_count;	
	int const id;
public:
	static int Total();
	void run(int=1,int=1) const;
	void operator*() const;
    Hello8(int v = 1)
    : id{ v > 0 ? v : 1}
    {
        obj_count++;
    	cout << "Ctor " << id << endl;
    }
    ~Hello8() {
        obj_count--;
    	cout << "Dtor " << id << endl;
	}
};

#endif //HELLO8_H
