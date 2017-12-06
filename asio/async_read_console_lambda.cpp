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
//async initiators
void do_timer() {
	tim.expires_from_now(milliseconds(1000));
	tim.async_wait(
		[](const boost::system::error_code & ec){
			std::cout << '*' << std::endl;
    		do_timer();
    	}); 
}
void do_read_input()  {      
    async_read_until(input_, input_buffer_, '\n', 
    	[](const error_code& error,  std::size_t length){
    		std::cout << &input_buffer_ << std::endl;    
   			do_read_input(); 
    	});  
} 
//main
int main(int argc, char* argv[])   {
   do_timer();
   do_read_input();
   io_.run();  
}
