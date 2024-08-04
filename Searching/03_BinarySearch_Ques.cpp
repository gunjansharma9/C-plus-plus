#include "bits/stdc++.h"
using namespace std;


// // 532. K-diff Pairs in an Array
// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         set<pair<int,int>>ans;
//         int i=0,j=1;
//         while(j < nums.size()){
//             int diff = nums[j] - nums[i];
//             if(diff == k){
//                 ans.insert({nums[i],nums[j]});
//                 i++,j++;
//             }
//             else if(diff > k){
//                 i++;
//             }else{
//                 j++;
//             }
//             if(i==j) j++;
//         }
//         return ans.size();
//     }
// };

// // 2nd approach
// class Solution {
// public:
//     int bs(vector<int>&nums,int start,int x){
//         int end = nums.size()-1;
//         while(start <= end){
//             int mid = (start+end)/2;
//             if(nums[mid] == x){
//                 return mid;
//             }else if(x > nums[mid]){
//                 start = mid+1;
//             }else{
//                 end = mid-1;
//             }
//         }
//         return -1;
//     }
//     int findPairs(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         set<pair<int,int>>ans;
//         for(int i=0;i<nums.size();i++){
    // // right subarray mein search krna hai isliye bs mein i+1 pass kia hai
//             if(bs(nums,i+1,nums[i]+k) != -1){
//                 ans.insert({nums[i],nums[i]+k});
//             }
//         }
//         return ans.size();
//     }
// };


// // 658. Find K Closest Elements
// class Solution {
// public:
//     vector<int>twoPtrMethod(vector<int>&arr,int k,int x){
//         int l=0,h=arr.size()-1;
//         while(h-l >= k){
//             if(x-arr[l] > arr[h]-x){
//                 l++;
//             }else{
//                 h--;
//             }
//         }
//         vector<int>ans;
//         for(int i=l;i<=h;i++){
//             ans.push_back(arr[i]);
//         }
//         return ans;
//     }
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         return twoPtrMethod(arr,k,x);
//     }
// };



// // other approach
// int lowerBound(vector<int>&arr,int x){
//     int start = 0,end=arr.size()-1;
//     int ans = end;
//     while(start <= end){
//         int mid = (start+end)/2;
//         if(arr[mid] >= x){
//             ans = mid;
//             end = mid-1;
//         }else if(x > arr[mid]){
//             start = mid+1;
//         }else{
//             end = mid-1;
//         }
//     }
//     return ans;
// }
// vector<int>bs_Method(vector<int>&arr,int k,int x){
//     int h = lowerBound(arr,x);
//     int l = h-1;
//     while(k--){
//         if(l<0){
//             h++;
//         }
//         else if(h >= arr.size()){
//             l--;
//         }
//         else if(x-arr[l] > arr[h]-x){
//             h++;
//         }
//         else{
//             l--;
//         }
//     }
//     return vector<int>(arr.begin()+l+1,arr.begin()+h);
// }


// // Exponential Search
// int bs(int a[],int s,int e,int x){
//     while(s <= e){
//         int mid = s+(e-s)/2;
//         if(a[mid] == x){
//             return mid;
//         }
//         else if(a[mid] < x){
//             s = mid+1;
//         }else{
//             e = mid-1;
//         }
//     }
//     return -1;
// }
// int expSearch(int a[],int n,int x){
//     if(a[0] == x) return 0;

//     int i=1;
//     while(i<n && a[i] <= x){
//         i = i*2;
//     }
//     return bs(a,i/2,min(i,n-1),x);
// }

// int main(){
//     int a[] = {3,4,5,6,11,13,14,15,56,70};
//     int n = sizeof(a)/sizeof(int);
//     int x = 13;
//     int ans = expSearch(a,n,x);
//     cout<<"Ans index is : "<<ans;
//     return 0;
// }
// // Applications of Binary Search
// //  1 -> Search in infinite array(unbounded array)
// //  2 -> Better than Binary Search(when x is near beginning )


// // Allocate minimum number of pages - gfg
// class Solution 
// {
//     public:
//     bool isPossibleSolution(int A[],int N,int M,int sol){
//         int pageSum = 0;
//         int c = 1;
//         for(int i=0;i<N;i++){
//             if(A[i] > sol){
//                 return false;
//             }
//             if(pageSum + A[i] > sol){
//                 c++;
//                 pageSum = A[i];
//                 // above condition is used to reset the pageSum
//                 if(c > M){
//                     return false;
//                 }
//             }
//             else{
//                 pageSum += A[i];
//             }
//         }
//         return true;
//     }
//     int findPages(int A[], int N, int M) 
//     {
//         if(M > N) return -1;
//         int start = 0;
//         int end = accumulate(A, A + N, 0);
//         // accumulate is used to find the sum of all the elements of array
//         int ans = -1;
//         while(start <= end){
//             int mid = (start + end)>>1;
//             if(isPossibleSolution(A,N,M,mid)){
//                 ans = mid;
//                 end = mid-1;
//             }else{
//                 start = mid+1;
//             }
//         }
//         return ans;
//     }
// };



