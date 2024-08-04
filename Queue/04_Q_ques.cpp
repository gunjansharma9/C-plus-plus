#include <iostream>
#include<deque>
#include <stack>
#include <queue>

using namespace std;

// // Sliding window problem-->first negative number in a stream

// void solve(int arr[],int n, int k ) {
//         deque<int> q;
//         //process first window of size k 
//         for(int i=0; i<k; i++) {
//                 if(arr[i] < 0) {
//                         q.push_back(i);
//                 }
//         }

//         //remaining window ko process kro
//         for(int i=k; i<n; i++) {
//                 //answer dedo purani wondow ka 
//                 if(q.empty()) {
//                         cout << 0 << " ";
//                 }
//                 else {
//                         cout << arr[q.front()] << " ";
//                 }

//                 //out of window elements ko remove krdo
//                 while((!q.empty()) && (i - q.front() >= k)) {
//                         q.pop_front();
//                 }

//                 //check current element for insertion 
//                 if(arr[i] < 0 ) 
//                         q.push_back(i);

//         }

//         //answer print karonfor last window
//        if(q.empty()) {
//                 cout << 0 << " ";
//         }
//         else {
//                 cout << arr[q.front()] << " ";
//         }


// }

// int main() {
//   int arr[] = {12,-1,-7,8,-15,30,16,28};
//   int size = 8;
  
//   int k = 3;

//   solve(arr,size,k);



//   return 0;
// }



// // non repeating characters in a stream

// int main(){
//         string str = "aacbdfghhhuijk";
//         int freq[26] = {0};
//         queue<char>q;

//         string ans = "";

//         for(int i=0;i<str.length();i++){
//                 char ch = str[i];

//                 // increment frequency
//                 freq[ch - 'a']++;

//                 // q.push
//                 q.push(ch);

//                 while(!q.empty()){
//                         if(freq[q.front() - 'a'] > 1){
//                                 q.pop();
//                         }else{
//                               ans.push_back(q.front());
//                               break; 
//                         }
//                 }

//                 if(q.empty()){
//                         ans.push_back('#');
//                 }
//         }
//         cout<<"Final Ans : "<<ans<<endl;

//         return 0;
// }




// GAS STATION --> leetcode

// int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
// // kitna petrol km pd gya
// int deficit = 0;

// // kitna petrol bacha hua h
// int balance = 0;

// // circuit kaha se start krre ho
// int start = 0;

// for(int i=0;i<gas.size();i++){
//         balance += gas[i] - cost[i];
//         if(balance < 0){
//         // yhi pr galti hogi
//         deficit += balance;
//         start = i+1;
//         balance = 0;
//         }
// }

// if(deficit + balance >= 0){
//         return start;
// }else{ 
//         return -1;
// }
// }



// // Sliding window maximum

// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
//         deque<int>dq;
//         vector<int>ans;

//         // first window of k size
//         for(int i=0;i<k;i++){
//                 // chote element ko remove krdo
//                 while(!dq.empty() && nums[i] >= nums[dq.back()]){
//                 dq.pop_back();
//                 }
//                 // inserting index,so that we can checkout of window
//                 dq.push_back(i);
//         }

//         // store answer for first window
//         ans.push_back(nums[dq.front()]);

//         // remaining windows ko process
//         for(int i=k;i<nums.size();i++){
//                 // out of window element ko remove krdo
//                 if(!dq.empty() && i-dq.front() >= k){
//                 dq.pop_front();
//                 }

//                 // ab firse current element k liye chotte element ko remove krna h
//                 while(!dq.empty() && nums[i] >= nums[dq.back()]){
//                 dq.pop_back();
//                 }
//                 // inserting index so that we can checkout of window element
//                 dq.push_back(i);

//                 // current window ka answer store krna h
//                 ans.push_back(nums[dq.front()]);
//         }
//         return ans;
// }


// Implement queue using stack

// class MyQueue {
// public:
//     stack<int>s1,s2;
//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         s1.push(x);
//     }
    
