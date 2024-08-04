#include <iostream>
#include <stack>
using namespace std;

// class Stack{
//     private:
//         int *arr;
//         int top;
//         int size;

//     public:
//     Stack(int size){
//         arr = new int[size];
//         this -> size = size;
//         top = -1;
//     }

//     void push(int data){
//         if(size-top > 1){
//             top++;
//             arr[top] = data;
//         }else{
//             cout<<"Stack Overflow"<<endl;
//         }
//     }

//     void pop(){
//         if(top != -1){
//             cout<<"Popped element is : "<<arr[top]<<endl;
//             top--;
//         }else{
//             cout<<"Stack is Empty"<<endl;
//         }
//     }

//     int getTop(){
//         if(top != -1){
//             return arr[top];
//         }else{
//             cout<<"Stack is empty"<<endl;
//         }
//     }

//     int getSize(){
//         return top+1;
//     }

//     bool isEmpty(){
//         if(top == -1){
//             return true;
//         }else{
//             return false;
//         }
//     }

//     bool isFull(){
//         if(top == size-1){
//             return true;
//         }else{
//             return false;
//         }
//     }

//     void display(){
//         if(top == -1){
//             cout<<"Stack is empty"<<endl;
//         }
//         int temp = top;
//         while(temp != -1){
//             cout<<arr[temp]<<" ";
//             temp--;
//         }
//         cout<<endl;
//     }
// };

// int main(){
//     Stack s(10);
//     s.push(34);
//     s.push(12);
//     s.push(67);

//     s.display();

//     s.push(4);
//     s.pop();

//     cout<<"Size of the stack is : "<<s.getSize()<<endl;

//     cout<<"Topmost element is : "<<s.getTop()<<endl;

//     if(s.isEmpty()){
//         cout<<"Stack is empty"<<endl;
//     }else{
//         cout<<"Stack is not empty"<<endl;
//     }

//     cout<<"Size of stack is : "<<s.getSize()<<endl;

//     if(s.isFull()){
//         cout<<"Stack is Full"<<endl;
//     }else{
//         cout<<"Stack is not Full"<<endl;
//     }
//     return 0;
// }


// 1 array 2 stack
class Stack{
    private:
    int *arr;
    int size;
    int top1;
    int top2;

    public:
    Stack(int size){
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
        this->arr = new int[size];
    }

    void push1(int data){
        if(size-top1 > 1 && (top1+1 != top2)){
            top1++;
            arr[top1] = data;
            return;
        }
        else{
            cout<<"Stack is Full"<<endl;
        }
    }

    void push2(int data){
        if(top2-1 != top1){
            top2--;
            arr[top2] = data;
            return;
        }else{
            cout<<"Stack is full"<<endl;
        }
    }

    void display1(){
        if(top1 == -1){
            cout<<"Stack 1 is empty"<<endl;
            return;
        }
        int temp = top1;
        while(temp != -1){
            cout<<arr[temp]<<" ";
            temp--;
        }cout<<endl;
    }

    void display2(){
        if(top2 == size){
            cout<<"Stack 2 is empty"<<endl;
            return;
        }
        int temp = top2;
        while(temp != size){
            cout<<arr[temp]<<" ";
            temp++;
        }cout<<endl;
    }

    void pop1(){
        if(top1 != -1){
            cout<<"Popped element from stack1 is : "<<arr[top1]<<endl;
            top1--;
            return;
        }
        else{
            cout<<"Stack 1 is empty"<<endl;
        }
    }

    void pop2(){
        if(top2 != size){
            cout<<"Popped element from stack2 is : "<<arr[top2]<<endl;
            top2++;
            return;
        }else{
            cout<<"Stack 2 is empty"<<endl;
        }
    }
};

int main(){
    Stack s(10);
    s.push1(4);
    s.push1(4);

    s.display1();
    s.display2();

    s.push2(5);
    s.push2(9);
    s.push2(29);
    s.push2(94);
    s.push2(96);
    s.push2(98);
    s.push2(97);
    s.push2(2);
    s.display2();

    s.push1(3);
    s.push2(90);

    s.pop1();
    s.pop1();

    s.pop2();
    s.pop2();
    s.pop2();
    s.pop2();

    cout<<"Stack 1 elements are "<<endl;
    s.display1();

    cout<<"Stack 2 element are "<<endl;
    s.display2();

    s.push1(3);
    s.push2(45);
    s.push2(44);
    s.push2(32);

    s.display1();
    s.display2();

    return 0;
}