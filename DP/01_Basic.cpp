#include "bits/stdc++.h"
using namespace std;

// DP kehti hai past se seekho
// Jo ek bar calculate kr chuke ho,ushe dubara calculate krne ki need nhi hai

// DP k ques ko 3 levels mein solve kro
// 1->Top-down -> Recursion + Memoisation
// 2->Bottom Up -> Tabulation method
// 3->Space Optimisation 

// When to apply DP? -> 2 conditions
//  1-> Overlapping Sub problems -> Same problem ko bar bar solve krre ho

// 2-> Optimal Substructure -> Optimal solution of Bigger problem canbe calculated using optimal solution of smaller problem

// DP Problem solution
// step1 - Create dp array
// vector<int>dp(n+1,-1)

// step2 - jha ans store krre ho usko replace krdo dp[n]

// check if ans already exists then no need to find it again like we don't need to find the f(2) again n again

class Solution {
public:

    int topDownSolve(int n,vector<int>&dp){
        // base case
        if(n == 1 || n == 0){
            return n;
        }
        // step3:check if ans already exist
        if(dp[n] != -1){
            return dp[n];
        }

        // step2:replace ans with dp[n]
        dp[n] = topDownSolve(n-1,dp) + topDownSolve(n-2,dp);
        return dp[n];
    }

    int bottomUpSolve(int n){
        // bottomUp approach is better in term of space complexity as compare to topDown approach
        // step1: create dp array
        vector<int>dp(n+1,-1);
        // step2: Observe base case in above solution
        dp[0] = 0;
        if(n == 0){
            return dp[0];
        }
        dp[1] = 1;
        if(n == 1){
            return dp[1];
        }

        // step3:
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int spaceOptSolve(int n){
        int prev2 = 0;
        int prev1 = 1;
        if(n == 0){
            return prev2;
        }
        if(n == 1){
            return prev1;
        }
        int curr;
        for(int i=2;i<=n;i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }

    int fib(int n) {
        // step1 : create dp array
        // vector<int>dp(n+1,-1);
        // int ans = topDownSolve(n,dp);
        // return ans;

        // return bottomUpSolve(n);

        return spaceOptSolve(n);
    }
};


// 322. Coin Change
// no space optimization strategy exists here
class Solution {
public:
    int solveUsingRecursion(vector<int>&coins,int amount){
        // base case
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solveUsingRecursion(coins,amount-coins[i]);
            if(ans != INT_MAX){
                // jisko hum minus kr rhe hai usko include krne k liye hmne ans+1 kia hai
                mini = min(mini,ans+1);
            }
        }
        return mini;
    }
    int solveMem(vector<int>&coins,int amount,vector<int>&dp){
        // stack space + dp space
        // base case
        if(amount == 0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        // ans already exists
        if(dp[amount] != -1){
            return dp[amount];
        }
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solveMem(coins,amount-coins[i],dp);
            if(ans != INT_MAX){
                mini = min(mini,ans+1);
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }
    int solveTab(vector<int>&coins,int amount){

        // yha dp[i] ka mtlb hai ith amount k liye kitne minimum coins lge hai

        // step1:create dp array
        vector<int>dp(amount+1,INT_MAX);
        // step2:base case dekho
        dp[0] = 0;
        // step3:check the range and flow of top down approach and code accordingly
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){
                    int ans = dp[i-coins[j]];
                    dp[i] = min(dp[i],ans+1);
                }
            }
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans = solveUsingRecursion(coins,amount);
        // if(ans == INT_MAX){
        //     return -1;
        // }
        // else{
        //     return ans;
        // }

        // vector<int>dp(amount+1,-1);
        // int ans = solveMem(coins,amount,dp);
        // if(ans == INT_MAX){
        //     return -1;
        // }
        // else{
        //     return ans;
        // }

        int ans = solveTab(coins,amount);
        if(ans == INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};



// 198. House Robber

class Solution {
public:
// here n represents the index of current house
// hm vector ko piche se traverse kr rhe hai

// isne li exponential time complexity qki ek call include k liye ja rhi hai ek exclude k liye
int solveusingRecursion(vector<int>&nums,int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        // if we have only one house to rob
        return nums[0];
    }

    // include 
    int include = solveusingRecursion(nums,n-2) + nums[n];
    int exclude = solveusingRecursion(nums,n-1) + 0;

    return max(include,exclude);
}

// isme O(N)
// sbko ek bar traverse kia h na
int solveUsingMem(vector<int>&nums,int n,vector<int>&dp){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return nums[0];
    }
    if(dp[n] != -1){
        return dp[n];
    }

    // include 
    int include = solveUsingMem(nums,n-2,dp) + nums[n];
    int exclude = solveUsingMem(nums,n-1,dp) + 0;

    dp[n] = max(include,exclude);
    return dp[n];
}

// isne O(n)  -> time complexity
// O(n) -> space complexity sirf hmne dp array k liye jo li hai
int solveUsingTabulation(vector<int>&nums,int n){
    // dp[i] ka mtlb hai ith index tk aate aate tum kitna max money kma chuke ho
    vector<int>dp(n+1,0);
    dp[0] = nums[0];

    for(int i=1;i<=n;i++){
        int temp = 0;
        if(i-2 >= 0)
            temp = dp[i-2];

        int include = temp + nums[i];
        int exclude = dp[i-1] + 0;
        dp[i] = max(include,exclude);
    }
    // dp[n] isliye return kra hai dp[n] tk aate aate hm kitna max money kma chuke hai
    return dp[n];
}

// isme 3 variables liye hai isliye space complexity O(1)
int spaceOptimisedSolution(vector<int>&nums,int n){
    int prev2 = 0;
    int prev1 = nums[0];
    int curr = 0;
    for(int i=1;i<=n;i++){
        int temp = 0;
        if(i-2 >= 0){
            temp = prev2;
        }
        int include = temp+nums[i];
        int exclude = prev1+0;

        curr = max(include,exclude);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
    int rob(vector<int>& nums) {
        int n = nums.size() - 1;
        // return solveusingRecursion(nums,n);

    // yha pr dp array ka size n+1 isliye lia qki n change ho rha h includ exclude main
        // vector<int>dp(n+1,-1);
        // return solveUsingMem(nums,n,dp);

        // return solveUsingTabulation(nums,n);

        return spaceOptimisedSolution(nums,n);
    }
};