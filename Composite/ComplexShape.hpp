#pragma once
#include <vector>
#include <iostream>
#include <tr1/memory>
#include "Shape.hpp"

template<typename T>
class ComplexShape : public Shape<T> {
    std::vector<std::tr1::shared_ptr<Shape<T> > > shapes;
  public:
    void addShape(std::tr1::shared_ptr<Shape<T> > s) {
        shapes.push_back(s);
    }

    T area() {
        T sumarea = T(0);
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
    ~ComplexShape() {}
};
