#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

class EchoServer {
private:
    class Connection {
    public:
        tcp::socket socket;
        Connection(boost::asio::io_service &io_service) : socket(io_service) {}
    };

    boost::asio::io_service io_service;

    tcp::endpoint endpoint;
    tcp::acceptor acceptor;

    void handle_request(shared_ptr<Connection> connection) {
        auto read_buffer = make_shared<boost::asio::streambuf>();
        async_read_until(connection->socket, *read_buffer, "\r\n",
                         [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
                             if(!ec) {
                                 istream read_stream(read_buffer.get());
                                 std::string message;
                                 getline(read_stream, message);
                                 message.pop_back();

                                 cout << "Message from a connected client: " << message << endl;
                                 if(message == "exit")
                                     return;
                                 if(message == "GET / HTTP/1.1") {
                                     message = "HTTP/1.1 200 OK"
                                               "Content-Type: text/html"
                                               "Connection: Closed\r\n\r\n"
                                               "<html>"
                                               "<body>"
                                               "<h1>This is the home page</h1>"
                                               "</body>"
                                               "</html>";
                                 }
                                 else if(message == "GET /en_side HTTP/1.1") {
                                     message = "HTTP/1.1 200 OK"
                                               "Content-Type: text/html"
                                               "Connection: Closed\r\n\r\n"
                                               "<html>"
                                               "<body>"
                                               "<h3>This is a page</h3>"
                                               "</body>"
                                               "</html>";
                                 }
                                 else {
                                     message = "HTTP/1.1 404 Not Found"
                                               "Content-Type: text/html"
                                               "Connection: Closed\r\n\r\n"
                                               "<html>"
                                               "<body>"
                                               "<h1>Oops! The page you're looking for does not exist</h1>"
                                               "</body>"
                                               "</html> ";
                                 }

                                 auto write_buffer = make_shared<boost::asio::streambuf>();
                                 ostream write_stream(write_buffer.get());

                                 // Add message to be written to client:
                                 write_stream << message << "\r\n";

                                 // Write to client
                                 async_write(connection->socket, *write_buffer,
                                             [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
                                                 // If not error:
                                                 if(!ec)
                                                     handle_request(connection);
                                             });
                             }
                         });
    }

    void accept() {
        // The (client) connection is added to the lambda parameter and handle_request
        // in order to keep the object alive for as long as it is needed.
        auto connection = make_shared<Connection>(io_service);

        // Accepts a new (client) connection. On connection, immediately start accepting a new connection
        acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
            accept();
            // If not error:
            if(!ec) {
                handle_request(connection);
            }
        });
    }

public:
    EchoServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

    void start() {
        accept();
        io_service.run();
    }
};

int main() {
    EchoServer echo_server;

    cout << "To connect in terminal: telnet localhost 8080\n. To exit simply type 'exit'." << endl;

    echo_server.start();
}