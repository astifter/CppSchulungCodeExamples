#pragma once
#include <sstream>
#include <iostream>
#include "Shape.hpp"
#include "Visitor.hpp"

class Circle : public Shape {
  public:
    float radius;
    
  public:
    Circle(float r) : radius(r) {}
    
    float area() {
        return float(3.141592653589793238462643383279502884) * radius * radius;
    }
    std::string str() {
        std::stringstream s;
        s << "C(" << radius << ")";
        return s.str();
    }
    void accept(Visitor &v) {
        v.visit(*this);
    }

    ~Circle() {}
};
