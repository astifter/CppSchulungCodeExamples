#pragma once
class Rectangle;
class Circle;
class ComplexShape;

class Visitor {
  public:
    virtual void visit(Rectangle &v) = 0;
    virtual void visit(Circle &v) = 0;
    virtual void visit(ComplexShape &v) = 0;
};
