//TIMER_ASYNC
#include <iostream>
#include <chrono>
#include <boost/asio/steady_timer.hpp>

boost::asio::io_service io;
boost::asio::steady_timer tim(io);
int count = 0;

void deadline_handler(const boost::system::error_code & ec)  { 
    std::cout << count++ << std::endl;
    tim.expires_from_now(std::chrono::milliseconds(1000));
    tim.async_wait(&deadline_handler); } 

int main() {
   tim.expires_from_now(std::chrono::milliseconds(1000));
   tim.async_wait(&deadline_handler); 
   io.run();  
}