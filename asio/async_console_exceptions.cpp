#include <iostream>
#include <chrono>
#include <unistd.h>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>

using boost::system::error_code;
using std::chrono::milliseconds;

class async_console {
    boost::asio::streambuf input_buffer_; 
    boost::asio::steady_timer tim_;
    boost::asio::posix::stream_descriptor input_;
public:
    void start() {do_timer(); do_read_input(); }
    async_console (boost::asio::io_service &io) 
    : input_(io, ::dup(STDIN_FILENO)), 
      tim_(io), input_buffer_(1024) {
           start();
    }
    void do_timer() {
        tim_.expires_from_now(milliseconds(1000));
        tim_.async_wait(
        [this](const error_code & ec){
            std::cout << '*' << std::endl;    
            do_timer();    	
        }); 
    }
    void do_read_input()  {          
        async_read_until(input_, input_buffer_, '\n',   
        [this](const error_code& error,  std::size_t length){
            std::cout << &input_buffer_ << std::endl;
            do_read_input();     	
         });  
    }
}; // end class async_console

//main
int main(int argc, char* argv[])  try {
   boost::asio::io_service io;
   async_console ac(io);
   io.run();  
}
catch(std::exception &e) {std::cerr << e.what();}
