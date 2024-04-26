#include <iostream>
#include <boost/asio.hpp>
using namespace boost::asio;
using ip = boost::asio::ip;

int main() {
    try {
        io_context io_context;
        ip::tcp::endpoint endpoint(ip::tcp::v4(), 8080); // port 8080
        ip::tcp::socket socket(io_context, endpoint);
        std::vector<char> buffer(1024);
        while (true) {
            size_t bytes_read = socket.read_some(buffer);
            std::cout << "Received: " << std::string(buffer.begin(), buffer.begin() + bytes_read) << std::endl;
            socket.write_some(boost::asio::buffer("Message received\n"));
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
