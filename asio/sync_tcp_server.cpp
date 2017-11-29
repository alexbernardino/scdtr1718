#include <iostream>
#include <boost/asio.hpp>
using namespace boost::asio;
using ip::tcp;

int main() 
{
    //initialize services
    io_service io;                       
    //create a listening socket
    // bind and start listening at port 10000
    auto ep = tcp::endpoint(tcp::v4(), 10000);
    std::cout << "Listening at: " << ep << std::endl;
    tcp::acceptor acceptor(io, ep);
    for (;;) 
   {              
        //create service socket       
        tcp::socket socket(io);    
        //wait client to connect                 
        acceptor.accept(socket);
        //client is accessing service
        write(socket, buffer("Hello World\n"));
  }  
}