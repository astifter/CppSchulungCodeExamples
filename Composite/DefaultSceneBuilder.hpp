#pragma once
#include "SceneBuilder.hpp"

class DefaultSceneBuilder : public SceneBuilder { 
  public:
    std::tr1::shared_ptr<Shape<float> > CreateScene(std::tr1::shared_ptr<ShapeFactory<float> > sf) {
        std::tr1::shared_ptr<Rectangle<float> > r = sf->CRectangle(5,4);
        std::tr1::shared_ptr<Circle<float> > c = sf->CCircle(5);
        std::tr1::shared_ptr<ComplexShape<float> > cs = sf->CComplexShape();
        cs->addShape(r);
        cs->addShape(c);
        cs->addShape(c);
        cs->addShape(c);
        cs->addShape(c);
        cs->addShape(c);
        return cs;
    }
};
