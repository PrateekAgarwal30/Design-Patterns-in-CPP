#include <iostream>
using namespace std;
class AnimalInterface{
protected:
    string name;
    int legs;
    int hands;
public:
    AnimalInterface(string s="",int hands=0,int legs=0){
        this->name = s;
        this->hands = hands;
        this->legs = legs;
    }
    string getName(){
        return name;
    }
    void setName(string name) {
        this->name = name;
    }

    int getLegs(){
        return legs;
    }

    void setLegs(int legs) {
        this->legs = legs;
    }

    int getHands(){
        return hands;
    }

    void setHands(int hands) {
        this->hands = hands;
    }
    void display(){
        cout << "Name : " << this->name << endl;
        cout << "Hands : " << this->hands << endl;
        cout << "Legs : " << this->legs << endl;
    }
    virtual void displayInfo()=0;
};
class CDog:public AnimalInterface{
public:
    CDog(string s,int h,int l):AnimalInterface(s,h,l){

    }
    void displayInfo(){
        cout << "Type : Dog" << endl;
        this->display();
    }
};

class COctupus:public AnimalInterface{
public:
    COctupus(string s,int h,int l):AnimalInterface(s,h,l){

    }
    void displayInfo(){
        cout << "Type : Octupus" << endl;
        this->display();
    }
};
class AnimalFactory{
public:
    AnimalFactory(){}
    virtual AnimalInterface* createAnimal()=0;
};
class RandomAnimalGenerator:public AnimalFactory{
public:
    RandomAnimalGenerator():AnimalFactory(){}
    AnimalInterface* createAnimal(){
        if(rand()%2 == 0){
            AnimalInterface* ai = new CDog("",2,2);
            return ai;
        }else{
            AnimalInterface* ai = new COctupus("",4,4);
            return ai;
        }
    }
};
int main(){
    for(int i=0;i<10;i++){
        RandomAnimalGenerator* raGenerator = new RandomAnimalGenerator();
        AnimalInterface* animal = raGenerator->createAnimal();
        animal->displayInfo();
    }
}