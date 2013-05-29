#include "Circle"
#include "Rectangle"
#include <iostream>
#include "ComplexShape"
#include <tr1/memory>
#include "ShapeFactory"
#include "DebugShapeFactory"

using namespace std::tr1;
shared_ptr<Shape<float> > CreateScene(shared_ptr<ShapeFactory<float> > sf);

shared_ptr<Shape<float> > CreateScene(shared_ptr<ShapeFactory<float> > sf) {
    shared_ptr<Rectangle<float> > r = sf->CRectangle(5,4);
    shared_ptr<Circle<float> > c = sf->CCircle(5);
    shared_ptr<ComplexShape<float> > cs = sf->CComplexShape();
    cs->addShape(r);
    cs->addShape(c);
    cs->addShape(c);
    cs->addShape(c);
    cs->addShape(c);
    cs->addShape(c);
    return cs;
}

int main (int argc, char** argv) {
    (void)argc;
    (void)argv;

    shared_ptr<DebugShapeFactory<float> > sf(new DebugShapeFactory<float>());

    shared_ptr<Shape<float> > cs = CreateScene(sf);

    std::cout << cs->str() << ", area: " << cs->area() << std::endl;
}
