#include <iostream>
#include <queue>
using namespace std;

// kth smallest element
// ish ques ko solve krne k liye hm min heap use kr skte hai lekin ni krre qki usse time complexity toh O(n) hai but space b O(n) hai pr agr hm max heap ka use kre toh time complexity toh O(n) hai lekin space complexity O(k) hai isliye maxheap preferable hai

// sbse phele first k element of array se maxheap bna do phir remaining element mein condition check kro agr next element chota hai maxheap k top k element se toh top element ko delete kro or next vale element ko push kro ,saare remaining element k liye process repeat kro


int getKthSmallestElement(int arr[],int n,int k){
    // create max heap
    priority_queue<int>pq;

    // insert initial k elements of array
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i=k;i<n;i++){
        int element = arr[i];
        if(element < pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}


int getKthLargestElement(int arr[],int n,int k){
    // create min heap
    priority_queue<int,vector<int>,greater<int>>pq;

    // insert initial k elements of array
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i=k;i<n;i++){
        int element = arr[i];
        if(element > pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}
void heapify(vector<int>&arr,int n,int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
vector<int>mergeHeaps(vector<int>&a,vector<int>&b,int n,int m){
    vector<int>ans;
    for(auto i:a){
        ans.push_back(i);
    }
    for(auto i:b){
        ans.push_back(i);
    }

    int size = ans.size();
    for(int i=size/2-1;i>=0;i--){
        heapify(ans,size,i);
    }
    return ans;
}

// check given binary tree is heap or not(max)

// pair bnao ab tk heap hai ya ni or dusri value usme maximum ab tk ki store krlo

// pair<bool,int>solve(Node* root){
//     if(root == NULL){
//         pair<bool,int>p = make_pair(true,INT_MIN);
//         return p;
//     }
//     if(root->left == NULL && root->right == NULL){
//         pair<bool,int> p = make_pair(true,root->data);
//         return p;
//     }
//     pair<bool,int>leftAns = solve(root->left);
//     pair<bool,int>rightAns = solve(root->right);

//     if(leftAns.first == true && rightAns.first == true && root->data > leftAns.second && root->data > rightAns.second){
//         pair<bool,int>p = make_pair(true,root->data);
//         return p;
//     }
//     else{
//         pair<bool,int>p = make_pair(false,root->data);
//         return p;
//     }
// }

int main(){
    int arr[] = {10,5,20,4,15};
    int n = 5;
    int k = 2;
    int ans = getKthSmallestElement(arr,n,k);
    cout<<"Kth smallest element is : "<<getKthSmallestElement(arr,n,k)<<endl;

    cout<<"Kth Largest element is : "<<getKthLargestElement(arr,n,k)<<endl;

    vector<int> arr1 = {10,5,6,2};
    vector<int> arr2 = {12,7,9};
    vector<int>mergedHeap;
    mergedHeap = mergeHeaps(arr1,arr2,4,3);

    for(auto i:mergedHeap){
        cout<<i<<" ";
    }

    return 0;
}