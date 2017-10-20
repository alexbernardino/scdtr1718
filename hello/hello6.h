//hello6.h

#ifndef HELLO6_H
#define HELLO6_H
#include <iostream>
using namespace std;

class Hello6 {
private: 
	static int obj_count;	
	int id;
public:
	static int Total();
	void run(int=1,int=1);
    Hello6(int v = 1) 
    : id{ v > 0 ? v : 1}
    {
        obj_count++;
    	cout << "Ctor " << id << endl;
    }
    ~Hello6() {
        obj_count--;
    	cout << "Dtor " << id << endl;
	}
};

#endif //HELLO6_H
