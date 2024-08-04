#include <iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d){
        this->data = d;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertWord(TrieNode* root,string word){

    // base case
    // agr length ek bchi hai toh iska mtlb hai last character hai toh isko terminal bnao
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    // present
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        // not present
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursion sambhal lega
    insertWord(child,word.substr(1));
}

bool searchWord(TrieNode* root,string word){
    // base case
    if(word.length() == 0){
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    // present
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        return false;
    }
    // rec call
    return searchWord(child,word.substr(1));
}

void deleteTrie(TrieNode* root,string word){
    if(word.length() == 0){
        root->isTerminal = false;
    }
    
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        return;
    }
    deleteTrie(child,word.substr(1));
}
int main(){
    TrieNode* root = new TrieNode('-');
    insertWord(root,"coding");
    insertWord(root,"code");
    insertWord(root,"coder");
    insertWord(root,"codehelp");
    insertWord(root,"baba");
    insertWord(root,"baby");
    insertWord(root,"babu");
    insertWord(root,"shona");
    deleteTrie(root,"coding");

    if(searchWord(root,"coding")){
        cout<<"present"<<endl;
    }
    else{
        cout<<"absent"<<endl;
    }

    return 0;
}



// implement Trie Lakshay
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

    bool searchUtil(TrieNode* root,string &word,int i){
        if(i >= word.size()){
            return root->isTerminal;
        }

        int index = word[i] - 'a';

        if(root->children[index]){
            return searchUtil(root->children[index],word,i+1);
        }
        return false;
    }

    bool startWithUtil(TrieNode* root,string &word,int i){
        if(i>=word.size()){
            return true;
        }
        int index = word[i] - 'a';

        if(root->children[index]){
            return startWithUtil(root->children[index],word,i+1);
        }

        return false;
    }
    public:
    Trie()
    {
        root = new TrieNode('/0');
    }

    void insert(string word) {
        insertUtil(root,word,0);
    }
    
    bool search(string word) {  
        return searchUtil(root,word,0);
    }
    
    bool startsWith(string prefix) {
        return startWithUtil(root,prefix,0);
    }
};