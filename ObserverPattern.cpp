#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Car{
protected:
    int position;
    vector<class Observer* >observers;
public:
    int getPosition() const {
        return position;
    }

    void setPosition(int position) {
        Car::position = position;
        notify();
    }
    void addObserver(Observer* a){
        observers.push_back(a);
    }
    void notify();
};
class Observer{
protected:
    Car* car;
public:
    Observer(Car* c){
        this->car = c;
        car->addObserver(this);
    }
    Car* getCar() const {
        return car;
    }
    virtual void update()=0;
};
void Car::notify() {
    for(auto i:this->observers){
        i->update();
    }
}
class LeftObserver:public Observer{
public:
    LeftObserver(Car * car): Observer(car){}
    void update(){
        if(this->car->getPosition() < 0){
            cout << "Position : Left" << endl;
        }
    }
};

class RightObserver:public Observer{
public:
    RightObserver(Car * car): Observer(car){}
    void update(){
        if(this->car->getPosition() > 0){
            cout << "Position : Right" << endl;
        }
    }
};

class MiddleObserver:public Observer{
public:
    MiddleObserver(Car * car): Observer(car){}
    void update(){
        if(this->car->getPosition() == 0){
            cout << "Position : Middle" << endl;
        }
    }
};
class AlwaysObserver:public Observer{
public:
    AlwaysObserver(Car * car): Observer(car){}
    void update(){
        cout << "Always Called" << endl;
    }
};
int main(){
    Car c;
    LeftObserver lo(&c);
    RightObserver ro(&c);
    MiddleObserver mo(&c);
    AlwaysObserver ao(&c);
    c.setPosition(-1);
    c.setPosition(0);
    c.setPosition(1);
}