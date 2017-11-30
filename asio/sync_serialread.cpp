//SERIALREAD.CPP
#include <iostream>
#include <boost/asio.hpp>
using namespace std;
using namespace boost::asio;

int main() {
    io_service io;                //initialize services                  
    serial_port sp(io);        //create io object
    boost::system::error_code ec;
    sp.open("/dev/ttyACM0", ec );    //connect to port
    if( ec ) {cout << "Error"; return -1;}
    //set baud rate
    sp.set_option(serial_port_base::baud_rate(9600), ec );
    if( ec ) { cout << "Error"; return -1; }
    for (;;) {           
       boost::asio::streambuf streambuffer;
       string str;
       int nbytes = read_until(sp, streambuffer, '\n', ec );
       if( ec ) { cout << "Error"; return -1; }
       cout << "Received " << nbytes << " bytes from port: ";
       cout << &streambuffer << endl;
    }  
}  
