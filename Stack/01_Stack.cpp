#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    stack <int> s;

    s.push(4);
    s.push(3); 
    s.push(1);

    s.pop();

    cout<<"Element on the top is : "<<s.top()<<endl;

    cout<<"Size of stack is : "<<s.size()<<endl;

    if(s.empty()){
        cout<<"Stack is empty.."<<endl;
    }else{
        cout<<"Stack is not empty..."<<endl;
    }

    // Printing element of stack
    while(!s.empty()){
        cout<<s.top()<<" ";  
        s.pop();
    }
    cout<<endl;
    // stack reverses the original order

    return 0;
}

// reverse of a string using stack
// int main(){
//     string str = "Gunjan";
//     stack <char> s;
//     int i = 0;
//     while(i != str.length()){
//         s.push(str[i]);
//         i++;
//     }

//     while(s.empty() != true){
//         cout<<s.top()<<"";
//         s.pop();
//     }


//     return 0;
// }