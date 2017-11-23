#include <pthread.h>
#include <thread>
#include <iostream>
using namespace std;
void concurrent_function(char ID)  {
  int counter = 0; 
  while(++counter  < 1000) {
      cout << ID;
      //this_thread::yield();
   }
}

int main()   {
  struct sched_param p1, p2;
  pthread_t h1, h2;
  
  cout << "Starting Main Thread # "  << this_thread::get_id() << endl;
  
  
  thread t1 {concurrent_function,'A'};
  cout << "Created Child Thread 1 # " << t1.get_id() << endl;
  
  thread t2 {concurrent_function,'B'};
  cout << "Created Child Thread 2 # "  << t2.get_id() << endl;
  
  h1 = t1.native_handle();
  p1.sched_priority = 1;
  pthread_setschedparam(h1, SCHED_RR, &p1);
  
  h2 = t2.native_handle();
  p2.sched_priority = 99;
  pthread_setschedparam(h2, SCHED_RR, &p2);
  
  t1.join(); //wait until t1 finishes
  t2.join(); //wait until t2 finishes
  cout << "Finished." << endl;
  getchar();
}
