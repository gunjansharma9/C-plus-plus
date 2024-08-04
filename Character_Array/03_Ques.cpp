#include "bits/stdc++.h"
using namespace std;

// 242. Valid Anagram
class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqTable[256] = {0};
        for(int i=0;i<s.size();i++){
            freqTable[s[i]]++;
        }

        for(int i=0;i<t.size();i++){
            freqTable[t[i]]--;
        }

        for(int i=0;i<256;i++){
            if(freqTable[i] != 0){
                return false;
            }
        }
        return true;
    }
};

// 917. Reverse Only Letters
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l=0,h=s.size()-1;
        while(l<h){
            if(isalpha(s[l]) && isalpha(s[h])){
                swap(s[l],s[h]);
                l++,h--;
            }
            else if(!isalpha(s[l])){
                l++;
            }else{
                h--;
            }
        }
        return s;
    }
};


// 14. Longest Common Prefix
string longestCommonPrefix(vector<string>& strs) {
    string ans;
    int i=0;
    while(true){
        char curr_ch=0;
        for(auto str:strs){
            if(i>=str.size()){
                curr_ch=0; 
                break;
            }
            if(curr_ch == 0){
                curr_ch = str[i];
            }
            else if(str[i] != curr_ch){
                curr_ch= 0;
                break;
            }
        }
        if(curr_ch == 0){
            break;
        }
        ans.push_back(curr_ch);
        i++;
    }
    return ans;
}


// 345. Reverse Vowels of a String
bool isVowel(char ch){
    ch = tolower(ch);
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}
string reverseVowels(string s) {
    int l=0,h=s.size()-1;
    while(l<h){
        if(isVowel(s[l]) && isVowel(s[h])){
            swap(s[l],s[h]);
            l++,h--;
        }else if(isVowel(s[l]) == 0){
            l++;
        }else{
            h--;
        }
    }
    return s;
}


// 205. Isomorphic Strings
bool isIsomorphic(string s, string t) {
    int hash[256] = {0};
    bool istCharsMapped[256] = {0};

    for(int i=0;i<s.size();i++){
        if(hash[s[i]] == 0 && istCharsMapped[t[i]] == 0){
            hash[s[i]] = t[i];
            istCharsMapped[t[i]] = true;
        }
    }

    for(int i=0;i<s.size();i++){
        if(char(hash[s[i]]) != t[i]){
            return false;
        }
    }
    return true;
}


// 49. Group Anagrams
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string,vector<string>>mp;
    for(auto str:strs){
        string s = str;
        sort(s.begin(),s.end());
        mp[s].push_back(str);
    }

    vector<vector<string>>ans;
    for(auto it=mp.begin();it != mp.end();it++){
        ans.push_back(it->second);
    }
    return ans;
}


// 28. Find the Index of the First Occurrence in a String
int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();

    for(int i=0;i<=n-m;i++){
        for(int j=0;j<m;j++){
            if(needle[j] != haystack[i+j]){
                break;
            }
            if(j == m-1){
                return i;
            }
        }
    }
    return -1;
}



// 8. String to Integer (atoi)
int myAtoi(string s) {
    int num=0,i=0,sign=1;
    while(s[i] == ' '){
        i++;
    }
    if(i<s.size() && (s[i] == '-' || s[i] == '+')){
        sign = s[i] == '+' ? 1 : -1;
        ++i;
    }

    while(i<s.size() && isdigit(s[i])){
        if(num > INT_MAX/10 || (num == INT_MAX/10 && s[i] > '7')){
            // to handle out of bound conditions
            return sign==-1 ? INT_MIN : INT_MAX;
        }
        num = num*10 + (s[i] - '0');
        ++i;
    }
    return num*sign;
}


// 443. String Compression
int compress(vector<char>& s) {
    int index=0,count=1;
    char prev = s[0];
    for(int i=1;i<s.size();++i){
        if(s[i] == prev){
            count++;
        }else{
            s[index++] = prev;
            if(count > 1){
                int start = index;
                while(count){
                    s[index++] = (count % 10) + '0';
                    count /= 10;
                }
                reverse(s.begin()+start,s.begin()+index);
            }
            prev = s[i];
            count = 1;
        }
    }
    s[index++] = prev;
    if(count > 1){
        int start = index;
        while(count){
            s[index++] = (count % 10) + '0';
            count /= 10;
        }
        reverse(s.begin()+start,s.begin()+index);
    }
    return index; 
}


// 12. Integer to Roman
string intToRoman(int num) {
    string romanSymbols[] = {"M","CM","D","CD","C","XC","L","XL",
                            "X","IX","V","IV","I"};
    int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string ans = "";
    for(int i=0;i<13;i++){
        while(num >= values[i]){
            ans += romanSymbols[i];
            num -= values[i];
        }
    }
    return ans;
}


// 6. Zigzag Conversion
string convert(string s, int numRows) {
    if(numRows == 1)  return s;
    vector<string>zigzag(numRows);

    int i=0,row=0;
    bool direction = 1;

    while(true){
        if(direction){
            while(row < numRows && i<s.size()){
                zigzag[row++].push_back(s[i++]);
            }
            row = numRows - 2;
        }else{
            while(row >= 0 && i<s.size()){
                zigzag[row--].push_back(s[i++]);
            }
            row = 1;
        }
        if(i >= s.size()) break;
        direction = !direction;
    }
    string ans="";
    for(int i=0;i<zigzag.size();i++){
        ans += zigzag[i];
    }
    return ans;
}


// 179. Largest Number
static bool mycomp(string a,string b){
    //when we compare 3 and 30 then then 30 is lesser so we have to handle this case
    string t1 = a+b;
    string t2 = b+a;
    return t1 > t2;
}
string largestNumber(vector<int>& nums) {
    vector<string>snums;
    for(auto n:nums){
        snums.push_back(to_string(n));
    }

    sort(snums.begin(),snums.end(),mycomp);
    if(snums[0] == "0") return "0";
    string ans = "";
    for(auto str:snums){
        ans += str;
    }
    return ans;
}