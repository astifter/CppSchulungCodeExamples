#pragma once
#include "DefaultShapeFactory.hpp"
#include "DebugCircle.hpp"

class DebugShapeFactory : public DefaultShapeFactory {
  public:
    std::tr1::shared_ptr<Circle> CCircle(float r) {
        return std::tr1::shared_ptr<Circle>(new DebugCircle(r));
    }
};
