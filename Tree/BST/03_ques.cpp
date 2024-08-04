#include "bits/stdc++.h"
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

// find predecessor of a node in BST
Node* findPredecessor(Node* root,Node* p){
    Node* pred = 0;
    Node* curr = root;
    while(curr){
        if(curr -> data < p->data){
            pred = curr;
            curr = curr -> right;
        }
        else{
            curr = curr->left;
        }
    }
    return pred;
}

// find inorder successor
Node* findSuccessor(Node* root,Node* q){
    Node* succ = 0;
    Node* curr = root;
    while(curr){
        if(curr->data > q->data){
            succ = curr;
            curr = curr -> left;
        }
        else{
            curr = curr -> right;
        }
    }
    return succ;
}


// 1008. Construct Binary Search Tree from Preorder Traversal
Node* build(int &i,int min,int max,vector<int>&preorder){
    if(i>=preorder.size()){
        return nullptr;
    }
    Node* root = nullptr;
    if(preorder[i] > min && preorder[i] < max){
        root = new Node(preorder[i++]);
        root->left = build(i,min,root->data,preorder);
        root -> right = build(i,root->data,max,preorder);
    }
    return root;
}
Node* bstFromPreorder(vector<int>& preorder) {
    int min = INT_MIN , max = INT_MAX;
    int i = 0;
    return build(i,min,max,preorder);
}




// brothers from different roots => gfg
int countPairs(Node* root1,Node* root2,int x){
    int ans = 0;
    stack<Node*>s1,s2;
    Node* a = root1;
    Node* b = root2;
    while(1){
        while(a){
            // inorder
            s1.push(a);
            a = a->left;
        }
        while(b){
            // reverse inorder
            s2.push(b);
            b = b->right;
        }
        if(s1.empty() || s2.empty()){
            break;
        }
        auto atop = s1.top();
        auto btop = s2.top();

        int sum = atop->data + btop->data;
        if(sum == x){
            ++ans;
            s1.pop();
            s2.pop();
            a = atop -> right;
            b = btop -> left;
        }
        else if(sum < x){
            s1.pop();
            a = atop->right;
        }
        else{
            s2.pop();
            b = btop->left;
        }
    }
    return ans;
}


