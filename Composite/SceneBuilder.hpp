#pragma once
#include "tr1/memory"
#include "ShapeFactory.hpp"

class SceneBuilder { 
  public:
    virtual std::tr1::shared_ptr<Shape<float> > CreateScene(std::tr1::shared_ptr<ShapeFactory<float> > sf) = 0;
    virtual ~SceneBuilder() = 0;
};
