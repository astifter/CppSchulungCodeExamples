#include "ConsoleCallback"
#include <iostream>
#include <sstream>

ConsoleCallback::ConsoleCallback() {
    std::cerr << "Created ConsoleCallback" << std::endl;
}

void ConsoleCallback::Callback(const std::string & message) {
    std::stringstream s;
    s << "ConsoleCallback: " << message << std::endl;
    std::cout << s.str();
}
