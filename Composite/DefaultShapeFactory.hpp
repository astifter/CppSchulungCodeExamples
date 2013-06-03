#pragma once
#include "ShapeFactory.hpp"

class DefaultShapeFactory : public ShapeFactory {
  public:
    std::tr1::shared_ptr<Rectangle> CRectangle(float w, float h) {
        return std::tr1::shared_ptr<Rectangle>(new Rectangle(w,h));
    }
    std::tr1::shared_ptr<Circle> CCircle(float r) {
        return std::tr1::shared_ptr<Circle>(new Circle(r));
    }
    std::tr1::shared_ptr<ComplexShape> CComplexShape() {
        return std::tr1::shared_ptr<ComplexShape>(new ComplexShape());
    }
};
