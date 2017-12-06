#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>

using namespace boost::asio;
using ip::udp;

int main() {
  io_service io;
  auto ep = udp::endpoint(udp::v4(),10000);
  std::cout << "Receiving at: " << ep << std::endl;
  udp::socket socket(io,ep);
  for (;;)    {
      boost::array<char, 1> recv;
      udp::endpoint client;
      boost::system::error_code err;
      //client endpoint retrieved on receive_from
      socket.receive_from(buffer(recv),client, 0, err);
      if (err && err != error::message_size) {
         std::cout << "Error"  << std::endl;  
         return -1;
      }
      boost::system::error_code ignored;
      socket.send_to(buffer("Hello\n"), client, 0,  ignored);
  }
}
