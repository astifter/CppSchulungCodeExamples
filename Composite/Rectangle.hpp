#pragma once
#include <sstream>
#include <iostream>
#include "Shape.hpp"
#include "Visitor.hpp"

class Rectangle : public Shape {
  public:
    float width;
    float heigth;
    
  public:
    Rectangle(float w, float h) : width(w), heigth(h) {}
    
    float area() {
        return width*heigth;
    }
    std::string str() {
        std::stringstream s;
        s << "R(" << width << "x" << heigth << ")";
        return s.str();
    }
    void accept(Visitor &v) {
        v.visit(*this);
    }

    ~Rectangle() {}
};
