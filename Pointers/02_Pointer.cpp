#include "bits/stdc++.h"
using namespace std;

int* solve(){
    int a = 5;
    int* ans = &a;
    return ans;
}
int main(){
    int a = 5;
    int* p = &a;
    int** q = &p;

    cout<<&a<<endl;
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<*p<<endl;
    cout<<q<<endl;
    cout<<&q<<endl;
    cout<<*q<<endl;
    cout<<**q<<endl;

    // creating a reference variable
    int b = 4;
    int& c = b;
    cout<<b<<endl;
    cout<<c<<endl;
    // a&b are pointing to same memory location

    cout<<"Printing interview ques : "<<endl;
    cout<<solve()<<endl;
    return 0;
}