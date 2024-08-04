#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <map>
#include <limits.h>
#include <algorithm>
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

Node* buildTree(){
    int data;
    cout<<"Enter the data : "<<endl;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node"<<endl;
    root -> left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node"<<endl;
    root -> right = buildTree();

    return root;
}


// // Balanced Binary Tree --> leetcode

// int height(Node* root){
//     if(root == NULL){
//         return 0;
//     }
//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);
//     int ans = max(leftHeight,rightHeight) + 1;

//     return ans;
// }
// bool isBalanced(Node* root) {
//     if(root == NULL){
//         return true;
//     }

//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);
//     int diff = abs(leftHeight - rightHeight);

//     bool ans1 = (diff <= 1);

//     // Recursion
//     bool leftAns = isBalanced(root->left);
//     bool rightAns = isBalanced(root->right);

//     if(ans1 && leftAns && rightAns){
//         return true;
//     }else{
//         return false;
//     }
// }


// // 236. Lowest Common Ancestor of a Binary Tree
// Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
//     if(root == NULL)
//         return NULL;

//     if(root->data == p->data)
//         return p;

//     if(root->data == q->data)
//         return q;

//     Node* leftAns = lowestCommonAncestor(root->left,p,q);
//     Node* rightAns = lowestCommonAncestor(root->right,p,q);

//     if(leftAns == NULL && rightAns == NULL)
//         return NULL;
//     else if(leftAns != NULL && rightAns == NULL)
//         return leftAns;
//     else if(leftAns == NULL && rightAns != NULL)
//         return rightAns;
//     else
//         return root;
// }


// // Convert into sum tree

// int convertIntoSumTree(Node* root){
//     if(root == NULL){
//         return 0;
//     }

//     int leftAns = convertIntoSumTree(root->left);
//     int rightAns = convertIntoSumTree(root->right);
//     root -> data = root->data + leftAns + rightAns;

//     return root->data;
// }



// int main(){
//     Node *root = NULL;
//     root = buildTree();

//     // input - 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1
//     cout<<"Ans sum is : "<<convertIntoSumTree(root)<<endl;
// }



// Kth ancestor of a node - gfg

// Node* solve(Node* root,int& k,int node){
//     if(root==NULL){
//         return NULL;
//     }
//     if(root->data==node){
//         return root;
//     }
//     Node* leftAns=solve(root->left,k,node);
//     Node* rightAns=solve(root->right,k,node);
    
//     if(leftAns != NULL && rightAns==NULL){
//         k--;
//         if(k<=0){
//             k=INT_MAX;
//             return root;
//         }
//         return leftAns;
//     }
//     if(leftAns==NULL && rightAns!= NULL){
//         k--;
//         if(k<=0){
//             k=INT_MAX;
//             return root;
//         }
//         return rightAns;
//     }
//     return NULL;
// }
// int kthAncestor(Node *root, int k, int node)
// {
//     Node* ans=solve(root,k,node);
//     if(ans==NULL || ans->data==node){
//         return -1;
//     }
//     else{
//         return ans->data;
//     }
// }




// path sum || --> leetcode

// void solve(Node* root,int targetSum,int &currSum,vector<int>path,vector<vector<int>>&ans){
//     if(root == NULL){
//         return;
//     }
//     // leaf node 
//     if(root->left == NULL && root->right == NULL){
//         path.push_back(root->data);
//         currSum += root->data;
//         if(currSum == targetSum){
//             ans.push_back(path);
//         }
//         path.pop_back();
//         currSum -= root->data;
//         return;
//     }

//     // include curr node
//     path.push_back(root->data);
//     currSum += root->data;

//     solve(root->left,targetSum,currSum,path,ans);
//     solve(root->right,targetSum,currSum,path,ans);

//     path.pop_back();
//     currSum -= root->data;
// }

// vector<vector<int>> pathSum(Node* root, int targetSum) {
//     vector<vector<int>>ans;
//     int sum = 0;
//     vector<int>temp;
//     solve(root,targetSum,sum,temp,ans);
//     return ans;
// }





int findPosition(int arr[],int n,int element){
    for(int i=0;i<n;i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

Node* buildTreeFromPreandInorder(int inorder[],int preorder[],int size,int &preIndex,int inorderStart,int inorderEnd){
    if(preIndex >= size || inorderStart > inorderEnd) {
        return NULL;
    }

    int element = preorder[preIndex++];
    Node* root = new Node(element);

    int pos = findPosition(inorder,size,element); 

    // solve left part
    root->left = buildTreeFromPreandInorder(inorder,preorder,size,preIndex,inorderStart,pos-1);

    // solve right part
    root->right = buildTreeFromPreandInorder(inorder,preorder,size,preIndex,pos+1,inorderEnd);

    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*>q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }
}

void createMapping(unordered_map<int,int>&mapping,int inorder[],int n){
    for(int i=0;i<n;i++){
        mapping[inorder[i]] = i;
    }
}

Node* buildTreeFromPostOrderInOrder(int inorder[],int postorder[],int &size,int &postIndex,int inorderStart,int inorderEnd,unordered_map<int,int>&mapping){
    // postIndex ko by reference pass krna hai remember

    // base case
    if(postIndex < 0 || inorderStart > inorderEnd){
        return NULL;
    }

    int element = postorder[postIndex];
    postIndex--;
    Node* root = new Node(element);

    // int pos = findPosition(inorder,size,element);
    int pos = mapping[element];

    // yha right ki call phele lgegi remember
    root->right = buildTreeFromPostOrderInOrder(inorder,postorder,size,postIndex,pos+1,inorderEnd,mapping);

    root->left = buildTreeFromPostOrderInOrder(inorder,postorder,size,postIndex,inorderStart,pos-1,mapping);

    return root;
}


int main(){

    // int inorder[] = {40,20,50,10,60,30,70};
    // int preorder[] = {10,20,40,50,30,60,70};
    // int size = 7;
    // int preIndex = 0;
    // int inorderStart = 0;
    // int inorderEnd = size-1;

    cout<<"building Tree: "<<endl;

    // Node* root = buildTreeFromPreandInorder(inorder,preorder,size,preIndex,inorderStart,inorderEnd);

    // cout<<"Printing level order traversal "<<endl;
    
    // levelOrderTraversal(root);

    int inorder2[] = {40,20,10,50,30,60};
    int postorder[] = {40,20,50,60,30,10};
    int size2 = 6;
    int postIndex = size2-1;
    int inorderStart2 = 0;
    int inorderEnd2 = size2-1;

    unordered_map<int,int> mapping;
    // we have used mapping here only to increase time complexity
    createMapping(mapping,inorder2,size2);

    Node* root = buildTreeFromPostOrderInOrder(inorder2,postorder,size2,postIndex,inorderStart2,inorderEnd2,mapping);

    cout<<"Printing level order traversal "<<endl;
    
    levelOrderTraversal(root);


    return 0;
}

