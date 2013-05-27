#include <iostream>


class SimpleClass {
  public:
    SimpleClass() {
        std::cout << "SimpleClass() called.";
    }

    ~SimpleClass() {
        std::cout << "~SimpleClass() called.";
    }
};

int main (int argc, char** argv) {
    std::cout << "main() called.";
    SimpleClass *c = new SimpleClass();
    
    std::cout << "main() exiting.";
    return 0;
}
