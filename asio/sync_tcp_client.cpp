#include <iostream>
#include <boost/array.hpp>  
#include <boost/asio.hpp>
using namespace boost::asio;
using ip::tcp;

int  main()  {
    io_service io;
    boost::system::error_code err; 
    tcp::resolver resolver(io); 
    tcp::resolver::query query("127.0.0.1", "10000");
    tcp::resolver::iterator endpoint = resolver.resolve(query);
    tcp::socket socket(io); 
    socket.connect(*endpoint,err); //connect and wait
    for (;;)     {
      boost::array<char, 128> buf;
      size_t len = socket.read_some(buffer(buf), err);  
      if (err == error::eof)   break; // Closed cleanly by peer.
      else if (err)  std::cout << "Unknown Error";  
      std::cout.write(buf.data(), len);
    }
  }