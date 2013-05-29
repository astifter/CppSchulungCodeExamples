#include "Circle"
#include "Rectangle"
#include <iostream>
#include "ComplexShape"
#include <tr1/memory>
#include "ShapeFactory"
#include "DebugShapeFactory"
#include "SceneBuilder"
#include "DefaultSceneBuilder"
#include "FileSceneBuilder"

using namespace std::tr1;

int main (int argc, char** argv) {
    (void)argc;
    (void)argv;

    shared_ptr<ShapeFactory<float> > sf(new DefaultShapeFactory<float>());
    shared_ptr<SceneBuilder> sb(new DefaultSceneBuilder());

    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);
        if (arg == std::string("-d")) {
            sf = shared_ptr<DebugShapeFactory<float> >(new DebugShapeFactory<float>());
        }
        if (arg == std::string("-b")) {
            if (i+1 >= argc) {
                std::cerr << "please provide filename" << std::endl;
                return -1;
            }   
            sb = shared_ptr<SceneBuilder>(new FileSceneBuilder(std::string(argv[i+1])));
            i++;
        }
    } 

    shared_ptr<Shape<float> > cs = sb->CreateScene(sf);

    std::cout << cs->str() << ", area: " << cs->area() << std::endl;
}
