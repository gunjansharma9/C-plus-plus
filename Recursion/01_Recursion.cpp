#include <iostream>
#include <vector>
#include <limits.h>
#include <string.h>
#include "bits/stdc++.h"
using namespace std;

// // check array is sorted or not

// bool checkSorted(vector<int>&arr,int &n,int i){
//     if(i==n-1){
//         return true;
//     }
//     if(arr[i+1] < arr[i]){
//         return false;
//     }
//     return checkSorted(arr,n,i+1);
// }


// SUBSEQUENCES OF A STRING

// void printSubSequences(string str,string output,int i){
//     if(i >= str.length()){
//         cout<<output<<endl;
//         return;
//     }

//     // exclude
//     printSubSequences(str,output,i+1);

//     // include
//     output.push_back(str[i]);
//     printSubSequences(str,output,i+1);
    
// }

// int main(){
//     string s;
//     cout<<"Enter a string : ";
//     cin>>s;
    
//     string output="";
//     int i=0;
//     cout<<"Subsequences are : "<<endl;
//     printSubSequences(s,output,i);

//     return 0;
// }



// BINARY SEARCH
// int binarySearch(vector<int>&v,int s,int e,int target){
//     if(s>e){
//         return -1;
//     }

//     int mid=(s+e)/2;

//     if(v[mid]==target){
//         return mid;
//     }

//     return ((v[mid]<target) ? binarySearch(v,mid+1,e,target):binarySearch(v,s,mid-1,target));
// }

// int main(){
//     vector<int> v{12,34,56,78,99,100,117,180};
//     int n=v.size();
//     int target=180;

//     int s=0;
//     int e=n-1;
//     int ans=binarySearch(v,s,e,target);
//     cout<<"Answer at : "<<ans;

//     return 0;
// }



// Minimum number of elements required to get sum equal to target value
// int solve(vector<int>&v,int target){
//     if(target==0){
//         return 0;
//     }

//     if(target<0){
//         return INT_MAX;
//     }

//     int mini=INT_MAX;
//     for(int i=0;i<v.size();i++){
//         int ans=solve(v,target-v[i]);
//         if(ans != INT_MAX){
//         mini=min(ans+1,mini);
//         }
//     }
//     return mini;
// }

// int main(){
//     vector<int>v{1,2,3};
//     int target=5;

//     int ans=solve(v,target);
//     cout<<"Answer is : "<<ans;

//     return 0;
// }



// MAXIMUM NUMBER OF SEGMENTS REQUIRED TO GIVE LENGTH N
// int solve(int n,int x,int y,int z){
//     if(n==0){
//         return 0;
//     }
//     if(n<0){
//         return INT_MIN;
//     }
//     int ans1=solve(n-x,x,y,z)+1;
//     int ans2=solve(n-y,x,y,z)+1;
//     int ans3=solve(n-z,x,y,z)+1;

//     int ans=max(ans1,max(ans2,ans3));
//     return ans;
// }
// int main(){
//     int n = 7;
//     int x = 5;
//     int y = 2;
//     int z = 2;

//     int ans=solve(n,x,y,z);
//     if(ans<0){
//         ans=0;
//     }
//     cout<<"Answer is : "<<ans;
//     return 0;
// }



// MAXIMUM SUM OF NON-ADJACENT ELEMENT
// void solve(vector<int>&arr,int i,int sum,int &maxi){
//     if(i >= arr.size()){
//         maxi=max(maxi,sum);
//         return;
//     }
//     // include
//     solve(arr,i+2,sum+arr[i],maxi);

//     // exclude
//     solve(arr,i+1,sum,maxi);

// }
// int main(){
//     vector<int>arr{2,1,4,9};
//     int sum=0;
//     int i=0;
//     int maxi=INT_MIN;

//     solve(arr,i,sum,maxi);
//     cout<<"Answer is : "<<maxi;
//     return 0;
// }



// LAST OCCURENCE OF A CHARACTER
// void solve(string str,int i,char targetOccurence,int &ans){
//     if(i>=str.length()){
//         return;
//     }

//     if(str[i]==targetOccurence){
//         ans=i;
//     }
//     solve(str,i+1,targetOccurence,ans);
// }

