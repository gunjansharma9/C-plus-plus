#include <iostream>
using namespace std;

// partition algo
// recursive algo
int partition(int arr[],int s,int e){
    // step1 : choose pivotElement
    int pivotIndex = s;
    int pivotElement = arr[s];

    // step2 : find right position for pivot element and place it there
    int count = 0;
    for(int i=s+1;i<=e;i++){
        if(arr[i] <= pivotElement){
            count++;
        }
    }

    // position pivot element at its right position
    int rightIndex = s+count;
    swap(arr[pivotIndex],arr[rightIndex]);
    pivotIndex = rightIndex;

    // now make sure all the element less than pivotelement are on the left side of the element and greater element are on its right side

    int i = s;
    int j = e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i] <= pivotElement && i<pivotIndex){
            i++;
        }
        while(arr[j] > pivotElement && j>pivotIndex){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i],arr[j]);
        }
    }

    return pivotIndex;
}

void QuickSort(int *arr,int s,int e){
    if(s >= e){
        return;
    }

    int p = partition(arr,s,e);

    QuickSort(arr,s,p-1);
    QuickSort(arr,p+1,e);
}

int main(){
    int arr[] = {6,3,22,12,45,67,89,90,76,87,43,33,56,67,90,99};
    int n = sizeof(arr)/sizeof(int);

    int s = 0;
    int e = n-1;
    QuickSort(arr,s,e);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}