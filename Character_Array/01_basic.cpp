#include "bits/stdc++.h"
using namespace std;

void reverseString(char s[]){
    int i=0;
    int j=strlen(s)-1;
    while(i<j){
        swap(s[i],s[j]);
        i++;
        j--;
    }
    cout<<"Reverse string is : "<<s<<endl;
}

void replaceAllSpaces(char s[]){
    for(int i=0;i<strlen(s);i++){
        if(s[i] == ' '){
            s[i] = '@';
        }
    }
    cout<<"After replacement string is : "<<s<<endl;
}

void isPalindrome(char s[]){
    bool flag = true;
    int i=0;
    int j=strlen(s)-1;
    while(i<j){
        if(s[i] != s[j]){
            flag = false;
            break;
        }
        i++;
        j--;
    }
    if(flag){
        cout<<"String is palindrome"<<endl;
    }else{
        cout<<"String is not a palindrome"<<endl;
    }
}

void convertIntoUppercase(char s[]){
    for(int i=0;i<strlen(s);i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            continue;
        }
        s[i] = s[i]-32;
    }
    cout<<s;
}

// 1047. Remove All Adjacent Duplicates In String
string removeDuplicatesAdjacent(string s){
    string ans = "";
    int i=0;
    while(i<s.length()){
        if(ans.length() > 0){
            if(ans[ans.length()-1] == s[i]){
                ans.pop_back();
            }else{
                ans.push_back(s[i]);
            }
        }else{
            ans.push_back(s[i]);
        }
        i++;
    }
    return ans;
}

// 1910. Remove All Occurrences of a Substring
string removeOccurrences(string s, string part) {
    int pos = s.find(part);
    while(pos != string::npos){
        s.erase(pos,part.length());
        pos = s.find(part);
    }
    return s;
}

// 680. Valid Palindrome II
class Solution {
public:
    bool checkPalindrome(string s,int i,int j){
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;

        while(i<=j){
            if(s[i] != s[j]){
                return checkPalindrome(s,i+1,j) || checkPalindrome(s,i,j-1);
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
};

int main(){
    // char arr[100];
    // cin.getline(arr,50);
    // // maximum 50 length ka input le skte hai
    // cout<<arr;
    // cout<<"Length is : "<<strlen(arr);

    char s[]="my name is gunjan s";
    char s1[] = "nitin";
    reverseString(s);
    replaceAllSpaces(s);
    isPalindrome(s1);
    convertIntoUppercase(s1);

    return 0;
}


// 539. Minimum Time Difference
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // step1:convert all the time in minutes in a vector
        vector<int>minutes;
        for(int i=0;i<timePoints.size();i++){
            string curr = timePoints[i];
            int hours = stoi(curr.substr(0,2));
            int min = stoi(curr.substr(3,2));
            int totalMinutes = hours*60 + min;
            minutes.push_back(totalMinutes);
        }
        // step2:sort the vector
        sort(minutes.begin(),minutes.end());

        // step3:difference and calculate diff
        int mini = INT_MAX;
        int n = minutes.size();

        for(int i=0;i<n-1;i++){
            int diff = minutes[i+1] - minutes[i];
            mini = min(mini,diff);
        }

        // cyclic vala case handle kro
        int lastDiff1 = (minutes[0]+1440) - minutes[n-1];
        int lastDiff2 = minutes[n-1] - minutes[0];
        int lastDiff = min(lastDiff1,lastDiff2);
        mini = min(mini,lastDiff);

        return mini;
    }
};


// 647. Palindromic Substrings
class Solution {
public:
    int expandAroundIndex(string s,int i,int j){
        int count=0;
        while(i >= 0 && j<s.length() && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            int oddKaAns = expandAroundIndex(s,i,i);
            count = count + oddKaAns;

            int evenKaAns = expandAroundIndex(s,i,i+1);
            count = count + evenKaAns;
        }
        return count;
    }
};