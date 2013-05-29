#include "Circle"
#include "Rectangle"
#include <iostream>
#include "ComplexShape"
#include <tr1/memory>

using namespace std::tr1;

shared_ptr<Shape<float> > CreateScene() {
    shared_ptr<Rectangle<float> > r(new Rectangle<float>(5,4));
    shared_ptr<Circle<float> > c(new Circle<float>(5));
    std::cout << r->str() << ", area: " << r->area() << std::endl;
    std::cout << c->str() << ", area: " << c->area() << std::endl;

    shared_ptr<ComplexShape<float> > cs(new ComplexShape<float>());
    cs->addShape(r);
    cs->addShape(c);
    return cs;
}

int main (int argc, char** argv) {
    (void)argc;
    (void)argv;

    shared_ptr<Shape<float> > cs = CreateScene();

    std::cout << cs->str() << ", area: " << cs->area() << std::endl;
}
