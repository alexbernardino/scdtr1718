#include <memory>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
using namespace boost::asio;  
using ip::tcp;
using namespace std;

class connection :  public
    boost::enable_shared_from_this<connection> {
private:  
  tcp::socket sock_;
  std::string msg_;
  connection(io_service& io) :  sock_(io)  {}
  void handle_write()   {/*nothing important*/}
public: 
    static shared_ptr<connection> create(io_service& io) {
         return shared_ptr<connection>(new connection(io));
    }
    tcp::socket& socket() {return sock_;}
    void start() {
        async_write(sock_,buffer("Hello World"),
             boost::bind(&connection::handle_write,
             shared_from_this())); 
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
      shared_ptr<connection> new_con =
            connection::create(acceptor_.get_io_service());
       acceptor_.async_accept(new_con->socket(),
       boost::bind(&tcp_server::handle_accept, this, new_con));
   }
  void handle_accept(shared_ptr<connection> new_con)  {
         new_con->start();
         start_accept();
   }
};
int main()  {
    io_service io;
    tcp_server server(io);
    io.run();
}
