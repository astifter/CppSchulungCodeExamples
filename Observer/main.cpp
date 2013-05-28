#include "Generator"
#include "ConsoleCallback"

int main ( int argc, char** argv ) {
    ConsoleCallback cb = ConsoleCallback();
    Generator g = Generator(cb);
    g.generate();
}
