#include "Generator"
#include <sstream>

void Generator::generate(void) {

    std::stringstream s;
    for (int i = 0; i<10000; i++) {
        s.str("");
        s << "generated something (" << i << ")";
        cb.Callback(s.str());
    }
};
