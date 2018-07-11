#include <iostream>
#include <asio.hpp>

using asio::ip::udp;

int main(int argc, char* argv[])
{
    std::cout << "Starting client running!" << std::endl;
    std::string hostName{"hostName"};
    try
    {
        if (argc >= 2)
        {
            hostName = argv[1];
        }
        asio::io_service io_service;
        udp::resolver resolver(io_service);
        udp::resolver::query query(udp::v4(), hostName, "daytime");
        udp::endpoint receiver_endpoint = *resolver.resolve(query);
        udp::socket socket(io_service);
        socket.open(udp::v4());

        std::array<char, 1> send_buf  = {{ 0 }};
        socket.send_to(asio::buffer(send_buf), receiver_endpoint);
        std::array<char, 128> recv_buf;
        udp::endpoint sender_endpoint;
        size_t len = socket.receive_from(
            asio::buffer(recv_buf), sender_endpoint);
        std::cout.write(recv_buf.data(), len);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