// void lastOccRightToLeft(string&s,char x,int i,int &ans){
//     if(i<0){
//         return;
//     }
//     if(s[i] == x){
//         ans = i;
//         return;
//     }
//     lastOccRightToLeft(s,x,i-1,ans);
// }

// int main(){
//     string str("aabcaab");

//     char targetOccurence='b';
//     int i=0;
//     int ans=-1;
//     // solve(str,i,targetOccurence,ans);
//     lastOccRightToLeft(str,targetOccurence,str.size()-1,ans);
//     cout<<"Last occurence of character is at : "<<ans;

//     return -1;
// }




// REVERSE A STRING USING RECURSION
// void reverse(string& s,int start,int end){
//     if(start>=end){
//         return;
//     }

//     swap(s[start],s[end]);
//     reverse(s,start+1,end-1);
// }
// int main(){

//     string s("gunjansharma");
//     cout<<"Reverse of given string is : ";
//     reverse(s,0,s.length()-1);
//     cout<<s<<endl;

//     return 0;
// }



// // ADDITION OF A STRING OF INTEGER
// void solve(string &num1,string &num2,int p1,int p2,string &ans,int carry=0){
//     // base case
//     if(p1<0 && p2<0){
//         if(carry != 0){
//             ans.push_back(carry+'0');
//         }
//         return ;
//     }

//     // ek case solve kro
//     int n1=(p1>=0 ? num1[p1] : '0') - '0';
//     int n2=(p2>=0 ? num2[p2] : '0') - '0';
//     int csum = n1+n2+carry;
//     int digit = csum % 10;
//     carry=csum/10;
//     ans.push_back(digit+'0');

//     solve(num1,num2,p1-1,p2-1,ans,carry);
// }

// int main(){
//     string num1("1244");
//     string num2("111");
//     int pointer1=num1.size()-1;
//     int pointer2=num2.size()-1;
//     string ans="";
//     solve(num1,num2,pointer1,pointer2,ans);
//     reverse(ans.begin(),ans.end());
//     cout<<ans;
//     return 0;
// }



// // IS PALINDROME
// bool solve(string s,int start,int end){
//     if(start>=end){
//         return 1;
//     }

//     if(s[start]!=s[end]){
//         return 0;
//     }
//     return solve(s,start+1,end-1);
// }
// int main(){
//     string s;
//     cout<<"Enter a string:";
//     cin>>s;

//     cout<<"Is palindrome? "<<solve(s,0,s.length()-1);
//     return 0;
// }



// REMOVE ALL OCCURENCE OF A SUBSTRING
// void removeOCCRE(string &s,string &part){
//     int found=s.find(part);
//     if(found != string::npos){
//         string left_part = s.substr(0,found);
//         string right_part = s.substr(found+part.size(),s.size());
//         s = left_part+right_part;
//         removeOCCRE(s,part);
//     }

//     else{
//         return;
//     }
// }

// int main(){
//     string s;
//     cout<<"Enter a string : ";
//     cin>>s;

//     string part;
//     cout<<"Enter part that you want to remove : ";
//     cin>>part;

//     removeOCCRE(s,part);
//     cout<<"Output string is : ";
//     cout<<s;
//     return 0;
// }



// void printSubarrays_util(vector<int>&arr,int start,int end){
//     if(end == arr.size()){
//         return;
//     }

//     for(int i=start;i<=end;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;

//     printSubarrays_util(arr,start,end+1);
// }
// void printSubarray(vector<int>&arr){
//     for(int start=0;start<arr.size();start++){
//         int end=start;
//         printSubarrays_util(arr,start,end);
//     }
// }

// int main(){
//     vector<int>arr{1,2,3,4,5};
//     printSubarray(arr);

//     return 0;
// }




// // BUY AND SELL STOCK
// void maxProfitFinder(vector<int>&prices,int i,int& minPrice,int& maxProfit){
//     // base case
//     if(i==prices.size()){
//         return;
//     }
//     if(prices[i]<minPrice){
//         minPrice = prices[i];
//     }
//     int todayProfit = prices[i] - minPrice;
//     if(todayProfit > maxProfit){
//         maxProfit = todayProfit;
//     }
//     maxProfitFinder(prices,i+1,minPrice,maxProfit);
// }
// int main(){
//     vector <int>prices ={3,7,8,4,1,2};
//     int minPrice = INT_MAX;
//     int maxProfit = INT_MIN;
//     maxProfitFinder(prices,0,minPrice,maxProfit);
//     cout<<"maxProfit "<<maxProfit;

