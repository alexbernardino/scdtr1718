#include <string>
#include <iostream>
#include <memory>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>

using namespace boost::asio;
using boost::asio::ip::udp;
using namespace std;

class udp_server  {
private:
   udp::socket sock_;
   udp::endpoint remote_ep_;
   boost::array<char, 1> recv_buffer_;
   void handle_receive();
   void handle_send(shared_ptr<string>  msg);
   void start_receive();
public:
   udp_server(io_service& io)
       : sock_(io, udp::endpoint(udp::v4(), 10000))   {
       start_receive();
    }
};

void udp_server::start_receive() {
   sock_.async_receive_from( buffer(recv_buffer_),     
       remote_ep_,
       boost::bind(&udp_server::handle_receive,  this));
}
void udp_server::handle_receive()  {
   shared_ptr<string> msg(new string("Hello"));
   sock_.async_send_to(buffer(*msg), 
         remote_ep_,
         boost::bind(&udp_server::handle_send, this, msg));
   start_receive();
}
void udp_server::handle_send(shared_ptr<string>  msg) {
   cout << "Sent: " << *msg << endl; 
}

int main()  
   try {
      io_service io;
      udp_server server(io);
      io.run();
   } 
   catch (exception& e)  {    
   	  cerr << e.what() << endl;  
}
