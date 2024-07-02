#include <iostream>
#include <fstream>
#include <boost/asio.hpp>

using namespace boost::asio;

void send_calculation_request(serial_port & port, const std::string & request) {
    write(port, buffer(request + "\n"));
}

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
    io_service io;
    serial_port port(io, "COM3"); // Passe den COM-Port entsprechend an
    port.set_option(serial_port_base::baud_rate(9600));
    port.set_option(serial_port_base::character_size(8));
    port.set_option(serial_port_base::parity(serial_port_base::parity::none));
    port.set_option(serial_port_base::stop_bits(serial_port_base::stop_bits::one));

    std::string request;
    std::cout << "Enter calculation (e.g., 12 + 34): ";
    std::getline(std::cin, request);

    // Öffnet die Datei für die Speicherung
    std::ofstream log_file("communication_log.txt", std::ios::app);
    if (!log_file.is_open()) {
        std::cerr << "Failed to open log file" << std::endl;
        return 1;
    }

    send_calculation_request(port, request);
    std::string response = receive_calculation_response(port);

    // Speichert die Kommunikation in der Datei
    log_file << "Request: " << request << std::endl;
    log_file << "Response: " << response << std::endl;

    std::cout << "Response from Arduino: " << response << std::endl;

    return 0;
}
