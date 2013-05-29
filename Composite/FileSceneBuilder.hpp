#pragma once
#include <fstream>
#include "SceneBuilder.hpp"

class FileSceneBuilder : public SceneBuilder { 
    std::string filename;
  public:
    FileSceneBuilder(std::string f) : filename(f){}
    std::tr1::shared_ptr<Shape<float> > CreateScene(std::tr1::shared_ptr<ShapeFactory<float> > sf) {
        std::fstream fs(filename.c_str()); 
        std::tr1::shared_ptr<ComplexShape<float> > cs = sf->CComplexShape();
       
        while(!fs.eof()) {
            std::string type;
            fs >> type;
            if (type == "circle") {
                float radius;
                fs >> radius;
                cs->addShape(sf->CCircle(radius));
            } else if (type == "rectangle") {
                float width;
                float height;
                fs >> width;
                fs >> height;
                cs->addShape(sf->CRectangle(width, height));
           } 

        }
        
        return cs;
    }
};
