#pragma once
#include "Visitor.hpp"

class PrintVisitor : public Visitor {
  public:
    void visit(Rectangle & c) {
        std::cout << "rectangle " << c.width << " " << c.heigth << std::endl;
    }
    void visit(Circle & c) {
        std::cout << "circle " << c.radius << std::endl;
    }
    void visit(ComplexShape & c) {
        for (size_t i = 0; i < c.shapes.size(); i++) {
            c.shapes[i]->accept(*this);
        }
        std::cout << "shape " << c.shapes.size() << std::endl;
    }
};
