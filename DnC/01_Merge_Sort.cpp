#include <iostream>
using namespace std;

void merge(int* arr,int s,int e){
    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    int *left = new int[len1];
    int *right = new int[len2];

    // create 2 arrays from 1 big array 
    int k = s;
    for(int i=0;i<len1;i++){
        left[i] = arr[k++];
    }

    k = mid+1;
    for(int i=0;i<len2;i++){
        right[i] = arr[k++];
    }

    int ptr1 = 0;
    int ptr2 = 0;
    int mainIndex = s;

    while(ptr1<len1 && ptr2<len2){
        if(left[ptr1]<right[ptr2]){
            arr[mainIndex++]= left[ptr1++];
        }else{
            arr[mainIndex++] = right[ptr2++];
        }
    }

    while(ptr1 < len1){
        arr[mainIndex++] = left[ptr1++];
    }

    while(ptr2 < len2){
        arr[mainIndex++] = right[ptr2++];
    }
}

void mergeSort(int *arr,int s,int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;

    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,e);
}

int main(){
    int arr[] = {34,12,32,66,86,87,44,89,80,90,31,50,2,2,2,3,4,5,6,8};
    int n = sizeof(arr)/sizeof(int);

    int s = 0;
    int e = n-1;
    mergeSort(arr,s,e);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}



// Merge sort in place => no extra space is used
// 912. Sort an Array


// class Solution {
// public: 
//     void mergeInPlace(vector<int>&v,int start,int mid,int end){
//         int total_len = end-start+1;
//         int gap = total_len/2 + total_len %2;
//         while(gap > 0){
//             int i = start,j = start+gap;
//             while(j <= end){
//                 if(v[i] > v[j]){
//                     swap(v[i],v[j]);
//                 }
//                 ++i,++j;
//             }   
//             // this computation of gap is to find the ceil value of gap
//             // it is just like shell sort
//             gap = gap <= 1 ? 0 : (gap/2) + (gap % 2);
//         }
//     }
//     void mergeSort(vector<int>&v,int start,int end){
//         if(start >= end) return;
//         int mid = (start + end) >> 1;
//         mergeSort(v,start,mid);
//         mergeSort(v,mid+1,end);
//         mergeInPlace(v,start,mid,end);
//     }
//     vector<int> sortArray(vector<int>& nums) {
//         mergeSort(nums,0,nums.size()-1);
//         return nums;
//     }
// };