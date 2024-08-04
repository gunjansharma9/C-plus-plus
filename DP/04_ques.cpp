#include "bits/stdc++.h"
using namespace std;


// 375. Guess Number Higher or Lower II
class Solution {
public:
    int solveUsingRecursion(int start,int end){
        if(start >= end)
            return 0;

        int ans = INT_MAX;
        for(int i=start;i<=end;i++){
            ans = min(ans,i+max(solveUsingRecursion(start,i-1),solveUsingRecursion(i+1,end)));
        }
        return ans;
    }
    int solveUsingMem(int start,int end,vector<vector<int>>&dp){
        if(start >= end){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int ans = INT_MAX;
        for(int i=start;i<=end;i++){
            ans = min(ans,i+max(solveUsingMem(start,i-1,dp),solveUsingMem(i+1,end,dp)));
        }
        dp[start][end]=ans;
        return dp[start][end];
    }

    int solveUsingTab(int n){
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int start=n;start >= 1;start--){
            for(int end = 1;end<=n;end++){
                // start equal to end case arise ho skta hai isliye usko continue kr dia
                if(start >= end){
                    continue;
                }
                else{
                    int ans = INT_MAX;
                    for(int i=start;i<=end;i++){
                        ans = min(ans,i+max(dp[start][i-1],dp[i+1][end]));
                    }
                    dp[start][end] = ans;
                }
            }
        }
        return dp[1][n];
    }
    int getMoneyAmount(int n) {
        // int ans = solveUsingRecursion(1,n);
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // int ans = solveUsingMem(1,n,dp);

        int ans = solveUsingTab(n);
        return ans;
    }
};


// 1130. Minimum Cost Tree From Leaf Values
class Solution {
public:
    int solveUsingRecursion(vector<int>&arr,map<pair<int,int>,int>&maxi,int left,int right){
        // base case
        // agr range converge krte krte single element pr aa gyi iska mtlb hai leaf node hai,hmhe ushe consider hi ni krna ans sum mein isliye return 0 krdo
        if(left == right){
            return 0;
        }
        int ans = INT_MAX;
        for(int i=left;i<right;i++){
            ans = min(ans,maxi[{left,i}]*maxi[{i+1,right}]
            +solveUsingRecursion(arr,maxi,left,i)
            +solveUsingRecursion(arr,maxi,i+1,right));
        }
        return ans;
    }

   int solveUsingMem(vector<int>& arr,map< pair<int,int> , int >& maxi, int left, int right, vector<vector<int> >& dp) {
        //base case
        if(left == right)
            return 0;

        if(dp[left][right] != -1) {
            return dp[left][right];
        }

        int ans = INT_MAX;

        for(int i=left; i<right; i++) {
            ans = min(ans, 
            maxi[{left,i}]*maxi[{i+1, right}] 
            + solveUsingMem(arr, maxi, left, i, dp)
            + solveUsingMem(arr, maxi, i+1, right, dp) );
        }
        dp[left][right] =  ans;
        return dp[left][right];
    }

