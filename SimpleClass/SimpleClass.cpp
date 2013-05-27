#include <iostream>

class SimpleClass {
  private:
    std::string name;
  public:
    SimpleClass() : name("default") {
        std::cout << "SimpleClass() named \"" << name << "\" called." << std::endl;
    }

    SimpleClass(std::string n) : name(n) {
        std::cout << "SimpleClass(std::string n) named \"" << name << "\" called." << std::endl;
    }

    ~SimpleClass() {
        std::cout << "~SimpleClass() for \""<<name<<"\"called." << std::endl;
    }

    std::string getName(void) {
        return this->name;
    }

    friend std::ostream & operator<< (std::ostream & other, SimpleClass & c);
};

std::ostream & operator<< (std::ostream & other, SimpleClass & c) {
    return (other << c.name);
}

int main (int argc, char** argv) {
    std::cout << "main() called." << std::endl;
    SimpleClass *d = new SimpleClass();
    SimpleClass c = SimpleClass("c");
    
    std::cout << "object d: " << *d << std::endl;
    std::cout << "object c: " << c << std::endl;

    delete d;
    std::cout << "main() exiting." << std::endl;
    return 0;
}
