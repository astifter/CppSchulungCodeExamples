#pragma once
#include "Circle.hpp"

class DebugCircle : public Circle {
    
  public:
    DebugCircle(float r) : Circle(r) {
        std::cerr << "DebugCircle(" << r << ")" << std::endl;
    }
    
    float area() {
        float area = Circle::area();
        std::cerr << "area(): returning " << area << std::endl;
        return area;
    }
    ~DebugCircle() { 
        std::cerr << "~DebugCircle()" << std::endl; 
    }
};
