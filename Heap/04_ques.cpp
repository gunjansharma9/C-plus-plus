#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;


// merge k sorted array
class info{
    public:
    int data;
    int row;
    int col;

    info(int val,int r,int c){
        data = val;
        row = r;
        col = c;
    }
};

// khud ka comparator bnao minHeap m comparision k liye
class compare{
    public:
    bool operator()(info* a,info* b){
        return a->data > b->data;
    }

};

// hr array ka first element minHeap m insert kro phir minheap se ek element nikalo or usko pop krke ushi array ka next element push kro 
vector<int> mergeKSortedArrays(int arr[][4],int k,int n){
    priority_queue<info*,vector<info*>,compare>minHeap;

    // hr array k first element ko insert kro
    for(int i=0;i<k;i++){
        info* temp = new info(arr[i][0],i,0);
        minHeap.push(temp);
    }
    vector<int>ans;

    while(!minHeap.empty()){
        info* temp = minHeap.top();
        int topElement = temp->data;
        int topRow = temp->row;
        int topCol = temp->col;
        minHeap.pop();

        ans.push_back(topElement);

        if(topCol + 1 < n){
            info* newInfo = new info(arr[topRow][topCol + 1],topRow,topCol+1);

            minHeap.push(newInfo);
        }
    }

    return ans;
}

int main(){
    int arr[][4] = {{2,4,6,8},
                    {1,3,5,7},
                    {0,9,10,11}};
    int k = 3;
    int n = 4;
    vector<int>ans = mergeKSortedArrays(arr,k,n);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}


// 23. Merge k Sorted Lists

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*,vector<ListNode*>,compare> minHeap;      

        int k = lists.size();
        if(k == 0){
            return NULL;
        }

        // first element of every linked list ko insert krdo heap m
        for(int i=0;i<k;i++){
            if(lists[i] != NULL){
                minHeap.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!minHeap.empty()){
            ListNode* temp = minHeap.top();
            minHeap.pop();

            // temp may or may not be the first element of ans linked list
            if(head == NULL){
                // temp->first element of ans LL
                head = temp;
                tail = temp;
                if(tail->next != NULL){
                    minHeap.push(tail->next);
                }
            }
            else{
                // temp in not the first element of LL
                tail->next = temp;
                tail = temp;
                if(tail->next != NULL){
                    minHeap.push(tail->next);
                }
            }
        }
        return head;
    }
};




// 632. Smallest Range Covering Elements from K Lists
class node{
    public:
    int data;
    int row;
    int col;

    node(int d,int r,int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<node*,vector<node*>,compare>minHeap;
        int k = nums.size();
        for(int i=0;i<k;i++){
            int element = nums[i][0];
            maxi = max(maxi,element);
            mini = min(mini,element);
            minHeap.push(new node(element,i,0));
        }

        int ansStart = mini;
        int ansEnd = maxi;

        while(!minHeap.empty()){
            node* top = minHeap.top();
            int topelement = top->data;
            int topRow = top->row;
            int topCol = top->col;
            minHeap.pop();

            // mini updated
            mini = topelement;

            // check for answer
            int currRange = maxi-mini;
            int ansRange = ansEnd-ansStart;
            if(currRange < ansRange){
                ansStart = mini;
                ansEnd = maxi;
            }

            // check for new element in the same list
            if(topCol + 1 < nums[topRow].size()){
                maxi = max(maxi,nums[topRow][topCol+1]);
                node* newNode = new node(nums[topRow][topCol+1],topRow,topCol+1);
                minHeap.push(newNode);   
            }
            else{
                // if there is no element in the same array or list
                break;
            }
        }

        vector<int>ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};


// 1962. Remove Stones to Minimize the Total

// saare element ko maxHeap m push krdo phir maximum element nikalte jao maxheap m se or value update krte jao or update krne k baad phir se heap m insert krdo phir last m jb k zero ho jaye toh saare element ko add krke sum return krdo
int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int>maxHeap;

