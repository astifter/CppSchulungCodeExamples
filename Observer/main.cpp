#include "Generator"
#include "FastConsoleCallback"
#include "ConsoleCallback"

int main ( int argc, char** argv ) {
    ICallback *cb;
    if (argc > 1 && std::string(argv[1]) == "-f") {
        cb = new FastConsoleCallback();
    } else {
        cb = new ConsoleCallback();
    }
    Generator g = Generator(*cb);
    g.generate();
    delete cb;
}
