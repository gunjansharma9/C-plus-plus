#include "bits/stdc++.h"
using namespace std;


// 279. Perfect Squares

class Solution {
public:
    int numSquareHelper(int n){
        // base case
        if(n==0) return 1;
        if(n<0) return 0;

        int ans = INT_MAX;
        int i=1;
        // sqrt of n tk isliye chala rhe hai qki agr hm consider kre 12 ko toh sqrt of 12 is approx 3 and 3 square is less than 12 but if we consider 4 square which is greater than sqrt of number toh uska square 16 is greater than 12
        int end = sqrt(n);
        while(i<=end){
            int perfectSquare = i*i;
            int numberOfPerfectSquares = 1 + numSquareHelper(n-perfectSquare);
            if(numberOfPerfectSquares < ans){
                ans = numberOfPerfectSquares;
            }
            ++i;
        }
        return ans;
    }

    int TopDownApproach(int n,vector<int>&dp){
        // base case
        if(n==0) return 1;
        if(n<1) return 0;

        if(dp[n] != -1){
            return dp[n];
        }
        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        while(i<=end){
            int perfectSquare = i*i;
            int numberOfPerfectSquares = 1 + TopDownApproach(n - perfectSquare,dp);
            if(numberOfPerfectSquares < ans){
                ans = numberOfPerfectSquares;
            }
            ++i;
        }
        dp[n] = ans;
        return dp[n];
    }

    int BottomUpApproach(int n){
        vector<int>dp(n+1,0);
        dp[0] = 1;

        for(int i=1;i<=n;i++){
            int ans = INT_MAX;
            int start = 1;
            int end = sqrt(i);
            while(start <= end){
                int perfectSquare = start*start;
                int numberOfPerfectSquares = 1 + dp[i-perfectSquare];
                if(numberOfPerfectSquares < ans){
                    ans = numberOfPerfectSquares;
                }
                ++start;
            }
            dp[i] = ans;
        }
        return dp[n];
    }
    int numSquares(int n) {
        // return numSquareHelper(n) - 1;
        vector<int>dp(n+1,-1);
        // return TopDownApproach(n,dp) - 1;
        return BottomUpApproach(n) - 1;
    }
};


// 983. Minimum Cost For Tickets
class Solution {
public:
    int mincostTickets_helper(vector<int>&days,vector<int>&costs,int i){
        // base case
        // i se hm days vale vector pr iterate kr rhe hai
        if(i >= days.size()) return 0;

        // sol for a case
        // 1 Day Pass Taken
        int cost1 = costs[0] + mincostTickets_helper(days,costs,i+1);

        // 7 days pass taken
        // 7 days tk valid hai ush day ko milakr
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost7 = costs[1] + mincostTickets_helper(days,costs,j);

        // 30 day pass taken
        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost30 = costs[2] + mincostTickets_helper(days,costs,j);
        return min(cost1,min(cost7,cost30));
    }

    int TopDownApproach(vector<int>&days,vector<int>&costs,int i,vector<int>&dp){
        if(i >= days.size()) return 0;

        if(dp[i] != -1) return dp[i];

        // 1 day pass taken
        // cost vale array mein 0 index pr 1 day k pass ki cost pdi hai isliye add kia
        int cost1 = costs[0] + TopDownApproach(days,costs,i+1,dp);

        // 7 days pass taken
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost7 = costs[1] + TopDownApproach(days,costs,j,dp);

        // 30 days pass taken
        passEndDay = days[i] + 30 -1;
        j = i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost30 = costs[2] + TopDownApproach(days,costs,j,dp);

        dp[i] = min(cost1,min(cost7,cost30));
        return dp[i];
    }

    int BottomUpApproach(vector<int>&days,vector<int>costs,int i){
        vector<int>dp(days.size()+1,0);
        dp[days.size()] = 0;

        for(int i = days.size()-1;i>=0;i--){
            int cost1 = costs[0] + dp[i+1];

            // 7 days pass taken
            int passEndDay = days[i] + 7 - 1;
            int j = i;
            while(j < days.size() && days[j] <= passEndDay){
                j++;
            }
            int cost7 = costs[1] + dp[j];

            // 30 days pass taken
            passEndDay = days[i] + 30 -1;
            j = i;
            while(j < days.size() && days[j] <= passEndDay){
                j++;
            }
            int cost30 = costs[2] + dp[j];

            dp[i] = min(cost1,min(cost7,cost30));
        }
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return mincostTickets_helper(days,costs,0);

        // vector<int>dp(days.size(),-1);
        // return TopDownApproach(days,costs,0,dp);

        return BottomUpApproach(days,costs,0);
    }
};


// 122. Best Time to Buy and Sell Stock II
class Solution {
public:
    int solve(vector<int>&prices,int i,int buy){
        if(i >= prices.size()) return 0;

        int profit = 0;
        if(buy){
            int buyItProfit = -prices[i] + solve(prices,i+1,0);
            int skipProfit = solve(prices,i+1,1);
            profit = max(buyItProfit,skipProfit);
        }
        else{
            int sellItProfit = prices[i] + solve(prices,i+1,1);
            int skipProfit = solve(prices,i+1,0);
            profit = max(sellItProfit,skipProfit);
        }
        return profit;
    }