    int solveUsingTab(vector<int>& arr, map< pair<int,int> , int >& maxi) {
        int n = arr.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

        for(int left = n-1; left>=0; left--) {
            for(int right=0; right<=n-1; right++) {

                if(left>=right)
                    continue;
                else {
                    //valid range
                      int ans = INT_MAX;

                    for(int i=left; i<right; i++) {
                        ans = min(ans, 
                        maxi[{left,i}]*maxi[{i+1, right}] 
                        + dp[left][i]
                        + dp[i+1][right]);
                    }
                    dp[left][right] =  ans;
                    
                }

            }
        }
    return dp[0][n-1];
    }
// map kia hai hmne range ko uski maximum value se means agr hmari range 1 to 4 hai toh isme max value kya hai or jo b other range hai usme maximum value kya hai
    int mctFromLeafValues(vector<int>& arr) {
        map< pair<int,int> , int> maxi;
        //pre-computation   
        for(int i=0;i<arr.size(); i++) {
            // pair<int,int> p;
            // p.first = i;
            // p.second=i;
            // maxi[p] = arr[i];

            maxi[{i,i}] = arr[i];
            for(int j=i+1; j<arr.size(); j++) {
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }
        int n = arr.size();
        // int ans = solveUsingRecursion(arr, maxi, 0, n-1);
        // vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
        // int ans = solveUsingMem(arr, maxi, 0, n-1, dp);
        int ans = solveUsingTab(arr, maxi);
        return ans;

    }
};




// 1143. Longest Common Subsequence
class Solution {
public:
    int solveUsingRecursion(string a,string b,int i,int j){
        if(i == a.length()){
            return 0;
        }
        if(j == b.length()){
            return 0;
        }
        int ans = 0;
        if(a[i] == b[j]){
            ans = 1 + solveUsingRecursion(a,b,i+1,j+1);
        }
        else{
            ans = 0 + max(solveUsingRecursion(a,b,i,j+1),solveUsingRecursion(a,b,i+1,j));
        }
        return ans;
    }

// yha pr strings ko pass by reference krna is very important
    int solveUsingMem(string& a,string& b,int i,int j,vector<vector<int>>&dp){
        if(i == a.length()){
            return 0;
        }
        if(j == b.length()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(a[i]==b[j]){
            ans = 1+solveUsingMem(a,b,i+1,j+1,dp);
        }
        else{
            ans = 0+max(solveUsingMem(a,b,i,j+1,dp),solveUsingMem(a,b,i+1,j,dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveUsingTab(string& a,string& b){
        vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                int ans = 0;
                if(a[i] == b[j])
                    ans = 1 + dp[i+1][j+1];
                else{
                    ans = 0 + max(dp[i][j+1],dp[i+1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveUsingTabSO(string&a,string&b){
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
            next = curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        // return solveUsingRecursion(text1,text2,i,j);

        // vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
        // return solveUsingMem(text1,text2,i,j,dp);

        return solveUsingTab(text1,text2);
    }
};


// 516. Longest Palindromic Subsequence

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
    int longestPalindromeSubseq(string s) {
        string first = s;
        reverse(s.begin(),s.end());
        string second = s;
        return solveUsingTabSO(first,second);
    }
};




// 300. Longest Increasing Subsequence
class Solution {
public:
    int solveUsingRecursion(vector<int>&arr,int curr,int prev){
        if(curr >= arr.size()){
            return 0;
        }
        // include
        int include = 0;
        if(prev == -1 || arr[curr] > arr[prev]){
            include = 1 + solveUsingRecursion(arr,curr+1,curr);
        }
        // exclude
        int exclude = 0 + solveUsingRecursion(arr,curr+1,prev);

        int ans = max(include,exclude);
        return ans;
    }

    int solveUsingMem(vector<int>&arr,int curr,int prev,vector<vector<int>>&dp){
        if(curr >= arr.size()){
            return 0;
        }
        // prev = -1 ek valid index ni hai ish wjh se hm hr jgh prev+1 use kr rhe h ,ush index ki value hm next index mein store krenge 
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        // include
        int include = 0;
        if(prev == -1 || arr[curr] > arr[prev]){
            include = 1 + solveUsingMem(arr,curr+1,curr,dp);
        }
        // exclude
        int exclude = 0 + solveUsingMem(arr,curr+1,prev,dp);
        dp[curr][prev+1] = max(include,exclude);
        return dp[curr][prev+1];
    }

    int solveUsingTab(vector<int>&arr){
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int curr=n-1;curr >=0;curr--){
            for(int prev = curr-1;prev >= -1;prev--){
                // include
                int include = 0;
                if(prev == -1 || arr[curr] > arr[prev]){
                    // yha pr b vo -1 vala case handle kia hai
                    include = 1 + dp[curr+1][curr+1];
                }
                // exclude
                int exclude = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(include,exclude);
            }
        }
        return dp[0][0];
    }

    int solveUsingSO(vector<int>&arr){
        int n = arr.size();
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
        for(int curr = n-1;curr >= 0;curr--){
            for(int prev = curr-1;prev >= -1;prev--){
                // include
                int include = 0;
                if(prev == -1 || arr[curr] > arr[prev]){
                    include = 1 + nextRow[curr+1];
                }

                // exclude
                int exclude = 0 + nextRow[prev+1];
                currRow[prev+1] = max(include,exclude);
            }
            // shift
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int solveOptimal(vector<int>&arr){
        // isko kehte h dp with binary search
        // isme ans array mein sbse phele first element ko push kro fir baki k element k liye check kro agr next elment bda hai ans vale vector m pde last element se toh push krdo otherwise ans vale vector mein usse next greater element jo hai uska index find kro or fir ush index pr overwrite krdo
        if(arr.size() == 0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(arr[0]);

        for(int i=1;i<arr.size();i++){
            if(arr[i] > ans.back()){
                // include
                ans.push_back(arr[i]);
            }
            else{
                // overwrite
                // find index of just bda element
                int index = lower_bound(ans.begin(),ans.end(),arr[i]) - ans.begin();
                ans[index] = arr[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        // prev ka yha ye mtlb hai ans vala jo hm subsequence imagine kr rhe hai uska last element taki jb include krne vala case phir se aaye toh hm compare kr ske ki jo ab element hmhe include krna hai vo last element se bda hai ya ni agr bda hoga toh hi include krenge isliye prev ka track rkh rkha hai

        // int ans = solveUsingRecursion(nums,curr,prev);

        // int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // int ans = solveUsingMem(nums,curr,prev,dp);

        // int ans = solveUsingTab(nums);

        // int ans = solveUsingSO(nums);

        int ans = solveOptimal(nums);

        return ans;
    }
};



// 72. Edit Distance

class Solution {
public:
    int solveUsingRecursion(string& a,string& b,int i,int j){
        if(i == a.length()){
           return b.length()-j;
        }
        if(j == b.length()){
           return a.length()-i;
        }
        int ans = 0;
        if(a[i] == b[j]){
            ans = solveUsingRecursion(a,b,i+1,j+1);
        }
        else{
            // operation perform kro
            int insert = 1 + solveUsingRecursion(a,b,i,j+1);
            int deleted = 1 + solveUsingRecursion(a,b,i+1,j);
            int replace = 1 + solveUsingRecursion(a,b,i+1,j+1);
            ans = min(insert,min(deleted,replace));
        }
        return ans;
    }

    int solveUsingMem(string& a,string& b,int i,int j,vector<vector<int>>&dp){
        if(i == a.length()){
           return b.length()-j;
        }
        if(j == b.length()){
           return a.length()-i;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(a[i] == b[j]){
            ans = solveUsingMem(a,b,i+1,j+1,dp);
        }
        else{
            // operation perform kro
            int insert = 1 + solveUsingMem(a,b,i,j+1,dp);
            int deleted = 1 + solveUsingMem(a,b,i+1,j,dp);
            int replace = 1 + solveUsingMem(a,b,i+1,j+1,dp);
            ans = min(insert,min(deleted,replace));
        }
        dp[i][j] = ans;
        return dp[i][j];       
    }

    int solveUsingTab(string&a,string&b){
        vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));

        for(int j=0;j<=b.length();j++){
            dp[a.length()][j] = b.length()-j;
        }

        for(int i=0;i<=a.length();i++){
            dp[i][b.length()] = a.length()- i;
        }

        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    int insert = 1 + dp[i][j+1];
                    int deleted = 1 + dp[i+1][j];
                    int replace = 1 + dp[i+1][j+1];
                    ans = min(insert,min(deleted,replace));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveUsingSO(string&a,string&b){
        vector<int>curr(b.length()+1,0);
        vector<int>next(b.length()+1,0);

        for(int j=0;j<=b.length();j++){
            next[j] = b.length()-j;
        }

        for(int i=a.length()-1;i>=0;i--){
            // every row starts here
            // ye dusre vala base case hai
            curr[b.length()] = a.length()-i;

            for(int j=b.length()-1;j>=0;j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = next[j+1];
                }
                else{
                    int insert = 1 + curr[j+1];
                    int deleted = 1 + next[j];
                    int replace = 1 + next[j+1];
                    ans = min(insert,min(deleted,replace));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        if(word1.length() == 0)
            return word2.length();
            // agr word1 ki length zero hai toh hmhe kitne words insert krne pdenge word2 se match krne k liye -> length of word2

        if(word2.length() == 0)
            return word1.length();
            // agr word2 ki length zero hai toh hmhe kitne words delete krne pdenge word1 mein se jo length hogi word1 ki
        int i = 0;
        int j = 0;

        // return solveUsingRecursion(word1,word2,i,j);
        // vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        // return solveUsingMem(word1,word2,i,j,dp);
        // return solveUsingTab(word1,word2);
        return solveUsingSO(word1,word2);
    }
};



// 1691. Maximum Height by Stacking Cuboids
class Solution {
public:
    bool check(vector<int>a,vector<int>b){
        // kya b(jo niche rkha hai) uski length,breath&height curr mein jo hm rkhna chate hai usse choti hai kya
        if(b[0]<=a[0] && b[1]<=a[1] && b[2]<=a[2]){
            return true;
        }
        else{
            return false;
        }
    }
    int solveUsingSO(vector<vector<int>>& arr){
        int n = arr.size();
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
        for(int curr = n-1;curr >= 0;curr--){
            for(int prev = curr-1;prev >= -1;prev--){
                // include
                int include = 0;
                // yhi pr condition check hoti hai
                if(prev == -1 || check(arr[curr],arr[prev])){
                    // yha pr hm 1 plus nhi kr rhe h blki height add kr rhe hai
                    include = arr[curr][2]+ nextRow[curr+1];
                }

                // exclude
                int exclude = 0 + nextRow[prev+1];
                currRow[prev+1] = max(include,exclude);
            }
            // shift
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        // hr array ko sort kr lenge fir usme first element ko width manenge second ko length or third ko height (qki sbse jyada height ko consider krna hai),sort krne k baad LIS vala logic lgayenge
        // sort every array
        for(auto &a:cuboids){
            sort(a.begin(),a.end());
        }
        // sort the 2D array
        // second bar jo ye sorting hui hai ye width k basis pr hui hai qki vo first element hai
        sort(cuboids.begin(),cuboids.end());

        int ans = solveUsingSO(cuboids);
        return ans;

    }
};