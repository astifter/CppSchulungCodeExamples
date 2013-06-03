#pragma once
#include <fstream>
#include <stdexcept>
#include "SceneBuilder.hpp"

class FileSceneBuilder : public SceneBuilder { 
    std::string filename;
  public:
    FileSceneBuilder(std::string f) : filename(f){}
    std::tr1::shared_ptr<Shape> CreateScene(std::tr1::shared_ptr<ShapeFactory> sf) {
        std::fstream fs(filename.c_str()); 
        std::vector<std::tr1::shared_ptr<Shape> > v;
        unsigned int line = 0; 
        while(!fs.eof()) {
            std::string type;
            fs >> type;
            line++;
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
                if (num > oldvsize) {
                    std::stringstream msg;
                    msg << "can not process " << num << " shapes in " << filename << ", line " << line;
                    throw std::invalid_argument::invalid_argument(msg.str());
                }
                std::tr1::shared_ptr<ComplexShape> cs = sf->CComplexShape();
                for (size_t i = v.size()-num; i < oldvsize; i++) {
                    cs->addShape(v[i]);
                }
                for (size_t i = v.size()-num; i < oldvsize; i++) {
                    v.pop_back();
                }
                v.push_back(cs);
            } else if (type == "") {
                continue;
            } else {
                std::stringstream msg;
                msg << "can not process " << type << " in " << filename << ", line " << line;
                throw std::invalid_argument::invalid_argument(msg.str());
            }
        }
        
        return v[0];
    }
};
