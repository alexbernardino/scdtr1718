#include <chrono>
#include <thread>
#include <iostream>
using namespace std;
using namespace std::chrono;

void concurrent_function(int samp_time_ms) {
   steady_clock::time_point start_time = steady_clock::now();
   //milliseconds period(samp_time_ms);
   steady_clock::time_point next_time = start_time + milliseconds(samp_time_ms);
   int counter = 0;
   while( ++counter < 10 ) {
      cout << counter << ": Hello from Child Thread # "
           << this_thread::get_id() << endl;
      this_thread::sleep_until(next_time);
      next_time += milliseconds(samp_time_ms);
   }
   steady_clock::time_point end_time = 
      steady_clock::now();
   cout << "Elapsed Time in Child Thread # "
        << this_thread::get_id() << ": " 
        << duration<double,milli>(end_time - start_time).count() << endl;
}

int main()
{
   cout<< "Starting Main Thread #" << this_thread::get_id() << endl;
   steady_clock::time_point start_time = 
      steady_clock::now();
   thread t1(concurrent_function, 200);
   cout << "Created Child Thread 1 # "
        << t1.get_id() << endl;
   this_thread::sleep_for(milliseconds(1000));
   thread t2(concurrent_function, 200);
   cout << "Created Child Thread 2 # "
        << t2.get_id() << endl;
   this_thread::sleep_for(milliseconds(1000));
   t1.join();
   t2.join();
   cout << "Finished." << endl;
   steady_clock::time_point end_time = 
      steady_clock::now();
   duration<double,milli> elapsed(end_time - start_time);
   cout << "Elapsed Time in Main Thread # "
        << this_thread::get_id() << ": " 
        << elapsed.count() << endl; 
   getchar(); 
}
