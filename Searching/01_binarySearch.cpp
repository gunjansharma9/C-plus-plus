#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(int *arr,int size,int target){
    int s = 0;
    int e = size-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {3,4,5,6,7,8,12,13,15,16,22};
    int target = 12;
    int size = sizeof(arr)/sizeof(int);

    int index = binarySearch(arr,size,target);
    cout<<"Target is present at index = "<<index<<endl;

    vector<int>v{3,5,6,12,14,15};
    // binary Search stl
    if(binary_search(v.begin(),v.end(),12)){
        cout<<"Found"<<endl;
    }else {
        cout<<"Not Found"<<endl;
    }
    
    // stl use in array
    if(binary_search(arr,arr+size,4)){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
    return 0;
}