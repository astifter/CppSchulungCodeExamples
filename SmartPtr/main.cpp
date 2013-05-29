#include <tr1/memory>
#include <iostream>

int main (int argc, char** argv) {
    (void)argc;
    (void)argv;
    std::tr1::shared_ptr<int> sp(new int(10));
    std::cout << "sp.use_count(): " << sp.use_count() << std::endl;
    {
        std::tr1::shared_ptr<int> sp2=sp;
        std::cout << "sp.use_count(): " << sp.use_count() << std::endl;
        std::cout << "sp2.use_count(): " << sp.use_count() << std::endl;
    }
    std::cout << "sp.use_count(): " << sp.use_count() << std::endl;
}
