#include "bits/stdc++.h"
using namespace std;

// 14. Longest Common Prefix
// first solution without trie
string longestCommonPrefix(vector<string>& strs) {
    string ans = "";
    for(int i=0;i<strs[0].length();i++){
        char ch = strs[0][i];
        bool match = true;

        // compare this chracter with all
        // the remaining strings at the same index
        for(int j=1;j<strs.size();j++){
            // compare
            if(strs[j].size() < i || ch != strs[j][i]){
                match = false;
                break;
            }
        }

        if(match == false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }

    return ans;
}


// second solution using Trie
// sbse phele elements ko Trie mein insert kro phir jb tk ek child hai aage bdhte jao jaise hi ek se jyada child miley toh ruk jao ya phir agr beech mein terminal b miley toh ruk jao
// hmhe ye b pta hona chahiye kiske kitne child hai isliye hmne childcount ko b initialize kr dia or jb b insertion hoga toh hm usko increase kr denge

// class TrieNode{
//     public:
//     char data;
//     TrieNode* children[26];
//     bool isTerminal;
//     int childCount;

//     TrieNode(char d){
//         this->data = d;
//         for(int i=0;i<26;i++){
//             children[i] = NULL;
//         }
//         this->isTerminal = false;
//         childCount = 0;
//     }
// };

// void insertWord(TrieNode* root,string word){
//     // base case
//     // agr length ek bchi hai toh iska mtlb hai last character hai toh isko terminal bnao
//     if(word.length() == 0){
//         root->isTerminal = true;
//         return;
//     }

//     char ch = word[0];
//     int index = ch - 'a';
//     TrieNode* child;
//     // present
//     if(root->children[index] != NULL){
//         child = root->children[index];
//     }
//     else{
//         // not present
//         child = new TrieNode(ch);
//         root->childCount++;
//         root->children[index] = child;
//     }

//     // recursion sambhal lega
//     insertWord(child,word.substr(1));
// }
// class Solution {
//     public:
//     void findLCP(string first,string &ans,TrieNode* root){
//         // agr mera root hi terminal node hai
//         // yha glti ho skti hai
//         if(root->isTerminal){
//             return;
//         }
//         for(int i=0;i<first.length();i++){
//             char ch = first[i];

//             if(root->childCount == 1){
//                 ans.push_back(ch);
//                 int index = ch - 'a';
//                 // agr hmari childcount 1 hai toh hm ushe ans mein include kr lenge or hm ush pr chale jayege index find krke
//                 root=root->children[index];
//             }
//             else{
//                 break;
//             }

//             if(root->isTerminal){
//                 break;
//             }
//         }
//     }
//     string longestCommonPrefix(vector<string>& strs) {
//         TrieNode* root = new TrieNode('-');
//         // insert strings
//         for(int i=0;i<strs.size();i++){
//             insertWord(root,strs[i]);
//         }

//         string ans = "";
//         string first = strs[0];
//         findLCP(first,ans,root);

//         return ans; 
//     }
// };



// // store suggestions
// void storeSuggestions(TrieNode* curr,vector<string>&temp,string &prefix){
//     if(curr -> isTerminal){
//         temp.push_back(prefix);
//     }

//     // a to z tk choices dedo
//     for(char ch = 'a';ch <= 'z';ch++){
//         int index = ch - 'a';

//         TrieNode* next = curr->children[index];

//         if(next != NULL){
//             // if child exists
//             prefix.push_back(ch);
//             storeSuggestions(next,temp,prefix);
//             prefix.pop_back();
//             // vaapas jaate time remove krdo
//         }
//     }
// }

// vector<vector<string>>getSuggestions(TrieNode* root,string input){
//     TrieNode* prev = root;
//     vector<vector<string>>output;
//     string prefix = "";

//     for(int i=0;i<input.length();i++){
//         char lastch = input[i];

//         int index = lastch - 'a';
//         TrieNode* curr = prev->children[index];

//         if(curr == NULL){
//             break;
//         }
//         else{
//             // iske andr saare suggestions store krke laane hai
//             vector<string>temp;
//             prefix.push_back(lastch);
//             storeSuggestions(curr,temp,prefix);
//             output.push_back(temp);
//             prev = curr;
//         }
//     }
//     return output;
// }

// int main(){
//     vector<string>v;
//     v.push_back("love");
//     v.push_back("lover");
//     v.push_back("loving");
//     v.push_back("last");
//     v.push_back("lost");
//     v.push_back("lane");
//     v.push_back("lord");

//     string input = "lovi";
//     // ish input string k every character k liye hmhe suggestions print krne hai vector mein se
//     TrieNode* root = new TrieNode('-');
//     for(int i=0;i<v.size();i++){
//         insertWord(root,v[i]);
//     }

//     vector<vector<string>> ans = getSuggestions(root,input);

//     cout<<"Printing the answer: "<<endl;

//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<ans[i].size();j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// // 648.Replace Words

class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) : data(ch),isTerminal(false) {
        for(int i=0;i<26;i++){
            children[i] = 0;
        }
    }
};

class Trie {
    TrieNode* root;

    void insertUtil(TrieNode* root,string &word,int i){
        if(i >= word.size()){
            root->isTerminal = true;
            return;
        }
        int index = word[i] - 'a';

        if(!root->children[index]){
            root->children[index] = new TrieNode(word[i]);
        }

        insertUtil(root->children[index],word,i+1);
    }

    bool searchUtil(TrieNode* root,string &word,int &i){
        if(root->isTerminal){
            return true;
        }

        if(i >= word.size()){
            return root->isTerminal;
        }

        int index = word[i++] - 'a';

        if(root->children[index]){
            return searchUtil(root->children[index],word,i);
        }
        return false;
    }

public:
    Trie()
    {
        root = new TrieNode('-');
    }

    void insert(string word) {
        insertUtil(root,word,0);
    }
    
    int search(string word) {  
        int i = 0;
        bool gotIt = searchUtil(root,word,i);
        // i hmhe btayega kitne character match hue hai
        return gotIt ? i : -1;
    }
    
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        Trie trie;
        // insert dictionary into Trie
        for(auto root:dictionary){
            trie.insert(root);
        }

        // pick each word and find in trie whether the is available or not
        int start = 0,end = 0;
        while(end < sentence.size()){
            if(sentence[end] == ' ' || end == sentence.size() - 1){
                int len = end == sentence.size()-1 ? sentence.size() : end - start;
                string word = sentence.substr(start,len);
                int trieMatchIndex = trie.search(word);
                ans += trieMatchIndex != -1 ? word.substr(0,trieMatchIndex) : word;
                if(sentence[end] == ' '){
                    ans += " ";
                }
                start = end+1;
            }
            ++end;
        }
        return ans;
    }
};