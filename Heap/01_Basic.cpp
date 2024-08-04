#include <iostream>
using namespace std;

class Heap{
    public:
    int arr[10];
    int size;

    Heap(){
        size = 0;
    }

    void insert(int value){
        // value insert kro end mein
        size = size + 1;
        int index = size;
        arr[index] = value;

        // iss value ko place at right[correct position] position
        while(index > 1){
            int parentIndex = index/2;
            if(arr[index] > arr[parentIndex]){
                swap(arr[index],arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    int deletenode(){
        int ans = arr[1];
        // replace root node value with last node data
        arr[1] = arr[size];
        size--;

        // replace root node ka data on its correct position
        int index = 1;
        while(index < size){
            int left = 2*index;
            int right = 2*index + 1;

            int largest = index;
            if(left < size && arr[largest]<arr[left]){
                largest = left;
            }
            if(right < size && arr[largest]<arr[right]){
                largest = right;
            }

            if(largest == index){
                // value is at correct position
                break;
            }else{
                swap(arr[index],arr[largest]);
                index = largest;
            }
        }
        return ans;
    }
};

void heapify(int arr[],int n,int i){
    int index = i;
    int leftIndex = 2*i;
    int rightIndex = 2*i+1;
    int largest = index;

    if(leftIndex <= n && arr[largest] < arr[leftIndex]){
        largest = leftIndex;
    }
    if(rightIndex <=n && arr[largest] < arr[rightIndex]){
        largest = rightIndex;
    }

    if(index != largest){
        // left ya right child me se koi > hogya hai currentNode se
        swap(arr[index],arr[largest]);
        index = largest;
        heapify(arr,n,index);
    }
}

void buildHeap(int arr[],int n){
    // n/2+1 se saari leaf node hai isliye include mt kro
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
}

void heapSort(int arr[],int n){
    while(n != 1){
        swap(arr[1],arr[n--]);
        heapify(arr,n,1);
    }
}

int  main(){
    // indexing 1 se hai
    Heap h;
    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);
    cout<<"Printing the heap"  <<endl;

    for(int i=1; i<=h.size ;i++){
        cout<<h.arr[i]<<" ";
    }cout<<endl;

    cout<<h.deletenode()<<endl;

    for(int i=1; i<=h.size ;i++){
        cout<<h.arr[i]<<" ";
    }cout<<endl;

    int arr[] = {-1,12,15,13,11,14};
    int n = 5;
    buildHeap(arr,n);

    cout<<"Printing heap"<<endl;
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }

    heapSort(arr,n);
    cout<<"Printing the heap"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}