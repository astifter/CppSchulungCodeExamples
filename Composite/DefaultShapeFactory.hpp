#pragma once
#include "ShapeFactory"

template<typename T>
class DefaultShapeFactory : public ShapeFactory<T> {
  public:
    std::tr1::shared_ptr<Rectangle<T> > CRectangle(T w, T h) {
        return std::tr1::shared_ptr<Rectangle<T> >(new Rectangle<T>(w,h));
    }
    std::tr1::shared_ptr<Circle<T> > CCircle(T r) {
        return std::tr1::shared_ptr<Circle<T> >(new Circle<T>(r));
    }
    std::tr1::shared_ptr<ComplexShape<T> > CComplexShape() {
        return std::tr1::shared_ptr<ComplexShape<T> >(new ComplexShape<T>());
    }
};
