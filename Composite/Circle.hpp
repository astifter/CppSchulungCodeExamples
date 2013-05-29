#pragma once
#include <sstream>
#include <iostream>
#include "Shape.hpp"

template<typename T>
class Circle : public Shape<T> {
  protected:
    T radius;
    
  public:
    Circle(T r) : radius(r) {}
    
    T area() {
        return T(3.141592653589793238462643383279502884) * radius * radius;
    }
    std::string str() {
        std::stringstream s;
        s << "C(" << radius << ")";
        return s.str();
    }
    ~Circle() {}
};
