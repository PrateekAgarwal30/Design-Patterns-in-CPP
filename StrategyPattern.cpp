#include <iostream>
using namespace std;
class DisplayInterface
{
 protected:
   string text;

 public:
   virtual void display() = 0;
};
class FlyInterface
{
 protected:
   bool fly;

 public:
   virtual void canFly() = 0;
};
class displayConcreteClass : public DisplayInterface
{
 public:
   displayConcreteClass(string s = "")
   {
      this->text = s;
   }
   void display()
   {
      cout << "Display : " << text << endl;
   }
};
class flyConcreteClass : public FlyInterface
{
 public:
   flyConcreteClass(bool f = false)
   {
      this->fly = f;
   }
   void canFly()
   {
      cout << "Can Fly : " << fly << endl;
   }
};
class Duck
{
   displayConcreteClass di;
   flyConcreteClass fi;

 public:
   Duck(displayConcreteClass di, flyConcreteClass fi)
   {
      this->di = di;
      this->fi = fi;
   }
   void getDisplay()
   {
      this->di.display();
   };
   void getFly()
   {
      this->fi.canFly();
   };
   void getInfo()
   {
      this->getDisplay();
      this->getFly();
      cout << endl;
   }
};

int main()
{
   displayConcreteClass s1("Mountain Duck");
   displayConcreteClass s2("Rubber Duck");
   displayConcreteClass s3("City Duck");
   flyConcreteClass f1(true);
   flyConcreteClass f2(false);
   Duck d1(s1, f1);
   d1.getInfo();
   Duck d2(s2, f2);
   d2.getInfo();
   Duck d3(s3, f1);
   d3.getInfo();
}
