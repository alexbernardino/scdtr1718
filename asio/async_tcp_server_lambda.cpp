#include <iostream>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

using namespace boost; 
using namespace boost::asio; 
using ip::tcp;

class conn :  public enable_shared_from_this<conn> {
private:  
   	tcp::socket sock_;
   	std::string msg_;
   	conn(io_service& io) :  sock_(io)  {}
public: 
	static shared_ptr<conn> create(io_service& io) {
         return shared_ptr<conn>(new conn(io));
    }
    tcp::socket& socket() {return sock_;}
    void start() {
    	auto self = shared_from_this();
    	async_write(sock_, buffer("Hello World\n"),
    	[this, self](boost::system::error_code ec, std::size_t length) {
    		std::cout << "Sent! Now closing connection" << std::endl;
    	}); 
    }
};

class tcp_server {
private:  
    tcp::acceptor acceptor_;
public:  
    tcp_server(io_service& io)
     : acceptor_(io, tcp::endpoint(tcp::v4(), 10000))  {
     	start_accept();
     }
private:  
   void start_accept() {
       	shared_ptr<conn> new_conn =
        	conn::create(acceptor_.get_io_service());
       	acceptor_.async_accept(new_conn->socket(),
       	[this, new_conn](boost::system::error_code ec) {
       		new_conn->start();
         	start_accept();
		});
   }
};
int main()  try {
    io_service io;
    tcp_server server(io);
    io.run();
} catch(std::exception &e) {std::cout << e.what();}
