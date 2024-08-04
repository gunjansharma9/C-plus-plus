#include <iostream>
using namespace std;

void printPermutation(string& str,int i){
    // base case
    if(i >= str.length()){
        cout<<str<<" ";
        return ;
    }

    for(int j=i;j<str.length();j++){
        // swap
        swap(str[i],str[j]);

        printPermutation(str,i+1);
        // Backtracking - to make string in original form
        swap(str[i],str[j]);
    }
}

int main(){
    string s="abc";
    int i=0;
    printPermutation(s,i);

    return 0;
}