// 1382. Balance a Binary Search Tree
void inorder(Node*root,vector<int>&in){
    if(!root) return;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
Node* buildTree(vector<int>&in,int start,int end){
    if(start > end) return NULL;
    int mid = (start+end)/2;
    Node* root = new Node(in[mid]);
    root->left = buildTree(in,start,mid-1);
    root->right = buildTree(in,mid+1,end);
    return root;
}
Node* balanceBST(Node* root) {
    vector<int>in;
    inorder(root,in);
    return buildTree(in,0,in.size()-1);
}


// Median of BST - gfg
// we have used morris traversal two times
int findNodeCount(Node* root) {
    int count = 0;
    Node* current,*pre;

    if(root == NULL){
        return -1;
    }

    current = root;
    while(current != NULL){
        if(current -> left == NULL){
            count++;
            current = current -> right;
        }
        else{
            pre = current -> left;
            while(pre -> right != NULL && pre->right != current){
                pre = pre -> right;
            }

            if(pre->right == NULL){
                pre -> right = current;
                current = current -> left;
            }
            else{
                pre -> right = NULL;
                count++;
                current = current -> right;
            }
        }
    } 
    return count;       
}
float findActualMedian(Node* root,int& n) {
    int i = 0;
    int odd1 = (n+1)/2,odd1Val = -1;
    int even1 = n/2,even1Val = -1;
    int even2 = n/2+1,even2Val = -1;
    Node* current,*pre;

    current = root;
    while(current != NULL){
        if(current -> left == NULL){
            i++;
            if(i==odd1) odd1Val = current->data;
            if(i==even1) even1Val = current->data;
            if(i==even2) even2Val = current->data;
            current = current -> right;
        }
        else{
            pre = current -> left;
            while(pre -> right != NULL && pre->right != current){
                pre = pre -> right;
            }

            if(pre->right == NULL){
                pre -> right = current;
                current = current -> left;
            }
            else{
                pre -> right = NULL;
                i++;
                if(i==odd1) odd1Val = current->data;
                if(i==even1) even1Val = current->data;
                if(i==even2) even2Val = current->data;
                current = current -> right;
            }
        }
    } 
    float median = 0;
    if((n%2)==0){
        // even
        median = (even1Val + even2Val)/2.0;
    }else{
        // odd
        median = odd1Val;
    }
    return median;
}
float findMedian(struct Node*root){
    int n = findNodeCount(root);
    return findActualMedian(root,n);
}



// Check whether BST contains Dead End -> gfg
void fun(Node* root,unordered_map<int,bool>&visited,bool &ans){
    if(root == 0) return;
    visited[root->data] = 1;
    // here zero means null
    if(root->left == 0 && root->right == 0) {
        int xp1 = root->data + 1;
        int xm1 = root->data - 1 == 0 ? root->data : root->data - 1;
        // yha pr agr minus krke 0 aa jata hai toh hm 1 hi rkhenge qki vo dead end hai
        if(visited.find(xp1) != visited.end() && visited.find(xm1) != visited.end()){
            ans = true;
            return;
        }
    }
    fun(root->left,visited,ans);
    fun(root->right,visited,ans);
}
bool isDeadEnd(Node *root)
{
    bool ans = false;
    unordered_map<int,bool>visited;
    fun(root,visited,ans);
    return ans;
}




// 938. Range Sum of BST

int rangeSumBST(Node* root, int low, int high) {
    if(!root) return 0;
    int ans = 0;

    bool wasInRange = false;
    if(root->data >= low && root->data <= high){
        wasInRange = true;
        ans += root->data;
    }
    if(wasInRange){
        ans += rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
    }
    else if(root->data < low){
        ans += rangeSumBST(root->right,low,high);
    }
    else if(root->data > high){
        ans += rangeSumBST(root->left,low,high);
    }
    return ans;
}


// Flatten a BST into sorted LL 
void in(Node* root,Node*&prev){
    if(!root) return;
    in(root->left,prev);
    prev->left = 0;
    prev->right = root;
    prev = root;
    in(root->right,prev);
}

Node* flatten(Node* root){
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    in(root,prev);
    prev->left = prev->right = 0;
    root= dummy->right;
    return root;
}



// Replace every element with the least greater element on its right - gfg

// class Node{
//     public:
//     int data;
//     Node*left,*right;
//     Node(int val):data(val),left(0),right(0){};
// };

// class Solution{
//     public:
//     Node* insert(Node*root,int val,int&succ){
//         if(!root) return new Node(val);
//         if(val >= root->data){
//             root->right = insert(root->right,val,succ);
//         }
//         else{
            // jb left jao phele succ ko store kro phir jao
//             succ = root->data;
//             root->left = insert(root->left,val,succ);
//         }
//         return root;
//     }
//     vector<int> findLeastGreater(vector<int>& arr, int n) {
//         vector<int>ans(arr.size(),-1);
//         Node* root = 0;
//         for(int i=arr.size()-1;i>=0;--i){
//             int succ = -1;
//             root = insert(root,arr[i],succ);
//             ans[i] = succ;
//         }
//         return ans;
//     }
// };




// Valid BST from preorder -> given a sequence of node you have to return true if the sequence is a valid BST preorder sequence otherwise false

void buildT(int &i,int min,int max,vector<int>&A){
    if(i >= A.size()){
        return ;
    }
    if(A[i] > min && A[i] < max){
        int rootData = A[i++];
        buildT(i,min,rootData,A);
        buildT(i,rootData,max,A);
    }
}

bool solve(vector<int>&A){
    int min = INT_MIN,max = INT_MAX;
    int i = 0;
    buildT(i,min,max,A);
    return i == A.size();
}


// Merge two BST -> gfg
vector<int> merge(Node *root1, Node *root2)
{
    vector<int>ans;
    stack<Node*>sa,sb;
    Node* a = root1,*b = root2;
    while(a || b || !sa.empty() || !sb.empty()){
        while(a){
            sa.push(a);
            a = a->left;
        }
        while(b){
            sb.push(b);
            b = b->left;
        }
        
        if(sb.empty() || (!sa.empty() && sa.top()->data <= sb.top()->data)){
            auto atop = sa.top();
            ans.push_back(atop->data);
            sa.pop();
            a = atop->right;
        }
        else{
            auto btop = sb.top();
            sb.pop();
            ans.push_back(btop->data);
            b = btop->right;
        }
    }
    return ans;
}