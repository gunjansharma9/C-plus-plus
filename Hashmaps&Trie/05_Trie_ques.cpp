#include "bits/stdc++.h"
using namespace std;


// // 1023. Camelcase Matching

// class TrieNode{
// public:
//     char data;
//     TrieNode* children[58];
//     bool isTerminal;

//     TrieNode(char ch) : data(ch),isTerminal(false) {
//         for(int i=0;i<58;i++){
//             children[i] = 0;
//         }
//     }
// };

// class Trie {
//     TrieNode* root;

//     void insertUtil(TrieNode* root,string &word,int i){
//         if(i >= word.size()){
//             root->isTerminal = true;
//             return;
//         }
//         int index = word[i] - 'A';

//         if(!root->children[index]){
//             root->children[index] = new TrieNode(word[i]);
//         }

//         insertUtil(root->children[index],word,i+1);
//     }

//     bool searchUtil(TrieNode* root,string &word,int i){
//         if(i >= word.size()){
//             return root->isTerminal;
//         }

//         int index = word[i] - 'A';

//         if(root->children[index]){
//             return searchUtil(root->children[index],word,i+1);
//         }
//         // agr hmara character lower case h toh usko consume krlo or trie m ushi node pr rho i.e. root pr hi
//         else if(islower(word[i])){
//             return searchUtil(root,word,i+1);
//         }
//         return false;
//     }

// public:
//     Trie()
//     {
//         root = new TrieNode('/0');
//     }

//     void insert(string& word) {
//         insertUtil(root,word,0);
//     }
    
//     bool search(string& word) {  
//         return searchUtil(root,word,0);
//     }
    
// };


// class Solution {
// public:
//     vector<bool> camelMatch(vector<string>& queries, string pattern) {
//         vector<bool>ans;
//         Trie trie;
//         trie.insert(pattern);
//         for(auto query:queries){
//             ans.push_back(trie.search(query));
//         }

//         return ans;
//     }
// };



// // Palindrome pairs;
class TrieNode{
public:
    char data;
    TrieNode* children[26];
    int stringNumber; //original words array index of that string

    TrieNode(char ch) : data(ch),stringNumber(-1) {
        for(int i=0;i<26;i++){
            children[i] = 0;
        }
    }
};

class Trie {
    TrieNode* root;

    void insertUtil(TrieNode* root,string &word,int i,int& stringNumber){
        if(i >= word.size()){
            root->stringNumber = stringNumber;
            return;
        }
        int index = word[i] - 'a';

        if(!root->children[index]){
            root->children[index] = new TrieNode(word[i]);
        }

        insertUtil(root->children[index],word,i+1,stringNumber);
    }

public:
    Trie()
    {
        root = new TrieNode('/0');
    }

    void insert(string& word,int &stringNumber) {
        insertUtil(root,word,0,stringNumber);
    }

    bool isPalindrome(string& s,int low,int high){
        while(low<=high){
            if(s[low] != s[high]) return false;
            low++,high--;
        }
        return true;
    }

    void searchCase2(TrieNode*root,vector<int>&myPalindrome,string s){
        // if dc is existing in the trie and we are finding abacd then dc will be matched with existing dc and we have to check for aba if it is also palindrome then return pair
        if(root->stringNumber != -1){
            if(isPalindrome(s,0,s.size()-1)){
                myPalindrome.push_back(root->stringNumber);
            }
        }

        for(int i=0;i<26;i++){
            if(root->children[i] != 0){
                s.push_back(i + 'a');
                searchCase2(root->children[i],myPalindrome,s);
                s.pop_back(); //bt
            }
        }
    }
    
    void search(string& word,vector<int>&myPalindrome) {  
        TrieNode* curr = root;

        // Case1 : when a prefix matching word,exactly matches with a word in trie
        // if bd is existing in the trie and we are searching pair of dbcc so db mathces but cc is remaining so if remaining is also palindrome then we return pair
        for(int i=0;i<word.size();++i){
            int index = word[i] - 'a';
            
            if(curr->stringNumber != -1){
                // check rest of the search-word is palindrome??
                if(isPalindrome(word,i,word.size()-1)){
                    myPalindrome.push_back(curr->stringNumber);
                }
            }

            if(curr->children[index]){
                curr = curr->children[index];
            }
            else{
                return;
            }
        }

        // case2:search-word is a prefix of a word in the trie.
        // check remaining subtrees in the trie for the palindrome.
        searchCase2(curr,myPalindrome,"");
    }
    
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        // sbse phele saare words ko reverse krke trie mein push krdo uske string no k saath phir every word ko check kro
        vector<vector<int>>ans;
        Trie trie;
        
        for(int i=0;i<words.size();i++){
            auto reverseword = words[i];
            reverse(reverseword.begin(),reverseword.end());
            trie.insert(reverseword,i);
        }

        // find palindromic pairs of ith word
        for(int i=0;i<words.size();i++){
            vector<int>myPalindrome; //array stores palindromic pairs of ith word mtlb jaise 0 ka 1 k saath pair h or 2 k saath b;
            trie.search(words[i],myPalindrome);

            for(auto it:myPalindrome){
                if(it != i){
                    ans.push_back({i,it});
                }
            }
        }
        return ans;
    }
};