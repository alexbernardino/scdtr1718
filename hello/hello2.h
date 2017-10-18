//hello2.h

#ifndef HELLO2_H
#define HELLO2_H

class Hello2 {
private: int id;
public:
	void set_id(int v) 
	{
	    if(v > 0) id = v;
   		else      id = 1;
   	}
	void run();
	void run(int,int);
};

#endif //HELLO2_H
