#include "FastConsoleCallback"
#include <iostream>

FastConsoleCallback::FastConsoleCallback() : charwritten(0) {
    std::cerr << "Created FastConsoleCallback" << std::endl;
}

void FastConsoleCallback::Callback(const std::string & message) {
    s << "FastConsoleCallback: " << message << std::endl;
    charwritten += message.length();
    if (charwritten > (128*1024))
    {
        std::cout << s.str();
        s.str("");
        charwritten = 0;
    }
}

FastConsoleCallback::~FastConsoleCallback() {
    std::cout << s.str();
}
