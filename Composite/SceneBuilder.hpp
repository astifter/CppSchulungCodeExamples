#pragma once
#include "tr1/memory"
#include "ShapeFactory.hpp"

class SceneBuilder { 
  public:
    virtual std::tr1::shared_ptr<Shape> CreateScene(std::tr1::shared_ptr<ShapeFactory> sf) = 0;
    virtual ~SceneBuilder() = 0;
};
