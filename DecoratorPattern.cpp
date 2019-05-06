/*
 * We're going to create a Shape interface and concrete classes implementing the Shape interface.
 * We will then create an abstract decorator class ShapeDecorator implementing the Shape
 * interface and having Shape object as its instance variable.
 * RedShapeDecorator is concrete class implementing ShapeDecorator.
 * */
#include <iostream>
using namespace std;
class Shape{
public:
    virtual void draw()=0;
};
class Reactangle:public Shape{
public:
    void draw(){
        cout << "Drawing a Reactangle" << endl;
    }
};

class Circle:public Shape{
public:
    void draw(){
        cout << "Drawing a Circle" << endl;
    }
};
class ShapeDecorder:public Shape{
protected:
    Shape* s;
public:
    ShapeDecorder(Shape* s):Shape(){
        this->s = s;
    }
    virtual void draw()=0;
};

class RedShapeDecorator:public ShapeDecorder{
private:
    Shape* s;
    void setRedBorder(Shape* a){
        cout << "Setting Red Border" << endl;
    }
public:
    RedShapeDecorator(Shape* s):ShapeDecorder(s){
        this->s = s;
    }
    void draw(){
        s->draw();
        this->setRedBorder(s);
    }
};
int main(){
    Shape* circle = new Circle();
    circle->draw();
    cout << endl;
    Shape* redBorderCircle = new RedShapeDecorator(circle);
    redBorderCircle->draw();
    cout << endl;
    Shape* redBorderRectangle = new RedShapeDecorator(new Reactangle());
    redBorderRectangle->draw();
}