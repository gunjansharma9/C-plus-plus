#include <iostream>
using namespace std;

class Animal{
    public:
    virtual void speak(){
        cout<<"Speaking "<<endl;
    }

    Animal(){
        cout<<"Animal class constructor is called"<<endl;
    }
};

class Dog:public Animal{
    public:
    // over write
    void speak(){
        cout<<"Barking"<<endl;
    }

    Dog(){
        cout<<"Dog class constructor is called"<<endl;
    }
};

int main(){
    // Dog a;
    // a.speak();

    // Animal* a = new Animal();
    // a->speak();

    // Dog* a = new Dog();
    // a->speak();

    // UpCasting
    Animal* a = new Dog();
    a->speak();

    // DownCasting
    // Dog* b = (Dog*) new Animal();
    // b->speak();

    return 0;
}
// left hand side vala pointer hota hai or right hand side vala object

// upcasting and downcasting dono mein hmara pointer ka method call ho rha hoga agr hm bina virtual keyword call krte hai toh

// jb child class ka object bnate hai toh constructor phele parent class ka call hota h phir child class ka

// agr parent ka object bnate hai toh bs parent ka constructor call hoga 

// encapsulation is a subset of abstraction