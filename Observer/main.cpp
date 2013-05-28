#include "Generator"
#include "ConsoleCallback"

int main ( int argc, char** argv ) {
    ICallback &cb = *(new ConsoleCallback());  ///;
    Generator g = Generator(cb);
    g.generate();
    delete &cb;
}
