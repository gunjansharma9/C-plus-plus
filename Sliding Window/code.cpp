#include "bits/stdc++.h"
using namespace std;

// 239. Sliding Window Maximum
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq; //pair<val,index>
        vector<int>ans;

        // consider first window
        for(int i=0;i<k;++i){
            pq.push({nums[i],i});
        }
        // store max of first window
        ans.push_back(pq.top().first);

        // consider rest of the window
        for(int i=k;i<nums.size();++i){
            pq.push({nums[i],i});

            // remove if maxs are from previous windows.
            while(pq.top().second <= i-k){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};


// 1. Two Sum
class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        return a.first < b.first;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>data; //{data index}
        // index isliye store kia hai agr hm sort krenge toh index miss ho jayenge
        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            int index = i;
            data.push_back({val,index});
        }

        sort(data.begin(),data.end(),cmp);

        int start = 0;
        int end = data.size() - 1;
        while(start < end){
            if(data[start].first + data[end].first == target){
                ans.push_back(data[start].second);
                ans.push_back(data[end].second);
                break;
            }
            else if(data[start].first + data[end].first > target){
                end--;
            }
            else{
                start++;
            }
        }

        return ans;
    }
};

// Variable length sliding window
// step1 : start with 1 size window from the extreame left
// step2 : increment "end" till you achieve the target specified in problem statement;
// step3 : once you achieve the target,try minimising the window

// 209. Minimum Size Subarray Sum
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int sum = 0;
        int len = INT_MAX;

        // initially 1 size ki window hai
        while(j < nums.size()){
            // include current number
            sum = sum + nums[j];
            // mere paas ek window ka sum ready hai
            while(sum >= target){
                // minimise -> sum mein se decrease kro,length bhi update krlena,i ko aage badhaana pdega
                len = min(len,j-i+1);
                sum = sum - nums[i];
                i++;
            }
            j++;
        }

        if(len == INT_MAX)
            return 0;
        else
            return len;
    }

};



// 76. Minimum Window Substring
class Solution {
public:
    string minWindow(string s, string p) {
        int len1 = s.length();
        int len2 = p.length();
        int start = 0;
        int ansIndex = -1;
        int ansLen = INT_MAX;

        if(len1 < len2){
            return "";
        }

        unordered_map<char,int>strMap;
        unordered_map<char,int>patMap;
        // to keep track of all characters of p string
        for(int i=0;i<p.length();i++){
            char ch = p[i];
            patMap[ch]++;
        }

        int count = 0;
        for(int i=0;i<s.length();i++){
            char ch = s[i];

            strMap[ch]++;

            // valid character -> jo character tumhare pattern mein bhi ho
            if(strMap[ch] <= patMap[ch]){
                count++;
            }

            if(count == len2){
                while(strMap[s[start]] > patMap[s[start]] || patMap[s[start]] == 0){
                    if(strMap[s[start]] > patMap[s[start]])
                        strMap[s[start]]--;
                    
                    start++;
                }

                int lengthOfWindow = i - start + 1;
                if(lengthOfWindow < ansLen){
                    ansLen = lengthOfWindow;
                    ansIndex = start;
                }
            }
        }
        if(ansIndex == -1)
            return "";
        else 
            return s.substr(ansIndex,ansLen);
    }
};


// 2134. Minimum Swaps to Group All 1's Together II
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int>temp(2*n);
        // to handle circular cases
        for(int i=0;i<2*n;i++){
            temp[i] = nums[i%n]; //{0,1,1,0} -----> {0,1,1,0,0,1,1,0}
        }

        int totalOnes = accumulate(nums.begin(),nums.end(),0);

        int i = 0;
        int j = 0;

        int currOnes = 0;
        int maxCount = 0;

        while(j<2*n){
            if(temp[j] == 1){
                currOnes++;
            }

            if(j-i+1 > totalOnes){
                currOnes -= temp[i];
                i++;
            }

            maxCount = max(maxCount,currOnes);
            j++;
        }
        return totalOnes - maxCount;
    }
};