    for(int i=0;i<piles.size();i++){
        maxHeap.push(piles[i]);
    }

    while(k--){
        int maxElement = maxHeap.top();
        maxHeap.pop();
        maxElement = maxElement - floor(maxElement/2);
        maxHeap.push(maxElement);
    }

    int sum = 0;
    while(!maxHeap.empty()){
        int temp = maxHeap.top();
        maxHeap.pop();
        sum += temp;
    }
    return sum;
}



// 767. Reorganize String

// class node{
//     public:
//     char data;
//     int count;

//     node(char d,int c){
//         data = d;
//         count = c;
//     }
// };

// class compare{
//     public:
//     bool operator()(node a,node b){
//         return a.count < b.count;
//     }
// };

// class Solution {
// public:
//     string reorganizeString(string s) {
//         //create mapping
//         int freq[26] = {0};

//         for(int i=0;i<s.length();i++){
//             char ch = s[i];
//             freq[ch-'a']++;
//         }

//         priority_queue<node,vector<node>,compare>maxHeap;

//         for(int i=0;i<26;i++){
//             if(freq[i] != 0){
//                 node temp(i+'a',freq[i]);
//                 maxHeap.push(temp);
//             }
//         }

//         string ans = "";

//         while(maxHeap.size() > 1){
//             node first = maxHeap.top();
//             maxHeap.pop();
//             node second = maxHeap.top();
//             maxHeap.pop();

//             ans += first.data;
//             ans += second.data;

//             first.count--;
//             second.count--;

//             if(first.count != 0){
//                 maxHeap.push(first);
//             }

//             if(second.count != 0){
//                 maxHeap.push(second);
//             }
//         }
//         if(maxHeap.size() == 1){
//             node temp = maxHeap.top();
//             maxHeap.pop();
//             if(temp.count == 1){
//                 ans += temp.data;
//             }
//             else{
//                 return "";
//             }
//         }
//         return ans;
//     }
// };



// 1405. Longest Happy String
// class node{
//     public:
//     char data;
//     int count;

//     node(char d,int c){
//         data = d;
//         count = c;
//     }
// };

// class compare{
//     public:
//     bool operator()(node a,node b){
//         return a.count < b.count;
//     }
// };

// class Solution {
// public:
//     string longestDiverseString(int a, int b, int c) {
//         priority_queue<node,vector<node>,compare>maxHeap;

//         if(a>0){
//             node temp('a',a);
//             maxHeap.push(temp);
//         }

//         if(b>0){
//             node temp('b',b);
//             maxHeap.push(temp);
//         }

//         if(c>0){
//             node temp('c',c);
//             maxHeap.push(temp);
//         }

//         string ans = "";
//         while(maxHeap.size() > 1){
//             node first = maxHeap.top();
//             maxHeap.pop();
//             node second = maxHeap.top();
//             maxHeap.pop();

//             if(first.count >= 2){
//                 ans += first.data;
//                 ans += first.data;
//                 first.count -= 2;
//             }
//             else{
//                 ans += first.data;
//                 first.count--;
//             }

//             if(second.count >= 2 && second.count >= first.count){
//                 // this line is important
//                 ans += second.data;
//                 ans += second.data;
//                 second.count -= 2;
//             }
//             else{
//                 ans += second.data;
//                 second.count--;
//             }

//             if(first.count > 0){
//                 maxHeap.push(first);
//             }

//             if(second.count > 0){
//                 maxHeap.push(second);
//             }
//         }

//         if(maxHeap.size() == 1){
//             node temp = maxHeap.top();
//             maxHeap.pop();

//             if(temp.count >= 2){
//                 ans += temp.data;
//                 ans += temp.data;
//                 temp.count -= 2;
//             }
//             else{
//                 ans += temp.data;
//                 temp.count--;
//             }
//         }
//         return ans;
//     }
// };