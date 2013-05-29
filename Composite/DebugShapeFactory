#pragma once
#include "DefaultShapeFactory"
#include "DebugCircle"

template<typename T>
class DebugShapeFactory : public DefaultShapeFactory<T> {
  public:
    std::tr1::shared_ptr<Circle<T> > CCircle(T r) {
        return std::tr1::shared_ptr<Circle<T> >(new DebugCircle<T>(r));
    }
};
