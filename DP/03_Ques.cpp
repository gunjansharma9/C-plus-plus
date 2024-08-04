#include "bits/stdc++.h"
using namespace std;

// Partition equal subset sum -> leetcode

class Solution {
public:
    bool solveUsingRecursion(int index,vector<int>&nums,int target){
        // base case
        int n = nums.size();
        if(index >= n){
            return 0;
        }
        if(target < 0){
            return 0;
        }
        if(target == 0)
            return 1;

        bool include = solveUsingRecursion(index+1,nums,target-nums[index]);
        bool exclude = solveUsingRecursion(index+1,nums,target);

        return (include || exclude);
    }

    bool solveUsingMemoisation(int index,vector<int>&nums,int target,vector<vector<int>>&dp){
        // base case
        int n = nums.size();
        if(index >= n){
            return 0;
        }
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        bool include = solveUsingMemoisation(index+1,nums,target-nums[index],dp);
        bool exclude = solveUsingMemoisation(index+1,nums,target,dp);

        dp[index][target] = (include || exclude);
        return dp[index][target];
    }

    bool solveUsingTabulation(vector<int>&nums,int target){
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,0));
        // iska size size+1 isliye kia hai qki niche include vale case m hm index+1 krre hai
        // dp k 0th column mein 1 store krlo
        // target ki value ko 0 kr dena ,target column mein h isliye kia
        for(int i=0;i<nums.size();i++){
            dp[i][0] = 1;
        }

        for(int index = nums.size()-1;index>=0;index--){
            // t=1 isliye lia hai qki upar target = 0 k liye chala chuke hai
            for(int t=1;t<=target;t++){
                bool include = 0;
                if(t-nums[index] >= 0){
                    include = dp[index+1][t-nums[index]];
                }
                bool exclude = dp[index+1][t];

                dp[index][t] = (include || exclude);
            }
        }
        return dp[0][target];
        // n mein hm 0 ki side ja rhe hai or target mein target ki side isliye ye return kia hai
    }

    bool solveUsingSO(vector<int>&nums,int target){
        int n = nums.size();
        vector<int>curr(target+1,0);
        vector<int>next(target+1,0);

        curr[0] = 1;
        next[0] = 1;

        for(int index = n-1;index>=0;index--){
            for(int t=1;t<=target;t++){
                bool include = 0;
                if(t-nums[index] >= 0){
                    include = next[t-nums[index]];
                }
                bool exclude = next[t];
                curr[t] = (include || exclude);
            }
            // hm n-1 se 0 ki side ja rhe h isliye
            next=curr;
        }
        return next[target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        // agr target sum odd hai toh usko hm find hi ni kr payenge subset sum k liye
        // yha glti hogi
        if(sum&1){
            return false;
        }
        int target = sum/2;
        int index = 0;
        // bool ans = solveUsingRecursion(index,nums,target);

        // vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        // bool ans = solveUsingMemoisation(index,nums,target,dp);

        // bool ans = solveUsingTabulation(nums,target);

        bool ans = solveUsingSO(nums,target);
        return ans;
    }
};





// 1155. Number of Dice Rolls With Target Sum
class Solution {
public:
    long long int MOD = 1000000007;

    int solveUsingRecursion(int n, int k , int target) {
        //base case
        if(n < 0)
            return 0;
        if(n == 0 && target == 0)
            return 1;
        if(n == 0 && target != 0) 
            return 0;
        if(n !=0 && target == 0)
            return 0;

        int ans = 0;
        for(int i=1; i<=k; i++) {
            ans += solveUsingRecursion(n-1, k , target-i);
        }
        return ans;
    }

    long long int solveUsingMem(  int n,  int k ,   int target,  vector<vector< long long int> >& dp) {
        //base case
        if(n < 0)
            return 0;
        if(n == 0 && target == 0)
            return 1;
        if(n == 0 && target != 0) 
            return 0;
        if(n !=0 && target == 0)
            return 0;
        
        if(dp[n][target] != -1)
            return dp[n][target];

        long long int ans = 0;
        for(int i=1; i<=k; i++) {
            long long int recAns = 0;
            if(target - i >= 0 )
                recAns = solveUsingMem(n-1, k , target-i, dp);
            ans = (ans % MOD + recAns % MOD) % MOD;
        }
        dp[n][target] =  ans;
        return dp[n][target];
    }

    int solveUsingTabulation(int n, int k, int target) {
        vector<vector< long long int> > dp(n+1, vector< long long int>(target+1, 0));
        dp[0][0] = 1;

        for(int index = 1; index <=n; index++) {
            for(int t=1; t<=target; t++) {

                long long int ans = 0;
                for(int i=1; i<=k; i++) {
                    long long int recAns = 0;
                    if(t - i >= 0 )
                        recAns = dp[index-1][t-i];
                    ans = (ans % MOD + recAns % MOD) % MOD;
                }
                dp[index][t] =  ans;
            }
        }

    return dp[n][target];

    }

    int solveUsingTabulationSO(int n, int k, int target) {

        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);

        prev[0] = 1;

        for(int index = 1; index <=n; index++) {
            for(int t=1; t<=target; t++) {

                long long int ans = 0;
                for(int i=1; i<=k; i++) {
                    long long int recAns = 0;
                    if(t - i >= 0 )
                        recAns = prev[t-i];
                    ans = (ans % MOD + recAns % MOD) % MOD;
                }
                curr[t] =  ans;
            }
            //shift
            prev = curr;
        }

    return prev[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        // vector<vector< long long int> > dp(n+1, vector< long long int>(target+1, -1));
        // return solveUsingMem(n,k,target, dp);
        return solveUsingTabulationSO(n, k, target);
    }
};