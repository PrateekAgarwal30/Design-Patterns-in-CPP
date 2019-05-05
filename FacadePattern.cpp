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
        cout << "***********************" << endl;
    }
};

class COctupus:public AnimalInterface{
public:
    COctupus(string s,int h,int l):AnimalInterface(s,h,l){

    }
    void displayInfo(){
        cout << "Type : Octupus" << endl;
        this->display();
        cout << "***********************" << endl;
    }
};
class AnimalMaker{
public:
    AnimalMaker(){}
    void createDog(string name,int hands,int legs){
        AnimalInterface* ai = new CDog(name,hands,legs);
        ai->displayInfo();
    }
    void createOctopus(string name,int hands,int legs){
        AnimalInterface* ai = new COctupus(name,hands,legs);
        ai->displayInfo();
    }
};
int main(){
    AnimalMaker* animalMaker = new AnimalMaker();
    animalMaker->createDog("Puppy",2,2);
    animalMaker->createOctopus("Blue Ringed Octopus",0,7);
}