#include <iostream>
using namespace std;

class SUM{
    public:

    int sum(int a,int b){
        cout<<"I am in first Signature"<<endl;
        return a+b;
    }

    int sum(int a,int b,int c){
        cout<<"I am in Second Signature"<<endl;
        return a+b+c;
    }

    int sum(int a,float b){
        cout<<"I am in third Signature"<<endl;
        return a+b+100;
    }
};

int main(){
    SUM obj;
    cout<<obj.sum(2,5.12f)<<endl;

    return 0;
}