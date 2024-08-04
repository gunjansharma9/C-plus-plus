#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

void DecimalToBinary(){
    int n;
    cout<<"Enter a number in Decimal : ";
    cin>>n;

    stack<int>s;
    while(n != 0){
        int r = n%2;
        s.push(r);
        n = n/2;
    }
    cout<<"Binary equivalent of "<<n<<" is :" ;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void BinaryToDecimal(){
    int n;
    cout<<"Enter a binary number : ";
    cin>>n;

    int i=0;
    int decimal=0;
    while(n){
        int r = n%10;
        n = n/10;
        decimal += r*(pow(2,i));
        i++;
    }
    cout<<"Decimal equivalent of "<<n<<" is : "<<decimal<<endl;
}
int main(){
    // DecimalToBinary();
    // BinaryToDecimal();
    return 0;
}