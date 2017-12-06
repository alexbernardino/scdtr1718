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
   void start_receive();
public:
   udp_server(io_service& io)
       : sock_(io, udp::endpoint(udp::v4(), 10000))   {
       start_receive();
    }
};

void udp_server::start_receive() {
   	sock_.async_receive_from( buffer(recv_buffer_), remote_ep_,
   	[this](const boost::system::error_code &ec, size_t bytes_recv){
   		shared_ptr<string> msg(new string("Hello"));
   		sock_.async_send_to(buffer(*msg), remote_ep_,
    	[this,msg](const boost::system::error_code &ec, size_t bytes_sent) {
    		cout << "Sent: " << *msg << endl; 
       	}); //end async_send_to
       	start_receive();
    }); //end async_receive_from
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
