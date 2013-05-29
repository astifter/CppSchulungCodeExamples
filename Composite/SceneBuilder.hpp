#pragma once
#include "ShapeFactory"
#include "tr1/memory"

class SceneBuilder { 
  public:
    virtual std::tr1::shared_ptr<Shape<float> > CreateScene(std::tr1::shared_ptr<ShapeFactory<float> > sf) = 0;
    virtual ~SceneBuilder() = 0;
};
