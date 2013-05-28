#include "Generator"
#include <sstream>

void Generator::generate(void) {

    std::stringstream s;
    for (int i = 0; i<1000000; i++) {
        s.str("");
        s << "generated something (" << i << ")";
        cb.Callback(s.str());
    }
};