    int solveTD(vector<int>&prices,int i,int buy,vector<vector<int>>&dp){
        if(i >= prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if(buy){
            int buyItProfit = -prices[i] + solveTD(prices,i+1,0,dp);
            int skipProfit = solveTD(prices,i+1,1,dp);
            profit = max(buyItProfit,skipProfit);
        }
        else{
            int sellItProfit = prices[i] + solveTD(prices,i+1,1,dp);
            int skipProfit = solveTD(prices,i+1,0,dp);
            profit = max(sellItProfit,skipProfit);
        }
        dp[i][buy] = profit;
        return dp[i][buy];
    }

    int solveBU(vector<int>&prices){
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        for(int i=prices.size()-1;i>=0;--i){
            for(int buy = 0;buy<2;++buy){
                int profit = 0;
                if(buy){
                    int buyItProfit = -prices[i]+dp[i+1][0];
                    int skipProfit = dp[i+1][1];
                    profit = max(buyItProfit,skipProfit);
                }
                else{
                    int sellItProfit = prices[i]+dp[i+1][1];
                    int skipProfit = dp[i+1][0];
                    profit = max(sellItProfit,skipProfit);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        // return solve(prices,0,true);
        // column ki value 2 hai buy = 0 & buy = 1

        // vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        // return solveTD(prices,0,true,dp);

        return solveBU(prices);
    }
};


// 123. Best Time to Buy and Sell Stock III
class Solution {
public:
    int solveRE(vector<int>&prices,int i,int buy,int limit){
        if(i >= prices.size() || limit == 0) return 0;

        int profit = 0;
        if(buy){
            int buyItProfit = -prices[i] + solveRE(prices,i+1,0,limit);
            int skipProfit = solveRE(prices,i+1,1,limit);
            profit = max(buyItProfit,skipProfit);
        }
        else{
            int sellItProfit = prices[i] + solveRE(prices,i+1,1,limit-1);
            int skipProfit = solveRE(prices,i+1,0,limit);
            profit = max(sellItProfit,skipProfit);
        }
        return profit;
    }
    int solveTD(vector<int>&prices,int i,int buy,int limit,vector<vector<vector<int>>>&dp){
        if(i >= prices.size() || limit == 0) return 0;

        if(dp[i][buy][limit] != -1) return dp[i][buy][limit];

        int profit = 0;
        if(buy){
            int buyItProfit = -prices[i] + solveTD(prices,i+1,0,limit,dp);
            int skipProfit = solveTD(prices,i+1,1,limit,dp);
            profit = max(buyItProfit,skipProfit);
        }
        else{
            int sellItProfit = prices[i] + solveTD(prices,i+1,1,limit-1,dp);
            int skipProfit = solveTD(prices,i+1,0,limit,dp);
            profit = max(sellItProfit,skipProfit);
        }
        dp[i][buy][limit] = profit;
        return profit;
    }

    int solveBU(vector<int>&prices){
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=prices.size()-1;i>=0;--i){
            for(int buy=0;buy<2;++buy){
                for(int limit = 1;limit<3;++limit){
                    int profit = 0;
                    if(buy){
                        int buyItProfit = -prices[i] + dp[i+1][0][limit];
                        int skipProfit = dp[i+1][1][limit];
                        profit = max(buyItProfit,skipProfit);
                    }
                    else{
                        int sellItProfit = prices[i]+dp[i+1][1][limit-1];
                        int skipProfit = dp[i+1][0][limit];
                        profit = max(sellItProfit,skipProfit);
                    }
                    dp[i][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }

    int solveSO(vector<int>&prices,int i,int buy,int limit,vector<vector<vector<int>>>&dp){
        for(int i=prices.size()-1;i>=0;--i){
            for(int buy=0;buy<2;buy++){
                for(int limit=1;limit<3;++limit){
                    int profit = 0;
                    if(buy){
                        int buyItProfit = -prices[i]+dp[1][0][limit];
                        int skipProfit = dp[1][1][limit];
                        profit = max(buyItProfit,skipProfit);
                    }
                    else{
                        int sellItProfit = prices[i]+dp[1][1][limit-1];
                        int skipProfit = dp[1][0][limit];
                        profit = max(sellItProfit,skipProfit);
                    }
                    dp[0][buy][limit] = profit;
                }
            }
            dp[1]=dp[0];
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        // return solveRE(prices,0,1,2);
        // vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        // return solveTD(prices,0,1,2,dp);
        // return solveBU(prices);
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(2,vector<int>(3,0)));
        return solveSO(prices,0,1,2,dp);
    }
};



// 188. Best Time to Buy and Sell Stock IV
class Solution {
public:
    int solveRE(vector<int>&prices,int i,int buy,int limit){
        if(i >= prices.size() || limit == 0) return 0;

        int profit = 0;
        if(buy){
            int buyItProfit = -prices[i]+solveRE(prices,i+1,0,limit);
            int skipProfit = solveRE(prices,i+1,1,limit);
            profit = max(buyItProfit,skipProfit);
        }
        else{
            int sellItProfit = prices[i]+solveRE(prices,i+1,1,limit-1);
            int skipProfit = solveRE(prices,i+1,0,limit);
            profit = max(sellItProfit,skipProfit);
        }
        return profit;
    }
    int solveTD(vector<int>&prices,int i,int buy,int limit,vector<vector<vector<int>>>&dp){
        if(i >= prices.size() || limit == 0) return 0;

        if(dp[i][buy][limit] != -1) return dp[i][buy][limit];

        int profit = 0;
        if(buy){
            int buyItProfit = -prices[i] + solveTD(prices,i+1,0,limit,dp);
            int skipProfit = solveTD(prices,i+1,1,limit,dp);
            profit = max(buyItProfit,skipProfit);
        }
        else{
            int sellItProfit = prices[i] + solveTD(prices,i+1,1,limit-1,dp);
            int skipProfit = solveTD(prices,i+1,0,limit,dp);
            profit = max(sellItProfit,skipProfit);
        }
        dp[i][buy][limit] = profit;
        return profit;
    }

    int solveBU(vector<int>&prices,int k){
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=prices.size()-1;i>=0;--i){
            for(int buy=0;buy<2;++buy){
                for(int limit = 1;limit<k+1;++limit){
                    int profit = 0;
                    if(buy){
                        int buyItProfit = -prices[i] + dp[i+1][0][limit];
                        int skipProfit = dp[i+1][1][limit];
                        profit = max(buyItProfit,skipProfit);
                    }
                    else{
                        int sellItProfit = prices[i]+dp[i+1][1][limit-1];
                        int skipProfit = dp[i+1][0][limit];
                        profit = max(sellItProfit,skipProfit);
                    }
                    dp[i][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
    int solveSO(vector<int>&prices,int i,int buy,int k,vector<vector<vector<int>>>&dp){
        for(int i=prices.size()-1;i>=0;--i){
            for(int buy=0;buy<2;buy++){
                for(int limit=1;limit<k+1;++limit){
                    int profit = 0;
                    if(buy){
                        int buyItProfit = -prices[i]+dp[1][0][limit];
                        int skipProfit = dp[1][1][limit];
                        profit = max(buyItProfit,skipProfit);
                    }
                    else{
                        int sellItProfit = prices[i]+dp[1][1][limit-1];
                        int skipProfit = dp[1][0][limit];
                        profit = max(sellItProfit,skipProfit);
                    }
                    dp[0][buy][limit] = profit;
                }
            }
            dp[1]=dp[0];
        }
        return dp[0][1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        // return solveRE(prices,0,1,k);
        // vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return solveTD(prices,0,1,k,dp);
        // return solveBU(prices,k);
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(2,vector<int>(k+1,0)));
        return solveSO(prices,0,1,k,dp);
    }
};



// 714. Best Time to Buy and Sell Stock with Transaction Fee
class Solution {
public:
    int solve(vector<int>&prices,int i,int buy,int &fee){
        if(i >= prices.size()) return 0;

        int profit = 0;
        if(buy){
            int buyItProfit = -prices[i] + solve(prices,i+1,0,fee);
            int skipProfit = solve(prices,i+1,1,fee);
            profit = max(buyItProfit,skipProfit);
        }
        else{
            int sellItProfit = prices[i] + solve(prices,i+1,1,fee)-fee;
            int skipProfit = solve(prices,i+1,0,fee);
            profit = max(sellItProfit,skipProfit);
        }
        return profit;
    }

    int solveTD(vector<int>&prices,int i,int buy,vector<vector<int>>&dp,int &fee){
        if(i >= prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if(buy){
            int buyItProfit = -prices[i] + solveTD(prices,i+1,0,dp,fee);
            int skipProfit = solveTD(prices,i+1,1,dp,fee);
            profit = max(buyItProfit,skipProfit);
        }
        else{
            int sellItProfit = prices[i] + solveTD(prices,i+1,1,dp,fee) - fee;
            int skipProfit = solveTD(prices,i+1,0,dp,fee);
            profit = max(sellItProfit,skipProfit);
        }
        dp[i][buy] = profit;
        return dp[i][buy];
    }

    int solveBU(vector<int>&prices,int fee){
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        for(int i=prices.size()-1;i>=0;--i){
            for(int buy = 0;buy<2;++buy){
                int profit = 0;
                if(buy){
                    int buyItProfit = -prices[i]+dp[i+1][0];
                    int skipProfit = dp[i+1][1];
                    profit = max(buyItProfit,skipProfit);
                }
                else{
                    int sellItProfit = prices[i]+dp[i+1][1] - fee;
                    int skipProfit = dp[i+1][0];
                    profit = max(sellItProfit,skipProfit);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }

    int solveSO(vector<int>&prices,vector<vector<int>>&dp,int &fee){
        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<2;++buy){
                int profit = 0;
                if(buy){
                    int buyItProfit = -prices[i]+dp[1][0];
                    int skipProfit = dp[1][1];
                    profit = max(buyItProfit,skipProfit);
                }
                else{
                    int sellItProfit = prices[i]+dp[1][1] - fee;
                    int skipProfit = dp[1][0];
                    profit = max(sellItProfit,skipProfit);
                }
                dp[0][buy] = profit;
            }
            dp[1] = dp[0];
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices,int fee) {
        // return solve(prices,0,true,fee);
        //// column ki value 2 hai buy = 0 & buy = 1

        // vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        // return solveTD(prices,0,true,dp,fee);

        // return solveBU(prices,fee);
        vector<vector<int>>dp(2,vector<int>(2,0));
        return solveSO(prices,dp,fee);
    }

};


// 309. Best Time to Buy and Sell Stock with Cooldown
class Solution {
public:
    int solve(vector<int>&prices,int i,int buy){
        if(i >= prices.size()) return 0;

        int profit = 0;
        if(buy){
            int buyItProfit = -prices[i] + solve(prices,i+1,0);
            int skipProfit = solve(prices,i+1,1);
            profit = max(buyItProfit,skipProfit);
        }
        else{
            int sellItProfit = prices[i] + solve(prices,i+2,1);
            int skipProfit = solve(prices,i+1,0);
            profit = max(sellItProfit,skipProfit);
        }
        return profit;
    }

    int solveTD(vector<int>&prices,int i,int buy,vector<vector<int>>&dp){
        if(i >= prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if(buy){
            int buyItProfit = -prices[i] + solveTD(prices,i+1,0,dp);
            int skipProfit = solveTD(prices,i+1,1,dp);
            profit = max(buyItProfit,skipProfit);
        }
        else{
            int sellItProfit = prices[i] + solveTD(prices,i+2,1,dp);
            int skipProfit = solveTD(prices,i+1,0,dp);
            profit = max(sellItProfit,skipProfit);
        }
        dp[i][buy] = profit;
        return dp[i][buy];
    }

    int solveBU(vector<int>&prices){
        vector<vector<int>>dp(prices.size()+2,vector<int>(2,0));
        for(int i=prices.size()-1;i>=0;--i){
            for(int buy = 0;buy<2;++buy){
                int profit = 0;
                if(buy){
                    int buyItProfit = -prices[i]+dp[i+1][0];
                    int skipProfit = dp[i+1][1];
                    profit = max(buyItProfit,skipProfit);
                }
                else{
                    int sellItProfit = prices[i]+dp[i+2][1];
                    int skipProfit = dp[i+1][0];
                    profit = max(sellItProfit,skipProfit);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        // return solve(prices,0,1);
        // vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        // return solveTD(prices,0,true,dp);

        return solveBU(prices);
    }
};



// 337. House Robber III
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int solve(TreeNode* root){
        if(!root) return 0;

        int robThisHouse = 0,dontRobThisHouse = 0;

        // rob current house
        robThisHouse += root->val;
        if(root->left){
            robThisHouse += solve(root->left->left)+solve(root->left->right);
        }
        if(root->right){
            robThisHouse += solve(root->right->left)+solve(root->right->right);
        }
        // dont rob current house
        dontRobThisHouse = solve(root->left)+solve(root->right);
        return max(robThisHouse,dontRobThisHouse);
    }

    int solveTD(TreeNode*root,unordered_map<TreeNode*,int>&dp){
        if(!root) return 0;

        if(dp.find(root) != dp.end()) return dp[root];

        int robThisHouse = 0,dontRobThisHouse = 0;
        robThisHouse += root->val;
        if(root->left){
            robThisHouse += solveTD(root->left->left,dp)+solveTD(root->left->right,dp);
        }
        if(root->right){
            robThisHouse += solveTD(root->right->left,dp)+solveTD(root->right->right,dp);
        }

        dontRobThisHouse = solveTD(root->left,dp)+solveTD(root->right,dp);
        dp[root] = max(robThisHouse,dontRobThisHouse);
        return dp[root];
    }
    int rob(TreeNode* root) {
        // return solve(root);

        unordered_map<TreeNode*,int>dp;
        return solveTD(root,dp);
    }

};


// 486. Predict the Winner
class Solution {
public:
    int solve(vector<int>&nums,int start,int end){
        if(start == end) return nums[start];
        int diffByStart = nums[start] - solve(nums,start+1,end);
        int diffByEnd = nums[end] - solve(nums,start,end-1);

        return max(diffByStart,diffByEnd);
    }
    int solveTD(vector<int>&nums,int start,int end,vector<vector<int>>&dp){
        if(start == end) return nums[start];

        if(dp[start][end] != -1) return dp[start][end];
        
        int diffByStart = nums[start] - solveTD(nums,start+1,end,dp);
        int diffByEnd = nums[end] - solveTD(nums,start,end-1,dp);
        dp[start][end] = max(diffByStart,diffByEnd);
        return dp[start][end];
    }
    int solveBU(vector<int>&nums,vector<vector<int>>&dp){
        for(int i=0;i<nums.size();++i) dp[i][i] = nums[i];
        int i = nums.size();
        for(int start = nums.size()-1;start >= 0;--start){
            for(int end = i;end<nums.size();++end){
                int diffByStart = nums[start] - dp[start+1][end];
                int diffByEnd = nums[end] - dp[start][end-1];
                dp[start][end] = max(diffByStart,diffByEnd);
            }
            --i;
        }
        return dp[0][nums.size()-1];
    }
    bool predictTheWinner(vector<int>& nums) {
        // return solve(nums,0,nums.size()-1) >= 0;

        // vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        // return solveTD(nums,0,nums.size()-1,dp) >= 0;

        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return solveBU(nums,dp) >= 0;
    }
};


// 139. Word Break
class Solution {
public:
    bool check(vector<string>&wordDict,string&s){
        for(auto i:wordDict){
            if(s == i) return true;
        }
        return false;
    }
    bool solve(string&s,vector<string>&wordDict,int start){
        if(start == s.size()) return true;

        // one case
        string word = "";
        bool flag = false;
        for(int i = start;i<s.size();++i){
            word += s[i];
            if(check(wordDict,word)){
                flag = flag || solve(s,wordDict,i+1);
            }
        }
        return flag;
    }
    bool solveTD(string&s,vector<string>&wordDict,int start,vector<int>&dp){
        if(start == s.size()) return true;

        if(dp[start] != -1) return dp[start];

        string word = "";
        bool flag = false;
        for(int i=start;i<s.size();++i){
            word += s[i];
            if(check(wordDict,word)){
                flag = flag || solveTD(s,wordDict,i+1,dp);
            }
        }
        dp[start] = flag;
        return dp[start];
    }

    bool solveBU(string&s,vector<string>&wordDict,vector<int>&dp){
        for(int start = s.size() - 1;start >= 0;--start){
            string word = "";
            bool flag = false;
            for(int i= start;i<s.size();++i){
                word += s[i];
                if(check(wordDict,word)){
                    flag = flag || dp[i+1];
                }
            }
            dp[start] = flag;
        }
        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // return solve(s,wordDict,0);

        // vector<int>dp(s.size(),-1);
        // return solveTD(s,wordDict,0,dp);

        vector<int>dp(s.size()+1,true);
        return solveBU(s,wordDict,dp);
    }
};



// 474. Ones and Zeroes

class Solution {
public:
    void convertStrsToNumStrs(vector<string>&strs,vector<pair<int,int>>&numStrs){
        for(auto str:strs){
            int zeros = 0,ones = 0;
            for(auto ch:str){
                if(ch == '0') ++zeros;
                else ++ones;
            }
            numStrs.push_back({zeros,ones});
        }
    }

    int solve(vector<pair<int,int>>&numStrs,int i,int m,int n){
        if(i == numStrs.size()) return 0;

        int zeros = numStrs[i].first;
        int ones = numStrs[i].second;

        int include = 0,exclude = 0;
        if(m-zeros >= 0 && n-ones >= 0){
            include = 1 + solve(numStrs,i+1,m-zeros,n-ones);
        }
        exclude = solve(numStrs,i+1,m,n);
        return max(include,exclude);
    }

    int solveTD(vector<pair<int,int>>&numStrs,int i,int m,int n,vector<vector<vector<int>>>&dp){
        if(i==numStrs.size()) return 0;

        if(dp[i][m][n] != -1) return dp[i][m][n];

        int zeros = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0,exclude = 0;
        if(m-zeros >= 0 && n-ones >= 0){
            include = 1 + solveTD(numStrs,i+1,m-zeros,n-ones,dp);
        }
        exclude = solveTD(numStrs,i+1,m,n,dp);
        return dp[i][m][n] = max(include,exclude);
    }

    int solveBU(vector<pair<int,int>>&numStrs,int m,int n){
        vector<vector<vector<int>>>dp(numStrs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(int i=numStrs.size()-1;i>=0;--i){
            for(int j=0;j<=m;++j){
                for(int k=0;k<=n;++k){
                    int zeros = numStrs[i].first;
                    int ones = numStrs[i].second;
                    int include= 0,exclude = 0;
                    if(j-zeros >= 0 && k-ones >= 0){
                        include = 1+dp[i+1][j-zeros][k-ones];
                    }
                    exclude = dp[i+1][j][k];
                    dp[i][j][k] = max(include,exclude);
                }
            }
        }
        return dp[0][m][n];
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>numStrs;
        convertStrsToNumStrs(strs,numStrs);

        // return solve(numStrs,0,m,n);

        // vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        // return solveTD(numStrs,0,m,n,dp);
        return solveBU(numStrs,m,n);
    }
};


// 801. Minimum Swaps To Make Sequences Increasing
class Solution {
public:
    int solve(vector<int>&nums1,vector<int>&nums2,int i,int p1,int p2){
        if(i == nums1.size()){
            return 0;
        }
        int swap = INT_MAX,noswap = INT_MAX;

        // swap condition
        if(p1 < nums2[i] && p2 < nums1[i]){
            swap = 1 + solve(nums1,nums2,i+1,nums2[i],nums1[i]);
        }
        // noswap
        if(p1 < nums1[i] && p2 < nums2[i]){
            noswap = solve(nums1,nums2,i+1,nums1[i],nums2[i]);
        }
        return min(swap,noswap);
    }
    int solveTD(vector<int>&nums1,vector<int>&nums2,int i,int p1,int p2,vector<vector<int>>&dp,int isswap){
        if(i == nums1.size()){
            return 0;
        }
        if(dp[i][isswap] != -1) return dp[i][isswap];
        int swap = INT_MAX,noswap = INT_MAX;

        if(p1<nums2[i] && p2<nums1[i]){
            swap = 1 + solveTD(nums1,nums2,i+1,nums2[i],nums1[i],dp,1);
        }
        if(p1<nums1[i] && p2<nums2[i]){
            noswap = solveTD(nums1,nums2,i+1,nums1[i],nums2[i],dp,0);
        }
        return dp[i][isswap] = min(swap,noswap);
    }

    int solveBU(vector<int>&nums1,vector<int>&nums2){
        vector<vector<int>>dp(nums1.size()+1,vector<int>(2,0));
        for(int i=nums1.size()-1;i>=1;--i){
            for(int j=1;j>=0;--j){
                int prev1 = nums1[i-1];
                int prev2 = nums2[i-1];

                if(j){
                    swap(prev1,prev2);
                }
                int swap = INT_MAX,noswap = INT_MAX;
                // swap condition
                if(prev1 < nums2[i] && prev2 < nums1[i]){
                    swap = 1 + dp[i+1][1];
                }
                // noswap
                if(prev1 < nums1[i] && prev2 < nums2[i]){
                    noswap = dp[i+1][0];
                }
                dp[i][j] = min(swap,noswap);
            }
        }
        return dp[1][0];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // return solve(nums1,nums2,0,-1,-1);

        // vector<vector<int>>dp(nums1.size(),vector<int>(2,-1));
        // return solveTD(nums1,nums2,0,-1,-1,dp,0);

        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        return solveBU(nums1,nums2);
    }
};


// 5. Longest Palindromic Substring
class Solution {
public:
    int maxlen = 1,start = 0;
    bool solve(string&s,int i,int j){
        if(i>=j){
            return true;
        }
        bool flag = false;
        if(s[i] == s[j]){
            flag = solve(s,i+1,j-1);
        }
        if(flag){
            int currlen = j-i+1;
            if(currlen > maxlen){
                maxlen = currlen;
                start = i;
            }
        }
        return flag;
    }
    bool solveTD(string&s,int i,int j,vector<vector<int>>&dp){
        if(i >= j){
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];

        bool flag = false;
        if(s[i] == s[j]){
            flag = solveTD(s,i+1,j-1,dp);
        }
        if(flag){
            int currlen = j-i+1;
            if(currlen > maxlen){
                maxlen = currlen;
                start = i;
            }
        }
        return dp[i][j] = flag;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;++j){
                // bool t = solve(s,i,j);

                bool t = solveTD(s,i,j,dp);
            }
        }
        return s.substr(start,maxlen);
    }
};


// 712. Minimum ASCII Delete Sum for Two Strings
class Solution {
public:
    int solve(string&s1,string&s2,int i,int j){
        int cost = 0;
        if(i == s1.size() || j == s2.size()){
            // return the sum of ASCII of remaining char of remaining string
            for(int x=i;x<s1.size();++x) cost += s1[x];
            for(int x=j;x<s2.size();++x) cost += s2[x];
        }
        else if(s1[i] == s2[j])
            cost = solve(s1,s2,i+1,j+1);
        else {
            int cost1 = s1[i]+solve(s1,s2,i+1,j);
            int cost2 = s2[j]+solve(s1,s2,i,j+1);
            cost = min(cost1,cost2);
        }
        return cost;
    }

    int solveTD(string&s1,string&s2,int i,int j,vector<vector<int>>&dp){
        int cost = 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == s1.size() || j == s2.size()){
            // return the sum of ASCII of remaining char of remaining string
            for(int x=i;x<s1.size();++x) cost += s1[x];
            for(int x=j;x<s2.size();++x) cost += s2[x];
        }
        else if(s1[i] == s2[j])
            cost = solveTD(s1,s2,i+1,j+1,dp);
        else {
            int cost1 = s1[i]+solveTD(s1,s2,i+1,j,dp);
            int cost2 = s2[j]+solveTD(s1,s2,i,j+1,dp);
            cost = min(cost1,cost2);
        }
        return dp[i][j] = cost;
    }

    int solveBU(string&s1,string&s2){
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int i=s1.size()-1;i>=0;--i){
            dp[i][s2.size()] = s1[i] + dp[i+1][s2.size()];
        }
        for(int i=s2.size()-1;i>=0;--i){
            dp[s1.size()][i] = s2[i] + dp[s1.size()][i+1];
        }

        for(int i=s1.size()-1;i>=0;--i){
            for(int j=s2.size()-1;j>=0;--j){
                int cost = 0;
                if(s1[i] == s2[j]){
                    cost = dp[i+1][j+1];
                }
                else{
                    int cost1 = s1[i] + dp[i+1][j];
                    int cost2 = s2[j] + dp[i][j+1];
                    cost = min(cost1,cost2);
                }
                dp[i][j] = cost;
            }
        }
        return dp[0][0];
    }
    int minimumDeleteSum(string s1, string s2) {
        // return solve(s1,s2,0,0);

        // vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        // return solveTD(s1,s2,0,0,dp);

        return solveBU(s1,s2);
    }
};


// 1402. Reducing Dishes
class Solution {
public:
    int solve(vector<int>&sat,int i,int time){
        if(i == sat.size()) return 0;

        int includeLikeTimeCoeff = time * sat[i] + solve(sat,i+1,time+1);
        int excludeLikeTimeCoeff = solve(sat,i+1,time);
        return max(includeLikeTimeCoeff,excludeLikeTimeCoeff);
    }

    int solveTD(vector<int>&sat,int i,int time,vector<vector<int>>&dp){
        if(i == sat.size()) return 0;
        if(dp[i][time] != -1) return dp[i][time];

        int include = time*sat[i]+solveTD(sat,i+1,time+1,dp);
        int exclude = solveTD(sat,i+1,time,dp);

        dp[i][time] = max(include,exclude);
        return dp[i][time];
    }

    int solveBU(vector<int>&sat){
        vector<vector<int>>dp(sat.size()+1,vector<int>(sat.size()+2,0));

        for(int i=sat.size()-1;i>=0;i--){
            for(int time = sat.size();time >= 1;time--){
            int include = time*sat[i]+dp[i+1][time+1];
            int exclude = dp[i+1][time];
            dp[i][time] = max(include,exclude);
            }
        }
        return dp[0][1];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        // return solve(satisfaction,0,1);

        // vector<vector<int>>dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,-1));
        // return solveTD(satisfaction,0,1,dp);

        return solveBU(satisfaction);
    }
};



// 95. Unique Binary Search Trees II

class Solution {
public:
    vector<TreeNode*> allPossibleBSTs(int start,int end){
        // base case
        if(start > end) return {0};
        if(start == end) return {new TreeNode(start)};

        vector<TreeNode*>ans;
        for(int i=start;i<=end;i++){
            vector<TreeNode*>left = allPossibleBSTs(start,i-1);
            vector<TreeNode*>right = allPossibleBSTs(i+1,end);
            for(int j = 0;j<left.size();++j){
                for(int k = 0;k<right.size();++k){
                    TreeNode* root = new TreeNode(i);
                    root -> left = left[j];
                    root -> right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    
    vector<TreeNode*>allPossibleBSTsTD(int start,int end,vector<vector<vector<TreeNode*>>>dp){
        // base case
        if(start > end) return {0};
        if(start == end) return {new TreeNode(start)};
        if(dp[start][end].size()) return dp[start][end];
        vector<TreeNode*>ans;
        for(int i=start;i<=end;++i){
            vector<TreeNode*>left = allPossibleBSTs(start,i-1);
            vector<TreeNode*>right = allPossibleBSTs(i+1,end);
            for(int j=0;j<left.size();++j){
                for(int k=0;k<right.size();k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return dp[start][end] = ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        // return allPossibleBSTs(1,n);

        vector<vector<vector<TreeNode*>>>dp(n+1,vector<vector<TreeNode*>>(n+1,vector<TreeNode*>(0)));
        return allPossibleBSTsTD(1,n,dp);
    }
};


// 140. Word Break II
class Solution {
public:
    vector<string>solve(string&s,unordered_map<string,bool>&dict,int i){
        if(i == s.size()) return {""};
        vector<string>ans;
        string word;

        for(int j=i;j<s.size();++j){
            word.push_back(s[j]);
            if(dict.find(word) == dict.end()) continue;

            // found a valid word
            auto right = solve(s,dict,j+1);
            for(auto eachRightPart:right){
                string endPart;
                if(eachRightPart.size() > 0) endPart = " " + eachRightPart;
                ans.push_back(word+endPart);
            }
        }
        return ans;
    }

    unordered_map<int,vector<string>>dp;
    vector<string>solveTD(string&s,unordered_map<string,bool>&dict,int i){
        if(i == s.size()) return {""};
        vector<string>ans;
        string word;

        if(dp.find(i) != dp.end()) return dp[i];

        for(int j=i;j<s.size();j++){
            word.push_back(s[j]);
            if(dict.find(word) == dict.end()) continue;

            // found a valid word
            auto right = solveTD(s,dict,j+1);
            for(auto eachRightPart:right){
                string endPart;
                if(eachRightPart.size() > 0) endPart = " " + eachRightPart;
                ans.push_back(word + endPart);
            }
        }
        return dp[i] = ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>dict;
        for(auto word:wordDict) dict[word] = 1;
        // return solve(s,dict,0);
        return solveTD(s,dict,0);

    }
};


// 115. Distinct Subsequences
class Solution {
public:
    int solve(string&s,string&t,int i,int j){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        int ans = 0;
        if(s[i] == t[j])
            ans += solve(s,t,i+1,j+1);
        ans += solve(s,t,i+1,j);
        return ans;
    }

    int solveTD(string &s,string&t,int i,int j,vector<vector<int>>&dp){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(s[i] == t[j])
            ans += solveTD(s,t,i+1,j+1,dp);
        ans += solveTD(s,t,i+1,j,dp);
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveBU(string&s,string&t){
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));
        for(int i=0;i<=s.size();i++){
            dp[i][t.size()] = 1;
        }
        for(int i=s.size()-1;i>=0;i--){
            for(int j=t.size()-1;j>=0;j--){
                long long ans = 0;
                if(s[i]==t[j]){
                    ans += dp[i+1][j+1];
                }
                ans += dp[i+1][j];
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int numDistinct(string s, string t) {
        // return solve(s,t,0,0);
        // vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        // return solveTD(s,t,0,0,dp);

        return solveBU(s,t);
    }
};

// 97. Interleaving String
class Solution {
public:
    int solve(string&s1,string&s2,string&s3,int i,int j,int k){
        if(i == s1.size() && j == s2.size() && k == s3.size()) return true;

        bool flag = false;
        if(i < s1.size() && s1[i] == s3[k])
            flag = flag || solve(s1,s2,s3,i+1,j,k+1);

        if(j <  s2.size() && s2[j] == s3[k])
            flag = flag || solve(s1,s2,s3,i,j+1,k+1);

        return flag;
    }

    bool solveTD(string&s1,string&s2,string&s3,int i,int j,int k,vector<vector<vector<int>>>&dp){
        if(i == s1.size() && j == s2.size() && k == s3.size()) return true;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        bool flag = false;
        if(i < s1.size() && s1[i] == s3[k])
            flag = flag || solveTD(s1,s2,s3,i+1,j,k+1,dp);
        if(j < s2.size() && s2[j] == s3[k])
            flag = flag || solveTD(s1,s2,s3,i,j+1,k+1,dp);
        
        dp[i][j][k] = flag;
        return dp[i][j][k];

    }

    bool solveBU(string&s1,string&s2,string&s3){
        vector<vector<vector<int>>>dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,0)));

        dp[s1.size()][s2.size()][s3.size()] = 1;

        for(int i=s1.size();i>=0;i--){
            for(int j=s2.size();j>=0;j--){
                for(int k=s3.size();k>=0;k--){
                    if(i==s1.size() && j==s2.size() && k==s3.size()) continue;
                    bool flag = false;
                    if(i < s1.size() && s1[i] == s3[k])
                        flag = flag || dp[i+1][j][k+1];

                    if(j < s2.size() && s2[j] == s3[k])
                        flag = flag || dp[i][j+1][k+1];

                    dp[i][j][k] = flag;
                }
            }
        }
        return dp[0][0][0];
    }

    bool isInterleave(string s1, string s2, string s3) {
        // return solve(s1,s2,s3,0,0,0);
        // vector<vector<vector<int>>>dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
        // return solveTD(s1,s2,s3,0,0,0,dp);

        return solveBU(s1,s2,s3);
    }
};

// 1312. Minimum Insertion Steps to Make a String Palindrome
class Solution {
public:
    int solveUsingTabSO(string a,string b){
        vector<int>curr(b.length()+1,0);
        vector<int>next(b.length()+1,0);

        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                int ans = 0;
                if(a[i] == b[j])
                    ans = 1 + next[j+1];
                else{
                    ans = 0 + max(curr[j+1],next[j]);
                }
                curr[j] = ans;
            }
            // shift
            next = curr;
        }
        return next[0];
    }
    int longestPalindromicSubSeq(string& s){
        string first = s;
        reverse(s.begin(),s.end());
        string second = s;
        return solveUsingTabSO(first,second);
    }
    int minInsertions(string s) {
        int LPS_len = longestPalindromicSubSeq(s);
        int insertionsToDo = s.size() - LPS_len;
        return insertionsToDo;
    }
};


// 1671. Minimum Number of Removals to Make Mountain Array
class Solution {
public:
    int solveOptimal(vector<int>&arr,vector<int>&lis){
        if(arr.size() == 0)
            return 0;
        vector<int>ans;
        lis.push_back(1);
        ans.push_back(arr[0]);

        for(int i=1;i<arr.size();i++){
            if(arr[i] > ans.back()){
                // include
                ans.push_back(arr[i]);
                lis.push_back(ans.size());
                // hr element k liye lis nikal rhe hai isliye bar bar ans array ka size dekh rhe hai
            }
            else{
                // overwrite 
                // find index of just bda element
                int index = lower_bound(ans.begin(),ans.end(),arr[i]) - ans.begin();
                ans[index] = arr[i];
                lis.push_back(index+1);
                // suppose jo element hmne overwrite kra hai vo 0 index pr present hai toh lds ki length vha 1 hogi na isliye index+1 kia hai
            }
        }
        return ans.size();
    }
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>lis,lds;
        // make lis and lds array by taking each element as pivot
        solveOptimal(nums,lis);
        reverse(nums.begin(),nums.end());
        solveOptimal(nums,lds);

        int largestMountain = INT_MIN;
        // yha lds vale array ko piche se traverse kia hai qki hmne reverse kia tha,agr ye ni krna hmhe toh lds ko fir se reverse krdo or fir 1 index se traverse krke hi ans nikaalo
        for(int i=0;i<nums.size();++i){
            if(lis[i] == 1 || lds[nums.size()-i-1] == 1) continue;
            largestMountain = max(largestMountain,lis[i]+lds[nums.size()-i-1]-1);
            // yha pr jo nums.size()-i-1-1 dusra 1 isliye minus kia hai qki element 2 bar count ho jata tha
        }
        int minRemovals = nums.size() - largestMountain;
        return minRemovals;
    }
};



// 354. Russian Doll Envelopes

class Solution {
public:
    int solve(vector<vector<int>>&env,int prev,int i){
        if(i == env.size()) return 0;

        int include = INT_MIN;
        if(prev == -1 || env[prev][0] < env[i][0] && env[prev][1] < env[i][1])
            include = 1 + solve(env,i,i+1);
        int exclude = solve(env,prev,i+1);
        return max(include,exclude);
    }

    int solveTD(vector<vector<int>>&env,int prev,int i,vector<vector<int>>&dp){
        if(i == env.size()) return 0;
        if(dp[prev+1][i] != -1) return dp[prev+1][i];

        int include = INT_MIN;
        if(prev == -1 || env[prev][0] < env[i][0] && env[prev][1] < env[i][1]){
            include = 1 + solveTD(env,i,i+1,dp);
        }
        int exclude = solveTD(env,prev,i+1,dp);
        dp[prev+1][i] = max(include,exclude);

        return dp[prev+1][i];
    }

    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int solveOptimal(vector<vector<int>>&arr){
        // sort envelopes in inc by w
        // & if wi==wj ,decreasing order by h

        sort(arr.begin(),arr.end(),comp);

        if(arr.size() == 0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(arr[0][1]);

        for(int i=1;i<arr.size();i++){
            if(arr[i][1] > ans.back()){
                // include
                ans.push_back(arr[i][1]);
            }
            else{
                // overwrite
                // find index of just bda element
                int index = lower_bound(ans.begin(),ans.end(),arr[i][1]) - ans.begin();
                ans[index] = arr[i][1];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sort(envelopes.begin(),envelopes.end());
        // // return solve(envelopes,-1,0);
        // vector<vector<int>>dp(envelopes.size()+1,vector<int>(envelopes.size()+1,-1));
        // return solveTD(envelopes,-1,0,dp);

        // // ish vale case mein hm function k andr hi sort krenge 
        return solveOptimal(envelopes);
    }
};


// 1187. Make Array Strictly Increasing
class Solution {
public:
    #define INF (1e9 + 1)
    int solve(vector<int>&arr1,vector<int>&arr2,int prev,int i){
        // yha pr previous element ko denote kr rha hai or i index ko
        if(i == arr1.size()) return 0;
        // do option pr chala kr dekha h agr prev chota h i se toh simply aage bdh jao dusre option m agr prev chota hai b toh dusre array m se ek element dhund kr lao jo curr se chota h or replace kr do 
        int op1 = INF;
        if(prev < arr1[i])
            op1 = solve(arr1,arr2,arr1[i],i+1);

        int op2 = INF;
        auto it = upper_bound(arr2.begin(),arr2.end(),prev);
        if(it != arr2.end()){
            int index = it - arr2.begin();
            // arr1[i] = arr2[index];
            op2 = 1 + solve(arr1,arr2,arr2[index],i+1);
        }
        return min(op1,op2);
    }
    int solveTD(vector<int>&arr1,vector<int>&arr2,int prev,int i,map<pair<int,int>,int>&dp){
        // yha pr previous element ko denote kr rha hai or i index ko
        if(i == arr1.size()) return 0;

        if(dp.find({prev,i}) != dp.end()) return dp[{prev,i}];

        int op1 = INF;
        if(prev < arr1[i])
            op1 = solveTD(arr1,arr2,arr1[i],i+1,dp);

        int op2 = INF;
        auto it = upper_bound(arr2.begin(),arr2.end(),prev);
        if(it != arr2.end()){
            int index = it - arr2.begin();
            op2 = 1 + solveTD(arr1,arr2,arr2[index],i+1,dp);
        }
        return dp[{prev,i}] = min(op1,op2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        // arr2 sort isliye kia qki upper bound element nikaalne k liye arry sort hona compulsary hai
        sort(arr2.begin(),arr2.end());

        // int ans = solve(arr1,arr2,-1,0);
        // return ans == INF ? -1 : ans;

        map<pair<int,int>,int>dp;
        int ans = solveTD(arr1,arr2,-1,0,dp);
        return ans == INF ? -1 : ans;
    }
};


// 312. Burst Balloons

class Solution {
public:
    int solve(vector<int>&nums,int start,int end){
        if(start > end) return 0;
        int coins = INT_MIN;
        for(int i=start;i<=end;++i){
            coins = max(coins,
                nums[start-1]*nums[i]*nums[end+1]
                + solve(nums,start,i-1)
                + solve(nums,i+1,end)
            );
        }
        return coins;
    }

    int solveTD(vector<int>&nums,int start,int end,vector<vector<int>>&dp){
        if(start > end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int coins = INT_MIN;
        for(int i=start;i<=end;++i){
            coins = max(coins,
                nums[start-1]*nums[i]*nums[end+1]
                + solveTD(nums,start,i-1,dp)
                + solveTD(nums,i+1,end,dp)
            );
        }
        return dp[start][end] = coins;
    }

    int solveBU(vector<int>&nums){
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),0));
        for(int start = nums.size()-2;start>=1;start--){
            for(int end = start;end<=nums.size()-2;end++){
                int coins = INT_MIN;
                for(int i=start;i<=end;++i){
                    coins = max(coins,
                            nums[start-1]*nums[i]*nums[end+1]
                            + dp[start][i-1]
                            + dp[i+1][end]
                        );
                }
                dp[start][end] = coins;
            }
        }
        return dp[1][nums.size()-2];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        // size-2 isliye pass kia h qki do element starting or last mein hmne 1 insert kia hai
        // return solve(nums,1,nums.size()-2);

        // vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        // return solveTD(nums,1,nums.size()-2,dp);

        return solveBU(nums);
    }
};


// 877. Stone Game

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // therevwill be atleast one way by which alice will win
        // that means,we should return true
        // bcz problem is asking is there any way that Alice can win
        return true;
    }
};


// 1140. Stone Game II

class Solution {
public:
    int solve(vector<int>&piles,int i,int M,int alice){
        if(i == piles.size()) return 0;
        
        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;

        for(int X=1;X<=2*M;++X){
            if(i+X-1 >= piles.size()) break;
            total += piles[i+X-1];
            if(alice){
                // hmhe alice ko maximize krna h toh bob se jo ans return hua hai h vo minimum hona chahiye tbhi toh alice maximize hoga
                ans = max(ans,total+solve(piles,i+X,max(X,M),!alice));
            }
            else{
                ans = min(ans,solve(piles,i+X,max(X,M),!alice));
            }
        }
        return ans;
    }

        int solveTD(vector<int>&piles,int i,int M,int alice,vector<vector<vector<int>>>&dp){
        if(i == piles.size()) return 0;
        if(dp[i][M][alice] != -1) return dp[i][M][alice];
        
        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;

        for(int X=1;X<=2*M;++X){
            if(i+X-1 >= piles.size()) break;
            total += piles[i+X-1];
            if(alice){
                ans = max(ans,total+solveTD(piles,i+X,max(X,M),!alice,dp));
            }
            else{
                ans = min(ans,solveTD(piles,i+X,max(X,M),!alice,dp));
            }
        }
        return dp[i][M][alice] = ans;
    }

    int solveBU(vector<int>&piles){
        vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,0)));
        for(int i=piles.size()-1;i>=0;--i){
            for(int M=piles.size();M>=1;--M){
                for(int alice = 0;alice <= 1;++alice){
                    int ans = alice ? INT_MIN : INT_MAX;
                    int total = 0;
                    for(int X=1;X<=2*M;++X){
                        if(i+X-1 >= piles.size()) break;
                        total += piles[i+X-1];
                        if(alice)
                            ans = max(ans,total+dp[i+X][max(X,M)][!alice]);
                        else{
                            ans = min(ans,dp[i+X][max(X,M)][!alice]);
                        }
                    }
                    dp[i][M][alice] = ans;
                }
            }
        }
        return dp[0][1][true];
    }
    int stoneGameII(vector<int>& piles) {
        // return solve(piles,0,1,true);
        // vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
        // return solveTD(piles,0,1,true,dp);
        return solveBU(piles);
    }
};


// 1406. Stone Game III -> from youtube

class Solution {
public:
    int stoneGame(vector<int>&stoneValue,int i){
        int n = stoneValue.size();
        if(i >= n) return 0;

        int takeOne = stoneValue[i] - stoneGame(stoneValue,i+1);

        int takeTwo = INT_MIN;
        if(i+1 < n) takeTwo = stoneValue[i]+stoneValue[i+1] - stoneGame(stoneValue,i+2);

        int takeThree = INT_MIN;
        if(i+2 < n) takeThree = stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-stoneGame(stoneValue,i+3);

        return max(takeOne,max(takeTwo,takeThree));
    }

    int solveTD(vector<int>&stoneValue,int i,vector<int>&dp){
        int n = stoneValue.size();
        if(i >= n) return 0;

        if(dp[i] != INT_MAX) return dp[i];
        int takeOne = stoneValue[i] - solveTD(stoneValue,i+1,dp);
        int takeTwo = INT_MIN;
        if(i+1 < n) takeTwo = stoneValue[i]+stoneValue[i+1]-solveTD(stoneValue,i+2,dp);

        int takeThree = INT_MIN;
        if(i+2 < n) takeThree = stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-solveTD(stoneValue,i+3,dp);

        return dp[i] = max(takeOne,max(takeTwo,takeThree));
    }

    int solveBU(vector<int>&stoneValue){
        int n = stoneValue.size();
        vector<int>dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int takeOne = stoneValue[i] - dp[i+1];

            int takeTwo = INT_MIN;
            if(i+1 < n) takeTwo = stoneValue[i] + stoneValue[i+1] - dp[i+2];

            int takeThree = INT_MIN;
            if(i+2 < n) takeThree = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3];
            dp[i] = max(takeOne,max(takeTwo,takeThree));
        }
        return dp[0];
    }

    int SpaceOptimized(vector<int>&stoneValue){
        int n = stoneValue.size();
        vector<int>dp(3,0);
        for(int i=n-1;i>=0;i--){
            int takeOne = stoneValue[i] - dp[(i+1)%3];

            int takeTwo = INT_MIN;
            if(i+1 < n) takeTwo = stoneValue[i] + stoneValue[i+1] - dp[(i+2)%3];

            int takeThree = INT_MIN;
            if(i+2 < n) takeThree = stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[(i+3)%3];
            dp[i%3] = max(takeOne,max(takeTwo,takeThree));
        }
        return dp[0];
    }

    string stoneGameIII(vector<int>& stoneValue) {
        // -1 isliye ni lia qki dp difference ko store kr rha h or difference canbe -1
        vector<int>dp(stoneValue.size()+1,INT_MAX);
        // int ans = stoneGame(stoneValue,0);
        // int ans = solveTD(stoneValue,0,dp);
        // int ans = solveBU(stoneValue);
        int ans = SpaceOptimized(stoneValue);
        if(ans > 0) return "Alice";
        if(ans < 0) return "Bob";
        return "Tie";
    }
};

