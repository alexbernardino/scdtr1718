//hello9.h

#ifndef HELLO9_H
#define HELLO9_H
#include <iostream>
using namespace std;

class Hello9 {
private: 
	static int obj_count;	
	int const id;
public:
        int get_id() const {
           return id;
        }
	static int Total();
	void run(int=1,int=1) const;
	void operator*() const;
    Hello9(int v = 1)
    : id{ v > 0 ? v : 1}
    {
        obj_count++;
    	cout << "Ctor " << id << endl;
    }
    ~Hello9() {
        obj_count--;
    	cout << "Dtor " << id << endl;
	}
};

#endif //HELLO9_H
