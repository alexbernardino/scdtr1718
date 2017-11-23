#include <thread>
#include <iostream>
using namespace std;
void concurrent_function()  {
  int counter = 0; 
  while(++counter  < 10) {
      cout << counter << ": Hello from Child Thread # "  <<   this_thread::get_id() << endl;
      this_thread::yield(); //pass time slot to other thread
   }
}
int main()   {
  cout << "Starting Main Thread # "  << this_thread::get_id() << endl;
  thread t1 {concurrent_function};
  cout << "Created Child Thread 1 # " << t1.get_id() << endl;
  thread t2 {concurrent_function };
  cout << "Created Child Thread 2 # "  << t2.get_id() << endl;
  t1.join(); //wait until t1 finishes
  t2.join(); //wait until t2 finishes
  cout << "Finished." << endl;
  getchar();
}
