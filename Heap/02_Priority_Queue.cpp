#include <iostream>
#include <queue>
using namespace std;

int main(){
    // Max heap creation
    priority_queue<int>pq;
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    cout<<"Top element is : "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top element is : "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top element is : "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top element is : "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top element is : "<<pq.top()<<endl;
    pq.pop();

    cout<<"Size: "<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"Max heap is empty"<<endl;
    }
    else{
        cout<<"Max heap is not empty"<<endl;
    }

    // Min heap creation
    priority_queue<int,vector<int>,greater<int>>minHeap;
    minHeap.push(3);
    minHeap.push(6);
    minHeap.push(4);
    minHeap.push(9);
    minHeap.push(8);

    cout<<"Top element : "<<minHeap.top()<<endl;
    minHeap.pop();

    cout<<"Size is : "<<minHeap.size()<<endl;

    cout<<"Top element : "<<minHeap.top()<<endl;
    minHeap.pop();

    cout<<"Top element : " <<minHeap.top()<<endl;
    minHeap.pop();

    if(minHeap.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
    return 0;
}