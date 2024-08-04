#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    // // UNION WITHOUT DUBLICATES
    // int arr1[] = {1,2,3,4,5,6};
    // int arr2[] = {5,6,7,8,4,3};

    // int n1 = sizeof(arr1)/sizeof(int);
    // int n2 = sizeof(arr2)/sizeof(int);
    // vector<int>ans;

    // for(int i=0;i<n1;i++){
    //     ans.push_back(arr1[i]);
    //     for(int j=0;j<n2;j++){
    //         if(arr1[i] == arr2[j]){
    //             arr2[j] = -1;
    //         }
    //     }
    // }
    // for(int j=0;j<n2;j++){
    //     if(arr2[j] != -1){
    //         ans.push_back(arr2[j]);
    //     }
    // }

    // for(int i:ans){
    //     cout<<i<<" ";
    // }cout<<endl;

    // // PAIR SUM
    // vector<int>sum{3,4,5,6,2,7,8,1};
    // int target = 9;
    // sort(sum.begin(),sum.end());

    // int start = 0;
    // int end = sum.size()-1;
    // pair<int,int>p = {-1,-1};
    // while(start < end){
    //     if(sum[start]+sum[end] == target){
    //         p.first = sum[start];
    //         p.second = sum[end];
    //         break;
    //     }
    //     else if(sum[start]+sum[end] > target){
    //         end--;
    //     }else {
    //         start++;
    //     }
    // }

    // cout<<"The pair which has sum = "<<target<<" is "<<"("<<p.first<<","<<p.second<<")"<<endl;


    // Sort 0's and 1's
    vector<int>arr{0,1,1,0,1,0,1,1,0,0,0,1,0,1,0,1};
    int start = 0;
    int end = arr.size()-1;
    int i=0;

    while(i != end){
        if(arr[i] == 0){
            swap(arr[start],arr[i]);
            i++;
            start++;
        }
        else{
            swap(arr[i],arr[end]);
            end--;
        }
    }

    for(int i:arr){
        cout<<i<<" ";
    }cout<<endl;

    // Transpose of a matrix
    int arr2[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int transpose[3][3];

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            // swap(arr2[i][j],arr2[j][i]);
            transpose[i][j] = arr2[j][i];
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}