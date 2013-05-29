#pragma once
#include <tr1/memory>
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "ComplexShape.hpp"

template<typename T>
class ShapeFactory {
  public:
    virtual std::tr1::shared_ptr<Rectangle<T> > CRectangle(T w, T h) = 0;
    virtual std::tr1::shared_ptr<Circle<T> > CCircle(T r) = 0;
    virtual std::tr1::shared_ptr<ComplexShape<T> > CComplexShape() = 0;
    virtual ~ShapeFactory() {}
};
