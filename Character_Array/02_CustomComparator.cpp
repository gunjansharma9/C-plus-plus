#include "bits/stdc++.h"
using namespace std;

bool cmp(char first,char second){
    return first > second;
}

int main(){
    string s = "babbar";
    sort(s.begin(),s.end(),cmp);
    cout<<s<<endl;
    return 0;
}