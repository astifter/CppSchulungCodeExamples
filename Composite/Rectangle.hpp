#pragma once
#include <sstream>
#include <iostream>
#include "Shape.hpp"

template<typename T>
class Rectangle : public Shape<T> {
    T width;
    T heigth;
    
  public:
    Rectangle(T w, T h) : width(w), heigth(h) {}
    
    T area() {
        return width*heigth;
    }
    std::string str() {
        std::stringstream s;
        s << "R(" << width << "x" << heigth << ")";
        return s.str();
    }
    ~Rectangle() {}
};
