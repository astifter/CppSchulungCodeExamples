#pragma once
#include "Circle"

template<typename T>
class DebugCircle : public Circle<T> {
    
  public:
    DebugCircle(T r) : Circle<T>(r) {
        std::cerr << "DebugCircle(" << r << ")" << std::endl;
    }
    
    T area() {
        T area = Circle<T>::area();
        std::cerr << "area(): returning " << area << std::endl;
        return area;
    }
    ~DebugCircle() { 
        std::cerr << "~DebugCircle()" << std::endl; 
    }
};
