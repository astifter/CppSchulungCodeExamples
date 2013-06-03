#pragma once
#include <tr1/memory>
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "ComplexShape.hpp"

class ShapeFactory {
  public:
    virtual std::tr1::shared_ptr<Rectangle> CRectangle(float w, float h) = 0;
    virtual std::tr1::shared_ptr<Circle> CCircle(float r) = 0;
    virtual std::tr1::shared_ptr<ComplexShape> CComplexShape() = 0;
    virtual ~ShapeFactory() {}
};
