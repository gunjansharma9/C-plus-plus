#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SelectionSort(vector<int>&arr,int size){
    for(int i=0;i<size-1;i++){
        int mini = i;
        for(int j=i+1;j<size;j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        swap(arr[i],arr[mini]);
    }
}
int main(){
    vector<int>arr{3,2,1,6,4,7,8,34,54,12,67,5,67,5,5,5,99,90};
    int size = arr.size();
    SelectionSort(arr,size);
    for(auto i:arr){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}