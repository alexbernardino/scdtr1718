#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
using namespace boost::asio;
using ip::udp;

int main() {
  io_service io;
  udp::resolver resolver(io);
  udp::resolver::query query(udp::v4(),"127.0.0.1", "10000");
  udp::endpoint receiver = *resolver.resolve(query);
  udp::socket socket(io);
  socket.open(udp::v4());
  boost::array<char, 1> send_buf  = {{ 0 }};
  //send dummy data to initiate communication
  socket.send_to(buffer(send_buf), receiver);
  boost::array<char, 128> recv_buf;
  udp::endpoint sender;
  size_t len=socket.receive_from( buffer(recv_buf),sender);
  //write received data to console
  std::cout.write(recv_buf.data(), len);
  std::cout << std::endl;
}