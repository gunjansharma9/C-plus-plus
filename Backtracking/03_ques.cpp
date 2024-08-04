#include "bits/stdc++.h"
using namespace std;


// 39. Combination Sum
class Solution {
public:
    void combinationSum_helper(vector<int>&candidates,int target,vector<int>&v,vector<vector<int>>&ans,int index){
        if(target == 0){
            ans.push_back(v);
            return;
        }

        if(target < 0){
            return;
        }

        for(int i=index;i<candidates.size();i++){
            v.push_back(candidates[i]);
            // agr hm 2 le rhe hai toh lete jaao 2 ko hi or return kro only when target becomes negative
            combinationSum_helper(candidates,target-candidates[i],v,ans,i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        combinationSum_helper(candidates,target,v,ans,0);
        return ans;
    }
};


// 40. Combination Sum II
class Solution {
public:
    void combinationSum_helper(vector<int>&candidates,int target,vector<int>&v,vector<vector<int>>&ans,int index){
        if(target == 0){
            ans.push_back(v);
            return;
        }

        if(target < 0){
            return;
        }

        for(int i=index;i<candidates.size();i++){
            // this line is important
            // this is used to avoid dublicate picking of same element at differenct index
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            v.push_back(candidates[i]);
            combinationSum_helper(candidates,target-candidates[i],v,ans,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        combinationSum_helper(candidates,target,v,ans,0);
        return ans;
    }
};


// 47. Permutations II
class Solution {
public:
    void permuteUniqueHelper(vector<int>&nums,vector<vector<int>>&ans,int start){
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_map<int,bool>visited;
        for(int i=start;i<nums.size();i++){
            if(visited.find(nums[i]) != visited.end()){
                continue;
            }
            visited[nums[i]] = true;
            // this visited map is used to generate unique sets only
            swap(nums[i],nums[start]);
            permuteUniqueHelper(nums,ans,start+1);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        permuteUniqueHelper(nums,ans,0);
        return ans;
    }
};


// 526. Beautiful Arrangement
class Solution {
public:
    void countArrangementHelper(vector<int>&v,int &n,int &ans,int currNum){
        if(currNum == n+1){
            ++ans;
            return;
        }

        for(int i=1;i<=n;i++){
            if(v[i] == 0 && (currNum % i == 0 || i % currNum == 0)){
                v[i] = currNum;
                countArrangementHelper(v,n,ans,currNum+1);
                v[i] = 0; //backtracking agr solution ni nikla toh backtrack kr jaao
            }
        }
    }
    int countArrangement(int n) {
        // n+1 size ki isliye li hai qki hm zero index ko ignore krna chate hai
        vector<int>v(n+1);
        int ans = 0;
        countArrangementHelper(v,n,ans,1);
        return ans;
    }
};


// 1655. Distribute Repeating Integers
class Solution {
public:
    bool canDistributeHelper(vector<int>&counts,vector<int>&quantity,int ithCustomer){
        if(ithCustomer == quantity.size()){
            return true;
        }

        for(int i=0;i<counts.size();i++){
            if(counts[i] >= quantity[ithCustomer]){
                counts[i] -= quantity[ithCustomer];
                if(canDistributeHelper(counts,quantity,ithCustomer+1)){
                    return true;
                }
                counts[i] += quantity[ithCustomer]; //backtracking
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int>countMap;
        for(auto num:nums){
            countMap[num]++;
        }
        vector<int>counts;
        for(auto it:countMap){
            counts.push_back(it.second);
        }
        sort(quantity.rbegin(),quantity.rend());
        // sorting in decreasing order
        return canDistributeHelper(counts,quantity,0);
    }
};

