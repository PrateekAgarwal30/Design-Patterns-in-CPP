#include <iostream>
#include <cstdlib>
using namespace std;
class InterfaceDataLoading{
protected:
    string data = "qwertyuiopasdfghjklzxcvbnm,qwertyuioasdfghjklzxcvbnm,";
public:
    virtual void getData()=0;
};
class CDataLoading:public InterfaceDataLoading{
public:
    CDataLoading():InterfaceDataLoading(){
        _sleep(5000);
    }
    void getData(){
        cout << this->data << endl;
    }
};
class CProxy:public InterfaceDataLoading{
private:
    CDataLoading* d = NULL;
public:
    CProxy():InterfaceDataLoading(){}
    void getData(){
        if(d == NULL) {
            d = new CDataLoading();
        }
        d->getData();
    }
};
int main(){
    CProxy c = CProxy();
    c.getData();
    c.getData();
}