#pragma once
#include "SceneBuilder.hpp"

class DefaultSceneBuilder : public SceneBuilder { 
  public:
    std::tr1::shared_ptr<Shape> CreateScene(std::tr1::shared_ptr<ShapeFactory> sf) {
        std::tr1::shared_ptr<Rectangle> r = sf->CRectangle(5,4);
        std::tr1::shared_ptr<Circle> c = sf->CCircle(5);
        std::tr1::shared_ptr<ComplexShape> cs = sf->CComplexShape();
        cs->addShape(r);
        cs->addShape(c);
        cs->addShape(c);
        cs->addShape(c);
        cs->addShape(c);
        cs->addShape(c);
        return cs;
    }
};
