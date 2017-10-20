//hello7.h

#ifndef HELLO7_H
#define HELLO7_H
#include <iostream>
using namespace std;

class Hello7 {
private: 
	static int obj_count;	
	int id;
public:
	static int Total();
	void run(int=1,int=1);
	void operator*();
    Hello7(int v = 1) 
    : id{ v > 0 ? v : 1}
    {
        obj_count++;
    	cout << "Ctor " << id << endl;
    }
    ~Hello7() {
        obj_count--;
    	cout << "Dtor " << id << endl;
	}
};

#endif //HELLO7_H
