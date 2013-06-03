#pragma once
#include <vector>
#include <iostream>
#include <tr1/memory>
#include "Shape.hpp"
#include "Visitor.hpp"

class ComplexShape : public Shape {
  public:
    std::vector<std::tr1::shared_ptr<Shape > > shapes;

  public:
    void addShape(std::tr1::shared_ptr<Shape > s) {
        shapes.push_back(s);
    }

    float area() {
        float sumarea = float(0);
        for (size_t i = 0; i < shapes.size(); i++) {
            sumarea += shapes[i]->area();
        }
        return sumarea;
    }
    std::string str() {
        std::stringstream s;
        s << "CX(";
        for (size_t i = 0; i < shapes.size(); i++) {
            s << shapes[i]->str();
            if (i+1 < shapes.size())
                s << ",";
        }
        s << ")";
        return s.str();
    }
    void accept(Visitor &v) {
        v.visit(*this);
    }

    ~ComplexShape() {}
};
