#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int>&arr,int n){
    for(int round=1;round<n;round++){
        int val = arr[round];
        int j=round-1;
        for(;j>=0;j--){
            if(arr[j] > val){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }

        arr[j+1] = val;
    }
}

int main(){
    vector<int>v{4,2,1,54,6,42,56,78,77,89,68};
    int size = v.size();
    InsertionSort(v,size);
    for(auto i:v){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}