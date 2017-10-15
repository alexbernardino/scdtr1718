//hello4.h

#ifndef HELLO4_H
#define HELLO4_H

class Hello4 {
private: int id;
public:
	void set_id(int v) {
		id = ( v > 0 ? v : 1 );
	}
	void run(int=1,int=1);
    Hello4();
    ~Hello4();
};

#endif //HELLO4_H
