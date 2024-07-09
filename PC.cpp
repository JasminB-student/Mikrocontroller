#include <iostream>
#include <fstream>
#include <boost/asio.hpp>

using namespace boost::asio;

// sends a authorization request to the arduino
void send_calculation_request(serial_port & port, const std::string & request) {
    write(port, buffer(request + "\n"));
}

// receives the answer from arduino
std::string receive_calculation_response(serial_port& port) {
    char c;
    std::string response;
    while (true) {
        read(port, buffer(&c, 1));
        if (c == '\n') break;
        response += c;
    }
    return response;
}

int main() {
    // initializes the serial communication with the same settings as the arduino
    io_service io;
    serial_port port(io, "COM3"); // Passe den COM-Port entsprechend an
    port.set_option(serial_port_base::baud_rate(9600)); 
    port.set_option(serial_port_base::character_size(8));
    port.set_option(serial_port_base::parity(serial_port_base::parity::none));
    port.set_option(serial_port_base::stop_bits(serial_port_base::stop_bits::one));

    // asks for input
    std::string request;
    std::cout << "Enter calculation (e.g., 12 + 34): ";
    std::getline(std::cin, request);

    // opens file for saving or behavior if not opened
    std::ofstream log_file("communication_log.txt", std::ios::app);
    if (!log_file.is_open()) {
        std::cerr << "Failed to open log file" << std::endl;
        return 1;
    }

    send_calculation_request(port, request);
    std::string response = receive_calculation_response(port);

    // saves the communication in file
    log_file << "Request: " << request << std::endl;
    log_file << "Response: " << response << std::endl;

    // shows the answer form the arduino
    std::cout << "Response from Arduino: " << response << std::endl;

    return 0;
}