//     return 0;
// }


// 273. Integer to English Words

// class Solution {
// public:
//     vector<pair<int,string>>mp = {{1000000000,"Billion"},{1000000,"Million"},
//     {1000,"Thousand"},{100,"Hundred"},{90,"Ninety"},{80,"Eighty"},{70,"Seventy"},
//     {60,"Sixty"},{50,"Fifty"},{40,"Forty"},{30,"Thirty"},{20,"Twenty"},{19,"Nineteen"},
//     {18,"Eighteen"},{17,"Seventeen"},{16,"Sixteen"},{15,"Fifteen"},{14,"Fourteen"},
//     {13,"Thirteen"},{12,"Twelve"},{11,"Eleven"},{10,"Ten"},{9,"Nine"},{8,"Eight"},
//     {7,"Seven"},{6,"Six"},{5,"Five"},{4,"Four"},{3,"Three"},{2,"Two"},{1,"One"}
//     };
//     string numberToWords(int num) {
//         if(num == 0){
//             return "Zero";
//         }

//         for(auto it:mp){
//             if(num >= it.first){
//                 string a = "";
//                 if(num >= 100){
//                     a = numberToWords(num/it.first) + " ";
//                 }
//                 string b = it.second;
//                 string c = "";
//                 if(num % it.first != 0){
//                     c = " "+numberToWords(num % it.first);
//                 }
//                 return a+b+c;
//             }
//         }
//         return "";
//     }
// };




// 44. Wildcard Matching

// class Solution {
// public:
//     bool isMatchHelper(string&s,int si,string&p,int pi){
//         // base case
//         if(si == s.size() && pi == p.size()){
//             return true;
//         }

//         if(si == s.size() && pi < p.size()){
//             while(pi < p.size()){
//                 if(p[pi] != '*') return false;
//                 pi++;
//             }
//             return true;
//         }

//         if(s[si] == p[pi] || p[pi] == '?'){
//             return isMatchHelper(s,si+1,p,pi+1);
//         }

//         if(p[pi] == '*'){
//             // treat * as empty or null
//             bool caseA = isMatchHelper(s,si,p,pi+1);

//             // let * consume one char
//             bool caseB = isMatchHelper(s,si+1,p,pi);
//             return caseA || caseB;
//         }
//         return false;
//     }
//     bool isMatch(string s, string p) {
//         int si = 0;  //pointer index for s string
//         int pi = 0;  //pointer index for p string
//         return isMatchHelper(s,si,p,pi);
//     }
// };


// above solution with dp

// class Solution {
// public:
//     bool isMatchHelper(string&s,int si,string&p,int pi,vector<vector<int>>&dp){
//         // base case
//         if(si == s.size() && pi == p.size()){
//             return true;
//         }

//         if(si == s.size() && pi < p.size()){
//             while(pi < p.size()){
//                 if(p[pi] != '*') return false;
//                 pi++;
//             }
//             return true;
//         }

//         if(dp[si][pi] != -1){
//             return dp[si][pi];
//         }

//         if(s[si] == p[pi] || p[pi] == '?'){
//             return dp[si][pi] = isMatchHelper(s,si+1,p,pi+1,dp);
//         }

//         if(p[pi] == '*'){
//             // treat * as empty or null
//             bool caseA = isMatchHelper(s,si,p,pi+1,dp);

//             // let * consume one char
//             bool caseB = isMatchHelper(s,si+1,p,pi,dp);
//             return dp[si][pi] = caseA || caseB;
//         }
//         return false;
//     }
//     bool isMatch(string s, string p) {
//         int si = 0;  //pointer index for s string
//         int pi = 0;  //pointer index for p string
//         vector<vector<int>>dp(s.length()+1,vector<int>(p.length()+1,-1));
//         return isMatchHelper(s,si,p,pi,dp);
//     }
// };




// fibonacci time complexity -> exponential O(2^n)
// fibonacci space complexity => linear O(n)