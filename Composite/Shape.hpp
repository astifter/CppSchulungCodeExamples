#pragma once
#include <string>
#include <iostream>

template<typename T>
class Shape {
  public:
    virtual T area() = 0;
    virtual std::string str() = 0;
    virtual ~Shape() = 0;
};

template<typename T>
Shape<T>::~Shape() {}