// // Painters partition problem - gfg
// class Solution
// {
//   public:
//   typedef long long ll;
//     bool isPossibleSolution(int a[],int n,int k,ll mid){
//         ll timeSum = 0;
//         int c = 1;
//         for(int i=0;i<n;i++){
//             if(a[i] > mid){
//                 return false;
//             }
//             if(a[i] + timeSum > mid){
//                 c++;
//                 timeSum = a[i];
//                 if(c>k) return false;
//             }
//             else{
//                 timeSum += a[i];
//             }
//         }
//         return true;
//     }
//     long long minTime(int arr[], int n, int k)
//     {
//         ll start = 0;
//         ll end = 0;
//         for(int i=0;i<n;i++){
//             end += arr[i];
//         }
//         long long ans = -1;
//         while(start <= end){
//             ll mid = start + (end-start)/2;
//             if(isPossibleSolution(arr,n,k,mid)){
//                 ans = mid;
//                 end = mid-1;
//             }else{
//                 start = mid+1;
//             }
//         }
//         return ans;
//     }
// };


// // Aggressive Cows - gfg
// class Solution {
// public:
//     bool isPossibleSolution(vector<int>&stalls,int k,int mid){
//         // can we place k cows , with atleast mid distance between cows
//         int c = 1;
//         int pos = stalls[0];
        
//         for(int i=1;i<stalls.size();i++){
//             if(stalls[i]-pos >= mid){
//                 c++;
//                 pos = stalls[i];
//             }
//             if(c == k) return true;
//         }
//         return false;
//     }
//     int solve(int n, int k, vector<int> &stalls) {
//         sort(stalls.begin(),stalls.end());
//         int start = 0;
//         int end = stalls[stalls.size()-1] - stalls[0];
//         int ans = -1;
//         while(start <= end){
//             int mid = start + (end - start)/2;
//             if(isPossibleSolution(stalls,k,mid)){
//                 ans = mid;
//                 start = mid+1;
//             }
//             else{
//                 end = mid-1;
//             }
//         }
//         return ans;
        
//     }
// };

// // Eko spoj -> sphere online judge
// bool isPossibleSolution(vector<long long int>trees,long long int m,long long int mid){
//     long long int woodCollected = 0;
//     for(long long int i=0;i<trees.size();i++){
//         if(trees[i] > mid){
//             woodCollected += trees[i]-mid;
//         }
//     }
//     return woodCollected >= m;
// }

// long long int maxSawBladeHeight(vector<long long int>trees,long long int m){
//     long long int start=0 ,end,ans = -1;
//     end = *max_element(trees.begin(),trees.end());

//     while(start <= end){
//         long long int mid = start + (end - start)/2;
//         if(isPossibleSolution(trees,m,mid)){
//             ans = mid;
//             start = mid+1;
//         }else{
//             end = mid-1;
//         }
//     }
//     return ans;
// }

// int main(){
//     long long int n=4,m=7;
//     vector<long long int>trees{20,15,10,17};
//     cout<<"Maximum height required to cut atleast "<<m<<" metres is : "<<maxSawBladeHeight(trees,m)<<endl;

//     return 0;
// }

// Prata spoj
bool isPossibleSolution(vector<int>cooksRanks,int nP,int mid){
    int currP = 0;
    for(int i=0;i<cooksRanks.size();i++){
        int R = cooksRanks[i],j=1;
        int timeTaken = 0;

        while(true){
            if(timeTaken + j*R <= mid ){
                ++currP;
                timeTaken += j*R;
                ++j;
            }
            else{
                break;
            }
        }
        if(currP >= nP){
            return true;
        }
    }
    return false;
}
int minTimeToCompleteOrder(vector<int>cooksRanks,int nP){
    int start = 0;
    int highestRank = *max_element(cooksRanks.begin(),cooksRanks.end());
    int end = highestRank*(nP * (nP+1)/2);
    int ans = -1;

    while(start <= end){
        int mid = start + (end-start)/2;
        if(isPossibleSolution(cooksRanks,nP,mid)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return ans;
}
int main(){
    int T=3;
    // no of test case
    while(T--){
        int nP,nC;
        // no of prata and no of cook
        cin>>nP>>nC;
        vector<int>cooksRanks;
        while(nC--){
            int R;cin>>R;
            cooksRanks.push_back(R);
        }
        cout<<minTimeToCompleteOrder(cooksRanks,nP)<<endl;
    }
    return 0;
}

// 10
// 4 1 2 3 4
// 8 
// 1 1 
// 8
// 8 1 1 1 1 1 1 1 1 