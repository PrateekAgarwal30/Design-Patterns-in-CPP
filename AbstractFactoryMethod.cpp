#include <iostream>
using namespace std;
class CarFactory
{
public:
    virtual class Body *createBody(string name) = 0;
    virtual class Tyre *createTyre(string name) = 0;
    virtual class Car *createWholeCar(string name) = 0;
};
class ConcreteCarFactory : public CarFactory
{
public:
    Body *createBody(string name);
    Tyre *createTyre(string name);
    Car *createWholeCar(string name);
};
class Car
{
protected:
    string name;
    Body *body;
    Tyre *tyre;

public:
    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        Car::name = name;
    }

    Body *getBody()
    {
        return body;
    }

    void setBody(Body *body)
    {
        Car::body = body;
    }

    Tyre *getTyre()
    {
        return tyre;
    }

    void setTyre(Tyre *tyre)
    {
        Car::tyre = tyre;
    }
    void GetDetails();
};

class Tyre
{
protected:
    string name;
    int maxPressure;

public:
    Tyre(string name = "", int maxPressure = 0)
    {
        this->name = name;
        this->maxPressure = maxPressure;
    }
    virtual void display() = 0;
};
class SimpleTyre : public Tyre
{
public:
    SimpleTyre(string name, int maxPressure) : Tyre(name, maxPressure) {}
    void display()
    {
        cout << name << " " << maxPressure << endl;
    }
};
class LuxuryTyre : public Tyre
{
public:
    LuxuryTyre(string name, int maxPressure) : Tyre(name, maxPressure) {}
    void display()
    {
        cout << name << " " << maxPressure << endl;
    }
};

class Body
{
protected:
    string name;
    int maxStrength;

public:
    Body(string name = "", int maxStrength = 0)
    {
        this->name = name;
        this->maxStrength = maxStrength;
    }
    virtual void display() = 0;
};
class SimpleBody : public Body
{
public:
    SimpleBody(string name, int maxStrength) : Body(name, maxStrength) {}
    void display()
    {
        cout << name << " " << maxStrength << endl;
    }
};

class LuxuryBody : public Body
{
public:
    LuxuryBody(string name, int maxStrength) : Body(name, maxStrength) {}
    void display()
    {
        cout << name << " " << maxStrength << endl;
    }
};

Body* ConcreteCarFactory::createBody(string name)
{
    if (name == "Simple")
    {
        Body *s = new SimpleBody("Simple Body", 500);
        return s;
    }
    else
    {
        Body *s = new LuxuryBody("Luxury Body", 1000);
        return s;
    }
}

Tyre* ConcreteCarFactory::createTyre(string name)
{
    if (name == "Simple")
    {
        Tyre *s = new SimpleTyre("Simple Tyre", 100);
        return s;
    }
    else
    {
        Tyre *s = new LuxuryTyre("Luxury Tyre", 200);
        return s;
    }
}

Car* ConcreteCarFactory::createWholeCar(string name)
{
    Car *s = new Car();
    s->setName(name + " Car");
    s->setBody(this->createBody(name));
    s->setTyre(this->createTyre(name));
    return s;
}
void Car::GetDetails()
{
    cout << "Car Name : " << this->name << endl;
    this->getBody()->display();
    this->getTyre()->display();
}
int main()
{
    ConcreteCarFactory f;
    Car *car = NULL;
    for (int i = 0; i < 10; i++)
    {
        if (rand() % 2 == 0)
        {
            car = f.createWholeCar("Simple");
        }
        else
        {
            car = f.createWholeCar("Luxury");
        }
        car->GetDetails();
    }
}