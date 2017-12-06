//TIMER_SYNC
#include <iostream>
#include <chrono>
#include <boost/asio/steady_timer.hpp>

int main() {
   boost::asio::io_service io;
   boost::asio::steady_timer tim(io);
   int count = 0;
   for(;;) {
      tim.expires_from_now(std::chrono::milliseconds(1000));
      tim.wait();  //blocks
      std::cout << count++ << std::endl;
   } 
}