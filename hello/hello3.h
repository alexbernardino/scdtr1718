//hello3.h

#ifndef HELLO3_H
#define HELLO3_H

class Hello3 {
private: int id;
public:
	void set_id(int v) {
		id = (v > 0 ? v : 1);
	}
	void run(int=1,int=1);
};

#endif //HELLO3_H