//     int pop() {
//         int pop = -1;
//         if(!s2.empty()){
//             pop = s2.top();
//         }else{
//             while(!s1.empty()){
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//             pop = s2.top();
//         }
//         s2.pop();
//         return pop;
//     }
    
//     int peek() {
//         int front = -1;
//         if(!s2.empty()){
//             front = s2.top();
//         }else{
//             while(!s1.empty()){
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//             front = s2.top();
//         }
//         return front;
//     }
    
//     bool empty() {
//         return s1.empty() && s2.empty();
//     }
// };



// // Implement stack using queue

// class MyStack {
// public:
//     queue<int>q;
//     MyStack() {
        
//     }
    
//     void push(int x) {
//         q.push(x);
//         for(int i=0;i<q.size()-1;i++){
//             int front = q.front();
//             q.pop();
//             q.push(front);
//         }
//     }
    
//     int pop() {
//         int top = q.front();
//         q.pop();
//         return top;
//     }
    
//     int top() {
//         return q.front();
//     }
    
//     bool empty() {
//         return q.empty();
//     }
// };



// // Sum of MIN & MAX elements of All Subarray of size k

// int sumOfMinMaxOfAllWindowOfSizeK(vector<int>nums,int k){
//     deque<int>dq,dq2;
//     int ans = 0;

//     // first window of k size
//     for(int i=0;i<k;i++){
//         // chote element remove krdo,
//         while(!dq.empty() && nums[i] >= nums[dq.back()]){
//             dq.pop_back();
//         }

//         // bda element remove krdo
//         while(!dq2.empty() && nums[i] <= nums[dq2.back()]){
//             dq2.pop_back();
//         }

//         // inserting index,so that we can checkout of window element
//         dq.push_back(i);
//         dq2.push_back(i);
//     }

//     ans += nums[dq.front()] + nums[dq2.front()];

//     // remaining windows ko process 
//     for(int i=k;i<nums.size();i++){
//         // out of window element ko remove krdia
//         if(!dq.empty() && i-dq.front() >= k){
//             dq.pop_front();
//         }

//         if(!dq2.empty() && i-dq2.front() >= k){
//             dq2.pop_front();
//         }

//         // ab firse current element k liye chotte element
//         // ko remove krna h
//         while(!dq.empty() && nums[i] >= nums[dq.back()]){
//             dq.pop_back();
//         }

//         while(!dq2.empty() && nums[i] <= nums[dq2.back()]){
//             dq2.pop_back();
//         }

//         // inserting index,so that we can checkout of window element
//         dq.push_back(i);
//         dq2.push_back(i);

//         // current window ka answer store krna h
//         ans += nums[dq.front()] + nums[dq2.front()];

//     }
//     return ans;
// }

// int main(){
//     vector<int>v{2,5,-1,7,-3,-1,-2};
//     int k = 4;
//     cout<<"Ans is : "<<sumOfMinMaxOfAllWindowOfSizeK(v,k)<<endl;

//     return 0;
// }



// // K queues in an array
 
class KQueue{
    public:
    int n,k,freeSpot;
    int *arr,*front,*rear,*next;

    KQueue(int _n,int _k) : n(_n),k(_k),freeSpot(0){
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        for(int i = 0;i<k;i++){
            front[i] = rear[i] = -1;
        }

        for(int i=0;i<n;i++){
            next[i] = i+1;
        }
        next[n-1] = -1;

    }
        // push X into qth Queue
    bool push(int x,int qi){
        // overflow
        if(freeSpot == -1){
            return false;
        }

        // find first free index
        int index = freeSpot;

        // update freespot
        freeSpot = next[index];

        // if first element in qi
        if(front[qi]==-1){
            front[qi] = index;
        }else{
            // link new element to that Q's rearest element
            next[rear[qi]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[qi] = index;
        arr[index] = x;
        return true;
    }

    // pop element from qith Queue
    int pop(int qi){
        // underflow
        if(front[qi] == -1){
            return -1;
        }

        // find index to pop
        int index = front[qi];

        // front update
        front[qi] = next[index];

        // update freespots
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};