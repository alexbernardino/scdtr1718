#include <iostream>
#include <chrono>
#include <unistd.h>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>

using boost::system::error_code;
using std::chrono::milliseconds;
//globals
boost::asio::io_service io_;
boost::asio::steady_timer tim(io_);
boost::asio::posix::stream_descriptor input_(io_, ::dup(STDIN_FILENO));
boost::asio::streambuf input_buffer_(1024);
//forward declarations
void start_timer();
void start_read_input();
//handlers
void handle_timer(const boost::system::error_code & ec)  { 
    std::cout << '*' << std::endl;
    start_timer(); 
} 
void handle_read_input(const boost::system::error_code& error,  std::size_t length) {  
	std::cout << &input_buffer_ << std::endl;    
    start_read_input();  
}
//async initiators
void start_timer() {
	tim.expires_from_now(std::chrono::milliseconds(1000));
	tim.async_wait(&handle_timer); 
}
void start_read_input()  {      
    async_read_until(input_, input_buffer_, '\n', &handle_read_input);  
} 
//main
int main(int argc, char* argv[])   {
   start_timer();
   start_read_input();
   io_.run();  
}
