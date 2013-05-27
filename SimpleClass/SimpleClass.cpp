#include <iostream>


class SimpleClass {
  public:
    SimpleClass() {
        std::cout << "SimpleClass() called." << std::endl;
    }

    ~SimpleClass() {
        std::cout << "~SimpleClass() called." << std::endl;
    }
};

int main (int argc, char** argv) {
    std::cout << "main() called." << std::endl;
    SimpleClass *c = new SimpleClass();
    
    delete c;
    std::cout << "main() exiting." << std::endl;
    return 0;
}
