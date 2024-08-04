#include <iostream>
#include <vector>
using namespace std;

// vector is dynamic in nature
// They automatically manage their own memory and resize dynamically as elements are added

// Q -> all the elements are present twice except one element,find that element
// Sol -> Xor operation return 0 when same element are present otherwise 1
// 1^1^2 == 2
int findUnique(vector<int>arr){
    int ans = 0;
    for(int i=0;i<arr.size();i++){
        ans = ans^arr[i];
    }
    return ans;
}
int main(){
    // vector<int>v;

    // cout<<v.size()<<endl;
    // cout<<v.capacity()<<endl;

    // vector<int>arr(5,-1);
    // for(int i:arr){
    //     cout<<i<<" ";
    // }cout<<endl;

    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter the elements of the array : "<<endl;
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    int uniqueElement = findUnique(arr);
    cout<<"Unique Element is : "<<uniqueElement<<endl;

    int row = 3;
    int col = 5;
    vector<vector<int> >arr2(row,vector<int>(col,0));
    for(int i=0;i<arr2.size();i++){
        for(int j=0;j<arr2[i].size();j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}