#include <iostream>
using namespace std;

// // Encapsulation -> data hiding
// // we can make read only data by using this
// // Reusability

// class Animal{
//     public:
//     int age;
//     int weight;

//     void eat(){
//         cout<<"Eating"<<endl;
//     }
// };

// // Inheritance
// class Dog:protected Animal{
//     public:
//     void print(){
//         cout<<this->age;
//     }
// };

// int main(){
//     Dog d1;
//     d1.print();
//     return 0;
// }

//protected mein sirf class k andr access kr skte hai bahr ni
// protected ko child class k andr b access kr skte hai 
// private or protected mein difference bs itna h private ko hm inherit nhi kr skte pr protected ko kr skte h

// types of inheritance
// 1-Single
// 2-Multiple
// 3-Multi-level
// 4-Hybrid
// 5-Heirarchical


class A{
    public:
    int chemistry;
    A(){
        chemistry = 101;
    }
};
class B{
    public:
    int chemistry;
    B(){
        chemistry = 432;
    }
};
class C:public A,public B{
    public:
    int maths;
};

int main(){
    C obj;
    cout<<" "<<obj.B::chemistry<<" "<<obj.maths<<endl;

    return 0;
}