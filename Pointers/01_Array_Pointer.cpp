#include "bits/stdc++.h"
using namespace std;

int main(){
    int arr[] = {34,21,33,56};
    int i=0;
    cout<<arr[i]<<endl;
    cout<<i[arr]<<endl;
    cout<<*(i+arr)<<endl;
    cout<<*(arr+i)<<endl;
    cout<<arr<<endl;
    cout<<&arr<<endl;
    cout<<&arr[0]<<endl;

    // behaviour of character and integer array is completely different 
    // in character array when we print ch then array value will get printed but in case of integer array base address will get printed
    cout<<"Character array : "<<endl;
    // char ch[10] = "Babbar";
    // char *c = ch;
    // cout<<ch<<endl;
    // cout<<&ch<<endl;
    // cout<<ch[0]<<endl;
    // cout<<&c<<endl;
    // cout<<*c<<endl;
    // cout<<c<<endl;

    char name[9] = "SherBano";
    char* c = &name[0];
    cout<<name<<endl;
    cout<<&name<<endl;
    cout<<*(name+3)<<endl;
    cout<<c<<endl;
    cout<<&c<<endl;
    cout<<*(c+3)<<endl;
    cout<<c+2<<endl;
    cout<<*c<<endl;
    cout<<c+8<<endl;

    // cout ka behaviour hai jb tk \0 na miley tb tk print krte jaao
    char character = 'g';
    char* cptr = &character;
    cout<<cptr;
    return 0;
}