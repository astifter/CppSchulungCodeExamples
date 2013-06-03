#pragma once
#include <string>
#include <iostream>

class Visitor;

class Shape {
  public:
    virtual float area() = 0;
    virtual std::string str() = 0;
    virtual void accept(Visitor &v) = 0;
};
