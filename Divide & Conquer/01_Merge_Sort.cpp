#include <iostream>
using namespace std;

void print(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Merge(int *arr,int s,int e){
    int mid=(s+e)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    int *left= new int[len1];
    int *right = new int[len2];

    int k=s;
    for(int i=0;i<len1;i++){
        left[i]=arr[k++];
    }

    for(int i=0;i<len2;i++){
        right[i]=arr[k++];
    }

    int leftIndex=0,rightIndex=0,mainIndex=s;
    while(leftIndex<len1 && rightIndex<len2){
        if(left[leftIndex]<right[rightIndex]){
            arr[mainIndex++] = left[leftIndex++];
        }
        else{
            arr[mainIndex++] = right[rightIndex++];
        }
    }

    while(leftIndex<len1){
        arr[mainIndex++] = left[leftIndex++];
    }

    while(rightIndex<len2){
        arr[mainIndex++] = right[rightIndex++];
    }

}

void MergeSort(int* arr,int s,int e){

    // base case
    if(s >= e){
        return ;
    }

    int mid=(s+e)/2;

    MergeSort(arr,s,mid);
    MergeSort(arr,mid+1,e);

    Merge(arr,s,e);
}


int main(){
    int arr[]={2,33,54,23,78,98,55,67,80,100,2,2,2,3,3,5,5,7};
    int size=sizeof(arr)/sizeof(int);

    int s=0,e=size-1;

    MergeSort(arr,s,e);

    cout<<"After sorting array becomes : "<<endl;

    print(arr,size);
    return 0;
}




// COUNT INVERSIONS

long merge(vector<int>& arr, vector<int>& temp, int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;
    long c = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // inversion count condition
            temp[k++] = arr[j++];
            c += mid - i + 1;
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= end) {
        temp[k++] = arr[j++];
    }

    for (int i = start; i <= end; i++) {
        arr[i] = temp[i];
    }

    return c;
}

long mergeSort(vector<int>& arr, vector<int>& temp, int start, int end) {
    if (start >= end) return 0;

    int mid = start + (end - start) / 2;
    long c = 0;

    c += mergeSort(arr, temp, start, mid);
    c += mergeSort(arr, temp, mid + 1, end);
    c += merge(arr, temp, start, mid, end);

    return c;
}

long countInversions(vector<int> arr) {
    long c = 0;
    vector<int> temp(arr.size(), 0);
    c = mergeSort(arr, temp, 0, arr.size() - 1);
    return c;
}