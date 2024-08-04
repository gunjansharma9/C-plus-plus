#include <iostream>
using namespace std;

class Animal{
    // property
    private:
    int weight;

    public:
    int age;
    string name;
    string type;

    // behaviour
    void eat(){
        cout<<"Eating"<<endl;
    }

    void sleep(){
        cout<<"Sleeping"<<endl;
    }

    // getter and setter
    int getWeight(){
        return weight;
    }

    void setWeight(int weight){
        this->weight = weight;
    }

    // Default Constructor 
    Animal(){
        this->weight = 0;
        this->age = 0;
        this->name=" ";
        this->type=" ";
        cout<<"Constructor called"<<endl;
    }

    // Parameterised constructor
    Animal(int age){
        this->age = age;
        cout<<"Parameterised constructor called"<<endl;
    }

    Animal(int age,int weight){
        this->age = age;
        this->weight = weight;
        cout<<"Parameterised constructor 2 called"<<endl;
    }

    // copy constructor
    // this is taking pointer as an argument
    // Animal(Animal* &obj){
    //     // yha pr pass by reference lena jruri hai...
    //     this->age = obj->age;
    //     this->weight = obj->weight;
    //     this->name = obj->name;
    //     this->type = obj->type;
    //     cout<<"I am inside copy constructor"<<endl;
    // }

    // this is taking static variable as an argument
    Animal(Animal &obj){
        this->age = obj.age;
        this->weight=obj.weight;
        this->name=obj.name;
        this->type=obj.type;
        cout<<"I am inside copy constructor which is taking static variable"<<endl;
    }

    void print(){
        cout<<this->age<<" "<<this->weight<<" "<<this->type<<" "<<this->name<<endl;
    }

    ~Animal(){
        cout<<"I am inside destructor"<<endl;
    }
};

int main(){
    // Animal Gunjan;
    // Gunjan.age = 19;
    // Gunjan.name = "Gunjan";
    // cout<<"Age of Gunjan is : "<<Gunjan.age<<endl;
    // cout<<"Name of Gunjan is : "<<Gunjan.name<<endl;

    // Gunjan.eat();
    // Gunjan.sleep();

    // // to access private member
    // Gunjan.setWeight(50);
    // cout<<"Weight : "<<Gunjan.getWeight()<<endl;


    // // Dynamic Memory
    // Animal* Bhavya = new Animal;

    // (*Bhavya).age=20;
    // (*Bhavya).type = "billi";

    // // alternate - dynamic
    // Bhavya->age=34;
    // Bhavya->type="kutta";
    // cout<<Bhavya->age<<" ";

    // Bhavya->eat();
    // Bhavya->sleep();

    // Animal nitya(78);
    // Animal* avni = new Animal(600,40);
    
    // // we are coping here
    // Animal* b = avni;
    // Animal c(nitya);

    Animal a;
    a.age=20;
    a.setWeight(101);
    a.type = "female";
    a.name="gunjan";

    Animal b=a;
    cout<<"a -> ";
    a.print();
    cout<<"b -> ";
    b.print();

    a.type[0]='G';
    cout<<"a -> ";
    a.print();

    cout<<"b -> ";
    b.print();
    return 0;
}

// 'new' keyword pointer return krta hai
// 'this' is a pointer to current object