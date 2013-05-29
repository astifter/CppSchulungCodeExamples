#include "Circle"
#include "Rectangle"
#include <iostream>
#include "ComplexShape"

Shape<float> *CreateScene() {
    Rectangle<float> r(5,4);
    Circle<float> c(5);
    std::cout << r.str() << ", area: " << r.area() << std::endl;
    std::cout << c.str() << ", area: " << c.area() << std::endl;

    ComplexShape<float> cs;
    cs.addShape(&r);
    cs.addShape(&c);
    return &cs;
}

int main (int argc, char** argv) {
    (void)argc;
    (void)argv;

    Shape<float> *cs = CreateScene();

    std::cout << cs->str() << ", area: " << cs->area() << std::endl;
}
