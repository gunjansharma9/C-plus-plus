#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


// Diameter of a tree another logic
int D = 0;
int height(Node* root){
    if(!root) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    // diameter
    int currD = lh + rh;
    D = max(D,currD);
    return max(lh,rh) + 1;
}

int diameterOfBinaryTree(Node* root){
    height(root);
    return D;
}


// isbalanced binary tree
bool isbalanced = true;
int height(Node* root){
    if(!root) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    // check for current node,is it balanced?
    if(isbalanced && abs(lh-rh) > 1){
        isbalanced = false;
    }
    return max(lh,rh) + 1;
}
bool isBalanced(Node* root) {
    height(root);
    return isbalanced;
}


// Same tree
bool isSameTree(Node* p, Node* q) {
    if(!p && !q)
        return true;
    if(p && q){
        return (p->data == q->data)
            && isSameTree(p->left,q->left)
            && isSameTree(p->right,q->right);
    }
    return false;
}


// Symmetric Tree

bool isMirror(Node* p,Node* q){
    if(!p && !q)
        return true;
    if(p && q){
        return (p->data == q->data)
            && isMirror(p->left,q->right)
            && isMirror(p->right,q->left);
    }
    return false;
}
bool isSymmetric(Node* root) {
    return isMirror(root->left,root->right);
}



// Diagonal Traversal of Binary Tree
vector<int> diagonal(Node *root)
{
   vector<int>ans;
   if(!root) return ans;
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
       Node* temp = q.front(); q.pop();
       while(temp){
           ans.push_back(temp->data);
           if(temp->left){
            //   baad me dekhna hai
            q.push(temp->left);
           }
           temp = temp->right;
       }
   }
   return ans;
}


// Zigzag Traversal of Binary tREE
vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>>ans;
    if(!root) return ans;
    bool LtoRdir = true;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int width = q.size();
        vector<int>oneLevel(width);
        for(int i=0;i<width;++i){
            Node* front = q.front(); q.pop();
            int index = LtoRdir? i : width-i-1;
            oneLevel[index] = front->data;
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        // toggle the direction
        LtoRdir = !LtoRdir;
        ans.push_back(oneLevel);
    }
    return ans;        
}


// Transform to Sum Tree - gfg

int sum(Node* root){
    if(!root) return 0;
    if(!root -> left && !root->right){
        // leaf node
        int temp = root->data;
        root->data = 0;
        return temp;
    }
    int lsum = sum(root->left);
    int rsum = sum(root->right);
    int temp = root->data;
    root->data = lsum + rsum;
    return root->data + temp;        
}
void toSumTree(Node *node)
{
    sum(node);
}


// Vertical traversal of Binary Tree
vector<int> verticalOrder(Node *root)
{
    map<int,map<int,vector<int>>> nodes;
    queue<pair<Node*,pair<int,int> > >q;
    vector<int>ans;
    
    if(root==NULL){
        return ans;
    }
    
    q.push(make_pair(root,make_pair(0,0)));
    
    while(!q.empty()){
        pair<Node*,pair<int,int>>temp=q.front();
        q.pop();
        Node* frontNode=temp.first;
        int hd=temp.second.first;
        int lvl=temp.second.second;
        
        nodes[hd][lvl].push_back(frontNode->data);
        
        if(frontNode->left){
            q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
        }
    }
    for(auto i:nodes){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}