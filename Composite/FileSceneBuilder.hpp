#pragma once
#include <fstream>
#include "SceneBuilder.hpp"

class FileSceneBuilder : public SceneBuilder { 
    std::string filename;
  public:
    FileSceneBuilder(std::string f) : filename(f){}
    std::tr1::shared_ptr<Shape<float> > CreateScene(std::tr1::shared_ptr<ShapeFactory<float> > sf) {
        std::fstream fs(filename.c_str()); 
        std::vector<std::tr1::shared_ptr<Shape<float> > > v;
       
        while(!fs.eof()) {
            std::string type;
            fs >> type;
            if (type == "circle") {
                float radius;
                fs >> radius;
                v.push_back(sf->CCircle(radius));
            } else if (type == "rectangle") {
                float width;
                float height;
                fs >> width;
                fs >> height;
                v.push_back(sf->CRectangle(width, height));
            } else if (type == "shape") {
                size_t num;
                fs >> num;
                size_t oldvsize = v.size();
                std::tr1::shared_ptr<ComplexShape<float> > cs = sf->CComplexShape();
                for (size_t i = v.size()-num; i < oldvsize; i++) {
                    cs->addShape(v[i]);
                }
                for (size_t i = v.size()-num; i < oldvsize; i++) {
                    v.pop_back();
                }
                v.push_back(cs);
            }

        }
        
        return v[0];
    }
};
